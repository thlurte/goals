# Vector Search Engine & AI Systems Specialization

> **28 weeks / 7 months** (Sep 2026 – Mar 2027).
> **Months 1–4 = Vector Search Engine (`secan`).** **Months 5–7 = GPU Specialization (CUDA/CUTLASS).**
> **Deep Learning Track**: Tuesday & Wednesday mornings (06:30–08:30 builder track).
> **No REST API** in `secan` (nanobind + CLI). Distributed CPU cluster = stretch.

## Start here

| Doc | Use when |
|:---|:---|
| [**Curriculum index**](curriculum/README.md) | Cadence, pillars, month map |
| [**Hard landings**](curriculum/landings.md) | What must ship which week |
| [**This month’s weeks**](curriculum/weeks/month-01-sep.md) | Day-by-day tables, actions, stretch & time traps |
| [**Architecture roadmap**](curriculum/roadmap.md) | Macro `secan` blueprint |
| [**Systems & CPU Performance Resources**](resources/cpu-performance-engineering.md) | Primary sources, microarchitecture papers, cache models & benchmarks |
| [**limbed + ggmbed**](projects/embed-runtimes.md) | Inspection holes + 6-month fix timeline (30–60 min/wk) |

## Entry prerequisites (before Sep 1)

| Gate | Requirement |
|:---|:---|
| **CPU** | x86_64 with AVX2 (AVX-512 nice-to-have). ARM64 host or CI by Week 23. |
| **GPU** | NVIDIA + CUDA by Week 13. Multi-GPU / NVLink = Week 20 stretch. |
| **Storage** | ≥50 GB free; **NVMe by Week 16** (DiskANN / `io_uring`). |
| **Datasets** | SIFT1M Week 1; **768-D text `.fvecs` by Week 8 Fri**; BEIR/MS MARCO slice Month 3. |
| **VRAM** | BERT/ColBERT/ViT expect a GPU; CPU-only = tiny synthetic runs. |
| **Tooling** | CMake 3.20+, C++20, `perf`, `uv`, Python 3.11+, Git. |

## 28 Weekly Technical Articles & Systems Publishing

Rather than superficial academic paper publishing deadlines, real-world systems engineering is demonstrated through **28 weekly, publication-grade technical lab-notes and systems articles** drafted every Friday morning (06:30–08:30) and grounded directly in empirical benchmark sweeps, cache profiling, and implementation insights.

* Weekday Morning Builder Rhythm:
  * **Monday (06:30–08:30)**: Hardware Profiling & Benchmark Sweeps (`secan` / microarchitecture).
  * **Tuesday (06:30–08:30)**: Deep Learning Track (Architecture & Tensor Shapes Part 1).
  * **Wednesday (06:30–08:30)**: Deep Learning Track (Autograd, Training Loops & Tests Part 2).
  * **Thursday (06:30–08:30)**: DL / Vector Retrieval Integration & Profiling (`secan` + DL).
  * **Friday (06:30–08:30)**: Weekly Technical Article: Drafting & Publishing.

## Layout

```
goals/
├── README.md                 ← you are here
├── curriculum/
│   ├── README.md             ← cadence + master index
│   ├── landings.md           ← VS / DL / deferred ledgers
│   ├── roadmap.md            ← architecture blueprint
│   ├── weeks/
│   │   ├── month-0N-*.md     ← day tables & actions by month
│   │   └── week-01.md ...    ← 28 weekly execution playbooks
│   └── days/
│       └── month-0N/day-*.md ← 196 individual daily runbooks
├── projects/
│   └── embed-runtimes.md     ← limbed + ggmbed (not secan)
├── resources/
│   └── cpu-performance-engineering.md ← primary sources, architecture papers & benchmarks
└── research/
    ├── README.md             ← empirical benchmark protocol & data guidelines
    └── YYYY-MM-<slug>/       ← empirical benchmark logs & sweeps
```
