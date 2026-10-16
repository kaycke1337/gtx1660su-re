# Complete GPU Reverse Engineering — NVIDIA GeForce GTX 1660 SUPER (TU116)

Date: 2026-10-13 · Hardware mode: **read-only** (no flash, no overclock, no power-limit change, no module reload, no writes to the card at any point)

Toolchain: REA 6.4.0 (`morluto/rea`) + **Ghidra 12.1.4** (installed on the secondary disk at `/run/media/kaycke/343AE6CE3AE68BE4/tools/ghidra_12.1.4_PUBLIC`, zip sha256 verified `ddac49f9…`), OpenJDK 26.0.2, `GHIDRA_INSTALL_DIR` persisted in `~/.bashrc` and `~/.config/environment.d/rea.conf`.

## 1. GPU identity

| Field | Value | Evidence |
|---|---|---|
| Name | NVIDIA GeForce GTX 1660 SUPER | `nvidia-smi` |
| Chip | TU116, PCI **10de:21c4** (rev a1) | `lspci -nn` |
| Subsystem | 10de:13d3 | `lspci-gpu.txt` |
| Bus / links | 01:00.0, PCIe Gen2 x16 (5 GT/s); BAR0 16M, BAR1 256M prefetch, BAR3 32M, I/O cc00 | `lspci-gpu.txt` |
| Memory | 6144 MiB | `nvidia-smi-full.txt` |
| Architecture | Turing | `nvidia-smi-full.txt` |
| Driver | NVRM Open Kernel Module **595.71.05** (DKMS `nvidia`) | `/proc/driver/nvidia/version`, `modinfo-nvidia.txt` |
| VBIOS | **90.16.4F.00.E5** | `nvidia-smi`, `proc-gpu-info.txt` |
| Board ID / UUID | 0x100 / GPU-ca27b7f0-ef35-fbc7-8f32-4723b798428c | `proc-gpu-info.txt` |
| Power | current/default limit 125 W (min 70 W) | `nvidia-smi-full.txt` |

## 2. VBIOS (sysfs dump, read-only)

- `vbios.rom` — **57,344 bytes** from `/sys/bus/pci/devices/0000:01:00.0/rom` (shadow-ROM enable `1` / restore `0`, a documented read operation that does not alter the card).
- Header `55 AA`, image length byte `0x70` = 112 × 512 B = 57,344 B (exact file size), PCIR structure @0x170: vendor `0x10de`, device `0x21c4`, data-structure length 24, legacy x86 option ROM (no embedded PE/EFI).
- **Image checksum = 0x00 (VALID)** → the dumped ROM is intact.
- Identity strings (`vbios-identidad.txt`, `vbios-strings.txt`, 106 strings):
  `NVIDIA GeForce GTX 1660 SUPER VGA BIOS V6693` · `Version 90.16.4F.00.E5` · `Copyright (C) 1996-2020 NVIDIA Corp.` · `S07/30/20` · part number `3002G1610026` · `PLEASE POWER DOWN AND CONNECT THE PCIe POWER CABLE(S) FOR THIS GRAPHICS CARD`

## 3. Kernel module `nvidia.ko` (working copy; original untouched)

- Source `/lib/modules/7.1.8-arch1-3/updates/dkms/nvidia.ko.zst` (11 MB) → decompressed copy `nvidia.ko` 25 MB, sha256 `4a7c1b5bb61790122e1e2c5b9d9aa8bbfd6c2bac8bd4d43b25b02bf28d1db556`.
- ELF64 **REL (relocatable)**, x86-64, 81 sections, **24,955 symbols** (not stripped), srcversion `58D233B8E3F4…`.
- Functions: **14,040 global (T) + 4,532 local (t)** ≈ 18,572 by `nm`.
- Kernel exports via `__ksymtab`: `nvidia_get_rm_ops`, `nvidia_p2p_get_pages`, `nvidia_p2p_dma_map_pages`, `nvidia_p2p_destroy_mapping`, … (P2P memory API).
- Module aliases: `pci:v000010DEd*…bc03sc00/sc02`, `char-major-195-*`, Tegra/OF entries.
- `NVreg*` parameters present (EnablePCIeGen3, EnableMSI, DynamicPowerManagement, EnableGpuFirmware, DmaRemapPeerMio, CoherentGPUMemoryMode, …); license Dual MIT/GPL.

## 4. REA + Ghidra evidence analyses (interactive path)

- `rea analyze nvidia.ko` → exit 0. Evidence `ev_8a09eebb6ed6…`, provider **Ghidra 12.1.4**, authority `shipped-artifact`. Segments: `.text` 4,356,263 B (0x103140–0x52a9e7), `.rodata` 8,709,594 B, `.data` 213,278 B, `.bss` 282,064 B, `.modinfo` 2,842 B, `__ksymtab` 1,152 B, …
- `rea function --procedure nv_start_device` → exit 0. Evidence `ev_3a61a8c3c0c3…`, confidence **observed**: procedure @0x1062a0, body 2,077 B, **463 instructions, 113 basic blocks**, caller `nv_open_device`, callees `nv_soc_register_irqs`/`nv_get_rsync_info`/`rm_ref_dynamic_power`/`kmem_cache_alloc_noprof(nvidia_stack_t_cache)`, referenced strings `EnableMSI`, `" is using the IRQ.\n"`, `nv_queue`, `nv_remove_numa_memory`; pseudocode 11,158 chars.

