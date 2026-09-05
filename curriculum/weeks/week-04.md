# 🚀 Week 04 Execution Playbook

> **Theme**: Euler's Formula, IVF, MIPS & List Rebalance  
> **Calendar Dates**: Sat Sep 26 – Fri Oct 2 (2026-09-26 to 2026-10-02)
> **Parent Month Dashboard**: [Month 1 (Sep 2026)](month-01-sep.md) · **Block**: I — Vector Search Engine

| | | |
|:---|:---|:---|
| [← Week 03](week-03.md) | [Month 1 (Sep 2026) Dashboard](month-01-sep.md) | [Week 05 →](week-05.md) |

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
| **Saturday** | Sat Sep 26 | [`Day 022`](../days/month-01/day-022-2026-09-26.md) | **09:00–13:00**: Pure Math Block 1 (Theory & Derivations) | **15:00–16:30**: Literature Sanctuary | **18:00–19:30**: Information Theory (Cover & Thomas) · **19:30–21:00**: Thought Leadership (George Pólya) · **21:00+**: Free / Rest|
| **Sunday** | Sun Sep 27 | [`Day 023`](../days/month-01/day-023-2026-09-27.md) | **09:00–13:00**: Pure Math Block 2 (Problem Sets & Proofs) | **13:00**: Maint · **15:00**: Penrose | **18:00–19:30**: Dist Systems (DDIA Ch 3.2) · **19:30–21:00**: Systems Lab (Gregg Ch 6) |
| **Monday** | Mon Sep 28 | [`Day 024`](../days/month-01/day-024-2026-09-28.md) | **PIKUS Ch 5**: Cache coherence, false sharing. | **Monthly Research: Planning & Literature Synthesis** | **secan**: `batch_linear_scan` $B=32/64$ (GEMV $\to$ GEMM). |
| **Tuesday** | Tue Sep 29 | [`Day 025`](../days/month-01/day-025-2026-09-29.md) | Faiss IVF coarse quantizer; **spherical k-means** for IP/MIPS. | **DL Track (Part 1): Architecture & Tensor Shapes** | **secan**: `IVFIndex` — L2 k-means + **spherical k-means** for IP. |
| **Wednesday** | Wed Sep 30 | [`Day 026`](../days/month-01/day-026-2026-09-30.md) | **PIKUS Ch 6**: Thread pools. | **DL Track (Part 2): Training Loop & Verification** | **secan**: Multi-probe IVF; `nprobe` sweep; pinned `std::jthread`. |
| **Thursday** | Thu Oct 1 | [`Day 027`](../days/month-01/day-027-2026-10-01.md) | IVF inverted-list skew (Faiss `make_direct_map` / list size). | **Monthly Research: Sweeps & Data Logging** | **secan (required)**: Histogram of IVF list sizes; **rebalance / split oversized lists**. |
| **Friday** | Fri Oct 2 | [`Day 028`](../days/month-01/day-028-2026-10-02.md) | IP vs L2 recall on same vectors. | **Technical Essay: Lab-Note Drafting** | **secan**: IP/MIPS search path on IVF; compare Recall@10 vs L2. Tag `v0.2-simd-ivf`. |

---

## 📋 Daily Action Items & Deliverables (Week 04)

### 🔹 Saturday, Sat Sep 26 ([`Day 022`](../days/month-01/day-022-2026-09-26.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 1**: Theory, concepts, and analytical derivations (textbook chapters & core proofs).
* `[ ]` **Core (15:00–16:30)**: **Weekend Reading Sanctuary**: Literature / Philosophy deep reading.
* `[ ]` **Core (16:30–18:00)**: **Physical Break & Mental Decompression**: Walk, tea, and recovery.
* `[ ]` **Core (18:00–19:30)**: **Information Theory Track**: Thomas M. Cover & Joy A. Thomas, *Elements of Information Theory* — **Ch 4.1–4.4** (Entropy Rates & Markov Chains).
* `[ ]` **Core (19:30–21:00)**: **Thought Leadership Masterclass**: George Pólya, *How to Solve It* — **Part III (R–Z) & Part IV: Problems** (Working Backwards, Specialization vs Generalization, Routine Problems vs Real Discovery).
* `⭐ Optional / Stretch`: 21:00 onwards 100% Free / Rest.

### 🔹 Sunday, Sun Sep 27 ([`Day 023`](../days/month-01/day-023-2026-09-27.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 2**: Advanced theorems, problem sets, and chalkboard proof defense.
* `[ ]` **Core (13:00–14:00)**: **Runtime Maintenance**: Quick 30–60 min check for `limbed` / `ggmbed` (`embed-runtimes`).
* `[ ]` **Core (15:00–16:45)**: **Penrose Sunday**: *The Road to Reality* (1 chapter/week, visual geometry focus).
* `[ ]` **Core (18:00–19:30)**: **Distributed Systems & IR Track**: **DDIA Ch 3.2** (Storage and Retrieval: B-Trees, OLAP vs OLTP, Column-Oriented Storage & Vector Blocks).
* `[ ]` **Core (19:30–21:00)**: **Graduate Systems & GPU Architecture Lab**: Microarchitecture analysis and CUDA exercises in **Gregg Ch 6** (CPU PMU performance counters, instruction-to-cycle (IPC) decomposition & stall profiling).
* `⭐ Optional / Stretch`: 21:00 onwards Weekly review & recovery.

