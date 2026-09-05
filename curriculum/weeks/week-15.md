# 🚀 Week 15 Execution Playbook

> **Theme**: Continuous Distributions, PDF, Gaussians & FlashAttention Scaffold  
> **Calendar Dates**: Sat Dec 12 – Fri Dec 18 (2026-12-12 to 2026-12-18)
> **Parent Month Dashboard**: [Month 4 (Dec 2026)](month-04-dec.md) · **Block**: I — Vector Search Engine

| | | |
|:---|:---|:---|
| [← Week 14](week-14.md) | [Month 4 (Dec 2026) Dashboard](month-04-dec.md) | [Week 16 →](week-16.md) |

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
| **Saturday** | Sat Dec 12 | [`Day 099`](../days/month-04/day-099-2026-12-12.md) | **09:00–13:00**: Pure Math Block 1 (Theory & Derivations) | **15:00–16:30**: Literature Sanctuary | **18:00–19:30**: Information Theory (Cover & Thomas) · **19:30–21:00**: Thought Leadership (Richard P. Feynman) · **21:00+**: Free / Rest|
| **Sunday** | Sun Dec 13 | [`Day 100`](../days/month-04/day-100-2026-12-13.md) | **09:00–13:00**: Pure Math Block 2 (Problem Sets & Proofs) | **13:00**: Maint · **15:00**: Penrose | **18:00–19:30**: Dist Systems (IIR Ch 4) · **19:30–21:00**: Systems Lab (Kirk & Hwu Ch 6) |
| **Monday** | Mon Dec 14 | [`Day 101`](../days/month-04/day-101-2026-12-14.md) | FlashAttention paper §1–3: HBM vs SRAM cost model; why materializing $S$ is the bottleneck. | **Monthly Research: Planning & Literature Synthesis** | **CUDA**: FA-1 grid ($B \times H$); shared mem tiles. *(Online softmax Python: Sat Dec 13.)* |
| **Tuesday** | Tue Dec 15 | [`Day 102`](../days/month-04/day-102-2026-12-15.md) | **PMPP Ch 16 / NVIDIA Docs**: Tensor Core / WMMA overview (context for GEMM tiles). | **DL Track (Part 1): Architecture & Tensor Shapes** | **CUDA**: FlashAttention kernel scaffold: grid ($B \times H$), shared mem for $Q_{block}, K_{block}, V_{block}, O_{block}$. |
| **Wednesday** | Wed Dec 16 | [`Day 103`](../days/month-04/day-103-2026-12-16.md) | CUDA Shared Memory banking: avoiding bank conflicts when loading $Q, K^T$ tiles. | **DL Track (Part 2): Training Loop & Verification** | **CUDA**: Block GEMM $S_{ij} = Q_i K_j^T / \sqrt{d}$ in shared memory. Check tiles vs PyTorch. |
| **Thursday** | Thu Dec 17 | [`Day 104`](../days/month-04/day-104-2026-12-17.md) | **CUDA-GUIDE Warp Primitives**: `__shfl_sync` for warp-level row max and row sum. | **Monthly Research: Sweeps & Data Logging** | **CUDA**: Online Softmax update in registers: block max $\tilde{m}$, $m_{new}$, update $\ell$, rescale $O$. |
| **Friday** | Fri Dec 18 | [`Day 105`](../days/month-04/day-105-2026-12-18.md) | Profile with `ncu` if kernel runs; else debug correctness first. | **Technical Essay: Lab-Note Drafting** | **CUDA**: Expose FA-1 via `torch.utils.cpp_extension`. Bench vs SDPA on small shapes. FA-2 → Week 25. |

---

## 📋 Daily Action Items & Deliverables (Week 15)

### 🔹 Saturday, Sat Dec 12 ([`Day 099`](../days/month-04/day-099-2026-12-12.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 1**: Theory, concepts, and analytical derivations (textbook chapters & core proofs).
* `[ ]` **Core (15:00–16:30)**: **Weekend Reading Sanctuary**: Literature / Philosophy deep reading.
* `[ ]` **Core (18:00–19:30)**: **Information Theory Track**: Thomas M. Cover & Joy A. Thomas, *Elements of Information Theory* (Reading & Notes).
* `[ ]` **Core (19:30–21:00)**: **Thought Leadership Masterclass**: Richard P. Feynman, *Feynman Lectures on Computation* — **Ch 4: Reversible Computation & Thermodynamics** (Landauer's Principle, Thermodynamic Cost of Bit Erasure (kT ln 2), Maxwell's Demon, Ballistic Gates).
* `⭐ Optional / Stretch`: 21:00 onwards 100% Free / Rest.

