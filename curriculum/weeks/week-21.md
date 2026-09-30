# 🚀 Week 21 Execution Playbook

> **Theme**: Convex Optimization, KKT, ColPali GPU Path  
> **Calendar Dates**: Sat Jan 23 – Fri Jan 29 (2027-01-23 to 2027-01-29)
> **Parent Month Dashboard**: [Month 6 (Feb 2027)](month-06-feb.md) · **Block**: II — GPU Specialization

| | | |
|:---|:---|:---|
| [← Week 20](week-20.md) | [Month 6 (Feb 2027) Dashboard](month-06-feb.md) | [Week 22 →](week-22.md) |

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
| **Saturday** | Sat Jan 23 | [`Day 141`](../days/month-06/day-141-2027-01-23.md) | **09:00–13:00**: Pure Math Block 1 (Theory & Derivations) | **15:00–16:30**: Literature Sanctuary | **18:00–19:30**: Information Theory (Cover & Thomas) · **19:30–21:00**: Thought Leadership (John von Neumann) · **21:00+**: Free / Rest|
| **Sunday** | Sun Jan 24 | [`Day 142`](../days/month-06/day-142-2027-01-24.md) | **09:00–13:00**: Pure Math Block 2 (Problem Sets & Proofs) | **13:00**: Maint · **15:00**: Penrose | **18:00–19:30**: Dist Systems (IIR Ch 11) · **19:30–21:00**: Systems Lab (Kirk & Hwu Ch 17) |
| **Monday** | Mon Jan 25 | [`Day 143`](../days/month-06/day-143-2027-01-25.md) | Re-read ColBERT/PLAID papers with GPU focus: mapping MaxSim to batched GEMM + reductions. | **Hardware Profiling & Benchmark Sweeps** | **secan**: Implement **GPU MaxSim kernel**: CUTLASS GEMM + warp row-max + column-sum. |
| **Tuesday** | Tue Jan 26 | [`Day 144`](../days/month-06/day-144-2027-01-26.md) | CLIP / SigLIP contrastive alignment (image encoder ↔ text encoder). | **DL Track (Part 1): Architecture & Tensor Shapes** | **secan**: GPU MaxSim polish / fused pipeline. * |
| **Wednesday** | Wed Jan 27 | [`Day 145`](../days/month-06/day-145-2027-01-27.md) | NN-Descent / CAGRA neighbor exchange. | **DL Track (Part 2): Training Loop & Verification** | **secan**: GPU NN-Descent base-layer graph construction. **FA-2 → Week 25.** |
| **Thursday** | Thu Jan 28 | [`Day 146`](../days/month-06/day-146-2027-01-28.md) | CAGRA / NN-Descent GPU neighbor exchange. | **DL / Vector Retrieval Integration & Profiling** | **secan**: GPU NN-Descent base-layer graph construction. |
| **Friday** | Fri Jan 29 | [`Day 147`](../days/month-06/day-147-2027-01-29.md) | Review GPU ColBERT / ColPali integration. | **Weekly Technical Article: Drafting & Publishing** | **secan**: Ingest ColPali visual embeddings; text query → visual page search. **Stretch**: same tokens through MUVERA FDE + IP MIPS. |

---

## 📋 Daily Action Items & Deliverables (Week 21)

### 🔹 Saturday, Sat Jan 23 ([`Day 141`](../days/month-06/day-141-2027-01-23.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 1**: Theory, concepts, and analytical derivations (textbook chapters & core proofs).
* `[ ]` **Core (15:00–16:30)**: **Weekend Reading Sanctuary**: Literature / Philosophy deep reading.
* `[ ]` **Core (18:00–19:30)**: **Information Theory Track**: Thomas M. Cover & Joy A. Thomas, *Elements of Information Theory* (Reading & Notes).
* `[ ]` **Core (19:30–21:00)**: **Thought Leadership Masterclass**: John von Neumann, *Probabilistic Logics & Synthesis of Reliable Organisms (1956)* — **Full Landmark Paper** (Multiplexing, Error Masking, Majority Gates, Organismic Reliability from Flawed Physical Devices).
* `⭐ Optional / Stretch`: 21:00 onwards 100% Free / Rest.

### 🔹 Sunday, Sun Jan 24 ([`Day 142`](../days/month-06/day-142-2027-01-24.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 2**: Advanced theorems, problem sets, and chalkboard proof defense.
* `[ ]` **Core (13:00–14:00)**: **Runtime Maintenance**: Quick 30–60 min check for `limbed` / `ggmbed` (`embed-runtimes`).
* `[ ]` **Core (15:00–16:45)**: **Penrose Sunday**: *The Road to Reality* (1 chapter/week, visual geometry focus).
* `[ ]` **Core (18:00–19:30)**: **Distributed Systems & IR Track**: **IIR Ch 11** (Probabilistic Information Retrieval: Binary Independence Model & BM25 / Okapi Scoring).
* `[ ]` **Core (19:30–21:00)**: **Graduate Systems & GPU Architecture Lab**: Microarchitecture analysis and CUDA exercises in **Kirk & Hwu Ch 17** (Tensor Core programming: WMMA / MMA PTX assembly layouts and fragment loading).
* `⭐ Optional / Stretch`: 21:00 onwards Weekly review & recovery.

