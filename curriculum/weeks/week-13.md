# 🚀 Week 13 Execution Playbook

> **Theme**: Axiomatic Probability, Combinatorics, CUDA Model & Naive Kernels  
> **Calendar Dates**: Sat Nov 28 – Fri Dec 4 (2026-11-28 to 2026-12-04)
> **Parent Month Dashboard**: [Month 4 (Dec 2026)](month-04-dec.md) · **Block**: I — Vector Search Engine

| | | |
|:---|:---|:---|
| [← Week 12](week-12.md) | [Month 4 (Dec 2026) Dashboard](month-04-dec.md) | [Week 14 →](week-14.md) |

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
| **Saturday** | Sat Nov 28 | [`Day 085`](../days/month-04/day-085-2026-11-28.md) | **09:00–13:00**: Pure Math Block 1 (Theory & Derivations) | **15:00–16:30**: Literature Sanctuary | **18:00–19:30**: Information Theory (Cover & Thomas) · **19:30–21:00**: Thought Leadership (Richard P. Feynman) · **21:00+**: Free / Rest|
| **Sunday** | Sun Nov 29 | [`Day 086`](../days/month-04/day-086-2026-11-29.md) | **09:00–13:00**: Pure Math Block 2 (Problem Sets & Proofs) | **13:00**: Maint · **15:00**: Penrose | **18:00–19:30**: Dist Systems (IIR Ch 1–2) · **19:30–21:00**: Systems Lab (Kirk & Hwu Ch 1–3) |
| **Monday** | Mon Nov 30 | [`Day 087`](../days/month-04/day-087-2026-11-30.md) | **PMPP Ch 1–2**: Heterogeneous computing, SIMT execution model, latency hiding via massive hardware multithreading. | **Hardware Profiling & Benchmark Sweeps** | **secan**: Add CUDA to CMakeLists.txt (`enable_language(CUDA)`). Create `src/gpu/`. Configure `compute-sanitizer` test script. |
| **Tuesday** | Tue Dec 1 | [`Day 088`](../days/month-04/day-088-2026-12-01.md) | **PMPP Ch 3 + 🔗 GPU NUMERIC FORMATS**: Grid/Block/Thread hierarchy. Computing linear indices. **Also**: BFloat16 vs Float16 vs TF32 bit layouts; why BF16 has same exponent range as FP32 but only 7 mantissa bits; mixed-precision training: loss scaling, master weights in FP32; when FP16 gradients underflow to zero. | **DL Track (Part 1): Architecture & Tensor Shapes** | **secan**: Implement RAII `GpuBuffer<T>` class for device memory allocation (`cudaMalloc`, `cudaFree`, `cudaMemcpy`). |
| **Wednesday** | Wed Dec 2 | [`Day 089`](../days/month-04/day-089-2026-12-02.md) | **PMPP Ch 4**: Compute Architecture: Streaming Multiprocessors (SMs), warps (32 threads), warp divergence, occupancy. | **DL Track (Part 2): Training Loop & Verification** | **secan**: Implement naive GPU L2 distance kernel: 1 thread per vector pair. Benchmark against CPU AVX2 on single query. |
| **Thursday** | Thu Dec 3 | [`Day 090`](../days/month-04/day-090-2026-12-03.md) | **CUDA-GUIDE Memory Hierarchy**: Global memory (HBM/GDDR), Shared memory (SRAM), Registers, Constant memory. | **DL / Vector Retrieval Integration & Profiling** | **secan**: Implement dataset upload: store SIFT1M in GPU global memory. Implement batch brute-force scan kernel (1 block per query). |
| **Friday** | Fri Dec 4 | [`Day 091`](../days/month-04/day-091-2026-12-04.md) | **PMPP Ch 5**: Memory architecture, shared memory tiling, bank conflicts, memory coalescing principles. | **Weekly Technical Article: Drafting & Publishing** | **secan**: Implement **shared memory tiled** L2 kernel: load query and dataset tiles into shared memory. Benchmark tiled vs naive. |

---

## 📋 Daily Action Items & Deliverables (Week 13)

