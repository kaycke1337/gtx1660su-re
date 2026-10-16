# GTX 1660 SUPER (TU116) — Reverse Engineering

Read-only reverse-engineering study of an NVIDIA GeForce GTX 1660 SUPER (TU116, PCI `10de:21c4`)
running on Linux (Arch, NVRM driver 595.71.05), using
[REA 6.4.0](https://github.com/morluto/rea) + Ghidra 12.1.4.

**Full report: [INFORME.md](INFORME.md)**

## Highlights

- **Hardware mode: 100% read-only** — no BIOS flash, no overclock, no power-limit change,
  no module reload, no writes to the card at any point.
- **VBIOS** dumped from sysfs; image checksum verified valid; identity `90.16.4F.00.E5`,
  part number `3002G1610026` (`vbios.rom`, `vbios-identidad.txt`).
- **Full-coverage decompilation** (custom Ghidra headless script `scripts/DumpAll.java`, the same
  engine REA drives):
  - `nvidia.ko` — **18,971 / 18,971 functions (100.00%)**
  - `libnvidia-ml.so.595.71.05` — **3,951 / 3,951 functions (100.00%)**
- Coverage is independently auditable: `full-dump/*/functions-index.csv` (index rows =
  `decompiled=true` rows) = number of `// =====` markers in `full-dump/*/decompiled/part_*.c`.
- REA evidence (JSON) for the binary overview, strings snapshot and a deep dive into
  `nv_start_device` (463 instructions / 113 basic blocks, confidence *observed*).
- `full-dump/MANIFEST.sha256` verifies all 74 exported artifacts (`sha256sum -c`).

## Layout

```
.
├── INFORME.md                  # the full report (start here)
├── README.md
├── SHA256SUMS                  # hashes of the top-level artifacts
├── scripts/DumpAll.java        # Ghidra headless full-coverage dumper
├── nvidia.ko / nvidia.ko.zst   # working copy of the DKMS module (sha256 in report)
├── vbios.rom                   # 57,344-byte VBIOS dump
├── *.txt                       # lspci, modinfo, nvidia-smi, VBIOS identity/strings
├── *.json                      # REA evidence (analyze / function / snapshot)
├── *.err                       # captured stderr of each step (mostly empty)
├── snapshots/gpu-snapshot.json # REA analysis snapshot
└── full-dump/                  # complete export (44 MB): all pseudocode + tables
    ├── MANIFEST.sha256
    ├── file-list.txt
    ├── nvidia-ko/              # decompiled/, functions-index.csv, symbols-all.csv,
    │                           # strings-defined.csv, sections.csv, summary.txt, logs
    └── libnvidia-ml/           # same layout
```

## Reproducing

```bash
export GHIDRA_INSTALL_DIR=/path/to/ghidra
rea function ~/rea-gpu-analysis/nvidia.ko --procedure nv_start_device --snapshot gpu --format json
mkdir -p /tmp/ghidra-projects
$GHIDRA_INSTALL_DIR/support/analyzeHeadless /tmp/ghidra-projects gpuko \
  -import ~/rea-gpu-analysis/nvidia.ko \
  -scriptPath ~/rea-gpu-analysis/scripts \
  -postScript DumpAll.java <output_dir> -log <output_dir>/headless.log
```

## Content note

This repository contains analysis artifacts derived from proprietary NVIDIA software,
including Ghidra decompiler output (pseudocode, not original source) and binary blobs,
published strictly for security research, interoperability and educational purposes.
All trademarks and copyrights belong to their respective owners.
