# 🚀 Week 05 Execution Playbook

> **Theme**: Partial Derivatives, Gradients, Hessians, **Probability Primer** & Vision Transformer (ViT)  
> **Calendar Dates**: Mon Sep 29 – Sun Oct 5 (2026-09-29 to 2026-10-05)  
> **Parent Month Dashboard**: [Month 2 (Oct 2026)](month-02-oct.md) · **Block**: I — Vector Search Engine

| | | |
|:---|:---|:---|
| [← Week 04](week-04.md) | [Month 2 (Oct 2026) Dashboard](month-02-oct.md) | [Week 06 →](week-06.md) |

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
| **Monday** | Mon Sep 29 | [`Day 029`](../days/month-02/day-029-2026-09-29.md) | **AGNER Ch 7.2 & CSAPP §2.2–2.3**: Integer arithmetic efficiency, two's complement, overflow, bit-width conversion. | **Monthly Research: Planning & Literature Synthesis** | **secan**: Implement `ScalarQuantizer` with **percentile clipping (0.05th/99.95th)** to handle outlier dimensions. Verify dequantization error. |
| **Tuesday** | Tue Sep 30 | [`Day 030`](../days/month-02/day-030-2026-09-30.md) | **INTEL Intrinsics Guide**: Study `_mm256_maddubs_epi16`, `_mm256_madd_epi16`, `_mm256_dpbusd_epi32` (VNNI dot product). | **DL Track (Part 1): Architecture & Tensor Shapes** | **secan**: Implement `l2_squared_sq8()` using AVX2 integer intrinsics. Process 32 dimensions per iteration in a single `__m256i`. |
| **Wednesday** | Wed Oct 1 | [`Day 031`](../days/month-02/day-031-2026-10-01.md) | **AGNER Ch 12**: Integer SIMD saturation arithmetic, signed vs unsigned byte multiplication, widening instructions. | **DL Track (Part 2): Training Loop & Verification** | **secan**: SQ8 LUT / packed layout polish; SIMD path vs scalar dequant error check. |
| **Thursday** | Thu Oct 2 | [`Day 032`](../days/month-02/day-032-2026-10-02.md) | **CSAPP §2.4 (deep)**: Floating-point representation, rounding modes (round-to-nearest-even), subnormals, FP16/BF16 range vs precision tradeoffs for quantization kernels. | **Monthly Research: Sweeps & Data Logging** | **secan**: Implement 4-bit scalar quantization (`SQ4`): pack 2 dimensions per byte with nibble masking. Build 2-stage SQ8 $\to$ FP32 re-ranker. |
| **Friday** | Fri Oct 3 | [`Day 033`](../days/month-02/day-033-2026-10-03.md) | **PIKUS Ch 9**: High-performance C++, move semantics, zero-copy buffer views (`std::span`). | **Technical Essay: Lab-Note Drafting** | **secan**: `std::span` views over quantized buffers; zero-copy encode path. *(DL: Sat Oct 4 ViT.)* |
| **Saturday** | Sat Oct 4 | [`Day 034`](../days/month-02/day-034-2026-10-04.md) | **09:00–13:00**: Pure Math Block 1 (Theory & Derivations) | **14:00–18:00**: FREE / Rest / Buffer | Weekend Deep Work |
| **Sunday** | Sun Oct 5 | [`Day 035`](../days/month-02/day-035-2026-10-05.md) | **09:00–13:00**: Pure Math Block 2 (Problem Sets & Proofs) | **13:00–14:00**: Maintenance | Rest & Buffer |

---

## 📋 Daily Action Items & Deliverables (Week 05)

### 🔹 Monday, Mon Sep 29 ([`Day 029`](../days/month-02/day-029-2026-09-29.md))
* `[ ]` **Core**: Implement `ScalarQuantizer` with percentile clipping (0.05th/99.95th); measure dequantization MSE on SIFT1M.
* `⭐ Optional / Stretch`: Derive and plot the Johnson-Lindenstrauss projection dimension curve $d(\epsilon, n)$ for $\epsilon \in [0.1, 0.5]$ and $n=10^6$.

### 🔹 Tuesday, Tue Sep 30 ([`Day 030`](../days/month-02/day-030-2026-09-30.md))
* `[ ]` **Core**: Implement `l2_squared_sq8()` using AVX2 `_mm256_maddubs_epi16` and `_mm256_madd_epi16` (32 dims per iteration).
* `⭐ Optional / Stretch`: Benchmark VNNI integer dot product (`_mm256_dpbusd_epi32`) if your CPU supports AVX-VNNI.