### 🔹 Saturday, Sat Nov 28 ([`Day 085`](../days/month-04/day-085-2026-11-28.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 1**: Theory, concepts, and analytical derivations (textbook chapters & core proofs).
* `[ ]` **Core (15:00–16:30)**: **Weekend Reading Sanctuary**: Literature / Philosophy deep reading.
* `[ ]` **Core (16:30–18:00)**: **Physical Break & Mental Decompression**: Walk, tea, and recovery.
* `[ ]` **Core (18:00–19:30)**: **Information Theory Track**: Thomas M. Cover & Joy A. Thomas, *Elements of Information Theory* — **Ch 11.1–11.4** (Method of Types & Sanov's Large Deviations Theorem).
* `[ ]` **Core (19:30–21:00)**: **Thought Leadership Masterclass**: Richard P. Feynman, *Feynman Lectures on Computation (Westview Press)* — **Ch 1–2: Introduction & Operations on Information** (Universal Gates, Logic Circuits, State Machines, Reversible Logic & Turing Computability).
* `⭐ Optional / Stretch`: 21:00 onwards 100% Free / Rest.

### 🔹 Sunday, Sun Nov 29 ([`Day 086`](../days/month-04/day-086-2026-11-29.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 2**: Advanced theorems, problem sets, and chalkboard proof defense.
* `[ ]` **Core (13:00–14:00)**: **Runtime Maintenance**: Quick 30–60 min check for `limbed` / `ggmbed` (`embed-runtimes`).
* `[ ]` **Core (15:00–16:45)**: **Penrose Sunday**: *The Road to Reality* (1 chapter/week, visual geometry focus).
* `[ ]` **Core (18:00–19:30)**: **Distributed Systems & IR Track**: **IIR Ch 1–2** (Boolean Retrieval, Inverted Index Construction, Tokenization & Postings Lists).
* `[ ]` **Core (19:30–21:00)**: **Graduate Systems & GPU Architecture Lab**: Microarchitecture analysis and CUDA exercises in **Kirk & Hwu Ch 1–3** (CUDA execution model: Grid, Block, Thread mapping & SM resource partitioning).
* `⭐ Optional / Stretch`: 21:00 onwards Weekly review & recovery.

### 🔹 Monday, Mon Nov 30 ([`Day 087`](../days/month-04/day-087-2026-11-30.md))
* `[ ]` **Core**: Configure CMake for CUDA (`enable_language(CUDA)`); set up `compute-sanitizer` automated memory checker in CI.
* `⭐ Optional / Stretch`: Write a CMake check that validates GPU compute capability (e.g. `sm_80`, `sm_89`, `sm_90`) and enables target-specific PTX generation.


### 🔹 Tuesday, Tue Dec 1 ([`Day 088`](../days/month-04/day-088-2026-12-01.md))
* `[ ]` **Core**: Implement RAII `GpuBuffer<T>` wrapper managing device memory (`cudaMalloc`, `cudaFree`, `cudaMemcpyAsync`).
* `⭐ Optional / Stretch`: Implement CUDA pinned host memory allocator (`cudaHostAlloc`) and compare host-to-device transfer bandwidth.


### 🔹 Wednesday, Wed Dec 2 ([`Day 089`](../days/month-04/day-089-2026-12-02.md))
* `[ ]` **Core**: Implement naive GPU L2 distance kernel (1 thread per vector pair); benchmark latency against single-threaded CPU AVX2.
* `⭐ Optional / Stretch`: Profile kernel with Nsight Compute (`ncu`) to observe warp execution stalls due to memory latency.


### 🔹 Thursday, Thu Dec 3 ([`Day 090`](../days/month-04/day-090-2026-12-03.md))
* `[ ]` **Core**: Upload full SIFT1M dataset to GPU VRAM; implement batch scan kernel assigning 1 thread block per query vector.
* `⭐ Optional / Stretch`: Measure PCIe bus upload bandwidth as a function of batch buffer size ($1\text{MB}$ to $1\text{GB}$).


### 🔹 Friday, Fri Dec 4 ([`Day 091`](../days/month-04/day-091-2026-12-04.md))
* `[ ]` **Core**: Implement shared memory tiled L2 distance kernel loading query and dataset chunks into SRAM; measure speedup over naive kernel.
* `⭐ Optional / Stretch`: Benchmark shared memory bank conflicts with varying tile dimension padding strategies.


---

## ⛔ What NOT to Overspend Time On (Week 13 Time Traps)

* ❌ **Do NOT** optimize single-query latency on GPU—GPUs require batched queries ($B \ge 32$) to hide launch and PCIe latency.
* ❌ **Do NOT** use CUDA dynamic parallelism (launching kernels from inside kernels)—keep control flow on host CPU.
* ❌ **Do NOT** hand-write complex combinatorial counting proofs on paper—master permutations and combinations, then move to probability rules.

---

## Benchmark Close

Before the Friday article or release, save the run manifest and raw JSON/CSV, add one meaningful parameter sweep and plot, update the comparable README result row, and state the oracle result plus one evidence-backed conclusion. Record results below the noise floor as inconclusive.

## 📝 Weekend Deliverables

### ✍️ Technical Essay 13 (Drafted Friday 06:30–08:30)
* **Title**: *"The SIMT Execution Model: Why Naive GPU Distance Kernels Lose to CPU AVX2"*
* **Target File**: `~/personal/goals/essays/essay_13.md`
* **5-Part Structure**:
  1. **Mathematical Foundation**: Core theorems, derivations, and formal definitions.
  2. **The Systems Bottleneck**: Hardware limitation (memory bandwidth, port contention, cache line splits, warp stalls).
  3. **The Engine Architecture**: Exact data structures and SIMD/CUDA kernel design implemented in `secan`.
  4. **Empirical Benchmarks**: Perf counter tables, latency percentiles ($p50/p95/p99$), and QPS curves.
  5. **Key Takeaway**: Architectural rule of thumb for production AI systems.

### 🧠 Deep Learning Track (Tue/Wed 06:30–08:30 Morning Builder)
* **Task**: 

### 🔬 Empirical Systems & Benchmarking Focus (Mon/Thu 06:30–08:30 Morning Builder)
* **Focus**: The Memory Wall in Multimodal Late Interaction: Baseline GPU Kernel Profiling
* **Workspace**: `research/2026-12-flashattn-vamana/`
* **Artifact Target**: Empirical benchmark and profiling data feeding into Friday's technical articles.
