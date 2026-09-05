# 🚀 Week 25 Execution Playbook

> **Theme**: FlashAttention-2 (Week 15 catch-up)  
> **Calendar Dates**: Sat Feb 20 – Fri Feb 26 (2027-02-20 to 2027-02-26)
> **Parent Month Dashboard**: [Month 7 (Mar 2027)](month-07-mar.md) · **Block**: II — GPU Specialization

| | | |
|:---|:---|:---|
| [← Week 24](week-24.md) | [Month 7 (Mar 2027) Dashboard](month-07-mar.md) | [Week 26 →](week-26.md) |

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
| **Saturday** | Sat Feb 20 | [`Day 169`](../days/month-07/day-169-2027-02-20.md) | **09:00–13:00**: Pure Math Block 1 (Theory & Derivations) | **15:00–16:30**: Literature Sanctuary | **18:00–19:30**: Information Theory (Cover & Thomas) · **19:30+**: Free / Rest |
| **Sunday** | Sun Feb 21 | [`Day 170`](../days/month-07/day-170-2027-02-21.md) | **09:00–13:00**: Pure Math Block 2 (Problem Sets & Proofs) | **13:00**: Maint · **15:00**: Penrose | **18:00–19:30**: Dist Systems (Dist-Vector Ch 1) · **19:30–21:00**: Systems Lab (FlashMaxSim Lab 4) |
| **Monday** | Mon Feb 22 | [`Day 171`](../days/month-07/day-171-2027-02-22.md) | FlashAttention-2 (Dao 2023). | **Monthly Research: Planning & Literature Synthesis** | **CUDA**: FA-2 loop order on Week 15 kernel. |
| **Tuesday** | Tue Feb 23 | [`Day 172`](../days/month-07/day-172-2027-02-23.md) | Warp partition along sequence. | **DL Track (Part 1): Architecture & Tensor Shapes** | **CUDA**: Reduce inter-warp sync; unit-test vs PyTorch. |
| **Wednesday** | Wed Feb 24 | [`Day 173`](../days/month-07/day-173-2027-02-24.md) | `ncu` metrics: DRAM, achieved TFLOPS. | **DL Track (Part 2): Training Loop & Verification** | **CUDA (required)**: Nsight FA-1 vs FA-2 vs SDPA. |
| **Thursday** | Thu Feb 25 | [`Day 174`](../days/month-07/day-174-2027-02-25.md) | Integrate GQA from Week 2/4. | **Monthly Research: Sweeps & Data Logging** | **Python/CUDA**: FA-2 path with `num_kv_heads`. |
| **Friday** | Fri Feb 26 | [`Day 175`](../days/month-07/day-175-2027-02-26.md) | — | **Technical Essay: Lab-Note Drafting** | Expose FA-2 via `cpp_extension`. Document speedup table for March paper. |

---

## 📋 Daily Action Items & Deliverables (Week 25)

### 🔹 Saturday, Sat Feb 20 ([`Day 169`](../days/month-07/day-169-2027-02-20.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 1**: Theory, concepts, and analytical derivations (textbook chapters & core proofs).
* `[ ]` **Core (15:00–16:30)**: **Weekend Reading Sanctuary**: Literature / Philosophy deep reading.
* `[ ]` **Core (18:00–19:30)**: **Information Theory Track**: Thomas M. Cover & Joy A. Thomas, *Elements of Information Theory* (Reading & Notes).
* `⭐ Optional / Stretch`: 21:00 onwards 100% Free / Rest.

### 🔹 Sunday, Sun Feb 21 ([`Day 170`](../days/month-07/day-170-2027-02-21.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 2**: Advanced theorems, problem sets, and chalkboard proof defense.
* `[ ]` **Core (13:00–14:00)**: **Runtime Maintenance**: Quick 30–60 min check for `limbed` / `ggmbed` (`embed-runtimes`).
* `[ ]` **Core (15:00–16:45)**: **Penrose Sunday**: *The Road to Reality* (1 chapter/week, visual geometry focus).
* `[ ]` **Core (18:00–19:30)**: **Distributed Systems & IR Track**: **Dist-Vector Ch 1** (Distributed Multi-Vector Indexing: ColBERT/ColPali Sharding & Two-Tier Routing).
* `[ ]` **Core (19:30–21:00)**: **Graduate Systems & GPU Architecture Lab**: Microarchitecture analysis and CUDA exercises in **FlashMaxSim Lab 4** (Nsight Compute (NCU) profiling: warp execution efficiency & memory roofline saturation).
* `⭐ Optional / Stretch`: 21:00 onwards Weekly review & recovery.