### 🔹 Wednesday, Wed Oct 1 ([`Day 031`](../days/month-02/day-031-2026-10-01.md))
* `[ ]` **Core**: Polish SQ8 LUT table layout; benchmark scalar dequantization + L2 vs direct integer SIMD distance.
* `⭐ Optional / Stretch`: Profile memory bandwidth saturation during full dataset SQ8 scan vs FP32 scan.

### 🔹 Thursday, Thu Oct 2 ([`Day 032`](../days/month-02/day-032-2026-10-02.md))
* `[ ]` **Core**: Implement 4-bit scalar quantization (`SQ4`) with nibble packing; construct 2-stage `SQ8 -> FP32` candidate re-ranker.
* `⭐ Optional / Stretch`: Implement a random hyperplane LSH bitset filter as a pre-stage candidate pruner.

### 🔹 Friday, Fri Oct 3 ([`Day 033`](../days/month-02/day-033-2026-10-03.md))
* `[ ]` **Core**: Refactor buffer management to zero-copy `std::span<const uint8_t>`; verify zero dynamic allocations during query execution.
* `⭐ Optional / Stretch`: Implement Kahan compensated summation in FP32 distance accumulator and compare error accumulation on 1536-D vectors.

### 🔹 Saturday, Sat Oct 4 ([`Day 034`](../days/month-02/day-034-2026-10-04.md))
* `[ ]` **Core (09:00–13:00)**: Write and ship **Technical Essay 5**: *"Low-Bit Compression Under Outliers: Gradients, Percentile Clipping, and SIMD Integer Saturation"* to `goals/essays/essay_05.md`.
* `[ ]` **Core (14:00–18:00)**: Execute Saturday Deep Learning from Scratch track (**🧠 DL weekend**: ViT patch embed + `[CLS]`.).
* `⭐ Optional / Stretch`: Run automated test suite validating PyTorch numerical gradient and attention equivalence.

### 🔹 Sunday, Sun Oct 5 ([`Day 035`](../days/month-02/day-035-2026-10-05.md))
* `[ ]` **Core (09:00–13:00)**: Execute Monthly Research Milestone for Month 2 (`research/2026-10-anisotropy-hubness-bits/`): run empirical benchmarks and record data tables.
* `⭐ Optional / Stretch`: Draft / update section figures and experimental limitations.

---

## ⛔ What NOT to Overspend Time On (Week 05 Time Traps)

* ❌ **Do NOT** implement complex per-dimension dynamic range clipping—a global 0.05th/99.95th percentile clip is sufficient.
* ❌ **Do NOT** spend time writing 2-bit or 3-bit scalar quantizers—focus strictly on SQ8 (1 byte) and SQ4 (1 nibble).
* ❌ **Do NOT** try to implement Product Quantization (PQ) yet—PQ starts next week (Week 6).

---

## 📝 Weekend Deliverables

### ✍️ Technical Essay 05 (Saturday 09:00–13:00)
* **Title**: *"Low-Bit Compression Under Outliers: Gradients, Percentile Clipping, and SIMD Integer Saturation"*
* **Target File**: `~/personal/goals/essays/essay_05.md`
* **5-Part Structure**:
  1. **Mathematical Foundation**: Core theorems, derivations, and formal definitions.
  2. **The Systems Bottleneck**: Hardware limitation (memory bandwidth, port contention, cache line splits, warp stalls).
  3. **The Engine Architecture**: Exact data structures and SIMD/CUDA kernel design implemented in `secan`.
  4. **Empirical Benchmarks**: Perf counter tables, latency percentiles ($p50/p95/p99$), and QPS curves.
  5. **Key Takeaway**: Architectural rule of thumb for production AI systems.

### 🧠 Deep Learning Track (Saturday 14:00–18:00)
* **Task**: **🧠 DL weekend**: ViT patch embed + `[CLS]`.

### 🔬 Monthly Research Milestone (Sunday 09:00–13:00)
* **Paper**: *"Anisotropy-Aware Vector Quantization: Dissecting the Interplay Between Embedding Cones, Hubness, and Quantization Loss Functions"*
* **Workspace**: `research/2026-10-anisotropy-hubness-bits/`
* **Publish Deadline**: **Sun Oct 25**
