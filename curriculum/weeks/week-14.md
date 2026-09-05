# 🚀 Week 14 Execution Playbook

> **Theme**: Discrete Random Variables, PMF, Expectation, Variance & Warp Shuffles  
> **Calendar Dates**: Sat Dec 5 – Fri Dec 11 (2026-12-05 to 2026-12-11)
> **Parent Month Dashboard**: [Month 4 (Dec 2026)](month-04-dec.md) · **Block**: I — Vector Search Engine

| | | |
|:---|:---|:---|
| [← Week 13](week-13.md) | [Month 4 (Dec 2026) Dashboard](month-04-dec.md) | [Week 15 →](week-15.md) |

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
| **Saturday** | Sat Dec 5 | [`Day 092`](../days/month-04/day-092-2026-12-05.md) | **09:00–13:00**: Pure Math Block 1 (Theory & Derivations) | **15:00–16:30**: Literature Sanctuary | **18:00–19:30**: Information Theory (Cover & Thomas) · **19:30–21:00**: Thought Leadership (Richard P. Feynman) · **21:00+**: Free / Rest|
| **Sunday** | Sun Dec 6 | [`Day 093`](../days/month-04/day-093-2026-12-06.md) | **09:00–13:00**: Pure Math Block 2 (Problem Sets & Proofs) | **13:00**: Maint · **15:00**: Penrose | **18:00–19:30**: Dist Systems (IIR Ch 3) · **19:30–21:00**: Systems Lab (Kirk & Hwu Ch 4–5) |
| **Monday** | Mon Dec 7 | [`Day 094`](../days/month-04/day-094-2026-12-07.md) | **PMPP Ch 6**: Performance considerations: memory coalescing patterns, maximizing global memory bus utilization. | **Monthly Research: Planning & Literature Synthesis** | **secan**: Implement **coalesced GPU distance kernel**: ensure adjacent threads in a warp access consecutive memory addresses. |
| **Tuesday** | Tue Dec 8 | [`Day 095`](../days/month-04/day-095-2026-12-08.md) | **PMPP Ch 10**: Parallel reductions, warp shuffle primitives (`__shfl_down_sync`), eliminating shared memory bank conflicts. | **DL Track (Part 1): Architecture & Tensor Shapes** | **secan**: Implement **warp-level reduction**: use `__shfl_down_sync` to reduce 32 partial sums inside a warp with zero shared memory overhead. |
| **Wednesday** | Wed Dec 9 | [`Day 096`](../days/month-04/day-096-2026-12-09.md) | **CUDA-GUIDE Warp Primitives**: `__shfl_sync`, `__shfl_xor_sync`, `__ballot_sync`, `__any_sync`, Cooperative Groups. | **DL Track (Part 2): Training Loop & Verification** | **secan**: Implement batched GPU scanner: process $B=256$ queries simultaneously. Each block processes a query; warps scan dataset chunks. |
| **Thursday** | Thu Dec 10 | [`Day 097`](../days/month-04/day-097-2026-12-10.md) | **PMPP Ch 7**: Tiling patterns, halo cells, constant memory for read-only query parameters. | **Monthly Research: Sweeps & Data Logging** | **secan**: Implement fused Cosine similarity GPU kernel: dot product + norms in a single pass. Add inner-product kernel. |
| **Friday** | Fri Dec 11 | [`Day 098`](../days/month-04/day-098-2026-12-11.md) | **PMPP Ch 11–12**: Parallel merge and sorting on GPU: partial bitonic sort, warp-cooperative top-$k$ selection. | **Technical Essay: Lab-Note Drafting** | **secan**: Implement **GPU top-k selection**: warp-cooperative partial bitonic sort extracting top-$k$ without sorting all $N$ distances. |

---

## 📋 Daily Action Items & Deliverables (Week 14)

### 🔹 Saturday, Sat Dec 5 ([`Day 092`](../days/month-04/day-092-2026-12-05.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 1**: Theory, concepts, and analytical derivations (textbook chapters & core proofs).
* `[ ]` **Core (15:00–16:30)**: **Weekend Reading Sanctuary**: Literature / Philosophy deep reading.
* `[ ]` **Core (18:00–19:30)**: **Information Theory Track**: Thomas M. Cover & Joy A. Thomas, *Elements of Information Theory* — **Ch 10.1–10.3** (Rate-Distortion Theory: Continuous Distortion Measures $d(x,\hat{x})$ & Rate-Distortion Function $R(D)$).
* `[ ]` **Core (19:30–21:00)**: **Thought Leadership Masterclass**: Richard P. Feynman, *Feynman Lectures on Computation* — **Ch 3: Coding and Information Theory** (Information Bounds, Shannon Entropy from Physical Principles, Data Compression & Error Detection).
* `⭐ Optional / Stretch`: 21:00 onwards 100% Free / Rest.

