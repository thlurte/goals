# 🚀 Week 02 Execution Playbook

> **Theme**: Trigonometric Identities, Chain Rule, SIMD AVX2 & Multi-Head Attention  
> **Calendar Dates**: Sat Sep 12 – Fri Sep 18 (2026-09-12 to 2026-09-18)
> **Parent Month Dashboard**: [Month 1 (Sep 2026)](month-01-sep.md) · **Block**: I — Vector Search Engine

| | | |
|:---|:---|:---|
| [← Week 01](week-01.md) | [Month 1 (Sep 2026) Dashboard](month-01-sep.md) | [Week 03 →](week-03.md) |

---

## ⏰ Daily Operational Rhythm

```
┌──────────────────────────────┬────────────────────────────────────────────────────────────────────────┐
│ Time Slot                    │ Focus / Activity                                                       │
├──────────────────────────────┼────────────────────────────────────────────────────────────────────────┤
│ 📐 Saturday 09:00 – 13:00    │ Pure Mathematics Block 1 (Theory, Concepts, Derivations)               │
│ ☕ Saturday 15:00 – 16:30    │ Weekend Reading Immersion (Pirsig / GEB / Literature)                  │
│ 📐 Sunday 09:00 – 13:00      │ Pure Mathematics Block 2 (Problem Sets, Chalkboard Proofs)             │
│ 🔧 Sunday 13:00 – 14:00      │ Runtime Maintenance (limbed / ggmbed check)                            │
│ 🌌 Sunday 15:00 – 16:45      │ Penrose Sunday: The Road to Reality (1 chapter/week, visual geometry)  │
├──────────────────────────────┼────────────────────────────────────────────────────────────────────────┤
│ 📖 Mon–Fri 05:30 – 06:30     │ Systems & Architecture Deep Reading (Papers & Microarchitecture)       │
│ 🛠️ Mon–Fri 06:30 – 08:30     │ Morning Builder Track (DL / Monthly Research / Technical Essays)        │
│ ☀️ Mon–Fri Daytime           │ Professional Workday (Full focus, zero math fatigue)                   │
│ 📚 Mon–Fri 18:30 – 20:00     │ Evening Reading Sanctuary (Pirsig / GEB / Dostoevsky / Wiener)         │
│ 💻 Mon–Fri 20:30 – 22:30     │ Night Hands-On Implementation (secan C++20 / CUDA flow state)          │
└──────────────────────────────┴────────────────────────────────────────────────────────────────────────┘
```

---

## 📅 Day-by-Day Master Timetable

| Day | Date | Daily Runbook | Systems Reading (05:30–06:30) | Morning Builder Track (06:30–08:30) | Night Hands-On C++/CUDA (20:30–23:00) |
|:---|:---|:---|:---|:---|:---|
| **Saturday** | Sat Sep 12 | [`Day 008`](../days/month-01/day-008-2026-09-12.md) | **09:00–13:00**: Pure Math Block 1 (Theory & Derivations) | **14:00–18:00**: FREE / Rest / Buffer | Weekend Deep Work |
| **Sunday** | Sun Sep 13 | [`Day 009`](../days/month-01/day-009-2026-09-13.md) | **09:00–13:00**: Pure Math Block 2 (Problem Sets & Proofs) | **13:00–14:00**: Maintenance | Rest & Buffer |
| **Monday** | Mon Sep 14 | [`Day 010`](../days/month-01/day-010-2026-09-14.md) | **AGNER Ch 12**: SIMD instructions, 256-bit YMM registers, data types, intrinsics syntax. | **Monthly Research: Planning & Literature Synthesis** | **secan**: Enable FTZ/DAZ flags. Implement `l2_squared_avx2()` in `src/search/distance_avx2.cpp`. Single accumulator baseline. |
| **Tuesday** | Tue Sep 15 | [`Day 011`](../days/month-01/day-011-2026-09-15.md) | **CSAPP §5.8–5.9**: Loop unrolling, breaking dependency chains with multiple independent accumulator registers. | **DL Track (Part 1): Architecture & Tensor Shapes** | **secan**: Implement 4-way unrolled `l2_squared_avx2` with 4 parallel `__m256` accumulators. Measure speedup over 1-acc. |
| **Wednesday** | Wed Sep 16 | [`Day 012`](../days/month-01/day-012-2026-09-16.md) | **AGNER-INST & AGNER Ch 11**: VFMADD latency/throughput port mapping on modern x86 microarchitectures. | **DL Track (Part 2): Training Loop & Verification** | **secan**: Implement `cosine_distance_avx2()`: compute dot product, norm $A$, and norm $B$ simultaneously in 1 pass. |
| **Thursday** | Thu Sep 17 | [`Day 013`](../days/month-01/day-013-2026-09-17.md) | **AGNER Ch 13.1–13.3**: Alignment, cache line splits. | **Monthly Research: Sweeps & Data Logging** | **secan**: `ip_avx2()` + fused cosine (dot + norms). Same unrolling as L2. *(DL: Sat Sep 13 GQA.)* |
| **Friday** | Fri Sep 18 | [`Day 014`](../days/month-01/day-014-2026-09-18.md) | **PIKUS Ch 3**: Instruction-level parallelism, register pressure, compiler vectorization limits. | **Technical Essay: Lab-Note Drafting** | **secan**: Add AVX-512 backend (`_mm512_*`) behind `#ifdef __AVX512F__`. Benchmark scalar vs AVX2 vs AVX-512. |