### 🔹 Monday, Mon Sep 28 ([`Day 024`](../days/month-01/day-024-2026-09-28.md))
* `[ ]` **Core**: Implement `batch_linear_scan()` for $B=32/64$ queries, transforming single-query GEMV into cached batch GEMM.
* `⭐ Optional / Stretch`: Implement cache-blocked matrix transpose to evaluate column-major vs row-major dataset layouts for batch scans.


### 🔹 Tuesday, Tue Sep 29 ([`Day 025`](../days/month-01/day-025-2026-09-29.md))
* `[ ]` **Core**: Implement `IVFIndex` class with coarse centroids trained via $k$-means; add spherical $k$-means for Inner Product (IP).
* `⭐ Optional / Stretch`: Implement $k$-means++ centroid initialization heuristic to speed up coarse quantizer convergence.


### 🔹 Wednesday, Wed Sep 30 ([`Day 026`](../days/month-01/day-026-2026-09-30.md))
* `[ ]` **Core**: Implement multi-probe IVF query scanner with `nprobe` parameter sweep; parallelize across queries with `std::jthread`.
* `⭐ Optional / Stretch`: Pin worker threads to physical CPU cores with `pthread_setaffinity_np` and measure latency jitter reduction.


### 🔹 Thursday, Thu Oct 1 ([`Day 027`](../days/month-01/day-027-2026-10-01.md))
* `[ ]` **Core**: Build histogram of inverted-list sizes; implement list rebalancing (splitting clusters larger than $2\times$ median size).
* `⭐ Optional / Stretch`: Analyze the relationship between cluster size variance and tail query latency ($p99$).


### 🔹 Friday, Fri Oct 2 ([`Day 028`](../days/month-01/day-028-2026-10-02.md))
* `[ ]` **Core**: Validate Inner Product (IP) search path on IVF index; plot Recall@10 vs `nprobe` for L2 and IP on SIFT1M. Tag `v0.2-simd-ivf`.
* `⭐ Optional / Stretch`: Compute exact Voronoi cell boundary distances to identify boundary query misclassification rates.


---

## ⛔ What NOT to Overspend Time On (Week 04 Time Traps)

* ❌ **Do NOT** run $k$-means for 100 iterations—10 to 15 Lloyd iterations are more than enough to stabilize coarse centroids.
* ❌ **Do NOT** implement Product Quantization (PQ) inside IVF lists yet—Month 1 is strictly IVFFlat (PQ is built in Month 2).
* ❌ **Do NOT** try to implement GPU kernels this week—GPU is scheduled for Month 4 (Weeks 13–16).

---

## 📝 Weekend Deliverables

### ✍️ Technical Essay 04 (Saturday 09:00–13:00)
* **Title**: *"From Complex Rotations to RoPE and Voronoi Cells: The Geometry of Spherical Inverted Files"*
* **Target File**: `~/personal/goals/essays/essay_04.md`
* **5-Part Structure**:
  1. **Mathematical Foundation**: Core theorems, derivations, and formal definitions.
  2. **The Systems Bottleneck**: Hardware limitation (memory bandwidth, port contention, cache line splits, warp stalls).
  3. **The Engine Architecture**: Exact data structures and SIMD/CUDA kernel design implemented in `secan`.
  4. **Empirical Benchmarks**: Perf counter tables, latency percentiles ($p50/p95/p99$), and QPS curves.
  5. **Key Takeaway**: Architectural rule of thumb for production AI systems.

### 🧠 Deep Learning Track (Tue/Wed 06:30–08:30 Morning Builder)
* **Task**: **🚀 Month 1 PUBLISH (Sun Sep 27)**. **🧠 DL**: RoPE + SwiGLU + CausalLM + CE + naive KV. **Also**: implement `SGD` optimizer from scratch (momentum $v_t = \beta v_{t-1} + \nabla\mathcal{L}$, $\theta_t = \theta_{t-1} - \alpha v_t$); train CausalLM with your SGD, verify loss matches `torch.optim.SGD`.

### 🔬 Monthly Research Milestone (GAPQ Milestone 1 — Mon/Thu 06:30–08:30 Morning Builder)
* **Paper**: *"Microarchitectural Limits of Distance Kernels & Empirical Embedding Cone Anisotropy"*
* **Workspace**: `research/2026-09-measurement-protocol/`
* **Publish Deadline**: **Sun Sep 27**