## 5. FULL-COVERAGE BULK DECOMPILATION (the "100%")

REA has no batch decompile, so a custom Ghidra headless script (`~/rea-gpu-analysis/scripts/DumpAll.java`, the same engine REA drives) decompiled **every** function and exported the complete tables.

| Target | Functions | Decompiled OK | Failed | Coverage |
|---|---|---|---|---|
| `nvidia.ko` (kernel driver) | **18,971** | **18,971** | 0 | **100.00 %** |
| `libnvidia-ml.so.595.71.05` (NVML, 2.5 MB) | **3,951** | **3,951** | 0 | **100.00 %** |
| **Total** | **22,922** | **22,922** | **0** | **100.00 %** |

Coverage was cross-verified three independent ways per target: index rows = `// ===== ` markers in the C output = `decompiled=true` rows (and `false` = 0).

Complete inventories also exported:

| Table | nvidia.ko | libnvidia-ml |
|---|---|---|
| Symbols (address, name, namespace, type, source, external) | 124,120 | 80,320 |
| Defined strings | 49,522 | 6,042 |
| Sections | 82 | 30 |

Output layout (44 MB, secondary disk):

```
/run/media/kaycke/343AE6CE3AE68BE4/rea-gpu-full/
├── MANIFEST.sha256            # 74/74 files verified OK
├── file-list.txt              # sizes of every artifact
├── nvidia-ko/
│   ├── decompiled/part_000.c … part_047.c   # all 18,971 functions as C pseudocode (400 per file)
│   ├── functions-index.csv    # address,name,thunk,body_bytes,decompiled,error
│   ├── symbols-all.csv  · strings-defined.csv  · sections.csv  · summary.txt
│   └── headless*.log
└── libnvidia-ml/              # same layout, all 3,951 functions
```

Ghidra metadata: language `x86:LE:64:default`, compiler spec `gcc`; `nvidia.ko` took 5.3 min, `libnvidia-ml` 1.8 min.

## 6. Card integrity (before/after)

- After all analysis: **38 °C**, 7–19 % utilization, 18 W, idle clocks, driver loaded.
- `dmesg`: **no Xid / NVRM errors**; only the informational `No more images in PCI ROM` lines produced by the sysfs ROM read (expected, harmless).
- No write-path command was ever used (no `nvidia-smi -pl`, no OC, no flash, no `rmmod`).

## 7. Problems found and fixed during this run

1. `provider_timeout` (330,000 ms) from REA → root cause `DEFAULT_GHIDRA_STARTUP_TIMEOUT_MS`; fixed with `REA_GHIDRA_STARTUP_TIMEOUT_MS=1800000` (retry exit 0).
2. `GHIDRA_INSTALL_DIR` not inherited by non-interactive shells → exported explicitly.
3. `rea analyze` rejects raw option ROMs (`unsupported binary format`) → parsed PCIR/checksum locally.
4. Broken quoting in my first headless command (`unexpected EOF`) → relaunched correctly.
5. Ghidra requires the project directory to pre-exist (`mkdir -p` first).
6. Ghidra 12.1.4 removed `Listing.getDefinedStrings(boolean)` → compile error; switched to `getDefinedData(true)` + String filter.

## 8. Limitations

- Pseudocode is Ghidra's representation, not the original NVIDIA source; thunks/`__fentry__`/return thunks appear as injections.
- Import warnings: `R_X86_64_PC64` relocations (tracepoint/`validate_usercopy_range` sites) are not applied by Ghidra's ELF loader; a handful of functions emit `pcode error … EXTERNAL block location` warnings when calling unresolved externals — bodies are still fully decompiled.
- Kernel-module addresses are section-relative (ET_REL); they relocate at load time.
- Deep firmware/GPU-command traffic lives in the signed firmware images (`gpu:0/gpu:…` GSP/scheduler blobs), not in the kernel module — out of scope here.
- User's `/` partition is at 100 % (was 1.3 GB free at session start, 674 MB now; my temporary Ghidra projects/caches were deleted). All deliverables live on the 44 GB-free secondary disk.

## 9. How to reproduce

```bash
export GHIDRA_INSTALL_DIR=/run/media/kaycke/343AE6CE3AE68BE4/tools/ghidra_12.1.4_PUBLIC
# REA evidence path (one function):
rea function ~/rea-gpu-analysis/nvidia.ko --procedure nv_start_device --snapshot gpu --format json
# Bulk path (all functions):
mkdir -p /tmp/ghidra-projects
$GHIDRA_INSTALL_DIR/support/analyzeHeadless /tmp/ghidra-projects gpuko \
  -import ~/rea-gpu-analysis/nvidia.ko \
  -scriptPath ~/rea-gpu-analysis/scripts \
  -postScript DumpAll.java <output_dir> -log <output_dir>/headless.log
```
