# Vector Search Engine & AI Systems Specialization

> **28 weeks / 7 months** (Sep 2026 – Mar 2027).  
> **Months 1–4 = Vector Search Engine.** **Months 5–7 = GPU specialization.**  
> **Deep learning**: one Saturday afternoon (not weekdays).  
> **No REST API** in `secan` (nanobind + CLI). Distributed CPU cluster = stretch.

## Start here

| Doc | Use when |
|:---|:---|
| [**Curriculum index**](curriculum/README.md) | Cadence, pillars, month map |
| [**Hard landings**](curriculum/landings.md) | What must ship which week |
| [**Week 1 execution**](curriculum/week-01/execution.md) | Sep 1–7 hour-by-hour |
| [**This month’s weeks**](curriculum/weeks/month-01-sep.md) | Day tables (pick current month) |
| [**Architecture roadmap**](curriculum/roadmap.md) | Macro `secan` blueprint |
| [**Monthly research**](research/README.md) | 7 publish topics + weekend research slots |

## Entry prerequisites (before Sep 1)

| Gate | Requirement |
|:---|:---|
| **CPU** | x86_64 with AVX2 (AVX-512 nice-to-have). ARM64 host or CI by Week 23. |
| **GPU** | NVIDIA + CUDA by Week 13. Multi-GPU / NVLink = Week 20 stretch. |
| **Storage** | ≥50 GB free; **NVMe by Week 16** (DiskANN / `io_uring`). |
| **Datasets** | SIFT1M Week 1; **768-D text `.fvecs` by Week 8 Fri**; BEIR/MS MARCO slice Month 3 Sundays. |
| **VRAM** | BERT/ColBERT/ViT expect a GPU; CPU-only = tiny synthetic runs. |
| **Tooling** | CMake 3.20+, C++20, `perf`, `uv`, Python 3.11+, Git. |

## Monthly research (publish)

| Month | Topic | Due |
|:---|:---|:---|
| Sep | Measurement-first distance microbenchmarks | Sep 27 |
| Oct | Anisotropy / hubness / SQ–PQ–FastScan–ScaNN + OPQ / asymmetric | Oct 25 |
| Nov | PLAID vs MUVERA FDE→MIPS + BEIR/MS MARCO slice | Nov 29 |
| Dec | GPU IVF + Vamana/DiskANN + RRF/WAND | Dec 27 |
| Jan | PagedAttention × TurboQuant (KV) | Jan 31 |
| Feb | Pre/post/range filters + ACORN + portable SIMD | Feb 28 |
| Mar | FA-2, multi-GPU, KV paging → `v2.0` | Mar 12 |

Details: [`research/README.md`](research/README.md).

## Layout

```
goals/
├── README.md                 ← you are here
├── curriculum/
│   ├── README.md             ← cadence + month index
│   ├── landings.md           ← VS / DL / deferred ledgers
│   ├── roadmap.md            ← architecture blueprint
│   ├── essays.md             ← lab-note titles
│   ├── week-01/execution.md  ← detailed Week 1
│   └── weeks/month-0N-*.md   ← day tables by month
└── research/
    ├── README.md             ← publish bar + 7 topics
    └── YYYY-MM-<slug>/       ← monthly paper folders
```
