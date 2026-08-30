# 🚀 Week 14 Execution Playbook

> **Theme**: Discrete Random Variables, PMF, Expectation, Variance & Warp Shuffles  
> **Calendar Dates**: Mon Dec 1 – Sun Dec 7 (2026-12-01 to 2026-12-07)  
> **Parent Month Dashboard**: [Month 4 (Dec 2026)](month-04-dec.md) · **Block**: I — Vector Search Engine

| | | |
|:---|:---|:---|
| [← Week 13](week-13.md) | [Month 4 (Dec 2026) Dashboard](month-04-dec.md) | [Week 15 →](week-15.md) |

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
| **Monday** | Mon Dec 1 | [`Day 092`](../days/month-04/day-092-2026-12-01.md) | **PROB §3.1–3.4**: Discrete random variables, PMF, CDF properties. Bernoulli and Binomial distributions: derivations of mean and variance. | **PMPP Ch 6**: Performance considerations: memory coalescing patterns, maximizing global memory bus utilization. | **secan**: Implement **coalesced GPU distance kernel**: ensure adjacent threads in a warp access consecutive memory addresses. |
| **Tuesday** | Tue Dec 2 | [`Day 093`](../days/month-04/day-093-2026-12-02.md) | **PROB §3.5–3.7**: Hypergeometric distribution, Geometric and Negative Binomial distributions. Memoryless property of Geometric distribution. | **PMPP Ch 10**: Parallel reductions, warp shuffle primitives (`__shfl_down_sync`), eliminating shared memory bank conflicts. | **secan**: Implement **warp-level reduction**: use `__shfl_down_sync` to reduce 32 partial sums inside a warp with zero shared memory overhead. |
| **Wednesday** | Wed Dec 3 | [`Day 094`](../days/month-04/day-094-2026-12-03.md) | **PROB §4.1–4.3**: Expectation from first principles. Rigorous proof of Linearity of Expectation. Solving complex counting problems with indicator variables. | **CUDA-GUIDE Warp Primitives**: `__shfl_sync`, `__shfl_xor_sync`, `__ballot_sync`, `__any_sync`, Cooperative Groups. | **secan**: Implement batched GPU scanner: process $B=256$ queries simultaneously. Each block processes a query; warps scan dataset chunks. |
| **Thursday** | Thu Dec 4 | [`Day 095`](../days/month-04/day-095-2026-12-04.md) | **PROB §4.4–4.6**: Law of the Unconscious Statistician (LOTUS). Variance and Standard Deviation properties: $\text{Var}(aX + b) = a^2 \text{Var}(X)$. | **PMPP Ch 7**: Tiling patterns, halo cells, constant memory for read-only query parameters. | **secan**: Implement fused Cosine similarity GPU kernel: dot product + norms in a single pass. Add inner-product kernel. |
| **Friday** | Fri Dec 5 | [`Day 096`](../days/month-04/day-096-2026-12-05.md) | **PROB §4.7–4.9**: The Poisson Distribution $\text{Pois}(\lambda)$: Poisson limit theorem (law of rare events), derivation from $\text{Bin}(n, \lambda/n)$ as $n \to \infty$. | **PMPP Ch 11–12**: Parallel merge and sorting on GPU: partial bitonic sort, warp-cooperative top-$k$ selection. | **secan**: Implement **GPU top-k selection**: warp-cooperative partial bitonic sort extracting top-$k$ without sorting all $N$ distances. |
| **Saturday** | Sat Dec 6 | [`Day 097`](../days/month-04/day-097-2026-12-06.md) | **09:00–13:00**: Essay 14 | **14:00–18:00**: Deep Learning Track | Deep Learning from Scratch (uv/PyTorch) |
| **Sunday** | Sun Dec 7 | [`Day 098`](../days/month-04/day-098-2026-12-07.md) | **09:00–13:00**: Monthly Research | Research Experimentation | Rest & Subconscious Incubation |

---

## 📋 Daily Action Items & Deliverables (Week 14)

### 🔹 Monday, Mon Dec 1 ([`Day 092`](../days/month-04/day-092-2026-12-01.md))
* `[ ]` **Core**: Implement coalesced memory layout for database vectors in GPU global memory; achieve $>85\%$ theoretical global memory bus utilization in `ncu`.
* `⭐ Optional / Stretch`: Compare AOS (Array-of-Structures) vs SOA (Structure-of-Arrays) memory layouts for high-dimensional vector embeddings on GPU.

