# 🚀 Week 18 Execution Playbook

> **Theme**: Markov Chains, Transition Matrices & GPU FastScan  
> **Calendar Dates**: Sat Jan 2 – Fri Jan 8 (2027-01-02 to 2027-01-08)
> **Parent Month Dashboard**: [Month 5 (Jan 2027)](month-05-jan.md) · **Block**: II — GPU Specialization

| | | |
|:---|:---|:---|
| [← Week 17](week-17.md) | [Month 5 (Jan 2027) Dashboard](month-05-jan.md) | [Week 19 →](week-19.md) |

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
| **Saturday** | Sat Jan 2 | [`Day 120`](../days/month-05/day-120-2027-01-02.md) | **09:00–13:00**: Pure Math Block 1 (Theory & Derivations) | **15:00–16:30**: Literature Sanctuary | **18:00–19:30**: Information Theory (Cover & Thomas) · **19:30–21:00**: Thought Leadership (Edwin T. Jaynes) · **21:00+**: Free / Rest|
| **Sunday** | Sun Jan 3 | [`Day 121`](../days/month-05/day-121-2027-01-03.md) | **09:00–13:00**: Pure Math Block 2 (Problem Sets & Proofs) | **13:00**: Maint · **15:00**: Penrose | **18:00–19:30**: Dist Systems (IIR Ch 7) · **19:30–21:00**: Systems Lab (Kirk & Hwu Ch 10) |
| **Monday** | Mon Jan 4 | [`Day 122`](../days/month-05/day-122-2027-01-04.md) | Faiss GPU PQ documentation: storing query lookup tables in GPU shared memory. | **Hardware Profiling & Benchmark Sweeps** | **secan**: Implement GPU PQ ADC kernel: upload query LUT to shared memory. Threads compute PQ distances via shared-memory lookups. |
| **Tuesday** | Tue Jan 5 | [`Day 123`](../days/month-05/day-123-2027-01-05.md) | **CUDA-GUIDE Shared Memory**: Bank conflicts, padding strategies, broadcast mechanisms. | **DL Track (Part 1): Architecture & Tensor Shapes** | **secan**: Optimize shared-memory LUT layout: apply padding to ensure conflict-free broadcast reads during distance accumulation. |
| **Wednesday** | Wed Jan 6 | [`Day 124`](../days/month-05/day-124-2027-01-06.md) | Research: GPU FastScan architecture using warp-level registers. | **DL Track (Part 2): Training Loop & Verification** | **secan**: Implement **GPU 4-bit FastScan**: store 16 centroid distances in warp registers. Execute lookups via `__shfl_sync(mask, dist, code)`. |
| **Thursday** | Thu Jan 7 | [`Day 125`](../days/month-05/day-125-2027-01-07.md) | E | **DL / Vector Retrieval Integration & Profiling** | }$ is the stationary distribution on an undirected graph with degree $d_i$. |
| **Friday** | Fri Jan 8 | [`Day 126`](../days/month-05/day-126-2027-01-08.md) | Review all GPU quantization kernels. | **Weekly Technical Article: Drafting & Publishing** | **secan**: Benchmark GPU-FP32 vs GPU-FP16 vs GPU-SQ8 vs GPU-IVF-PQ vs GPU-FastScan. Create comprehensive comparison table. |

---

## 📋 Daily Action Items & Deliverables (Week 18)