### 🔹 Monday, Mon Feb 22 ([`Day 171`](../days/month-07/day-171-2027-02-22.md))
* `[ ]` **Core**: Implement FlashAttention-2 loop inversion (outer loop over $Q$ blocks, inner loop over $K, V$ blocks) to reduce shared memory write traffic.
* `⭐ Optional / Stretch`: Derive the exact register footprint comparison between FlashAttention-1 and FlashAttention-2.


### 🔹 Tuesday, Tue Feb 23 ([`Day 172`](../days/month-07/day-172-2027-02-23.md))
* `[ ]` **Core**: Implement sequence-level warp partitioning inside thread blocks; eliminate inter-warp synchronization barriers during forward pass.
* `⭐ Optional / Stretch`: Verify numerical equivalence against PyTorch `scaled_dot_product_attention` across sequence lengths $L \in [512, 16384]$.


### 🔹 Wednesday, Wed Feb 24 ([`Day 173`](../days/month-07/day-173-2027-02-24.md))
* `[ ]` **Core**: Profile FA-1 vs FA-2 vs PyTorch SDPA in Nsight Compute (`ncu`); measure achieved TFLOPS and DRAM bandwidth saturation.
* `⭐ Optional / Stretch`: Calculate tensor core compute efficiency percentage (% of theoretical FP16 peak).


### 🔹 Thursday, Thu Feb 25 ([`Day 174`](../days/month-07/day-174-2027-02-25.md))
* `[ ]` **Core**: Implement Grouped-Query Attention (GQA) support in FA-2 kernel (`num_heads_q != num_heads_kv`); broadcast $K, V$ heads to query groups in SRAM.
* `⭐ Optional / Stretch`: Benchmark latency speedup of GQA ($G=8$) vs MHA ($G=1$) at batch size 32.


### 🔹 Friday, Fri Feb 26 ([`Day 175`](../days/month-07/day-175-2027-02-26.md))
* `[ ]` **Core**: Build production PyTorch C++ extension bindings for FA-2; generate speedup curves for Month 7 publication paper.
* `⭐ Optional / Stretch`: Profile FlashAttention-2 vs FlashAttention-3 architectural mechanisms: analyze Hopper Tensor Memory Accelerator (TMA) asynchronous copy pipelines, warp specialization, and `wgmma` GEMM instructions.


---

## ⛔ What NOT to Overspend Time On (Week 25 Time Traps)

* ❌ **Do NOT** implement backward gradient kernels for FA-2—forward inference execution is the complete target.
* ❌ **Do NOT** hand-tune PTX for specific Hopper (SM90) wgmma instructions—standard FP16/BF16 shared-memory tiling provides massive speedup portably.
* ❌ **Do NOT** spend days micro-optimizing head dimensions beyond $d \in \{64, 128\}$.

---

## 📝 Weekend Deliverables

### ✍️ Technical Essay 25 (Saturday 09:00–13:00)
* **Title**: *"Warp Partitioning and Register Rescaling: Implementing FlashAttention-2 with Grouped-Query Attention"*
* **Target File**: `~/personal/goals/essays/essay_25.md`
* **5-Part Structure**:
  1. **Mathematical Foundation**: Core theorems, derivations, and formal definitions.
  2. **The Systems Bottleneck**: Hardware limitation (memory bandwidth, port contention, cache line splits, warp stalls).
  3. **The Engine Architecture**: Exact data structures and SIMD/CUDA kernel design implemented in `secan`.
  4. **Empirical Benchmarks**: Perf counter tables, latency percentiles ($p50/p95/p99$), and QPS curves.
  5. **Key Takeaway**: Architectural rule of thumb for production AI systems.

### 🧠 Deep Learning Track (Tue/Wed 06:30–08:30 Morning Builder)
* **Task**: 

### 🔬 Monthly Research Milestone (FlashMaxSim Milestone 4 (Landmark Paper 2 Freeze) — Mon/Thu 06:30–08:30 Morning Builder)
* **Paper**: *"Nsight Compute Roofline Validation & Master Conference Submission"*
* **Workspace**: `research/2027-03-gpu-serving/`
* **Publish Deadline**: **Fri Mar 12**
