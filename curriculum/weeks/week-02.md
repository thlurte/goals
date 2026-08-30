# 🚀 Week 02 Execution Playbook

> **Theme**: Trigonometric Identities, Chain Rule, SIMD AVX2 & Multi-Head Attention  
> **Calendar Dates**: Mon Sep 8 – Sun Sep 14 (2026-09-08 to 2026-09-14)  
> **Parent Month Dashboard**: [Month 1 (Sep 2026)](month-01-sep.md) · **Block**: I — Vector Search Engine

| | | |
|:---|:---|:---|
| [← Week 01](week-01.md) | [Month 1 (Sep 2026) Dashboard](month-01-sep.md) | [Week 03 →](week-03.md) |

---

## ⏰ Daily Operational Rhythm

```
┌──────────────────────────────┬────────────────────────────────────────────────────────────────────────┐
│ Time Block                   │ Focus Area                                                             │
├──────────────────────────────┼────────────────────────────────────────────────────────────────────────┤
│ 🌅 06:00 – 07:30 (90 min)    │ Pure Mathematics (Pencil, paper, theorems, derivations & proofs)       │
│ 📖 07:30 – 08:30 (60 min)    │ Systems & Architecture Deep Reading (Hardware mechanics & papers)      │
│ ☀️ Daytime                   │ Subconscious Incubation Period (Diffuse thinking)                      │
│ 💻 20:30 – 23:00 (2.5 hrs)   │ Night Hands-On Implementation (secan C++20 / CUDA flow state)          │
├──────────────────────────────┼────────────────────────────────────────────────────────────────────────┤
│ 📝 Saturday 09:00 – 13:00    │ Weekly Long-Form Technical Essay / Lab Note                            │
│ 🧠 Saturday 14:00 – 18:00    │ Deep Learning from Scratch Track (PyTorch / uv)                        │
│ 🔬 Sunday 09:00 – 13:00      │ Monthly Research Paper Experiments & Drafting                          │
└──────────────────────────────┴────────────────────────────────────────────────────────────────────────┘
```

---

## 📅 Day-by-Day Master Timetable

| Day | Date | Daily Runbook | Pure Mathematics (90 min) | Systems / Architecture Reading (45-60 min) | Night Hands-On C++/CUDA (2.5 hrs) |
|:---|:---|:---|:---|:---|:---|
| **Monday** | Mon Sep 8 | [`Day 008`](../days/month-01/day-008-2026-09-08.md) | **TRIG (Gelfand Ch 4)**: Geometric proof of angle addition: $\cos(\alpha - \beta) = \cos\alpha \cos\beta + \sin\alpha \sin\beta$. Derivation of all addition formulas. | **AGNER Ch 12**: SIMD instructions, 256-bit YMM registers, data types, intrinsics syntax. | **secan**: Enable FTZ/DAZ flags. Implement `l2_squared_avx2()` in `src/search/distance_avx2.cpp`. Single accumulator baseline. |
| **Tuesday** | Tue Sep 9 | [`Day 009`](../days/month-01/day-009-2026-09-09.md) | **TRIG (Gelfand Ch 4)**: Double-angle formulas: $\sin 2\theta = 2\sin\theta\cos\theta$, $\cos 2\theta = \cos^2\theta - \sin^2\theta$. Half-angle formulas. | **CSAPP §5.8–5.9**: Loop unrolling, breaking dependency chains with multiple independent accumulator registers. | **secan**: Implement 4-way unrolled `l2_squared_avx2` with 4 parallel `__m256` accumulators. Measure speedup over 1-acc. |
| **Wednesday** | Wed Sep 10 | [`Day 010`](../days/month-01/day-010-2026-09-10.md) | **CALC (Strang §2.6)**: The Chain Rule: step-by-step rigorous proof using limits. Differentiating nested composite functions. | **AGNER-INST & AGNER Ch 11**: VFMADD latency/throughput port mapping on modern x86 microarchitectures. | **secan**: Implement `cosine_distance_avx2()`: compute dot product, norm $A$, and norm $B$ simultaneously in 1 pass. |
| **Thursday** | Thu Sep 11 | [`Day 011`](../days/month-01/day-011-2026-09-11.md) | **CALC (Strang §3.1–3.2)**: Derivatives of $e^x$ and $\ln x$. | **AGNER Ch 13.1–13.3**: Alignment, cache line splits. | **secan**: `ip_avx2()` + fused cosine (dot + norms). Same unrolling as L2. *(DL: Sat Sep 13 GQA.)* |
| **Friday** | Fri Sep 12 | [`Day 012`](../days/month-01/day-012-2026-09-12.md) | **TRIG & CALC Integration**: Differentiating inverse trigonometric functions: $\frac{d}{dx}\arcsin x = \frac{1}{\sqrt{1-x^2}}$, $\frac{d}{dx}\arctan x = \frac{1}{1+x^2}$. | **PIKUS Ch 3**: Instruction-level parallelism, register pressure, compiler vectorization limits. | **secan**: Add AVX-512 backend (`_mm512_*`) behind `#ifdef __AVX512F__`. Benchmark scalar vs AVX2 vs AVX-512. |
| **Saturday** | Sat Sep 13 | [`Day 013`](../days/month-01/day-013-2026-09-13.md) | **09:00–13:00**: Essay 2 | **14:00–18:00**: Deep Learning Track | Deep Learning from Scratch (uv/PyTorch) |
| **Sunday** | Sun Sep 14 | [`Day 014`](../days/month-01/day-014-2026-09-14.md) | **09:00–13:00**: Monthly Research | Research Experimentation | Rest & Subconscious Incubation |

