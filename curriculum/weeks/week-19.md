# 🚀 Week 19 Execution Playbook

> **Theme**: Mathematical Statistics, MLE, PagedAttention & KV Compression  
> **Calendar Dates**: Sat Jan 9 – Fri Jan 15 (2027-01-09 to 2027-01-15)
> **Parent Month Dashboard**: [Month 5 (Jan 2027)](month-05-jan.md) · **Block**: II — GPU Specialization

| | | |
|:---|:---|:---|
| [← Week 18](week-18.md) | [Month 5 (Jan 2027) Dashboard](month-05-jan.md) | [Week 20 →](week-20.md) |

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
| **Saturday** | Sat Jan 9 | [`Day 127`](../days/month-05/day-127-2027-01-09.md) | **09:00–13:00**: Pure Math Block 1 (Theory & Derivations) | **15:00–16:30**: Literature Sanctuary | **18:00–19:30**: Information Theory (Cover & Thomas) · **19:30–21:00**: Thought Leadership (Edwin T. Jaynes) · **21:00+**: Free / Rest|
| **Sunday** | Sun Jan 10 | [`Day 128`](../days/month-05/day-128-2027-01-10.md) | **09:00–13:00**: Pure Math Block 2 (Problem Sets & Proofs) | **13:00**: Maint · **15:00**: Penrose | **18:00–19:30**: Dist Systems (IIR Ch 8) · **19:30–21:00**: Systems Lab (Kirk & Hwu Ch 11) |
| **Monday** | Mon Jan 11 | [`Day 129`](../days/month-05/day-129-2027-01-11.md) | vLLM Paper §1–3: The KV Cache fragmentation problem in LLMs ($60\%–80\%$ memory wasted on over-allocation). | **Hardware Profiling & Benchmark Sweeps** | **Python/CUDA**: Implement `BlockTable` data structure in PyTorch: maps logical sequence tokens to physical GPU memory blocks (block size 16). |
| **Tuesday** | Tue Jan 12 | [`Day 130`](../days/month-05/day-130-2027-01-12.md) | vLLM Paper §4: PagedAttention kernel design: reading $K, V$ blocks via block lookup table in CUDA. | **DL Track (Part 1): Architecture & Tensor Shapes** | **CUDA**: Implement **PagedAttention CUDA kernel**: during self-attention, resolve physical $K, V$ block pointers on-the-fly via block table. |
| **Wednesday** | Wed Jan 13 | [`Day 131`](../days/month-05/day-131-2027-01-13.md) | [TurboQuant](https://research.google/blog/turboquant-redefining-ai-efficiency-with-extreme-compression/): KV experiments (LongBench, RULER, needle-in-haystack); PolarQuant + QJL residual as bias killer for attention scores. | **DL Track (Part 2): Training Loop & Verification** | **secan**: Build unified `GpuIndex` wrapper class: device memory lifecycle, async transfers, kernel launches, RAII cleanup. |
| **Thursday** | Thu Jan 14 | [`Day 132`](../days/month-05/day-132-2027-01-14.md) | **PMPP Ch 19**: Heterogeneous CPU+GPU workload partitioning. | **DL / Vector Retrieval Integration & Profiling** | **secan**: Implement **CPU↔GPU hybrid fallback**: partition oversized dataset into GPU VRAM (fast) and CPU RAM (AVX2). Merge results. |
| **Friday** | Fri Jan 15 | [`Day 133`](../days/month-05/day-133-2027-01-15.md) | Profile PagedAttention vs standard KV cache memory; contrast with TurboQuant bitwidth story (paging ≠ quantizing). | **Weekly Technical Article: Drafting & Publishing** | **secan**: Benchmark query batch sizes ($B=1, 10, 100, 1000$). Plot the CPU vs GPU crossover curve. |

---

## 📋 Daily Action Items & Deliverables (Week 19)

### 🔹 Saturday, Sat Jan 9 ([`Day 127`](../days/month-05/day-127-2027-01-09.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 1**: Theory, concepts, and analytical derivations (textbook chapters & core proofs).
* `[ ]` **Core (15:00–16:30)**: **Weekend Reading Sanctuary**: Literature / Philosophy deep reading.
* `[ ]` **Core (18:00–19:30)**: **Information Theory Track**: Thomas M. Cover & Joy A. Thomas, *Elements of Information Theory* (Reading & Notes).
* `[ ]` **Core (19:30–21:00)**: **Thought Leadership Masterclass**: Edwin T. Jaynes, *Probability Theory: The Logic of Science* — **Ch 11: Discrete Prior Probabilities** (The Maximum Entropy Principle, Information Entropy as an Inference Criterion under Constraints).
* `⭐ Optional / Stretch`: 21:00 onwards 100% Free / Rest.

### 🔹 Sunday, Sun Jan 10 ([`Day 128`](../days/month-05/day-128-2027-01-10.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 2**: Advanced theorems, problem sets, and chalkboard proof defense.
* `[ ]` **Core (13:00–14:00)**: **Runtime Maintenance**: Quick 30–60 min check for `limbed` / `ggmbed` (`embed-runtimes`).
* `[ ]` **Core (15:00–16:45)**: **Penrose Sunday**: *The Road to Reality* (1 chapter/week, visual geometry focus).
* `[ ]` **Core (18:00–19:30)**: **Distributed Systems & IR Track**: **IIR Ch 8** (Evaluation in Information Retrieval: Precision, Recall, MAP, NDCG, MRR & Benchmarks).
* `[ ]` **Core (19:30–21:00)**: **Graduate Systems & GPU Architecture Lab**: Microarchitecture analysis and CUDA exercises in **Kirk & Hwu Ch 11** (Atomic operations, lock-free queues in GPU memory & memory fence semantics).
* `⭐ Optional / Stretch`: 21:00 onwards Weekly review & recovery.

### 🔹 Monday, Mon Jan 11 ([`Day 129`](../days/month-05/day-129-2027-01-11.md))
* `[ ]` **Core**: Implement PyTorch `BlockTable` data structure mapping logical sequence tokens to physical GPU memory pages (block size 16).
* `⭐ Optional / Stretch`: Simulate KV cache memory fragmentation under random sequence length arrivals (verify $>60\%$ memory savings).


### 🔹 Tuesday, Tue Jan 12 ([`Day 130`](../days/month-05/day-130-2027-01-12.md))
* `[ ]` **Core**: Implement PagedAttention CUDA kernel resolving physical $K, V$ block pointers on-the-fly via block table during attention decoding.
* `⭐ Optional / Stretch`: Add support for variable sequence lengths in a single batched kernel launch.


### 🔹 Wednesday, Wed Jan 13 ([`Day 131`](../days/month-05/day-131-2027-01-13.md))
* `[ ]` **Core**: Build unified `GpuIndex` wrapper managing device memory lifecycle, async streams, and RAII cleanup.
* `⭐ Optional / Stretch`: Design a PolarQuant 3-bit KV compression sketch storing quantized $K$ cache blocks inside the PagedAttention block table.


### 🔹 Thursday, Thu Jan 14 ([`Day 132`](../days/month-05/day-132-2027-01-14.md))
* `[ ]` **Core**: Implement heterogeneous CPU+GPU fallback pipeline: retain hot dataset in GPU VRAM and overflow in host RAM; merge top-$k$ results.
* `⭐ Optional / Stretch`: Measure end-to-end query latency as a function of GPU VRAM partition fraction (0% to 100%).


### 🔹 Friday, Fri Jan 15 ([`Day 133`](../days/month-05/day-133-2027-01-15.md))
* `[ ]` **Core**: Benchmark query batch sizes $B \in [1, 1000]$; plot CPU AVX2 vs GPU latency crossover curve.
* `⭐ Optional / Stretch`: Compute the exact QPS break-even point where GPU throughput justifies PCIe transfer latency overhead.


---

## ⛔ What NOT to Overspend Time On (Week 19 Time Traps)

* ❌ **Do NOT** implement dynamic memory defragmentation compaction algorithms—block paging naturally eliminates internal and external fragmentation.
* ❌ **Do NOT** build a full LLM serving scheduler with continuous batching—focus strictly on the `BlockTable` address resolution kernel.
* ❌ **Do NOT** solve advanced hypothesis testing Neyman-Pearson lemma optimization problems by hand—understand Type I/II error trade-offs and move on.

---

## Benchmark Close

Before the Friday article or release, save the run manifest and raw JSON/CSV, add one meaningful parameter sweep and plot, update the comparable README result row, and state the oracle result plus one evidence-backed conclusion. Record results below the noise floor as inconclusive.

## 📝 Weekend Deliverables

### ✍️ Technical Essay 19 (Drafted Friday 06:30–08:30)
* **Title**: *"Virtual Memory for Attention: Paged KV Blocks and Extreme PolarQuant 3-Bit Compression"*
* **Target File**: `~/personal/goals/essays/essay_19.md`
* **5-Part Structure**:
  1. **Mathematical Foundation**: Core theorems, derivations, and formal definitions.
  2. **The Systems Bottleneck**: Hardware limitation (memory bandwidth, port contention, cache line splits, warp stalls).
  3. **The Engine Architecture**: Exact data structures and SIMD/CUDA kernel design implemented in `secan`.
  4. **Empirical Benchmarks**: Perf counter tables, latency percentiles ($p50/p95/p99$), and QPS curves.
  5. **Key Takeaway**: Architectural rule of thumb for production AI systems.

### 🧠 Deep Learning Track (Tue/Wed 06:30–08:30 Morning Builder)
* **Task**: 

### 🔬 Empirical Systems & Benchmarking Focus (Mon/Thu 06:30–08:30 Morning Builder)
* **Focus**: The Online Max Reduction Invariant & In-SRAM Accumulation Mechanics
* **Workspace**: `research/2027-01-cagra-warp-search/`
* **Artifact Target**: Empirical benchmark and profiling data feeding into Friday's technical articles.
