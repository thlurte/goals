# 🚀 Week 16 Execution Playbook

> **Theme**: VS Spine Capstone — GPU IVF + DiskANN + Hybrid WAND  
> **Calendar Dates**: Sat Dec 19 – Fri Dec 25 (2026-12-19 to 2026-12-25)
> **Parent Month Dashboard**: [Month 4 (Dec 2026)](month-04-dec.md) · **Block**: I — Vector Search Engine

| | | |
|:---|:---|:---|
| [← Week 15](week-15.md) | [Month 4 (Dec 2026) Dashboard](month-04-dec.md) | [Week 17 →](week-17.md) |

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
| **Saturday** | Sat Dec 19 | [`Day 106`](../days/month-04/day-106-2026-12-19.md) | **09:00–13:00**: Pure Math Block 1 (Theory & Derivations) | **15:00–16:30**: Literature Sanctuary | **18:00–19:30**: Information Theory (Cover & Thomas) · **19:30–21:00**: Thought Leadership (Richard P. Feynman) · **21:00+**: Free / Rest|
| **Sunday** | Sun Dec 20 | [`Day 107`](../days/month-04/day-107-2026-12-20.md) | **09:00–13:00**: Pure Math Block 2 (Problem Sets & Proofs) | **13:00**: Maint · **15:00**: Penrose | **18:00–19:30**: Dist Systems (IIR Ch 5) · **19:30–21:00**: Systems Lab (Kirk & Hwu Ch 7) |
| **Monday** | Mon Dec 21 | [`Day 108`](../days/month-04/day-108-2026-12-21.md) | Faiss GPU 2019 §1–3: billion-scale GPU similarity search. | **Hardware Profiling & Benchmark Sweeps** | **secan**: GPU IVF memory layout: coarse centroids; cell vectors + offset table. |
| **Tuesday** | Tue Dec 22 | [`Day 109`](../days/month-04/day-109-2026-12-22.md) | Faiss GPU §4–5: GPU $k$-selection, warp-cooperative list scanning. | **DL Track (Part 1): Architecture & Tensor Shapes** | **secan**: GPU coarse quantizer + top-`nprobe` cell select; warp-cooperative cell scan. |
| **Wednesday** | Wed Dec 23 | [`Day 110`](../days/month-04/day-110-2026-12-23.md) | **CUDA-GUIDE Streams & Events**. | **DL Track (Part 2): Training Loop & Verification** | **secan**: CUDA stream pipelining for IVF batches; quick SQ8-in-cell stretch if time. Tag `v1.1-gpu-ivf`. |
| **Thursday** | Thu Dec 24 | [`Day 111`](../days/month-04/day-111-2026-12-24.md) | DiskANN: **Vamana graph construction** (α-prune) + `io_uring` fetch. | **DL / Vector Retrieval Integration & Profiling** | **secan (required)**: Implement **Vamana prune** (build graph, not only SSD fetch); compressed vectors in RAM; FP32 via `io_uring`. Recall vs in-RAM. |
| **Friday** | Fri Dec 25 | [`Day 112`](../days/month-04/day-112-2026-12-25.md) | Ding & Suel WAND; **RRF** (Cormack et al.). | **Weekly Technical Article: Drafting & Publishing** | **secan (required)**: BM25 + Block-Max WAND; fuse via **RRF** *and* linear $\alpha$. Query-time $\alpha$ / k sweep. SPLADE = stretch. Tag `v1.2-vs-spine-complete`. |

---

## 📋 Daily Action Items & Deliverables (Week 16)

### 🔹 Saturday, Sat Dec 19 ([`Day 106`](../days/month-04/day-106-2026-12-19.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 1**: Theory, concepts, and analytical derivations (Markov/Chebyshev/Cantelli, WLLN, CLT, **Gaussian Comparison Inequalities: Slepian's Lemma, Sudakov–Fernique**, and **Gordon's Escape Through a Mesh**).
* `[ ]` **Core (15:00–16:30)**: **Weekend Reading Sanctuary**: Literature / Philosophy deep reading.
* `[ ]` **Core (18:00–19:30)**: **Information Theory Track**: Thomas M. Cover & Joy A. Thomas, *Elements of Information Theory* (Reading & Notes).
* `[ ]` **Core (19:30–21:00)**: **Thought Leadership Masterclass**: Richard P. Feynman, *Feynman Lectures on Computation* — **Ch 5: Quantum Mechanical Computers** (Quantum Superposition Amplitudes, Unitary Operators, Quantum Logic Gates, Spin Measurement Systems).
* `⭐ Optional / Stretch`: 21:00 onwards 100% Free / Rest.

### 🔹 Sunday, Sun Dec 20 ([`Day 107`](../days/month-04/day-107-2026-12-20.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 2**: Advanced theorems, problem sets, and chalkboard proof defense (Multivariate Gaussians, Sample Covariance, **Wigner Semicircle Law**, **Marchenko–Pastur Law for $\mathbf{S} = \frac{1}{N}\mathbf{X}^T\mathbf{X}$**, and **Regularized Covariance Whitening**).
* `[ ]` **Core (13:00–14:00)**: **Runtime Maintenance**: Quick 30–60 min check for `limbed` / `ggmbed` (`embed-runtimes`).
* `[ ]` **Core (15:00–16:45)**: **Penrose Sunday**: *The Road to Reality* (1 chapter/week, visual geometry focus).
* `[ ]` **Core (18:00–19:30)**: **Distributed Systems & IR Track**: **IIR Ch 5** (Index Compression: Heaps' Law, Zipf's Law, Variable Byte & $\gamma$-Encoding).
* `[ ]` **Core (19:30–21:00)**: **Graduate Systems & GPU Architecture Lab**: Microarchitecture analysis and CUDA exercises in **Kirk & Hwu Ch 7** (Parallel reduction algorithms: tree reduction vs warp shuffle divergence minimization).
* `⭐ Optional / Stretch`: 21:00 onwards Weekly review & recovery.