---

## 📋 Daily Action Items & Deliverables (Week 02)

### 🔹 Saturday, Sat Sep 12 ([`Day 008`](../days/month-01/day-008-2026-09-12.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 1**: Theory, concepts, and analytical derivations (textbook chapters & core proofs).
* `[ ]` **Core (15:00–16:30)**: **Weekend Reading Sanctuary**: Literature / Philosophy deep reading.
* `⭐ Optional / Stretch`: 100% Free / Rest / Recovery buffer.

### 🔹 Sunday, Sun Sep 13 ([`Day 009`](../days/month-01/day-009-2026-09-13.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 2**: Advanced theorems, problem sets, and chalkboard proof defense.
* `[ ]` **Core (13:00–14:00)**: **Runtime Maintenance**: Quick 30–60 min check for `limbed` / `ggmbed` (`embed-runtimes`).
* `[ ]` **Core (15:00–16:45)**: **Penrose Sunday**: *The Road to Reality* (1 chapter/week, visual geometry focus).

### 🔹 Monday, Mon Sep 14 ([`Day 010`](../days/month-01/day-010-2026-09-14.md))
* `[ ]` **Core**: Enable FTZ/DAZ (`_MM_SET_FLUSH_ZERO_MODE`); implement `l2_squared_avx2()` baseline (1 `__m256` accumulator).
* `⭐ Optional / Stretch`: Write a microbenchmark testing floating-point denormal performance penalties with FTZ disabled vs enabled.


### 🔹 Tuesday, Tue Sep 15 ([`Day 011`](../days/month-01/day-011-2026-09-15.md))
* `[ ]` **Core**: Implement 4-way unrolled `l2_squared_avx2()` (4 parallel accumulators); measure IPC improvement on Google Benchmark.
* `⭐ Optional / Stretch`: Benchmark 2-way vs 4-way vs 8-way unrolling to determine register pressure limits on your specific CPU microarchitecture.


### 🔹 Wednesday, Wed Sep 16 ([`Day 012`](../days/month-01/day-012-2026-09-16.md))
* `[ ]` **Core**: Implement fused `cosine_distance_avx2()` computing dot product and norms concurrently in a single pass.
* `⭐ Optional / Stretch`: Verify numerical precision parity between 1-pass fused cosine vs 2-pass separate norm computation on float vectors with large magnitude variance.


### 🔹 Thursday, Thu Sep 17 ([`Day 013`](../days/month-01/day-013-2026-09-17.md))
* `[ ]` **Core**: Implement `ip_avx2()` with 4-way unrolling; ensure 64-byte vector alignment (`alignas(64)`).
* `⭐ Optional / Stretch`: Benchmark unaligned load (`_mm256_loadu_ps`) vs aligned load (`_mm256_load_ps`) across cache line boundaries.


### 🔹 Friday, Fri Sep 18 ([`Day 014`](../days/month-01/day-014-2026-09-18.md))
* `[ ]` **Core**: Implement `#ifdef __AVX512F__` backend for 512-bit ZMM registers (`_mm512_sub_ps`, `_mm512_fmadd_ps`).
* `⭐ Optional / Stretch`: Profile AVX-512 frequency downclocking behavior (if CPU throttles clock speed under 512-bit vector load).


---

## ⛔ What NOT to Overspend Time On (Week 02 Time Traps)

* ❌ **Do NOT** hand-tune assembly (`__asm__`)—intrinsic functions (`_mm256_fmadd_ps`) give the compiler full register allocator freedom and produce optimal code.
* ❌ **Do NOT** worry if AVX-512 is unsupported on your CPU—the `#ifdef __AVX512F__` macro ensures portable fallback to AVX2.
* ❌ **Do NOT** write a custom memory allocator for vector alignments—`alignas(64)` or `posix_memalign` is sufficient.

---

## 📝 Weekend Deliverables

### ✍️ Technical Essay 02 (Saturday 09:00–13:00)
* **Title**: *"Breaking Dependency Chains: Multi-Register Accumulator Unrolling and Port Saturation in AVX2/AVX-512"*
* **Target File**: `~/personal/goals/essays/essay_02.md`
* **5-Part Structure**:
  1. **Mathematical Foundation**: Core theorems, derivations, and formal definitions.
  2. **The Systems Bottleneck**: Hardware limitation (memory bandwidth, port contention, cache line splits, warp stalls).
  3. **The Engine Architecture**: Exact data structures and SIMD/CUDA kernel design implemented in `secan`.
  4. **Empirical Benchmarks**: Perf counter tables, latency percentiles ($p50/p95/p99$), and QPS curves.
  5. **Key Takeaway**: Architectural rule of thumb for production AI systems.

### 🧠 Deep Learning Track (Tue/Wed 06:30–08:30 Morning Builder)
* **Task**: **🧠 DL weekend**: MHA + GQA; Pre-LN vs Post-LN.

### 🔬 Monthly Research Milestone (GAPQ Milestone 1 — Mon/Thu 06:30–08:30 Morning Builder)
* **Paper**: *"Microarchitectural Limits of Distance Kernels & Empirical Embedding Cone Anisotropy"*
* **Workspace**: `research/2026-09-measurement-protocol/`
* **Publish Deadline**: **Sun Sep 27**
