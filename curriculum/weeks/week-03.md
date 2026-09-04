# 🚀 Week 03 Execution Playbook

> **Theme**: Integration, Fundamental Theorem, Cache Hierarchy & Transformer Encoder  
> **Calendar Dates**: Mon Sep 15 – Sun Sep 21 (2026-09-15 to 2026-09-21)  
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
│ 📖 05:30 – 06:30 (60 min)    │ Systems & Architecture Deep Reading (Papers & Microarchitecture)       │
│ 🛠️ 06:30 – 08:30 (120 min)   │ Morning Builder Track (DL / Monthly Research / Technical Essays)        │
│ ☀️ Daytime                   │ Professional Workday (Full focus, zero math fatigue)                   │
│ 💻 20:30 – 23:00 (2.5 hrs)   │ Night Hands-On Implementation (secan C++20 / CUDA flow state)          │
├──────────────────────────────┼────────────────────────────────────────────────────────────────────────┤
│ 📐 Saturday 09:00 – 13:00    │ Pure Mathematics Block 1 (Theory, Concepts, Derivations)               │
│ 🧘 Saturday 14:00 – 18:00    │ 100% FREE / Rest / Personal Time / Buffer                              │
│ 📐 Sunday 09:00 – 13:00      │ Pure Mathematics Block 2 (Problem Sets, Chalkboard Proofs)             │
│ 🔧 Sunday 13:00 – 14:00      │ Runtime Maintenance (limbed / ggmbed check)                            │
│ 🧘 Sunday 14:00 – 18:00      │ 100% FREE / Rest / Personal Time / Buffer                              │
└──────────────────────────────┴────────────────────────────────────────────────────────────────────────┘
```

---

## 📅 Day-by-Day Master Timetable

| Day | Date | Daily Runbook | Systems Reading (05:30–06:30) | Morning Builder Track (06:30–08:30) | Night Hands-On C++/CUDA (20:30–23:00) |
|:---|:---|:---|:---|:---|:---|
| **Monday** | Mon Sep 15 | [`Day 015`](../days/month-01/day-015-2026-09-15.md) | **CSAPP §6.1–6.3**: SRAM vs DRAM, memory latency gap, spatial and temporal locality principles. | **Monthly Research: Planning & Literature Synthesis** | **secan**: Profile SIFT1M cache misses with `perf stat -e L1-dcache-load-misses,LLC-load-misses`. Calculate working set. |
| **Tuesday** | Tue Sep 16 | [`Day 016`](../days/month-01/day-016-2026-09-16.md) | **CSAPP §6.4–6.5**: Cache line organization, set associativity, conflict misses, cache-friendly coding. | **DL Track (Part 1): Architecture & Tensor Shapes** | **secan**: Implement cache-blocked `linear_scan_tiled`: partition dataset into tiles fitting in L2 cache ($256\text{KB}$). |
| **Wednesday** | Wed Sep 17 | [`Day 017`](../days/month-01/day-017-2026-09-17.md) | **CSAPP §6.6 & PIKUS Ch 4**: The Memory Mountain, cache hierarchy on real workloads, software prefetching. | **DL Track (Part 2): Training Loop & Verification** | **secan**: Add software prefetching (`_mm_prefetch`, `_MM_HINT_T0`). Tune prefetch distances ($4, 8, 16, 32$ vectors). |
| **Thursday** | Thu Sep 18 | [`Day 018`](../days/month-01/day-018-2026-09-18.md) | **AGNER Ch 9**: Memory access, non-temporal stores. | **Monthly Research: Sweeps & Data Logging** | **secan**: Unit-sphere pre-normalization path for cosine/IP. Store optional `norm` column. |
| **Friday** | Fri Sep 19 | [`Day 019`](../days/month-01/day-019-2026-09-19.md) | **FINSY Ch 6**: `madvise(MADV_HUGEPAGE)`. | **Technical Essay: Lab-Note Drafting** | **secan**: Hugepage / `madvise` warmup on dataset mmap. *(DL: Sat Sep 20 Pre-LN encoder.)* |
| **Saturday** | Sat Sep 20 | [`Day 020`](../days/month-01/day-020-2026-09-20.md) | **09:00–13:00**: Pure Math Block 1 (Theory & Derivations) | **14:00–18:00**: FREE / Rest / Buffer | Weekend Deep Work |
| **Sunday** | Sun Sep 21 | [`Day 021`](../days/month-01/day-021-2026-09-21.md) | **09:00–13:00**: Pure Math Block 2 (Problem Sets & Proofs) | **13:00–14:00**: Maintenance | Rest & Buffer |

---

## 📋 Daily Action Items & Deliverables (Week 03)

### 🔹 Monday, Mon Sep 15 ([`Day 015`](../days/month-01/day-015-2026-09-15.md))
* `[ ]` **Core**: Profile SIFT1M cache miss rates with `perf stat`; compute working set size for $10^5$ and $10^6$ vectors.
* `⭐ Optional / Stretch`: Write a tiny benchmark that measures the cache memory mountain (bandwidth vs stride size from 4KB to 64MB).

### 🔹 Tuesday, Tue Sep 16 ([`Day 016`](../days/month-01/day-016-2026-09-16.md))
* `[ ]` **Core**: Implement `linear_scan_tiled()` partitioning vector database into L2-cache tiles ($256\text{KB}$).
* `⭐ Optional / Stretch`: Experiment with multi-level cache tiling (L1 tile inside L2 tile) for multi-query batches.

### 🔹 Wednesday, Wed Sep 17 ([`Day 017`](../days/month-01/day-017-2026-09-17.md))
* `[ ]` **Core**: Insert `_mm_prefetch` instructions in linear scan loop; benchmark prefetch lookahead distance $K \in \{4, 8, 16, 32\}$.
* `⭐ Optional / Stretch`: Test non-temporal prefetch hints (`_MM_HINT_NTA`) vs temporal (`_MM_HINT_T0`) on datasets that exceed L3 cache.

### 🔹 Thursday, Thu Sep 18 ([`Day 018`](../days/month-01/day-018-2026-09-18.md))
* `[ ]` **Core**: Implement offline unit-sphere pre-normalization for cosine distance so queries reduce to pure inner product `ip()`.
* `⭐ Optional / Stretch`: Implement in-place SIMD normalization kernel using `_mm256_div_ps` and compare throughput.

### 🔹 Friday, Fri Sep 19 ([`Day 019`](../days/month-01/day-019-2026-09-19.md))
* `[ ]` **Core**: Add `madvise(MADV_HUGEPAGE)` and transparent hugepage allocation on dataset mmap buffer.
* `⭐ Optional / Stretch`: Measure TLB page fault overhead via `perf stat -e dTLB-load-misses` before and after hugepages.

### 🔹 Saturday, Sat Sep 20 ([`Day 020`](../days/month-01/day-020-2026-09-20.md))
* `[ ]` **Core (09:00–13:00)**: Write and ship **Technical Essay 3**: *"Integrals, Accumulation, and CPU Cache Hierarchies: Cache Tiling and Autograd from Scratch"* to `goals/essays/essay_03.md`.
* `[ ]` **Core (14:00–18:00)**: Execute Saturday Deep Learning from Scratch track (**🧠 DL weekend**: **Micrograd autograd engine** (~150 lines): `Value` class with `+`, `*`, `tanh`, `exp`, `backward()` using topological sort. Verify gradient of a tiny 2-layer MLP matches PyTorch. **Then** implement Pre-LN encoder + FFN with manual `backward()` for `Linear` layer (compare `dW` vs `param.grad`).).
* `⭐ Optional / Stretch`: Run automated test suite validating PyTorch numerical gradient and attention equivalence.

### 🔹 Sunday, Sun Sep 21 ([`Day 021`](../days/month-01/day-021-2026-09-21.md))
* `[ ]` **Core (09:00–13:00)**: Execute Monthly Research Milestone for Month 1 (`research/2026-09-measurement-protocol/`): run empirical benchmarks and record data tables.
* `⭐ Optional / Stretch`: Draft / update section figures and experimental limitations.

---

## ⛔ What NOT to Overspend Time On (Week 03 Time Traps)

* ❌ **Do NOT** spend hours over-tuning prefetch distances—test 4 discrete distances ($4, 8, 16, 32$) and select the best median.
* ❌ **Do NOT** implement complex custom thread pools for tiled scans yet—single-threaded cache tiling establishes the baseline.
* ❌ **Do NOT** solve advanced trigonometric integrals with multiple integration-by-parts iterations on paper—grasp the reduction formula concept and stop.

---

## 📝 Weekend Deliverables

### ✍️ Technical Essay 03 (Saturday 09:00–13:00)
* **Title**: *"Integrals, Accumulation, and CPU Cache Hierarchies: Cache Tiling and Autograd from Scratch"*
* **Target File**: `~/personal/goals/essays/essay_03.md`
* **5-Part Structure**:
  1. **Mathematical Foundation**: Core theorems, derivations, and formal definitions.
  2. **The Systems Bottleneck**: Hardware limitation (memory bandwidth, port contention, cache line splits, warp stalls).
  3. **The Engine Architecture**: Exact data structures and SIMD/CUDA kernel design implemented in `secan`.
  4. **Empirical Benchmarks**: Perf counter tables, latency percentiles ($p50/p95/p99$), and QPS curves.
  5. **Key Takeaway**: Architectural rule of thumb for production AI systems.

### 🧠 Deep Learning Track (Saturday 14:00–18:00)
* **Task**: **🧠 DL weekend**: **Micrograd autograd engine** (~150 lines): `Value` class with `+`, `*`, `tanh`, `exp`, `backward()` using topological sort. Verify gradient of a tiny 2-layer MLP matches PyTorch. **Then** implement Pre-LN encoder + FFN with manual `backward()` for `Linear` layer (compare `dW` vs `param.grad`).

### 🔬 Monthly Research Milestone (Sunday 09:00–13:00)
* **Paper**: *"Microarchitectural Limits of SIMD Vector Distance Kernels: Execution Port Contention, Cache-Line Splits, and Measurement Artifacts on Modern x86"*
* **Workspace**: `research/2026-09-measurement-protocol/`
* **Publish Deadline**: **Sun Sep 27**
