# 🚀 Week 15 Execution Playbook

> **Theme**: Continuous Distributions, PDF, Gaussians & FlashAttention Scaffold  
> **Calendar Dates**: Mon Dec 8 – Sun Dec 14 (2026-12-08 to 2026-12-14)  
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
| **Monday** | Mon Dec 8 | [`Day 099`](../days/month-04/day-099-2026-12-08.md) | FlashAttention paper §1–3: HBM vs SRAM cost model; why materializing $S$ is the bottleneck. | **Monthly Research: Planning & Literature Synthesis** | **CUDA**: FA-1 grid ($B \times H$); shared mem tiles. *(Online softmax Python: Sat Dec 13.)* |
| **Tuesday** | Tue Dec 9 | [`Day 100`](../days/month-04/day-100-2026-12-09.md) | **PMPP Ch 16 / NVIDIA Docs**: Tensor Core / WMMA overview (context for GEMM tiles). | **DL Track (Part 1): Architecture & Tensor Shapes** | **CUDA**: FlashAttention kernel scaffold: grid ($B \times H$), shared mem for $Q_{block}, K_{block}, V_{block}, O_{block}$. |
| **Wednesday** | Wed Dec 10 | [`Day 101`](../days/month-04/day-101-2026-12-10.md) | CUDA Shared Memory banking: avoiding bank conflicts when loading $Q, K^T$ tiles. | **DL Track (Part 2): Training Loop & Verification** | **CUDA**: Block GEMM $S_{ij} = Q_i K_j^T / \sqrt{d}$ in shared memory. Check tiles vs PyTorch. |
| **Thursday** | Thu Dec 11 | [`Day 102`](../days/month-04/day-102-2026-12-11.md) | **CUDA-GUIDE Warp Primitives**: `__shfl_sync` for warp-level row max and row sum. | **Monthly Research: Sweeps & Data Logging** | **CUDA**: Online Softmax update in registers: block max $\tilde{m}$, $m_{new}$, update $\ell$, rescale $O$. |
| **Friday** | Fri Dec 12 | [`Day 103`](../days/month-04/day-103-2026-12-12.md) | Profile with `ncu` if kernel runs; else debug correctness first. | **Technical Essay: Lab-Note Drafting** | **CUDA**: Expose FA-1 via `torch.utils.cpp_extension`. Bench vs SDPA on small shapes. FA-2 → Week 25. |
| **Saturday** | Sat Dec 13 | [`Day 104`](../days/month-04/day-104-2026-12-13.md) | **09:00–13:00**: Pure Math Block 1 (Theory & Derivations) | **14:00–18:00**: FREE / Rest / Buffer | Weekend Deep Work |
| **Sunday** | Sun Dec 14 | [`Day 105`](../days/month-04/day-105-2026-12-14.md) | **09:00–13:00**: Pure Math Block 2 (Problem Sets & Proofs) | **13:00–14:00**: Maintenance | Rest & Buffer |

---

## 📋 Daily Action Items & Deliverables (Week 15)

### 🔹 Monday, Mon Dec 8 ([`Day 099`](../days/month-04/day-099-2026-12-08.md))
* `[ ]` **Core**: Implement CUDA thread grid configuration for FlashAttention ($B \times H$ blocks); allocate shared memory tiles for $Q, K, V$.
* `⭐ Optional / Stretch`: Derive the exact IO complexity reduction of FlashAttention ($O(N^2 d^2 / M)$ HBM accesses vs standard attention $O(N d + N^2)$).

### 🔹 Tuesday, Tue Dec 9 ([`Day 100`](../days/month-04/day-100-2026-12-09.md))
* `[ ]` **Core**: Scaffold shared memory layout for $Q_{block}, K_{block}, V_{block}, O_{block}$; implement coalesced global-to-shared memory staging loop.
* `⭐ Optional / Stretch`: Implement double-buffered shared memory loading (`cuda::memcpy_async` in CUDA 11+) to overlap GMEM loads with computation.

### 🔹 Wednesday, Wed Dec 10 ([`Day 101`](../days/month-04/day-101-2026-12-10.md))
* `[ ]` **Core**: Implement block GEMM tile multiplication $S_{ij} = Q_i K_j^T / \sqrt{d}$ in shared memory; verify numerical parity against `torch.matmul`.
* `⭐ Optional / Stretch`: Apply shared memory swizzling (XOR indexing) to eliminate bank conflicts during matrix transpose $K^T$ lookups.

### 🔹 Thursday, Thu Dec 11 ([`Day 102`](../days/month-04/day-102-2026-12-11.md))
* `[ ]` **Core**: Implement register online softmax algorithm: track running row max $\tilde{m}$, running normalizer $\ell$, and dynamically rescale accumulator $O$.
* `⭐ Optional / Stretch`: Verify numerical overflow protection of online softmax on inputs containing extreme logits ($> 10^4$).

### 🔹 Friday, Fri Dec 12 ([`Day 103`](../days/month-04/day-103-2026-12-12.md))
* `[ ]` **Core**: Package FlashAttention-1 kernel via `torch.utils.cpp_extension`; benchmark forward latency against `torch.nn.functional.scaled_dot_product_attention`.
* `⭐ Optional / Stretch`: Profile kernel memory throughput in Nsight Compute (`ncu --metrics dram__bytes_read.sum,dram__bytes_write.sum`).

### 🔹 Saturday, Sat Dec 13 ([`Day 104`](../days/month-04/day-104-2026-12-13.md))
* `[ ]` **Core (09:00–13:00)**: Write and ship **Technical Essay 15**: *"IO-Aware Tiling and Online Softmax: Constructing a FlashAttention-1 CUDA Kernel from First Principles"* to `goals/essays/essay_15.md`.
* `[ ]` **Core (14:00–18:00)**: Execute Saturday Deep Learning from Scratch track (**🧠 DL weekend**: Online softmax reference vs `torch.softmax`.).
* `⭐ Optional / Stretch`: Run automated test suite validating PyTorch numerical gradient and attention equivalence.

### 🔹 Sunday, Sun Dec 14 ([`Day 105`](../days/month-04/day-105-2026-12-14.md))
* `[ ]` **Core (09:00–13:00)**: Execute Monthly Research Milestone for Month 4 (`research/2026-12-three-paths-spine/`): run empirical benchmarks and record data tables.
* `⭐ Optional / Stretch`: Draft / update section figures and experimental limitations.

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

### 🧠 Deep Learning Track (Saturday 14:00–18:00)
* **Task**: **🧠 DL weekend**: Online softmax reference vs `torch.softmax`.

### 🔬 Monthly Research Milestone (Sunday 09:00–13:00)
* **Paper**: *"Billion-Scale Retrieval Frontiers: Comparing In-VRAM GPU IVF and Asynchronous NVMe DiskANN Under Concurrent Query Pressure"*
* **Workspace**: `research/2026-12-three-paths-spine/`
* **Publish Deadline**: **Sun Dec 27**