### 🔹 Monday, Mon Dec 21 ([`Day 108`](../days/month-04/day-108-2026-12-21.md))
* `[ ]` **Core**: Implement GPU IVF memory layout: store coarse centroids and jagged inverted list arrays with prefix sum offset table in device memory.
* `⭐ Optional / Stretch`: Implement zero-copy unified memory (`cudaMallocManaged`) coarse centroid lookup.


### 🔹 Tuesday, Tue Dec 22 ([`Day 109`](../days/month-04/day-109-2026-12-22.md))
* `[ ]` **Core**: Implement GPU coarse cell routing kernel finding top-`nprobe` nearest centroids followed by warp-cooperative inverted list scanning.
* `⭐ Optional / Stretch`: Profile warp divergence when inverted lists have non-uniform lengths; implement dynamic warp-balancing scheduler.


### 🔹 Wednesday, Wed Dec 23 ([`Day 110`](../days/month-04/day-110-2026-12-23.md))
* `[ ]` **Core**: Implement CUDA stream pipelining overlapping query upload, cell scan, and top-$k$ download. Tag `v1.1-gpu-ivf`.
* `⭐ Optional / Stretch`: Implement SQ8 integer quantization inside GPU IVF lists to double effective VRAM vector capacity.


### 🔹 Thursday, Thu Dec 24 ([`Day 111`](../days/month-04/day-111-2026-12-24.md))
* `[ ]` **Core**: Implement Vamana graph construction ($\alpha$-pruning heuristic); implement asynchronous out-of-core SSD vector fetch via Linux `io_uring` with `O_DIRECT` on **Deep10M** (~4 GB core verification dataset; full Deep1B staged for dedicated NVMe).
* `⭐ Optional / Stretch`: Benchmark `IORING_SETUP_SQPOLL` zero-syscall kernel polling + `IORING_REGISTER_BUFFERS` vs standard `io_uring_enter()` syscall submissions on NVMe random reads.


### 🔹 Friday, Fri Dec 25 ([`Day 112`](../days/month-04/day-112-2026-12-25.md))
* `[ ]` **Core**: Implement **SINDI (Sparse Inverted Index for Learned Sparse Vectors / SPLADE / BGE-M3)** with SIMD dot-product accumulation + BM25 inverted index with Block-Max WAND early termination; fuse dense ANN candidates with sparse scores via Reciprocal Rank Fusion (RRF). Tag `v1.2-vs-spine-complete`.
* `⭐ Optional / Stretch`: Compare retrieval quality (NDCG@10) of RRF rank fusion vs linear weighted score interpolation ($\alpha \cdot S_{\text{dense}} + (1-\alpha) \cdot S_{\text{sparse}}$) on BEIR.


---

## ⛔ What NOT to Overspend Time On (Week 16 Time Traps)

* ❌ **Do NOT** spend time fine-tuning large sparse encoders during systems blocks—use pre-computed SPLADE / BGE-M3 sparse vectors to benchmark SINDI and BM25 directly.
* ❌ **Do NOT** download and run full 400 GB Deep1B during weekday coding blocks—**Deep10M (~4 GB)** is the core proof of out-of-core `io_uring` execution; full Deep1B is strictly for high-capacity NVMe overnight runs.
* ❌ **Do NOT** build complex C++ REST server wrappers—keep `secan` exposed via `nanobind` and CLI.

---

## Benchmark Close

Before the Friday article or release, save the run manifest and raw JSON/CSV, add one meaningful parameter sweep and plot, update the comparable README result row, and state the oracle result plus one evidence-backed conclusion. Record results below the noise floor as inconclusive.

## 📝 Weekend Deliverables

### ✍️ Technical Essay 16 (Drafted Friday 06:30–08:30)
* **Title**: *"Closing the Vector Search Spine: GPU IVF Streaming, Vamana Graph Pruning, and Out-of-Core `io_uring`"*
* **Target File**: `~/personal/goals/essays/essay_16.md`
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

## ⚡  Embedding Engine Track (Week 16)
> **Weekly Focus**: *Month 4 Milestone: CUDA GPU Ingestion & secan Composition*

| Day | 23:00 – 00:00 Implementation Task |
|:---|:---|
| **Mon** | Direct GPU pointer handoff: pass cennan GPU embeddings directly to secan GPU IVF buffers. |
| **Tue** | Implement batch GPU inference server processing 10,000 queries per second. |
| **Wed** | Stress test multi-GPU memory balancing and CUDA stream concurrency. |
| **Thu** | Document GPU roofline analysis and memory bandwidth saturation graphs. |
| **Fri** | Milestone Release: Tag cennan v0.3-cuda-gpu and tag secan v0.4-gpu-ivf. |
