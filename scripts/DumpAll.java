// Ghidra headless script: full-coverage dump of a program.
// Usage: analyzeHeadless ... -postScript DumpAll.java <output_dir>
// Produces: decompiled/part_NNN.c, functions-index.csv, symbols-all.csv,
//           strings-defined.csv, sections.csv, summary.txt
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolIterator;

import java.io.*;
import java.nio.charset.StandardCharsets;
import java.nio.file.*;

public class DumpAll extends GhidraScript {

    private static String csv(String v) {
        if (v == null) return "";
        return v.replace('\n', ' ').replace('\r', ' ').replace(',', ';').replace('"', '\'');
    }

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length == 0) {
            println("DumpAll: missing output dir argument");
            return;
        }
        Path out = Paths.get(args[0]);
        Path decDir = out.resolve("decompiled");
        Files.createDirectories(decDir);
        long t0 = System.currentTimeMillis();
        Program prog = currentProgram;

        DecompInterface dec = new DecompInterface();
        dec.toggleCCode(true);
        dec.setSimplificationStyle("decompile");
        dec.openProgram(prog);

        // ---- 1) decompile EVERY function, chunked output ----
        int total = 0, ok = 0, fail = 0, chunkNo = 0, inChunk = 0;
        final int PER_CHUNK = 400;
        BufferedWriter idx = null, chunk = null;
        try {
            idx = Files.newBufferedWriter(out.resolve("functions-index.csv"), StandardCharsets.UTF_8);
            idx.write("address,name,thunk,body_bytes,decompiled,error\n");
            FunctionIterator it = prog.getFunctionManager().getFunctions(true);
            while (it.hasNext()) {
                if (monitor.isCancelled()) { println("CANCELLED at " + total); break; }
                Function f = it.next();
                total++;
                if (chunk == null || inChunk >= PER_CHUNK) {
                    if (chunk != null) { chunk.flush(); chunk.close(); }
                    chunk = Files.newBufferedWriter(decDir.resolve(String.format("part_%03d.c", chunkNo++)), StandardCharsets.UTF_8);
                    inChunk = 0;
                }
                String name = f.getName();
                String addr = f.getEntryPoint().toString();
                long bodyBytes = f.getBody().getNumAddresses();
                boolean thunk = f.isThunk();
                boolean decompiled = false;
                String err = "";
                try {
                    DecompileResults r = dec.decompileFunction(f, 60, monitor);
                    if (r != null && r.decompileCompleted() && r.getDecompiledFunction() != null) {
                        String c = r.getDecompiledFunction().getC();
                        chunk.write("// ===== " + addr + " " + name + " =====\n");
                        chunk.write(c == null || c.isEmpty() ? "// <empty decompilation>\n" : c);
                        if (!c.endsWith("\n")) chunk.write("\n");
                        chunk.write("\n");
                        decompiled = true;
                        ok++;
                    } else {
                        err = r == null ? "null_results"
                                : (r.getErrorMessage() == null ? "no_code" : r.getErrorMessage());
                        fail++;
                    }
                } catch (Exception e) {
                    err = "exception:" + (e.getMessage() != null ? e.getMessage() : e.getClass().getName());
                    fail++;
                }
                idx.write(addr + "," + csv(name) + "," + thunk + "," + bodyBytes + "," + decompiled + "," + csv(err) + "\n");
                inChunk++;
                if (total % 2000 == 0) {
                    println("PROGRESS functions=" + total + " ok=" + ok + " fail=" + fail
                            + " elapsed_s=" + ((System.currentTimeMillis() - t0) / 1000));
                }
            }
        } finally {
            if (chunk != null) { chunk.flush(); chunk.close(); }
            if (idx != null) { idx.flush(); idx.close(); }
        }

        // ---- 2) every symbol ----
        int symCount = 0;
        try (BufferedWriter sym = Files.newBufferedWriter(out.resolve("symbols-all.csv"), StandardCharsets.UTF_8)) {
            sym.write("address,name,namespace,type,source,external\n");
            SymbolIterator sit = prog.getSymbolTable().getAllSymbols(true);
            while (sit.hasNext()) {
                Symbol s = sit.next();
                sym.write(s.getAddress() + "," + csv(s.getName()) + ","
                        + csv(s.getParentNamespace().getName()) + "," + s.getSymbolType() + ","
                        + s.getSource() + "," + s.isExternal() + "\n");
                symCount++;
            }
        }

        // ---- 3) every defined string ----
        int strCount = 0;
        try (BufferedWriter strw = Files.newBufferedWriter(out.resolve("strings-defined.csv"), StandardCharsets.UTF_8)) {
            strw.write("address,value\n");
            DataIterator di = prog.getListing().getDefinedData(true);
            while (di.hasNext()) {
                Data d = di.next();
                Object v = d.getValue();
                if (!(v instanceof String)) continue;
                strw.write(d.getAddress() + "," + csv(v.toString()) + "\n");
                strCount++;
            }
        }

        // ---- 4) sections ----
        int secCount = 0;
        try (BufferedWriter sw = Files.newBufferedWriter(out.resolve("sections.csv"), StandardCharsets.UTF_8)) {
            sw.write("name,start,end,length,read,write,execute,type\n");
            for (MemoryBlock b : prog.getMemory().getBlocks()) {
                sw.write(csv(b.getName()) + "," + b.getStart() + "," + b.getEnd() + ","
                        + b.getSize() + "," + b.isRead() + "," + b.isWrite() + "," + b.isExecute()
                        + "," + b.getType() + "\n");
                secCount++;
            }
        }

        long ms = System.currentTimeMillis() - t0;
        String summary =
                "program=" + prog.getName() + "\n" +
                "executable_path=" + prog.getExecutablePath() + "\n" +
                "language=" + prog.getLanguageID() + "\n" +
                "compiler_spec=" + prog.getCompilerSpec().getCompilerSpecID() + "\n" +
                "functions_total=" + total + "\n" +
                "functions_decompiled_ok=" + ok + "\n" +
                "functions_failed=" + fail + "\n" +
                "symbols_total=" + symCount + "\n" +
                "defined_strings=" + strCount + "\n" +
                "sections=" + secCount + "\n" +
                "elapsed_ms=" + ms + "\n" +
                "elapsed_min=" + (ms / 60000.0) + "\n";
        Files.write(out.resolve("summary.txt"), summary.getBytes(StandardCharsets.UTF_8));
        println("DUMP_COMPLETE " + summary.replace("\n", " | "));
    }
}
