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
| [**This month’s weeks**](curriculum/weeks/month-01-sep.md) | Day-by-day tables, actions, stretch & time traps |
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
| Sep | Microarchitectural Limits of SIMD Vector Distance Kernels | Sep 27 |
| Oct | Anisotropy-Aware Quantization: Hubness, Cones & Loss Functions | Oct 25 |
| Nov | Streaming Late Interaction: PLAID vs MUVERA FDE in Dynamic LSM Storage | Nov 29 |
| Dec | Billion-Scale Retrieval Frontiers: In-VRAM GPU IVF vs Asynchronous NVMe DiskANN | Dec 27 |
| Jan | Paging vs Quantizing LLM KV Caches at Long Contexts | Jan 31 |
| Feb | Mitigating Recall Collapse in Filtered ANN Graphs: ACORN vs Post-Filtering | Feb 28 |
| Mar | Unified IO-Aware GPU Architecture: FlashAttention-2, Paged KV & Multi-GPU | Mar 12 |

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
│   └── weeks/month-0N-*.md   ← day tables & actions by month
└── research/
    ├── README.md             ← publish bar + 7 topics
    └── YYYY-MM-<slug>/       ← monthly paper folders
```