### 🔹 Tuesday, Tue Dec 2 ([`Day 093`](../days/month-04/day-093-2026-12-02.md))
* `[ ]` **Core**: Implement warp-level horizontal tree reduction using `__shfl_down_sync(0xffffffff, sum, offset)` in registers without shared memory.
* `⭐ Optional / Stretch`: Benchmark latency of register warp shuffle vs shared-memory atomic reduction across varying thread block sizes.

### 🔹 Wednesday, Wed Dec 3 ([`Day 094`](../days/month-04/day-094-2026-12-03.md))
* `[ ]` **Core**: Implement batched GPU scanner processing $B=256$ queries in parallel; utilize CUDA Cooperative Groups for grid synchronization.
* `⭐ Optional / Stretch`: Implement asynchronous CUDA streams interleaving kernel execution for batch chunk $i$ with data transfer for chunk $i+1$.

### 🔹 Thursday, Thu Dec 4 ([`Day 095`](../days/month-04/day-095-2026-12-04.md))
* `[ ]` **Core**: Implement fused GPU Cosine similarity and Inner Product kernels computing dot products and norms in a single memory pass.
* `⭐ Optional / Stretch`: Use fast math compiler flag (`--use_fast_math`) and measure reciprocal square root (`rsqrtf`) speedup vs precision impact.

### 🔹 Friday, Fri Dec 5 ([`Day 096`](../days/month-04/day-096-2026-12-05.md))
* `[ ]` **Core**: Implement GPU warp-cooperative top-$k$ selection using partial bitonic sort; extract top-$k$ without sorting full dataset distance array.
* `⭐ Optional / Stretch`: Benchmark top-$k$ throughput against NVIDIA CUB `BlockRadixSort` / `DeviceSegmentedRadixSort`.

### 🔹 Saturday, Sat Dec 6 ([`Day 097`](../days/month-04/day-097-2026-12-06.md))
* `[ ]` **Core (09:00–13:00)**: Write and ship **Technical Essay 14**: *"Warp Shuffles and Parallel Reductions: Saturating GPU Memory Bandwidth in Batch Vector Scanning"* to `goals/essays/essay_14.md`.
* `[ ]` **Core (14:00–18:00)**: Execute Saturday Deep Learning from Scratch track ().
* `⭐ Optional / Stretch`: Run automated test suite validating PyTorch numerical gradient and attention equivalence.

### 🔹 Sunday, Sun Dec 7 ([`Day 098`](../days/month-04/day-098-2026-12-07.md))
* `[ ]` **Core (09:00–13:00)**: Execute Monthly Research Milestone for Month 4 (`research/2026-12-three-paths-spine/`): run empirical benchmarks and record data tables.
* `⭐ Optional / Stretch`: Draft / update section figures and experimental limitations.

---

## ⛔ What NOT to Overspend Time On (Week 14 Time Traps)

* ❌ **Do NOT** sort the entire 1,000,000 distances on GPU—use partial bitonic sort or warp priority queues to maintain only the top-$k$ ($k \le 100$).
* ❌ **Do NOT** use atomic operations in global memory for distance reductions—warp shuffles (`__shfl_down_sync`) in registers are zero-overhead.
* ❌ **Do NOT** implement complex thread block dynamic grid sizing—stick to 128 or 256 threads per block.

---

## 📝 Weekend Deliverables

### ✍️ Technical Essay 14 (Saturday 09:00–13:00)
* **Title**: *"Warp Shuffles and Parallel Reductions: Saturating GPU Memory Bandwidth in Batch Vector Scanning"*
* **Target File**: `~/personal/goals/essays/essay_14.md`
* **5-Part Structure**:
  1. **Mathematical Foundation**: Core theorems, derivations, and formal definitions.
  2. **The Systems Bottleneck**: Hardware limitation (memory bandwidth, port contention, cache line splits, warp stalls).
  3. **The Engine Architecture**: Exact data structures and SIMD/CUDA kernel design implemented in `secan`.
  4. **Empirical Benchmarks**: Perf counter tables, latency percentiles ($p50/p95/p99$), and QPS curves.
  5. **Key Takeaway**: Architectural rule of thumb for production AI systems.

### 🧠 Deep Learning Track (Saturday 14:00–18:00)
* **Task**: 

### 🔬 Monthly Research Milestone (Sunday 09:00–13:00)
* **Paper**: *"Billion-Scale Retrieval Frontiers: Comparing In-VRAM GPU IVF and Asynchronous NVMe DiskANN Under Concurrent Query Pressure"*
* **Workspace**: `research/2026-12-three-paths-spine/`
* **Publish Deadline**: **Sun Dec 27**
