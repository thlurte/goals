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
│ 🛠️ Mon–Fri 06:30 – 08:30     │ Morning Builder Track (DL / Benchmarking / Technical Articles)        │
│ ☀️ Mon–Fri Daytime           │ Professional Workday (Full focus, zero math fatigue)                   │
│ 📚 Mon–Fri 18:30 – 20:00     │ Evening Reading Sanctuary (Pirsig / GEB / Dostoevsky / Wiener)         │
│ 💻 Mon–Fri 20:30 – 23:00     │ Night Block 1:  (Vector Search Engine in C++20 / SIMD / GPU)    │
│ ⚡ Mon–Fri 23:00 – 00:00     │ Night Block 2:  (C++ Multi-Modal High-D Embedding Runtime)     │
└──────────────────────────────┴────────────────────────────────────────────────────────────────────────┘
```

---

## 📅 Day-by-Day Master Timetable

| Day | Date | Daily Runbook | Systems Reading (05:30–06:30) | Morning Builder Track (06:30–08:30) | Night Hands-On C++/CUDA (20:30–23:00) |
|:---|:---|:---|:---|:---|:---|
| **Saturday** | Sat Dec 5 | [`Day 092`](../days/month-04/day-092-2026-12-05.md) | **09:00–13:00**: Pure Math Block 1 (Theory & Derivations) | **15:00–16:30**: Literature Sanctuary | **18:00–19:30**: Information Theory (Cover & Thomas) · **19:30–21:00**: Thought Leadership (Richard P. Feynman) · **21:00+**: Free / Rest|
| **Sunday** | Sun Dec 6 | [`Day 093`](../days/month-04/day-093-2026-12-06.md) | **09:00–13:00**: Pure Math Block 2 (Problem Sets & Proofs) | **13:00**: Maint · **15:00**: Penrose | **18:00–19:30**: Dist Systems (IIR Ch 3) · **19:30–21:00**: Systems Lab (Kirk & Hwu Ch 4–5) |
| **Monday** | Mon Dec 7 | [`Day 094`](../days/month-04/day-094-2026-12-07.md) | **PMPP Ch 6**: Performance considerations: memory coalescing patterns, maximizing global memory bus utilization. | **Hardware Profiling & Benchmark Sweeps** | **secan**: Implement **coalesced GPU distance kernel**: ensure adjacent threads in a warp access consecutive memory addresses. |
| **Tuesday** | Tue Dec 8 | [`Day 095`](../days/month-04/day-095-2026-12-08.md) | **PMPP Ch 10**: Parallel reductions, warp shuffle primitives (`__shfl_down_sync`), eliminating shared memory bank conflicts. | **DL Track (Part 1): Architecture & Tensor Shapes** | **secan**: Implement **warp-level reduction**: use `__shfl_down_sync` to reduce 32 partial sums inside a warp with zero shared memory overhead. |
| **Wednesday** | Wed Dec 9 | [`Day 096`](../days/month-04/day-096-2026-12-09.md) | **CUDA-GUIDE Warp Primitives**: `__shfl_sync`, `__shfl_xor_sync`, `__ballot_sync`, `__any_sync`, Cooperative Groups. | **DL Track (Part 2): Training Loop & Verification** | **secan**: Implement batched GPU scanner: process $B=256$ queries simultaneously. Each block processes a query; warps scan dataset chunks. |
| **Thursday** | Thu Dec 10 | [`Day 097`](../days/month-04/day-097-2026-12-10.md) | **PMPP Ch 7**: Tiling patterns, halo cells, constant memory for read-only query parameters. | **DL / Vector Retrieval Integration & Profiling** | **secan**: Implement fused Cosine similarity GPU kernel: dot product + norms in a single pass. Add inner-product kernel. |
| **Friday** | Fri Dec 11 | [`Day 098`](../days/month-04/day-098-2026-12-11.md) | **PMPP Ch 11–12**: Parallel merge and sorting on GPU: partial bitonic sort, warp-cooperative top-$k$ selection. | **Weekly Technical Article: Drafting & Publishing** | **secan**: Implement **GPU top-k selection**: warp-cooperative partial bitonic sort extracting top-$k$ without sorting all $N$ distances. |

---

> **📚 Advanced Research Reference (Week 14)**: * [Alex Petrov, *Database Internals*](https://www.databass.dev/) — **Ch 7 (§7.1–7.4)** (*Log-Structured Merge-Trees (LSM-Trees): MemTables, SSTables & Bloom Filter Sizing for Vector Postings*) · * [Paul E. McKenney, *Is Parallel Programming Hard ("The Perfbook")*](https://mirrors.edge.kernel.org/pub/linux/kernel/people/paulmck/perfbook/perfbook.html) — **Ch 5 (§5.1–5.4)** (*Non-Blocking Statistical Counters & Scalable Reference Counting*)

## 📋 Daily Action Items & Deliverables (Week 14)

### 🔹 Saturday, Sat Dec 5 ([`Day 092`](../days/month-04/day-092-2026-12-05.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 1**: Theory, concepts, and analytical derivations (textbook chapters & core proofs).
* `[ ]` **Core (15:00–16:30)**: **Weekend Reading Sanctuary**: [Douglas Hofstadter, *Gödel, Escher, Bach: An Eternal Golden Braid*](https://www.basicbooks.com/titles/douglas-r-hofstadter/godel-escher-bach/9780465026562/) — **Ch 1: The MU-puzzle & Three-Part Invention**.
* `[ ]` **Core (16:30–18:00)**: **Physical Break & Mental Decompression**: Walk, tea, and recovery.
* `[ ]` **Core (18:00–19:30)**: **Information Theory Track**: [Thomas M. Cover & Joy A. Thomas, *Elements of Information Theory (2nd ed)*](https://www.wiley.com/en-us/Elements+of+Information+Theory%2C+2nd+Edition-p-9780471241959) — **Ch 9 (§9.1–9.4)** (Gaussian Channel, Bandlimited Channels, Water-Filling Theorem & Parallel Gaussian Channels).
* `[ ]` **Core (19:30–21:00)**: **Thought Leadership Masterclass**: [Richard P. Feynman, *Feynman Lectures on Computation*](https://www.taylorfrancis.com/books/mono/10.1201/9780429500442/feynman-lectures-computation-richard-feynman) — **Ch 3: Coding and Information Theory** (Entropy, Error-Correction, and the Physics of Information).
* `⭐ Optional / Stretch`: 21:00 onwards 100% Free / Rest.

### 🔹 Sunday, Sun Dec 6 ([`Day 093`](../days/month-04/day-093-2026-12-06.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 2**: Advanced theorems, problem sets, and chalkboard proof defense.
* `[ ]` **Core (13:00–14:00)**: **Runtime Maintenance**: Quick 30–60 min check for `limbed` / `ggmbed` (`embed-runtimes`).
* `[ ]` **Core (15:00–16:45)**: **Penrose Sunday**: [Sir Roger Penrose, *The Road to Reality*](https://www.vintagebooks.com) — **Ch 9: Fourier Decomposition and Hyperfunctions** (Fourier series/integrals, orthogonal sine/cosine bases, Dirac delta functions, hyperfunctions.).
* `[ ]` **Core (18:00–19:30)**: **Distributed Systems & IR Track**: [Martin Kleppmann, *Designing Data-Intensive Applications*](https://dataintensive.net/) — **DDIA Ch 9** (Consistency and Consensus: Linearizability, Total Order Broadcast, 2PC, Paxos & Raft consensus).
* `[ ]` **Core (19:30–21:00)**: **Graduate Systems & GPU Architecture Lab**: [John L. Hennessy & David A. Patterson, *Computer Architecture: A Quantitative Approach (6th ed)*](https://shop.elsevier.com/books/computer-architecture/hennessy/978-0-443-15406-5) — **H&P Ch 5 (§5.5–5.8)** (Memory Consistency Models & Synchronization: Sequential consistency, TSO, acquire-release & CAS).
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

## Benchmark Close

Before the Friday article or release, save the run manifest and raw JSON/CSV, add one meaningful parameter sweep and plot, update the comparable README result row, and state the oracle result plus one evidence-backed conclusion. Record results below the noise floor as inconclusive.

## 📝 Weekend Deliverables

### ✍️ Technical Essay 14 (Drafted Friday 06:30–08:30)
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

### 🔬 Empirical Systems & Benchmarking Focus (Mon/Thu 06:30–08:30 Morning Builder)
* **Focus**: The Memory Wall in Multimodal Late Interaction: Baseline GPU Kernel Profiling
* **Workspace**: `research/2026-12-flashattn-vamana/`
* **Artifact Target**: Empirical benchmark and profiling data feeding into Friday's technical articles.

---

## ⚡  Embedding Engine Track (Week 14)
> **Weekly Focus**: *FlashAttention & In-SRAM Attention Kernels*

| Day | 23:00 – 00:00 Implementation Task |
|:---|:---|
| **Mon** | Implement tiled online softmax attention in CUDA to avoid writing [B, H, L, L] attention matrix to VRAM. |
| **Tue** | Implement FlashAttention forward pass in shared memory with causal masking. |
| **Wed** | Fuse RoPE complex rotation directly into QK dot product kernel in CUDA shared memory. |
| **Thu** | Benchmark FlashAttention VRAM reduction and latency scaling across sequence lengths up to 8192. |
| **Fri** | Verify exact mathematical parity of CUDA FlashAttention output against PyTorch SDPA. |