### 🔹 Sunday, Sun Dec 6 ([`Day 093`](../days/month-04/day-093-2026-12-06.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 2**: Advanced theorems, problem sets, and chalkboard proof defense.
* `[ ]` **Core (13:00–14:00)**: **Runtime Maintenance**: Quick 30–60 min check for `limbed` / `ggmbed` (`embed-runtimes`).
* `[ ]` **Core (15:00–16:45)**: **Penrose Sunday**: *The Road to Reality* (1 chapter/week, visual geometry focus).
* `[ ]` **Core (18:00–19:30)**: **Distributed Systems & IR Track**: **IIR Ch 3** (Dictionaries and Tolerant Retrieval: Wildcards, Edit Distance & k-Gram Indexes).
* `[ ]` **Core (19:30–21:00)**: **Graduate Systems & GPU Architecture Lab**: Microarchitecture analysis and CUDA exercises in **Kirk & Hwu Ch 4–5** (Warp scheduling, register pressure vs occupancy trade-offs & global memory coalescing).
* `⭐ Optional / Stretch`: 21:00 onwards Weekly review & recovery.

### 🔹 Monday, Mon Dec 7 ([`Day 094`](../days/month-04/day-094-2026-12-07.md))
* `[ ]` **Core**: Implement coalesced memory layout for database vectors in GPU global memory; achieve $>85\%$ theoretical global memory bus utilization in `ncu`.
* `⭐ Optional / Stretch`: Compare AOS (Array-of-Structures) vs SOA (Structure-of-Arrays) memory layouts for high-dimensional vector embeddings on GPU.


### 🔹 Tuesday, Tue Dec 8 ([`Day 095`](../days/month-04/day-095-2026-12-08.md))
* `[ ]` **Core**: Implement warp-level horizontal tree reduction using `__shfl_down_sync(0xffffffff, sum, offset)` in registers without shared memory.
* `⭐ Optional / Stretch`: Benchmark latency of register warp shuffle vs shared-memory atomic reduction across varying thread block sizes.


### 🔹 Wednesday, Wed Dec 9 ([`Day 096`](../days/month-04/day-096-2026-12-09.md))
* `[ ]` **Core**: Implement batched GPU scanner processing $B=256$ queries in parallel; utilize CUDA Cooperative Groups for grid synchronization.
* `⭐ Optional / Stretch`: Implement asynchronous CUDA streams interleaving kernel execution for batch chunk $i$ with data transfer for chunk $i+1$.


### 🔹 Thursday, Thu Dec 10 ([`Day 097`](../days/month-04/day-097-2026-12-10.md))
* `[ ]` **Core**: Implement fused GPU Cosine similarity and Inner Product kernels computing dot products and norms in a single memory pass.
* `⭐ Optional / Stretch`: Use fast math compiler flag (`--use_fast_math`) and measure reciprocal square root (`rsqrtf`) speedup vs precision impact.


### 🔹 Friday, Fri Dec 11 ([`Day 098`](../days/month-04/day-098-2026-12-11.md))
* `[ ]` **Core**: Implement GPU warp-cooperative top-$k$ selection using partial bitonic sort; extract top-$k$ without sorting full dataset distance array.
* `⭐ Optional / Stretch`: Benchmark top-$k$ throughput against NVIDIA CUB `BlockRadixSort` / `DeviceSegmentedRadixSort`.


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

### 🧠 Deep Learning Track (Tue/Wed 06:30–08:30 Morning Builder)
* **Task**: 

### 🔬 Monthly Research Milestone (FlashMaxSim Milestone 1 — Mon/Thu 06:30–08:30 Morning Builder)
* **Paper**: *"The Memory Wall in Multimodal Late Interaction: Baseline GPU Kernel Profiling"*
* **Workspace**: `research/2026-12-flashattn-vamana/`
* **Publish Deadline**: **Sun Dec 27**
