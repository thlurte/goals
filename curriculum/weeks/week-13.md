# 🚀 Week 13 Execution Playbook

> **Theme**: Axiomatic Probability, Combinatorics, CUDA Model & Naive Kernels  
> **Calendar Dates**: Mon Nov 24 – Sun Nov 30 (2026-11-24 to 2026-11-30)  
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
| **Monday** | Mon Nov 24 | [`Day 085`](../days/month-04/day-085-2026-11-24.md) | **PMPP Ch 1–2**: Heterogeneous computing, SIMT execution model, latency hiding via massive hardware multithreading. | **Monthly Research: Planning & Literature Synthesis** | **secan**: Add CUDA to CMakeLists.txt (`enable_language(CUDA)`). Create `src/gpu/`. Configure `compute-sanitizer` test script. |
| **Tuesday** | Tue Nov 25 | [`Day 086`](../days/month-04/day-086-2026-11-25.md) | **PMPP Ch 3 + 🔗 GPU NUMERIC FORMATS**: Grid/Block/Thread hierarchy. Computing linear indices. **Also**: BFloat16 vs Float16 vs TF32 bit layouts; why BF16 has same exponent range as FP32 but only 7 mantissa bits; mixed-precision training: loss scaling, master weights in FP32; when FP16 gradients underflow to zero. | **DL Track (Part 1): Architecture & Tensor Shapes** | **secan**: Implement RAII `GpuBuffer<T>` class for device memory allocation (`cudaMalloc`, `cudaFree`, `cudaMemcpy`). |
| **Wednesday** | Wed Nov 26 | [`Day 087`](../days/month-04/day-087-2026-11-26.md) | **PMPP Ch 4**: Compute Architecture: Streaming Multiprocessors (SMs), warps (32 threads), warp divergence, occupancy. | **DL Track (Part 2): Training Loop & Verification** | **secan**: Implement naive GPU L2 distance kernel: 1 thread per vector pair. Benchmark against CPU AVX2 on single query. |
| **Thursday** | Thu Nov 27 | [`Day 088`](../days/month-04/day-088-2026-11-27.md) | **CUDA-GUIDE Memory Hierarchy**: Global memory (HBM/GDDR), Shared memory (SRAM), Registers, Constant memory. | **Monthly Research: Sweeps & Data Logging** | **secan**: Implement dataset upload: store SIFT1M in GPU global memory. Implement batch brute-force scan kernel (1 block per query). |
| **Friday** | Fri Nov 28 | [`Day 089`](../days/month-04/day-089-2026-11-28.md) | **PMPP Ch 5**: Memory architecture, shared memory tiling, bank conflicts, memory coalescing principles. | **Technical Essay: Lab-Note Drafting** | **secan**: Implement **shared memory tiled** L2 kernel: load query and dataset tiles into shared memory. Benchmark tiled vs naive. |
| **Saturday** | Sat Nov 29 | [`Day 090`](../days/month-04/day-090-2026-11-29.md) | **09:00–13:00**: Pure Math Block 1 (Theory & Derivations) | **14:00–18:00**: FREE / Rest / Buffer | Weekend Deep Work |
| **Sunday** | Sun Nov 30 | [`Day 091`](../days/month-04/day-091-2026-11-30.md) | **09:00–13:00**: Pure Math Block 2 (Problem Sets & Proofs) | **13:00–14:00**: Maintenance | Rest & Buffer |

---

## 📋 Daily Action Items & Deliverables (Week 13)

### 🔹 Monday, Mon Nov 24 ([`Day 085`](../days/month-04/day-085-2026-11-24.md))
* `[ ]` **Core**: Configure CMake for CUDA (`enable_language(CUDA)`); set up `compute-sanitizer` automated memory checker in CI.
* `⭐ Optional / Stretch`: Write a CMake check that validates GPU compute capability (e.g. `sm_80`, `sm_89`, `sm_90`) and enables target-specific PTX generation.

### 🔹 Tuesday, Tue Nov 25 ([`Day 086`](../days/month-04/day-086-2026-11-25.md))
* `[ ]` **Core**: Implement RAII `GpuBuffer<T>` wrapper managing device memory (`cudaMalloc`, `cudaFree`, `cudaMemcpyAsync`).
* `⭐ Optional / Stretch`: Implement CUDA pinned host memory allocator (`cudaHostAlloc`) and compare host-to-device transfer bandwidth.

### 🔹 Wednesday, Wed Nov 26 ([`Day 087`](../days/month-04/day-087-2026-11-26.md))
* `[ ]` **Core**: Implement naive GPU L2 distance kernel (1 thread per vector pair); benchmark latency against single-threaded CPU AVX2.
* `⭐ Optional / Stretch`: Profile kernel with Nsight Compute (`ncu`) to observe warp execution stalls due to memory latency.

### 🔹 Thursday, Thu Nov 27 ([`Day 088`](../days/month-04/day-088-2026-11-27.md))
* `[ ]` **Core**: Upload full SIFT1M dataset to GPU VRAM; implement batch scan kernel assigning 1 thread block per query vector.
* `⭐ Optional / Stretch`: Measure PCIe bus upload bandwidth as a function of batch buffer size ($1\text{MB}$ to $1\text{GB}$).

### 🔹 Friday, Fri Nov 28 ([`Day 089`](../days/month-04/day-089-2026-11-28.md))
* `[ ]` **Core**: Implement shared memory tiled L2 distance kernel loading query and dataset chunks into SRAM; measure speedup over naive kernel.
* `⭐ Optional / Stretch`: Benchmark shared memory bank conflicts with varying tile dimension padding strategies.

### 🔹 Saturday, Sat Nov 29 ([`Day 090`](../days/month-04/day-090-2026-11-29.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 1**: Theory, concepts, and analytical derivations (textbook chapters & core proofs).
* `[ ]` **Core (15:00–16:30)**: **Weekend Reading Sanctuary**: Literature / Philosophy deep reading.
* `⭐ Optional / Stretch`: 100% Free / Rest / Recovery buffer.
### 🔹 Sunday, Sun Nov 30 ([`Day 091`](../days/month-04/day-091-2026-11-30.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 2**: Advanced theorems, problem sets, and chalkboard proof defense.
* `[ ]` **Core (13:00–14:00)**: **Runtime Maintenance**: Quick 30–60 min check for `limbed` / `ggmbed` (`embed-runtimes`).
* `[ ]` **Core (15:00–16:45)**: **Penrose Sunday**: *The Road to Reality* (1 chapter/week, visual geometry focus).
---

## ⛔ What NOT to Overspend Time On (Week 13 Time Traps)

* ❌ **Do NOT** optimize single-query latency on GPU—GPUs require batched queries ($B \ge 32$) to hide launch and PCIe latency.
* ❌ **Do NOT** use CUDA dynamic parallelism (launching kernels from inside kernels)—keep control flow on host CPU.
* ❌ **Do NOT** hand-write complex combinatorial counting proofs on paper—master permutations and combinations, then move to probability rules.

---

## 📝 Weekend Deliverables

### ✍️ Technical Essay 13 (Saturday 09:00–13:00)
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

### 🔬 Monthly Research Milestone (FlashMaxSim Milestone 1 — Mon/Thu 06:30–08:30 Morning Builder)
* **Paper**: *"The Memory Wall in Multimodal Late Interaction: Baseline GPU Kernel Profiling"*
* **Workspace**: `research/2026-12-flashattn-vamana/`
* **Publish Deadline**: **Sun Dec 27**