---

## 📋 Daily Action Items & Deliverables (Week 02)

### 🔹 Monday, Mon Sep 8 ([`Day 008`](../days/month-01/day-008-2026-09-08.md))
* `[ ]` **Core**: Enable FTZ/DAZ (`_MM_SET_FLUSH_ZERO_MODE`); implement `l2_squared_avx2()` baseline (1 `__m256` accumulator).
* `⭐ Optional / Stretch`: Write a microbenchmark testing floating-point denormal performance penalties with FTZ disabled vs enabled.

### 🔹 Tuesday, Tue Sep 9 ([`Day 009`](../days/month-01/day-009-2026-09-09.md))
* `[ ]` **Core**: Implement 4-way unrolled `l2_squared_avx2()` (4 parallel accumulators); measure IPC improvement on Google Benchmark.
* `⭐ Optional / Stretch`: Benchmark 2-way vs 4-way vs 8-way unrolling to determine register pressure limits on your specific CPU microarchitecture.

### 🔹 Wednesday, Wed Sep 10 ([`Day 010`](../days/month-01/day-010-2026-09-10.md))
* `[ ]` **Core**: Implement fused `cosine_distance_avx2()` computing dot product and norms concurrently in a single pass.
* `⭐ Optional / Stretch`: Verify numerical precision parity between 1-pass fused cosine vs 2-pass separate norm computation on float vectors with large magnitude variance.

### 🔹 Thursday, Thu Sep 11 ([`Day 011`](../days/month-01/day-011-2026-09-11.md))
* `[ ]` **Core**: Implement `ip_avx2()` with 4-way unrolling; ensure 64-byte vector alignment (`alignas(64)`).
* `⭐ Optional / Stretch`: Benchmark unaligned load (`_mm256_loadu_ps`) vs aligned load (`_mm256_load_ps`) across cache line boundaries.

### 🔹 Friday, Fri Sep 12 ([`Day 012`](../days/month-01/day-012-2026-09-12.md))
* `[ ]` **Core**: Implement `#ifdef __AVX512F__` backend for 512-bit ZMM registers (`_mm512_sub_ps`, `_mm512_fmadd_ps`).
* `⭐ Optional / Stretch`: Profile AVX-512 frequency downclocking behavior (if CPU throttles clock speed under 512-bit vector load).

### 🔹 Saturday, Sat Sep 13 ([`Day 013`](../days/month-01/day-013-2026-09-13.md))
* `[ ]` **Core (09:00–13:00)**: Write and ship **Technical Essay 2**: *"Breaking Dependency Chains: Multi-Register Accumulator Unrolling and Port Saturation in AVX2/AVX-512"* to `goals/essays/essay_02.md`.
* `[ ]` **Core (14:00–18:00)**: Execute Saturday Deep Learning from Scratch track (**🧠 DL weekend**: MHA + GQA; Pre-LN vs Post-LN.).
* `⭐ Optional / Stretch`: Run automated test suite validating PyTorch numerical gradient and attention equivalence.

### 🔹 Sunday, Sun Sep 14 ([`Day 014`](../days/month-01/day-014-2026-09-14.md))
* `[ ]` **Core (09:00–13:00)**: Execute Monthly Research Milestone for Month 1 (`research/2026-09-measurement-protocol/`): run empirical benchmarks and record data tables.
* `⭐ Optional / Stretch`: Draft / update section figures and experimental limitations.

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

### 🧠 Deep Learning Track (Saturday 14:00–18:00)
* **Task**: **🧠 DL weekend**: MHA + GQA; Pre-LN vs Post-LN.

### 🔬 Monthly Research Milestone (Sunday 09:00–13:00)
* **Paper**: *"Microarchitectural Limits of SIMD Vector Distance Kernels: Execution Port Contention, Cache-Line Splits, and Measurement Artifacts on Modern x86"*
* **Workspace**: `research/2026-09-measurement-protocol/`
* **Publish Deadline**: **Sun Sep 27**
