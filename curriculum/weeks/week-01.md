# 🚀 Week 01 Execution Playbook

> **Theme**: Pure Trigonometry, Limits, Derivatives & Measurement  
> **Calendar Dates**: Mon Sep 1 – Sun Sep 7 (2026-09-01 to 2026-09-07)  
> **Parent Month Dashboard**: [Month 1 (Sep 2026)](month-01-sep.md) · **Block**: I — Vector Search Engine

| | | |
|:---|:---|:---|
| [← Curriculum Index](../README.md) | [Month 1 (Sep 2026) Dashboard](month-01-sep.md) | [Week 02 →](week-02.md) |

---

## ⏰ Daily Operational Rhythm

```
┌──────────────────────────────┬────────────────────────────────────────────────────────────────────────┐
│ Time Slot                    │ Focus / Activity                                                       │
├──────────────────────────────┼────────────────────────────────────────────────────────────────────────┤
│ 📖 05:30 – 06:30 (60 min)    │ Systems & Architecture Deep Reading (Papers & Microarchitecture)       │
│ 🛠️ 06:30 – 08:30 (120 min)   │ Morning Builder Track (DL / Monthly Research / Technical Essays)        │
│ ☀️ Daytime                   │ Professional Workday (Full focus, zero math fatigue)                   │
│ 📚 18:30 – 20:00 (90 min)    │ Evening Reading Sanctuary (Pirsig / GEB / Dostoevsky / Wiener)         │
│ 💻 20:30 – 22:30 (2.0 hrs)   │ Night Hands-On Implementation (secan C++20 / CUDA flow state)          │
├──────────────────────────────┼────────────────────────────────────────────────────────────────────────┤
│ 📐 Saturday 09:00 – 13:00    │ Pure Mathematics Block 1 (Theory, Concepts, Derivations)               │
│ ☕ Saturday 15:00 – 16:30    │ Weekend Reading Immersion (Pirsig / GEB / Literature)                  │
│ 📐 Sunday 09:00 – 13:00      │ Pure Mathematics Block 2 (Problem Sets, Chalkboard Proofs)             │
│ 🔧 Sunday 13:00 – 14:00      │ Runtime Maintenance (limbed / ggmbed check)                            │
│ 🌌 Sunday 15:00 – 16:45      │ Penrose Sunday: The Road to Reality (1 chapter/week, visual geometry)  │
└──────────────────────────────┴────────────────────────────────────────────────────────────────────────┘
```

---

## 📅 Day-by-Day Master Timetable

| Day | Date | Daily Runbook | Systems Reading (05:30–06:30) | Morning Builder Track (06:30–08:30) | Night Hands-On C++/CUDA (20:30–23:00) |
|:---|:---|:---|:---|:---|:---|
| **Monday** | Mon Sep 1 | [`Day 001`](../days/month-01/day-001-2026-09-01.md) | **PIKUS Ch 2**: Performance measurements, high-res timers, profiler sampling, micro-benchmark noise floor. | **Monthly Research: Planning & Literature Synthesis** | **secan**: Integrate Google Benchmark via CMake. Add ASan/UBSan build flags. Write first benchmark for `l2_squared` with `DoNotOptimize`. |
| **Tuesday** | Tue Sep 2 | [`Day 002`](../days/month-01/day-002-2026-09-02.md) | **CSAPP §5.1–5.6**: Compiler limitations, Cycles Per Element (CPE), loop inefficiencies, memory aliasing. | **DL Track (Part 1): Architecture & Tensor Shapes** | **secan**: Implement binary `.fvecs`, `.bvecs`, and `.ivecs` parsers. Download SIFT1M base + ground-truth; load into `data/sift1m/`. |
| **Wednesday** | Wed Sep 3 | [`Day 003`](../days/month-01/day-003-2026-09-03.md) | **CSAPP §5.7**: Superscalar architecture, out-of-order execution, execution ports, latency vs throughput. | **DL Track (Part 2): Training Loop & Verification** | **secan**: Build IR metrics in `tests/test_ir_metrics.cpp` (NDCG@K, MRR, **MAP**). Run exact scan on a **SIFT1M subset** (e.g. 100K base / 1K queries) first; verify Recall@10 = 1.0. Full 1M scan = stretch. |
| **Thursday** | Thu Sep 4 | [`Day 004`](../days/month-01/day-004-2026-09-04.md) | **AGNER Ch 3 & Ch 7.1–7.3**: Bottlenecks, FP efficiency. | **Monthly Research: Sweeps & Data Logging** | **secan**: First-class **inner-product** kernel `ip()` alongside `l2_squared`. Distance enum: L2 / IP / cosine. *(DL: Sat Sep 6.)* |
| **Friday** | Fri Sep 5 | [`Day 005`](../days/month-01/day-005-2026-09-05.md) | **PIKUS Ch 1 & CSAPP §5.14**: Measurement-driven optimization, profiling-guided workflow with `perf stat`. | **Technical Essay: Lab-Note Drafting** | **secan**: Profile baseline scan with `perf stat`. Record IPC, cache misses, branch misses. Populate first row of README benchmark table. |
| **Saturday** | Sat Sep 6 | [`Day 006`](../days/month-01/day-006-2026-09-06.md) | **09:00–13:00**: Pure Math Block 1 (Theory & Derivations) | **14:00–18:00**: FREE / Rest / Buffer | Weekend Deep Work |
| **Sunday** | Sun Sep 7 | [`Day 007`](../days/month-01/day-007-2026-09-07.md) | **09:00–13:00**: Pure Math Block 2 (Problem Sets & Proofs) | **13:00–14:00**: Maintenance | Rest & Buffer |

