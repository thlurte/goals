# 🚀 Week 03 Execution Playbook

> **Theme**: Integration, Fundamental Theorem, Cache Hierarchy & Scalar Autograd Engine  
> **Calendar Dates**: Sat Sep 19 – Fri Sep 25 (2026-09-19 to 2026-09-25)
> **Parent Month Dashboard**: [Month 1 (Sep 2026)](month-01-sep.md) · **Block**: I — Vector Search Engine

| | | |
|:---|:---|:---|
| [← Week 02](week-02.md) | [Month 1 (Sep 2026) Dashboard](month-01-sep.md) | [Week 04 →](week-04.md) |

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
| **Saturday** | Sat Sep 19 | [`Day 015`](../days/month-01/day-015-2026-09-19.md) | **09:00–13:00**: Pure Math Block 1 (Theory & Derivations) | **15:00–16:30**: Literature Sanctuary | **18:00–19:30**: Information Theory (Cover & Thomas) · **19:30–21:00**: Thought Leadership (George Pólya) · **21:00+**: Free / Rest|
| **Sunday** | Sun Sep 20 | [`Day 016`](../days/month-01/day-016-2026-09-20.md) | **09:00–13:00**: Pure Math Block 2 (Problem Sets & Proofs) | **13:00**: Maint · **15:00**: Penrose | **18:00–19:30**: Dist Systems (DDIA Ch 3.1) · **19:30–21:00**: Systems Lab (H&P Ch 2) |
| **Monday** | Mon Sep 21 | [`Day 017`](../days/month-01/day-017-2026-09-21.md) | **CSAPP §6.1–6.3**: SRAM vs DRAM, memory latency gap, spatial and temporal locality principles. | **Hardware Profiling & Benchmark Sweeps** | **secan**: Profile SIFT1M cache misses with `perf stat -e L1-dcache-load-misses,LLC-load-misses`. Calculate working set. |
| **Tuesday** | Tue Sep 22 | [`Day 018`](../days/month-01/day-018-2026-09-22.md) | **CSAPP §6.4–6.5**: Cache line organization, set associativity, conflict misses, cache-friendly coding. | **DL Track (Part 1): Architecture & Tensor Shapes** | **secan**: Implement cache-blocked `linear_scan_tiled`: partition dataset into tiles fitting in L2 cache ($256\text{KB}$). |
| **Wednesday** | Wed Sep 23 | [`Day 019`](../days/month-01/day-019-2026-09-23.md) | **CSAPP §6.6 & PIKUS Ch 4**: The Memory Mountain, cache hierarchy on real workloads, software prefetching. | **DL Track (Part 2): Training Loop & Verification** | **secan**: Add software prefetching (`_mm_prefetch`, `_MM_HINT_T0`). Tune prefetch distances ($4, 8, 16, 32$ vectors). |
| **Thursday** | Thu Sep 24 | [`Day 020`](../days/month-01/day-020-2026-09-24.md) | **AGNER Ch 9**: Memory access, non-temporal stores. | **DL / Vector Retrieval Integration & Profiling** | **secan**: Unit-sphere pre-normalization path for cosine/IP. Store optional `norm` column. |
| **Friday** | Fri Sep 25 | [`Day 021`](../days/month-01/day-021-2026-09-25.md) | **FINSY Ch 6**: `madvise(MADV_HUGEPAGE)` & **FLANN** KD-Trees. | **Weekly Technical Article: Drafting & Publishing** | **secan**: Hugepage `madvise` warmup + **FLANN Randomized KD-Trees**. |

---

## 📋 Daily Action Items & Deliverables (Week 03)

### 🔹 Saturday, Sat Sep 19 ([`Day 015`](../days/month-01/day-015-2026-09-19.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 1**: Theory, concepts, and analytical derivations (textbook chapters & core proofs).
* `[ ]` **Core (15:00–16:30)**: **Weekend Reading Sanctuary**: Literature / Philosophy deep reading.
* `[ ]` **Core (16:30–18:00)**: **Physical Break & Mental Decompression**: Walk, tea, and recovery.
* `[ ]` **Core (18:00–19:30)**: **Information Theory Track**: Thomas M. Cover & Joy A. Thomas, *Elements of Information Theory* — **Ch 3.1–3.3** (Asymptotic Equipartition Property (AEP) & Typical Sets).
* `[ ]` **Core (19:30–21:00)**: **Thought Leadership Masterclass**: George Pólya, *How to Solve It* — **Part III (E–P): Dictionary of Heuristic** (Induction, Mathematical Invariants, Indirect Proof (Reductio ad Absurdum), Notation & Figures).
* `⭐ Optional / Stretch`: 21:00 onwards 100% Free / Rest.

### 🔹 Sunday, Sun Sep 20 ([`Day 016`](../days/month-01/day-016-2026-09-20.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 2**: Advanced theorems, problem sets, and chalkboard proof defense.
* `[ ]` **Core (13:00–14:00)**: **Runtime Maintenance**: Quick 30–60 min check for `limbed` / `ggmbed` (`embed-runtimes`).
* `[ ]` **Core (15:00–16:45)**: **Penrose Sunday**: *The Road to Reality* (1 chapter/week, visual geometry focus).
* `[ ]` **Core (18:00–19:30)**: **Distributed Systems & IR Track**: **DDIA Ch 3.1** (Storage and Retrieval: Log-Structured Storage, SSTables, LSM-Trees, Memtables & Compaction).
* `[ ]` **Core (19:30–21:00)**: **Graduate Systems & GPU Architecture Lab**: Microarchitecture analysis and CUDA exercises in **H&P Ch 2** (Multi-banked memory architectures, cache line conflict analysis & stride optimization).
* `⭐ Optional / Stretch`: 21:00 onwards Weekly review & recovery.