### 🔹 Saturday, Sat Jan 2 ([`Day 120`](../days/month-05/day-120-2027-01-02.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 1**: Theory, concepts, and analytical derivations (textbook chapters & core proofs).
* `[ ]` **Core (15:00–16:30)**: **Weekend Reading Sanctuary**: [Douglas Hofstadter, *Gödel, Escher, Bach: An Eternal Golden Braid*](https://www.basicbooks.com/titles/douglas-r-hofstadter/godel-escher-bach/9780465026562/) — **Ch 14: On Formally Undecidable Propositions of TNT**.
* `[ ]` **Core (16:30–18:00)**: **Physical Break & Mental Decompression**: Walk, tea, and recovery.
* `[ ]` **Core (18:00–19:30)**: **Information Theory Track**: [Thomas M. Cover & Joy A. Thomas, *Elements of Information Theory (2nd ed)*](https://www.wiley.com/en-us/Elements+of+Information+Theory%2C+2nd+Edition-p-9780471241959) — **Ch 12 (§12.1–12.5)** (Maximum Entropy, Max-Entropy Distributions, Spectrum Estimation & Burg's Theorem).
* `[ ]` **Core (19:30–21:00)**: **Thought Leadership Masterclass**: [Edwin T. Jaynes, *Probability Theory: The Logic of Science*](https://www.cambridge.org/core/books/probability-theory/9780521770347) — **Ch 3–4: Sampling Theory & Bayesian Hypothesis Testing** (Bayesian Evidence, Likelihood Ratios, and Multi-Hypothesis Discriminations).
* `⭐ Optional / Stretch`: 21:00 onwards 100% Free / Rest.

### 🔹 Sunday, Sun Jan 3 ([`Day 121`](../days/month-05/day-121-2027-01-03.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 2**: Advanced theorems, problem sets, and chalkboard proof defense.
* `[ ]` **Core (13:00–14:00)**: **Runtime Maintenance**: Quick 30–60 min check for `limbed` / `ggmbed` (`embed-runtimes`).
* `[ ]` **Core (15:00–16:45)**: **Penrose Sunday**: [Sir Roger Penrose, *The Road to Reality*](https://www.vintagebooks.com) — **Ch 13: Symmetry Groups** (Lie groups, Lie algebras, rotation group $SO(3)$, unitary group $SU(2)$, Lorentz group $SO(1,3)$.).
* `[ ]` **Core (18:00–19:30)**: **Distributed Systems & IR Track**: [Christopher D. Manning, Prabhakar Raghavan & Hinrich Schütze, *Introduction to Information Retrieval*](https://nlp.stanford.edu/IR-book/) — **IIR Ch 1–2** (Boolean Retrieval, Inverted Index Construction, Tokenization & Postings Lists).
* `[ ]` **Core (19:30–21:00)**: **Graduate Systems & GPU Architecture Lab**: [David B. Kirk & Wen-mei W. Hwu, *Programming Massively Parallel Processors (4th ed)*](https://www.elsevier.com/books/programming-massively-parallel-processors/kirk/978-0-323-91231-0) — **Kirk & Hwu Ch 6–7** (Performance Considerations & Parallel Patterns: Convolution & Constant Memory Caching).
* `⭐ Optional / Stretch`: 21:00 onwards Weekly review & recovery.

### 🔹 Monday, Mon Jan 4 ([`Day 122`](../days/month-05/day-122-2027-01-04.md))
* `[ ]` **Core**: Implement GPU PQ ADC kernel staging query centroid lookup tables ($M \times 256$ floats) in shared memory.
* `⭐ Optional / Stretch`: Derive the exact transition probability matrix of random walk beam search on a small $k$-regular graph.


### 🔹 Tuesday, Tue Jan 5 ([`Day 123`](../days/month-05/day-123-2027-01-05.md))
* `[ ]` **Core**: Optimize shared-memory LUT layout with stride padding; verify 0 shared-memory bank conflicts in `ncu`.
* `⭐ Optional / Stretch`: Benchmark shared memory broadcast efficiency when all 32 warp threads access the identical centroid entry.


### 🔹 Wednesday, Wed Jan 6 ([`Day 124`](../days/month-05/day-124-2027-01-06.md))
* `[ ]` **Core**: Implement GPU 4-bit FastScan storing 16 centroid distances across 16 warp registers; execute table lookups via `__shfl_sync(mask, dist, code)`.
* `⭐ Optional / Stretch`: Measure register pressure and warp occupancy trade-offs in GPU FastScan kernel.


### 🔹 Thursday, Thu Jan 7 ([`Day 125`](../days/month-05/day-125-2027-01-07.md))
* `[ ]` **Core**: Compose GPU IVF-PQ index (GPU coarse quantizer + GPU FastScan kernel inside selected cells).
* `⭐ Optional / Stretch`: Implement asynchronous batch cell scanning using multiple CUDA streams.


### 🔹 Friday, Fri Jan 8 ([`Day 126`](../days/month-05/day-126-2027-01-08.md))
* `[ ]` **Core**: Benchmark full suite: GPU-FP32 vs GPU-FP16 vs GPU-SQ8 vs GPU-IVF-PQ vs GPU-FastScan; produce comprehensive performance matrix.
* `⭐ Optional / Stretch`: Compute total memory bandwidth efficiency percentage against theoretical GPU VRAM bandwidth limit.


---

## ⛔ What NOT to Overspend Time On (Week 18 Time Traps)

* ❌ **Do NOT** implement 8-bit FastScan—4-bit FastScan fits 16 centroids directly in 16 warp registers for zero-shared-memory execution.
* ❌ **Do NOT** spend hours proving stationary distributions for continuous-state Markov processes—focus on finite discrete-state transition matrices.
* ❌ **Do NOT** tune codebook centroids on GPU—train codebooks offline on CPU/NumPy and upload final centroids to device memory.

---

## Benchmark Close

Before the Friday article or release, save the run manifest and raw JSON/CSV, add one meaningful parameter sweep and plot, update the comparable README result row, and state the oracle result plus one evidence-backed conclusion. Record results below the noise floor as inconclusive.

## 📝 Weekend Deliverables

### ✍️ Technical Essay 18 (Drafted Friday 06:30–08:30)
* **Title**: *"Markov Chains, Graph Random Walks, and High-Throughput GPU Quantized FastScan"*
* **Target File**: `~/personal/goals/essays/essay_18.md`
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


---

## ⚡  Embedding Engine Track (Week 18)
> **Weekly Focus**: *Vision Transformer (ViT / SigLIP) Backbone*

| Day | 23:00 – 00:00 Implementation Task |
|:---|:---|
| **Mon** | Implement ViT Encoder Block with Pre-LayerNorm and GELU activations in C++. |
| **Tue** | Implement Class Token ([CLS]) and Global Attention Pooling for single-vector visual representations. |
| **Wed** | Load pretrained SigLIP / CLIP vision weights via zero-copy mmap parser. |
| **Thu** | Benchmark vision forward pass latency across image resolutions (224x224, 384x384). |
| **Fri** | Validate visual embedding cosine similarity parity against HuggingFace transformers. |