---

## 📋 Daily Action Items & Deliverables (Week 01)

### 🔹 Monday, Mon Sep 1 ([`Day 001`](../days/month-01/day-001-2026-09-01.md))
* `[ ]` **Core**: CMake setup for Google Benchmark via `FetchContent`; implement `benchmarks/bench_distance.cpp` with `benchmark::DoNotOptimize`.
* `⭐ Optional / Stretch`: Add a benchmark measuring the exact nanosecond cost of compiler dead-code elimination (with vs without `DoNotOptimize`).

### 🔹 Tuesday, Tue Sep 2 ([`Day 002`](../days/month-01/day-002-2026-09-02.md))
* `[ ]` **Core**: Implement `.fvecs`, `.bvecs`, `.ivecs` binary loaders in `include/secan/utils/io.h` and `src/utils/io.cpp`; verify SIFT1M headers.
* `⭐ Optional / Stretch`: Implement memory-mapped (`mmap`) zero-copy loader in addition to standard `std::ifstream` and compare load times.

### 🔹 Wednesday, Wed Sep 3 ([`Day 003`](../days/month-01/day-003-2026-09-03.md))
* `[ ]` **Core**: Implement NDCG@K, MRR, and MAP in `tests/test_ir_metrics.cpp`; run exact scan on 100K SIFT subset.
* `⭐ Optional / Stretch`: Complete exact scan over the full 1M SIFT1M dataset; verify Recall@10 = 1.000 on all 10,000 queries.

### 🔹 Thursday, Thu Sep 4 ([`Day 004`](../days/month-01/day-004-2026-09-04.md))
* `[ ]` **Core**: Implement first-class `ip()` inner product kernel in `distance.cpp`; define `enum class MetricType { L2, IP, Cosine }`.
* `⭐ Optional / Stretch`: Implement a fast reciprocal square root (`1.0f / sqrtf(...)`) approximation for cosine normalizations.

### 🔹 Friday, Fri Sep 5 ([`Day 005`](../days/month-01/day-005-2026-09-05.md))
* `[ ]` **Core**: Profile baseline exact scan with `perf stat -e cycles,instructions,branches,branch-misses,L1-dcache-load-misses`; record baseline IPC.
* `⭐ Optional / Stretch`: Capture a flame graph / `perf record` trace of the exact scan loop; identify instruction-cache vs data-cache bottleneck.

### 🔹 Saturday, Sat Sep 6 ([`Day 006`](../days/month-01/day-006-2026-09-06.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 1**: Theory, concepts, and analytical derivations (textbook chapters & core proofs).
* `[ ]` **Core (15:00–16:30)**: **Weekend Reading Sanctuary**: Literature / Philosophy deep reading.
* `⭐ Optional / Stretch`: 100% Free / Rest / Recovery buffer.
### 🔹 Sunday, Sun Sep 7 ([`Day 007`](../days/month-01/day-007-2026-09-07.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 2**: Advanced theorems, problem sets, and chalkboard proof defense.
* `[ ]` **Core (13:00–14:00)**: **Runtime Maintenance**: Quick 30–60 min check for `limbed` / `ggmbed` (`embed-runtimes`).
* `[ ]` **Core (15:00–16:45)**: **Penrose Sunday**: *The Road to Reality* (1 chapter/week, visual geometry focus).
---

## ⛔ What NOT to Overspend Time On (Week 01 Time Traps)

* ❌ **Do NOT** hand-write custom timing harnesses or CLI parsers—use Google Benchmark.
* ❌ **Do NOT** start writing AVX2/AVX-512 intrinsics—keep distance kernels in scalar C++ to establish the true unoptimized baseline.
* ❌ **Do NOT** run exact scans on all 1,000,000 vectors $\times$ 10,000 queries if scalar latency exceeds 60s—use the 100K subset for rapid iteration.
* ❌ **Do NOT** do Pure Mathematics on weekday mornings—math is strictly reserved for Saturday and Sunday morning deep-work blocks (09:00–13:00). Keep weekday mornings focused on Systems Reading and Builder Track.

---

## 📝 Weekend Deliverables

### ✍️ Technical Essay 01 (Saturday 09:00–13:00)
* **Title**: *"The Geometry of High-Dimensional Retrieval: Trigonometric Projections, NDCG Ranking, and Hardware Performance Counters"*
* **Target File**: `~/personal/goals/essays/essay_01.md`
* **5-Part Structure**:
  1. **Mathematical Foundation**: Core theorems, derivations, and formal definitions.
  2. **The Systems Bottleneck**: Hardware limitation (memory bandwidth, port contention, cache line splits, warp stalls).
  3. **The Engine Architecture**: Exact data structures and SIMD/CUDA kernel design implemented in `secan`.
  4. **Empirical Benchmarks**: Perf counter tables, latency percentiles ($p50/p95/p99$), and QPS curves.
  5. **Key Takeaway**: Architectural rule of thumb for production AI systems.

### 🧠 Deep Learning Track (Tue/Wed 06:30–08:30 Morning Builder)
* **Task**: **🧠 DL weekend**: `uv init transformers-pytorch`; SDPA + causal mask.

### 🔬 Monthly Research Milestone (GAPQ Milestone 1 — Mon/Thu 06:30–08:30 Morning Builder)
* **Paper**: *"Microarchitectural Limits of Distance Kernels & Empirical Embedding Cone Anisotropy"*
* **Workspace**: `research/2026-09-measurement-protocol/`
* **Publish Deadline**: **Sun Sep 27**