### 🔹 Sunday, Sun Dec 13 ([`Day 100`](../days/month-04/day-100-2026-12-13.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 2**: Advanced theorems, problem sets, and chalkboard proof defense.
* `[ ]` **Core (13:00–14:00)**: **Runtime Maintenance**: Quick 30–60 min check for `limbed` / `ggmbed` (`embed-runtimes`).
* `[ ]` **Core (15:00–16:45)**: **Penrose Sunday**: *The Road to Reality* (1 chapter/week, visual geometry focus).
* `[ ]` **Core (18:00–19:30)**: **Distributed Systems & IR Track**: **IIR Ch 4** (Index Construction: BSBI, SPIMI, Dynamic Indexing & Distributed Index Construction).
* `[ ]` **Core (19:30–21:00)**: **Graduate Systems & GPU Architecture Lab**: Microarchitecture analysis and CUDA exercises in **Kirk & Hwu Ch 6** (Shared memory architecture: 32-bank conflict analysis & padding strategies).
* `⭐ Optional / Stretch`: 21:00 onwards Weekly review & recovery.

### 🔹 Monday, Mon Dec 14 ([`Day 101`](../days/month-04/day-101-2026-12-14.md))
* `[ ]` **Core**: Implement CUDA thread grid configuration for FlashAttention ($B \times H$ blocks); allocate shared memory tiles for $Q, K, V$.
* `⭐ Optional / Stretch`: Derive the exact IO complexity reduction of FlashAttention ($O(N^2 d^2 / M)$ HBM accesses vs standard attention $O(N d + N^2)$).


### 🔹 Tuesday, Tue Dec 15 ([`Day 102`](../days/month-04/day-102-2026-12-15.md))
* `[ ]` **Core**: Scaffold shared memory layout for $Q_{block}, K_{block}, V_{block}, O_{block}$; implement coalesced global-to-shared memory staging loop.
* `⭐ Optional / Stretch`: Implement double-buffered shared memory loading (`cuda::memcpy_async` in CUDA 11+) to overlap GMEM loads with computation.


### 🔹 Wednesday, Wed Dec 16 ([`Day 103`](../days/month-04/day-103-2026-12-16.md))
* `[ ]` **Core**: Implement block GEMM tile multiplication $S_{ij} = Q_i K_j^T / \sqrt{d}$ in shared memory; verify numerical parity against `torch.matmul`.
* `⭐ Optional / Stretch`: Apply shared memory swizzling (XOR indexing) to eliminate bank conflicts during matrix transpose $K^T$ lookups.


### 🔹 Thursday, Thu Dec 17 ([`Day 104`](../days/month-04/day-104-2026-12-17.md))
* `[ ]` **Core**: Implement register online softmax algorithm: track running row max $\tilde{m}$, running normalizer $\ell$, and dynamically rescale accumulator $O$.
* `⭐ Optional / Stretch`: Verify numerical overflow protection of online softmax on inputs containing extreme logits ($> 10^4$).


### 🔹 Friday, Fri Dec 18 ([`Day 105`](../days/month-04/day-105-2026-12-18.md))
* `[ ]` **Core**: Package FlashAttention-1 kernel via `torch.utils.cpp_extension`; benchmark forward latency against `torch.nn.functional.scaled_dot_product_attention`.
* `⭐ Optional / Stretch`: Profile kernel memory throughput in Nsight Compute (`ncu --metrics dram__bytes_read.sum,dram__bytes_write.sum`).


---

## ⛔ What NOT to Overspend Time On (Week 15 Time Traps)

* ❌ **Do NOT** implement backward pass for FlashAttention—this week is strictly forward attention execution.
* ❌ **Do NOT** attempt FlashAttention-2 loop inversion this week—FA-2 is specifically scheduled for Month 7 (Week 25).
* ❌ **Do NOT** write inline PTX for Tensor Cores (`mma.sync`)—standard FP32/FP16 shared memory arithmetic is the foundation.

---

## 📝 Weekend Deliverables

### ✍️ Technical Essay 15 (Saturday 09:00–13:00)
* **Title**: *"IO-Aware Tiling and Online Softmax: Constructing a FlashAttention-1 CUDA Kernel from First Principles"*
* **Target File**: `~/personal/goals/essays/essay_15.md`
* **5-Part Structure**:
  1. **Mathematical Foundation**: Core theorems, derivations, and formal definitions.
  2. **The Systems Bottleneck**: Hardware limitation (memory bandwidth, port contention, cache line splits, warp stalls).
  3. **The Engine Architecture**: Exact data structures and SIMD/CUDA kernel design implemented in `secan`.
  4. **Empirical Benchmarks**: Perf counter tables, latency percentiles ($p50/p95/p99$), and QPS curves.
  5. **Key Takeaway**: Architectural rule of thumb for production AI systems.

### 🧠 Deep Learning Track (Tue/Wed 06:30–08:30 Morning Builder)
* **Task**: **🧠 DL weekend**: Online softmax reference vs `torch.softmax`.

### 🔬 Monthly Research Milestone (FlashMaxSim Milestone 1 — Mon/Thu 06:30–08:30 Morning Builder)
* **Paper**: *"The Memory Wall in Multimodal Late Interaction: Baseline GPU Kernel Profiling"*
* **Workspace**: `research/2026-12-flashattn-vamana/`
* **Publish Deadline**: **Sun Dec 27**