### 🔹 Monday, Mon Jan 25 ([`Day 143`](../days/month-06/day-143-2027-01-25.md))
* `[ ]` **Core**: Implement GPU MaxSim kernel in CUTLASS computing batched GEMM followed by warp row-max and column-sum reduction.
* `⭐ Optional / Stretch`: Derive the dual formulation of token alignment under convex regularized transportation costs.


### 🔹 Tuesday, Tue Jan 26 ([`Day 144`](../days/month-06/day-144-2027-01-26.md))
* `[ ]` **Core**: Fuse GPU MaxSim query scoring and candidate document filtering into a single CUDA pipeline.
* `⭐ Optional / Stretch`: Implement fused In-SRAM MaxSim kernel accumulating row-max scores directly in GPU shared memory without materializing the intermediate $L_q \times L_d$ matrix in global VRAM (benchmark vs naive GEMM on 1030 ColPali tokens/page).


### 🔹 Wednesday, Wed Jan 27 ([`Day 145`](../days/month-06/day-145-2027-01-27.md))
* `[ ]` **Core**: Implement GPU NN-Descent base-layer $k$-NN graph construction algorithm exchanging neighbor candidates across thread blocks.
* `⭐ Optional / Stretch`: Measure convergence speed (graph recall vs iteration count) on 100K embedding vectors.


### 🔹 Thursday, Thu Jan 28 ([`Day 146`](../days/month-06/day-146-2027-01-28.md))
* `[ ]` **Core**: Implement 2-opt edge pruning heuristic in GPU NN-Descent graph construction.
* `⭐ Optional / Stretch`: Verify Slater's condition for constrained graph sparsification optimization problems.


### 🔹 Friday, Fri Jan 29 ([`Day 147`](../days/month-06/day-147-2027-01-29.md))
* `[ ]` **Core**: Ingest ColPali multimodal embeddings (text query $\to$ multi-vector document pages); evaluate visual search Recall@10.
* `⭐ Optional / Stretch`: Route ColPali visual multi-vectors through MUVERA FDEs for instant 1-stage MIPS candidate retrieval.


---

## ⛔ What NOT to Overspend Time On (Week 21 Time Traps)

* ❌ **Do NOT** write a custom vision transformer model in C++—run ColPali image embeddings generation in Python/PyTorch.
* ❌ **Do NOT** optimize GPU NN-Descent beyond 10-15 iterations—NN-Descent achieves $>98\%$ $k$-NN graph quality quickly.
* ❌ **Do NOT** spend hours proving convex duality theorems for non-linear constraints—focus on KKT conditions for linear/quadratic programs.

---

## Benchmark Close

Before the Friday article or release, save the run manifest and raw JSON/CSV, add one meaningful parameter sweep and plot, update the comparable README result row, and state the oracle result plus one evidence-backed conclusion. Record results below the noise floor as inconclusive.

## 📝 Weekend Deliverables

### ✍️ Technical Essay 21 (Drafted Friday 06:30–08:30)
* **Title**: *"Duality and Multimodal Retrieval: Karush-Kuhn-Tucker Conditions, CLIP Alignment, and ColPali MaxSim"*
* **Target File**: `~/personal/goals/essays/essay_21.md`
* **5-Part Structure**:
  1. **Mathematical Foundation**: Core theorems, derivations, and formal definitions.
  2. **The Systems Bottleneck**: Hardware limitation (memory bandwidth, port contention, cache line splits, warp stalls).
  3. **The Engine Architecture**: Exact data structures and SIMD/CUDA kernel design implemented in `secan`.
  4. **Empirical Benchmarks**: Perf counter tables, latency percentiles ($p50/p95/p99$), and QPS curves.
  5. **Key Takeaway**: Architectural rule of thumb for production AI systems.

### 🧠 Deep Learning Track (Tue/Wed 06:30–08:30 Morning Builder)
* **Task**: **🧠 DL Builder Track (Tue/Wed)**: CLIP-style projector + ColPali head.

### 🔬 Empirical Systems & Benchmarking Focus (Mon/Thu 06:30–08:30 Morning Builder)
* **Focus**: Bare-Metal CUTLASS Implementation with Hopper/Blackwell TMA & Warp Specialization
* **Workspace**: `research/2027-02-predicate-aware-graphs/`
* **Artifact Target**: Empirical benchmark and profiling data feeding into Friday's technical articles.


---

## ⚡  Embedding Engine Track (Week 21)
> **Weekly Focus**: *Standalone Zero-Dependency C++ CLI (<10MB)*

| Day | 23:00 – 00:00 Implementation Task |
|:---|:---|
| **Mon** | Bundle cennan into a single standalone static binary with zero dynamic library dependencies. |
| **Tue** | Implement model weight bundling and embedded vocabulary tables in binary format. |
| **Wed** | Add high-performance batch embedding CLI with multithreaded file streaming. |
| **Thu** | Profile memory footprint: verify RSS memory overhead < 15MB above model weight size. |
| **Fri** | Automate cross-platform builds (Linux x86_64, ARM64 / Apple Silicon). |