### 🔹 Monday, Mon Sep 21 ([`Day 017`](../days/month-01/day-017-2026-09-21.md))
* `[ ]` **Core**: Profile SIFT1M cache miss rates with `perf stat`; compute working set size for $10^5$ and $10^6$ vectors.
* `⭐ Optional / Stretch`: Write a tiny benchmark that measures the cache memory mountain (bandwidth vs stride size from 4KB to 64MB).


### 🔹 Tuesday, Tue Sep 22 ([`Day 018`](../days/month-01/day-018-2026-09-22.md))
* `[ ]` **Core**: Implement `linear_scan_tiled()` partitioning vector database into L2-cache tiles ($256\text{KB}$).
* `⭐ Optional / Stretch`: Experiment with multi-level cache tiling (L1 tile inside L2 tile) for multi-query batches.


### 🔹 Wednesday, Wed Sep 23 ([`Day 019`](../days/month-01/day-019-2026-09-23.md))
* `[ ]` **Core**: Insert `_mm_prefetch` instructions in linear scan loop; benchmark prefetch lookahead distance $K \in \{4, 8, 16, 32\}$.
* `⭐ Optional / Stretch`: Test non-temporal prefetch hints (`_MM_HINT_NTA`) vs temporal (`_MM_HINT_T0`) on datasets that exceed L3 cache.


### 🔹 Thursday, Thu Sep 24 ([`Day 020`](../days/month-01/day-020-2026-09-24.md))
* `[ ]` **Core**: Implement offline unit-sphere pre-normalization for cosine distance so queries reduce to pure inner product `ip()`.
* `⭐ Optional / Stretch`: Implement in-place SIMD normalization kernel using `_mm256_div_ps` and compare throughput.


### 🔹 Friday, Fri Sep 25 ([`Day 021`](../days/month-01/day-021-2026-09-25.md))
* `[ ]` **Core**: Add `madvise(MADV_HUGEPAGE)` transparent hugepage allocation on dataset mmap buffer + implement **FLANN `RandomizedKdTree` baseline** with Best-Bin-First search.
* `⭐ Optional / Stretch`: Benchmark KD-Tree speedup vs brute-force across $D \in \{2, 8, 16, 64, 128\}$ to demonstrate the high-D curse of dimensionality phase transition.


---

## ⛔ What NOT to Overspend Time On (Week 03 Time Traps)

* ❌ **Do NOT** spend hours over-tuning prefetch distances—test 4 discrete distances ($4, 8, 16, 32$) and select the best median.
* ❌ **Do NOT** implement complex custom thread pools for tiled scans yet—single-threaded cache tiling establishes the baseline.
* ❌ **Do NOT** solve advanced trigonometric integrals with multiple integration-by-parts iterations on paper—grasp the reduction formula concept and stop.

---

## Benchmark Close

Before the Friday article or release, save the run manifest and raw JSON/CSV, add one meaningful parameter sweep and plot, update the comparable README result row, and state the oracle result plus one evidence-backed conclusion. Record results below the noise floor as inconclusive.

## 📝 Weekend Deliverables

### ✍️ Technical Essay 03 (Drafted Friday 06:30–08:30)
* **Title**: *"Integrals, Accumulation, and CPU Cache Hierarchies: Cache Tiling and Autograd from Scratch"*
* **Target File**: `~/personal/goals/essays/essay_03.md`
* **5-Part Structure**:
  1. **Mathematical Foundation**: Core theorems, derivations, and formal definitions.
  2. **The Systems Bottleneck**: Hardware limitation (memory bandwidth, port contention, cache line splits, warp stalls).
  3. **The Engine Architecture**: Exact data structures and SIMD/CUDA kernel design implemented in `secan`.
  4. **Empirical Benchmarks**: Perf counter tables, latency percentiles ($p50/p95/p99$), and QPS curves.
  5. **Key Takeaway**: Architectural rule of thumb for production AI systems.

### 🧠 Deep Learning Track (Tue/Wed 06:30–08:30 Morning Builder)
* **Task**: **🧠 DL Builder Track (Tue/Wed)**: **Micrograd autograd engine** (~150 lines): `Value` class with `+`, `*`, `tanh`, `exp`, `backward()` using topological sort. Verify gradient of a tiny 2-layer MLP matches PyTorch. **Then** implement Pre-LN encoder + FFN with manual `backward()` for `Linear` layer (compare `dW` vs `param.grad`).

### 🔬 Empirical Systems & Benchmarking Focus (Mon/Thu 06:30–08:30 Morning Builder)
* **Focus**: Memory Mountain Sweeps, Cache Tiling & Software Prefetching
* **Workspace**: `research/2026-09-measurement-protocol/` & `secan/benchmarks/`
* **Artifact Target**: Cache eviction data (`week3_memory_mountain.json`) feeding into Friday's Technical Article 03.
