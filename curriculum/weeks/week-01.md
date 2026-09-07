# 🚀 Week 01 Execution Playbook

> **Theme**: Pure Trigonometry, Limits, Derivatives & Measurement  
> **Calendar Dates**: Sat Sep 5 – Fri Sep 11 (2026-09-05 to 2026-09-11)  
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
│ 📐 Saturday 09:00 – 13:00    │ Pure Mathematics Block 1 (Theory, Concepts, Derivations)               │
│ ☕ Saturday 15:00 – 16:30    │ Weekend Literature Sanctuary (Pirsig / GEB / Literature)               │
│ 🍵 Saturday 16:30 – 18:00    │ Physical Break & Mental Decompression (Walk, tea, workout)             │
│ 📚 Saturday 18:00 – 19:30    │ [NEW] Information Theory (Cover & Thomas: Rate-Distortion & AEP)       │
│ 🌙 Saturday 19:30 Onwards    │ 100% Free / Dinner & Recovery (No night math; morning block done)       │
├──────────────────────────────┼────────────────────────────────────────────────────────────────────────┤
│ 📐 Sunday 09:00 – 13:00      │ Pure Mathematics Block 2 (Problem Sets, Chalkboard Proofs)             │
│ 🔧 Sunday 13:00 – 14:00      │ Runtime Maintenance (limbed / ggmbed check)                            │
│ 🌌 Sunday 15:00 – 16:45      │ Penrose Sunday: The Road to Reality (1 chapter/week, visual geometry)  │
│ 🗄️ Sunday 18:00 – 19:30      │ [NEW] Distributed Systems & IR Track (DDIA / Manning IIR)              │
│ ⚙️ Sunday 19:30 – 21:00      │ [LAB] Graduate Systems & GPU Architecture Lab (H&P / Kirk & Hwu)       │
├──────────────────────────────┼────────────────────────────────────────────────────────────────────────┤
│ 📖 Mon–Fri 05:30 – 06:30     │ Systems & Architecture Deep Reading (Papers & Microarchitecture)       │
│ 🛠️ Mon–Fri 06:30 – 08:30     │ Morning Builder Track (DL / Benchmarking / Technical Articles)        │
│ ☀️ Mon–Fri Daytime           │ Professional Workday (Full focus, zero math fatigue)                   │
│ 📚 Mon–Fri 18:30 – 20:00     │ Evening Reading Sanctuary (Pirsig / GEB / Dostoevsky / Wiener)         │
│ 💻 Mon–Fri 20:30 – 22:30     │ Night Hands-On Implementation (secan C++20 / CUDA flow state)          │
└──────────────────────────────┴────────────────────────────────────────────────────────────────────────┘
```

---

## 📅 Day-by-Day Master Timetable

| Day | Date | Daily Runbook | Systems Reading (05:30–06:30) | Morning Builder Track (06:30–08:30) | Night Hands-On C++/CUDA (20:30–23:00) |
|:---|:---|:---|:---|:---|:---|
| **Saturday** | Sat Sep 5 | [`Day 001`](../days/month-01/day-001-2026-09-05.md) | **09:00–13:00**: Pure Math Block 1 (Theory & Derivations) | **15:00–16:30**: Literature Sanctuary | **18:00–19:30**: Information Theory (Cover & Thomas) · **19:30–21:00**: Thought Leadership (George Pólya) · **21:00+**: Free / Rest|
| **Sunday** | Sun Sep 6 | [`Day 002`](../days/month-01/day-002-2026-09-06.md) | **09:00–13:00**: Pure Math Block 2 (Problem Sets & Proofs) | **13:00**: Maint · **15:00**: Penrose | **18:00–19:30**: Dist Systems (DDIA Ch 1) · **19:30–21:00**: Systems Lab (H&P Ch 1) |
| **Monday** | Mon Sep 7 | [`Day 003`](../days/month-01/day-003-2026-09-07.md) | **PIKUS Ch 2** & **H&P §1.1–1.5**: Performance measurements, high-res timers, profiler sampling, micro-benchmark noise floor, quantitative computer architecture. | **Hardware Profiling & Benchmark Calibration** | **secan**: Integrate Google Benchmark via CMake. Add ASan/UBSan build flags. Write first benchmark for `l2_squared` with `DoNotOptimize`. |
| **Tuesday** | Tue Sep 8 | [`Day 004`](../days/month-01/day-004-2026-09-08.md) | **CSAPP §5.1–5.6** & **H&P §2.1**: Compiler limitations, Cycles Per Element (CPE), loop inefficiencies, memory aliasing & cache hierarchy. | **DL Track (Part 1): Architecture & Tensor Shapes** | **secan**: Implement binary `.fvecs`, `.bvecs`, and `.ivecs` parsers. Download SIFT1M base + ground-truth; load into `data/sift1m/`. |
| **Wednesday** | Wed Sep 9 | [`Day 005`](../days/month-01/day-005-2026-09-09.md) | **CSAPP §5.7** & **GREGG Ch 2**: Superscalar architecture, out-of-order execution, execution ports, latency vs throughput, systems performance methodologies. | **DL Track (Part 2): Training Loop & Verification** | **secan**: Build IR metrics in `tests/test_ir_metrics.cpp` (NDCG@K, MRR, **MAP**). Run exact scan on a **SIFT1M subset** (100K base / 1K queries) first; verify Recall@10 = 1.0. Full 1M scan = stretch. |
| **Thursday** | Thu Sep 10 | [`Day 006`](../days/month-01/day-006-2026-09-10.md) | **AGNER Ch 3 & Ch 7.1–7.3** & **H&P §3.1**: Bottlenecks, FP efficiency, instruction-level parallelism. | **DL / Vector Retrieval Integration & Profiling** | **secan**: First-class **inner-product** kernel `ip()` alongside `l2_squared`. Distance enum: L2 / IP / cosine. |
| **Friday** | Fri Sep 11 | [`Day 007`](../days/month-01/day-007-2026-09-11.md) | **PIKUS Ch 1, CSAPP §5.14** & **GREGG Ch 6**: Measurement-driven optimization, profiling-guided workflow with `perf stat`, PMU hardware counters. | **Weekly Technical Article: Drafting & Publishing** | **secan**: Profile baseline scan with `perf stat`. Record IPC, cache misses, branch misses. Populate first row of README benchmark table. |

---

## 📋 Daily Action Items & Deliverables (Week 01)

### 🔹 Saturday, Sat Sep 5 ([`Day 001`](../days/month-01/day-001-2026-09-05.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 1**: Theory, concepts, and analytical derivations (Gelfand Trig Ch 0–3: right triangle ratios, fundamental relations, Law of Cosines & Sines; Strang Calculus §1.1–1.5: $\epsilon$-$\delta$ limit definition, continuity, IVT; Vershynin Ch 1 intro to random vectors on $\mathcal{S}^{d-1}$).
* `[x]` **Core (15:00–16:30)**: **Weekend Reading Sanctuary**: Robert M. Pirsig, *Zen and the Art of Motorcycle Maintenance* Ch 1–2 (Central Plains journey; classic vs romantic understanding). *(Completed through Chapter 4 ahead of schedule!)*
* `[ ]` **Core (16:30–18:00)**: **Physical Break & Mental Decompression**: Walk, tea, and recovery.
* `[ ]` **Core (18:00–19:30)**: **Information Theory Track**: Thomas M. Cover & Joy A. Thomas, *Elements of Information Theory* — **Ch 1 & Ch 2.1–2.3** (Entropy, Joint Entropy, Conditional Entropy & Mutual Information).
* `[ ]` **Core (19:30–21:00)**: **Thought Leadership Masterclass**: George Pólya, *How to Solve It (Princeton Science Library)* — **Part I: In the Classroom** (The Four Stages: Understanding the Problem, Devising a Plan, Carrying Out the Plan, Looking Back).
* `⭐ Optional / Stretch`: 21:00 onwards 100% Free / Rest.

### 🔹 Sunday, Sun Sep 6 ([`Day 002`](../days/month-01/day-002-2026-09-06.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 2**: Advanced theorems, problem sets, and chalkboard proof defense (Strang Calculus §2.1–2.5: derivatives from first principles, linearity, power rule proof, product and quotient rules, algebraic derivatives).
* `[ ]` **Core (13:00–14:00)**: **Runtime Maintenance**: Quick 30–60 min check for `limbed` / `ggmbed` (`embed-runtimes`).
* `[ ]` **Core (15:00–16:45)**: **Penrose Sunday**: *The Road to Reality* — **Ch 1: The Roots of Science** (The Three Worlds: Platonic mathematical, physical, mental).
* `[ ]` **Core (18:00–19:30)**: **Distributed Systems & IR Track**: **DDIA Ch 1** (Reliable, Scalable, and Maintainable Applications: Faults, Load & $p99$ Latency).
* `[ ]` **Core (19:30–21:00)**: **Graduate Systems & GPU Architecture Lab**: Microarchitecture analysis and CUDA exercises in **H&P Ch 1** (Amdahl's law derivations, energy-delay products, CPI/IPC bottleneck calculations).
* `⭐ Optional / Stretch`: 21:00 onwards Weekly review & recovery.

### 🔹 Monday, Mon Sep 7 ([`Day 003`](../days/month-01/day-003-2026-09-07.md))
* `[ ]` **Core**: CMake setup for Google Benchmark via `FetchContent`; implement `benchmarks/bench_distance.cpp` with `benchmark::DoNotOptimize`.
* `⭐ Optional / Stretch`: Add a benchmark measuring the exact nanosecond cost of compiler dead-code elimination (with vs without `DoNotOptimize`).

### 🔹 Tuesday, Tue Sep 8 ([`Day 004`](../days/month-01/day-004-2026-09-08.md))
* `[ ]` **Core**: Implement `.fvecs`, `.bvecs`, `.ivecs` binary loaders in `include/secan/utils/io.h` and `src/utils/io.cpp`; verify SIFT1M headers.
* `⭐ Optional / Stretch`: Implement memory-mapped (`mmap`) zero-copy loader in addition to standard `std::ifstream` and compare load times.

### 🔹 Wednesday, Wed Sep 9 ([`Day 005`](../days/month-01/day-005-2026-09-09.md))
* `[ ]` **Core**: Implement NDCG@K, MRR, and MAP in `tests/test_ir_metrics.cpp`; run exact scan on 100K SIFT subset.
* `⭐ Optional / Stretch`: Complete exact scan over the full 1M SIFT1M dataset; verify Recall@10 = 1.000 on all 10,000 queries.

### 🔹 Thursday, Thu Sep 10 ([`Day 006`](../days/month-01/day-006-2026-09-10.md))
* `[ ]` **Core**: Implement first-class `ip()` inner product kernel in `distance.cpp`; define `enum class MetricType { L2, IP, Cosine }`.
* `⭐ Optional / Stretch`: Implement a fast reciprocal square root (`1.0f / sqrtf(...)`) approximation for cosine normalizations.

### 🔹 Friday, Fri Sep 11 ([`Day 007`](../days/month-01/day-007-2026-09-11.md))
* `[ ]` **Core**: Profile baseline exact scan with `perf stat -e cycles,instructions,branches,branch-misses,L1-dcache-load-misses`; record baseline IPC.
* `⭐ Optional / Stretch`: Capture a flame graph / `perf record` trace of the exact scan loop; identify instruction-cache vs data-cache bottleneck.

---

## ⛔ What NOT to Overspend Time On (Week 01 Time Traps)

* ❌ **Do NOT** hand-write custom timing harnesses or CLI parsers—use Google Benchmark.
* ❌ **Do NOT** start writing AVX2/AVX-512 intrinsics—keep distance kernels in scalar C++ to establish the true unoptimized baseline.
* ❌ **Do NOT** run exact scans on all 1,000,000 vectors $\times$ 10,000 queries if scalar latency exceeds 60s—use the 100K subset for rapid iteration.
* ❌ **Do NOT** do Pure Mathematics on weekday mornings—math is strictly reserved for Saturday and Sunday morning deep-work blocks (09:00–13:00). Keep weekday mornings focused on Systems Reading and Builder Track.

---

## 📝 Weekend & Milestone Deliverables

### ✍️ Technical Essay 01 (Drafted Friday 06:30–08:30)
* **Title**: *"The Geometry of High-Dimensional Retrieval: Trigonometric Projections, NDCG Ranking, and Hardware Performance Counters"*
* **Target File**: `~/personal/goals/essays/essay_01.md`
* **5-Part Structure**:
  1. **Mathematical Foundation**: Core theorems, derivations, and formal definitions.
  2. **The Systems Bottleneck**: Hardware limitation (memory bandwidth, port contention, cache line splits, warp stalls).
  3. **The Engine Architecture**: Exact data structures and SIMD/CUDA kernel design implemented in `secan`.
  4. **Empirical Benchmarks**: Perf counter tables, latency percentiles (/p95/p99$), and QPS curves.
  5. **Key Takeaway**: Architectural rule of thumb for production AI systems.

### 🧠 Deep Learning Track (Tue/Wed 06:30–08:30 Morning Builder)
* **Task**: `uv init transformers-pytorch`; SDPA + causal mask from first principles.

### 🔬 Empirical Systems & Benchmarking Focus (Mon/Thu 06:30–08:30 Morning Builder)
* **Focus**: Microarchitectural Limits of Distance Kernels & Hardware Calibration
* **Workspace**: `research/2026-09-measurement-protocol/` & `secan/benchmarks/`
* **Artifact Target**: Baseline calibration data (`week1_baseline.json`) feeding directly into Friday's Technical Article 01.
