# 🚀 Week 06 Execution Playbook

> **Theme**: Lagrange Multipliers, Multiple Integrals, Jacobians & BERT from Scratch  
> **Calendar Dates**: Mon Oct 6 – Sun Oct 12 (2026-10-06 to 2026-10-12)  
> **Parent Month Dashboard**: [Month 2 (Oct 2026)](month-02-oct.md) · **Block**: I — Vector Search Engine

| | | |
|:---|:---|:---|
| [← Week 05](week-05.md) | [Month 2 (Oct 2026) Dashboard](month-02-oct.md) | [Week 07 →](week-07.md) |

---

## ⏰ Daily Operational Rhythm

```
┌──────────────────────────────┬────────────────────────────────────────────────────────────────────────┐
│ Time Slot                    │ Focus / Activity                                                       │
├──────────────────────────────┼────────────────────────────────────────────────────────────────────────┤
│ 📖 05:30 – 06:30 (60 min)    │ Systems & Architecture Deep Reading (Papers & Microarchitecture)       │
│ 🛠️ 06:30 – 08:30 (120 min)   │ Morning Builder Track (DL / Monthly Research / Technical Essays)        │
│ ☀️ Daytime                   │ Professional Workday (Full focus, zero math fatigue)                   │
│ 💻 20:30 – 23:00 (2.5 hrs)   │ Night Hands-On Implementation (secan C++20 / CUDA flow state)          │
├──────────────────────────────┼────────────────────────────────────────────────────────────────────────┤
│ 📐 Saturday 09:00 – 13:00    │ Pure Mathematics Block 1 (Theory, Concepts, Derivations)               │
│ 🧘 Saturday 14:00 – 18:00    │ 100% FREE / Rest / Personal Time / Buffer                              │
│ 📐 Sunday 09:00 – 13:00      │ Pure Mathematics Block 2 (Problem Sets, Chalkboard Proofs)             │
│ 🔧 Sunday 13:00 – 14:00      │ Runtime Maintenance (limbed / ggmbed check)                            │
│ 🧘 Sunday 14:00 – 18:00      │ 100% FREE / Rest / Personal Time / Buffer                              │
└──────────────────────────────┴────────────────────────────────────────────────────────────────────────┘
```

---

## 📅 Day-by-Day Master Timetable

| Day | Date | Daily Runbook | Systems Reading (05:30–06:30) | Morning Builder Track (06:30–08:30) | Night Hands-On C++/CUDA (20:30–23:00) |
|:---|:---|:---|:---|:---|:---|
| **Monday** | Mon Oct 6 | [`Day 036`](../days/month-02/day-036-2026-10-06.md) | Research paper: *"Product Quantization for Nearest Neighbor Search"* (Jégou et al. 2011) §1–4. | **Monthly Research: Planning & Literature Synthesis** | **secan**: Implement $k$-means clustering in C++ for a subspace: `train_kmeans(data, k=256, dim_sub)` using $k$-means++. |
| **Tuesday** | Tue Oct 7 | [`Day 037`](../days/month-02/day-037-2026-10-07.md) | Faiss wiki on Product Quantizer: subspace splitting, codebook memory layouts. | **DL Track (Part 1): Architecture & Tensor Shapes** | **secan**: Implement `ProductQuantizer`: split $D$ dimensions into $M$ subspaces. Train $M$ codebooks. Encode vectors as $M$-byte codes. |
| **Wednesday** | Wed Oct 8 | [`Day 038`](../days/month-02/day-038-2026-10-08.md) | **AGNER Ch 7.10 & Ch 9**: Array structures for cache-friendly table lookups, stride optimization. | **DL Track (Part 2): Training Loop & Verification** | **secan**: Implement Asymmetric Distance Computation (ADC): precompute query-to-centroid table `float LUT[M][256]`. Distance = sum of $M$ lookups. |
| **Thursday** | Thu Oct 9 | [`Day 039`](../days/month-02/day-039-2026-10-09.md) | **PIKUS Ch 10**: Compiler optimizations, `__restrict__`, loop vectorization, Link-Time Optimization (LTO). | **Monthly Research: Sweeps & Data Logging** | **secan**: **Asymmetric BQ**: FP32 query vs 1-bit db (Hamming / IP estimator). Keep query in FP32. |
| **Friday** | Fri Oct 10 | [`Day 040`](../days/month-02/day-040-2026-10-10.md) | **PIKUS Ch 11**: Undefined behavior, memory aliasing. | **Technical Essay: Lab-Note Drafting** | **secan (required)**: Wire **IVF + PQ ADC** sketch (`IVFPQIndex` stub): coarse IVF then PQ inside lists. Recall vs IVFFlat on SIFT subset. **Compose, do not stop at PQ-only.** *(DL InfoNCE: Sat Oct 11.)* |
| **Saturday** | Sat Oct 11 | [`Day 041`](../days/month-02/day-041-2026-10-11.md) | **09:00–13:00**: Pure Math Block 1 (Theory & Derivations) | **14:00–18:00**: FREE / Rest / Buffer | Weekend Deep Work |
| **Sunday** | Sun Oct 12 | [`Day 042`](../days/month-02/day-042-2026-10-12.md) | **09:00–13:00**: Pure Math Block 2 (Problem Sets & Proofs) | **13:00–14:00**: Maintenance | Rest & Buffer |

---

## 📋 Daily Action Items & Deliverables (Week 06)

### 🔹 Monday, Mon Oct 6 ([`Day 036`](../days/month-02/day-036-2026-10-06.md))
* `[ ]` **Core**: Implement $k$-means clustering in C++ with $k$-means++ centroid seeding for a single subspace.
* `⭐ Optional / Stretch`: Implement multi-threaded parallel $k$-means Lloyd iteration across CPU cores.

### 🔹 Tuesday, Tue Oct 7 ([`Day 037`](../days/month-02/day-037-2026-10-07.md))
* `[ ]` **Core**: Implement `ProductQuantizer` ($D \to M$ subspaces, $M \times 256$ codebooks); encode $N$ vectors into $N \times M$ bytes.
* `⭐ Optional / Stretch`: Measure quantization distortion $\|x - \tilde{x}\|^2$ as a function of subspace count $M \in \{8, 16, 32, 64\}$.

### 🔹 Wednesday, Wed Oct 8 ([`Day 038`](../days/month-02/day-038-2026-10-08.md))
* `[ ]` **Core**: Implement Asymmetric Distance Computation (`float LUT[M][256]`); compute query distances via $M$ byte lookups.
* `⭐ Optional / Stretch`: Implement 4-way unrolled ADC distance loop accumulating 4 database vectors simultaneously into registers.

### 🔹 Thursday, Thu Oct 9 ([`Day 039`](../days/month-02/day-039-2026-10-09.md))
* `[ ]` **Core**: Implement asymmetric 1-bit Binary Quantization (FP32 query dot product with 1-bit binary codes).
* `⭐ Optional / Stretch`: Derive the exact expectation of inner-product error under 1-bit quantization for isotropic Gaussian vectors.

### 🔹 Friday, Fri Oct 10 ([`Day 040`](../days/month-02/day-040-2026-10-10.md))
* `[ ]` **Core**: Wire `IVFPQIndex` composed index (coarse IVF centroids + PQ ADC inside inverted lists); benchmark Recall@10 on SIFT subset.
* `⭐ Optional / Stretch`: Compare memory footprint and search latency of IVFFlat vs IVFPQ (e.g. 128 bytes/vector vs 16 bytes/vector).

### 🔹 Saturday, Sat Oct 11 ([`Day 041`](../days/month-02/day-041-2026-10-11.md))
* `[ ]` **Core (09:00–13:00)**: Write and ship **Technical Essay 6**: *"Constrained Optimization and Subspace Codebooks: Lagrange Multipliers in Product Quantization"* to `goals/essays/essay_06.md`.
* `[ ]` **Core (14:00–18:00)**: Execute Saturday Deep Learning from Scratch track (**🧠 DL weekend**: BERT + InfoNCE + **in-batch negatives**; export 768-D `.fvecs`. **Also**: implement `AdamW` optimizer from scratch ($m_t, v_t$ moment estimates, bias correction, **weight decay decoupling** from L2 reg). Train BERT with your AdamW; verify loss curve matches `torch.optim.AdamW`. **Hard negative mining**: retrieve BM25 top-100 per query, sample hard negatives from rank 10–100 for InfoNCE training.).
* `⭐ Optional / Stretch`: Run automated test suite validating PyTorch numerical gradient and attention equivalence.

### 🔹 Sunday, Sun Oct 12 ([`Day 042`](../days/month-02/day-042-2026-10-12.md))
* `[ ]` **Core (09:00–13:00)**: Execute Monthly Research Milestone for Month 2 (`research/2026-10-anisotropy-hubness-bits/`): run empirical benchmarks and record data tables.
* `⭐ Optional / Stretch`: Draft / update section figures and experimental limitations.

---

## ⛔ What NOT to Overspend Time On (Week 06 Time Traps)

* ❌ **Do NOT** train PQ codebooks on all 1M vectors—subsample 50,000 to 100,000 vectors for codebook training.
* ❌ **Do NOT** implement symmetric PQ distance computation (SDC)—asymmetric ADC (FP32 query vs PQ codes) is strictly superior for query accuracy.
* ❌ **Do NOT** build a custom multi-threading pool for PQ encoding—standard `std::jthread` or OpenMP parallel loop is sufficient.

---

## 📝 Weekend Deliverables

### ✍️ Technical Essay 06 (Saturday 09:00–13:00)
* **Title**: *"Constrained Optimization and Subspace Codebooks: Lagrange Multipliers in Product Quantization"*
* **Target File**: `~/personal/goals/essays/essay_06.md`
* **5-Part Structure**:
  1. **Mathematical Foundation**: Core theorems, derivations, and formal definitions.
  2. **The Systems Bottleneck**: Hardware limitation (memory bandwidth, port contention, cache line splits, warp stalls).
  3. **The Engine Architecture**: Exact data structures and SIMD/CUDA kernel design implemented in `secan`.
  4. **Empirical Benchmarks**: Perf counter tables, latency percentiles ($p50/p95/p99$), and QPS curves.
  5. **Key Takeaway**: Architectural rule of thumb for production AI systems.

### 🧠 Deep Learning Track (Saturday 14:00–18:00)
* **Task**: **🧠 DL weekend**: BERT + InfoNCE + **in-batch negatives**; export 768-D `.fvecs`. **Also**: implement `AdamW` optimizer from scratch ($m_t, v_t$ moment estimates, bias correction, **weight decay decoupling** from L2 reg). Train BERT with your AdamW; verify loss curve matches `torch.optim.AdamW`. **Hard negative mining**: retrieve BM25 top-100 per query, sample hard negatives from rank 10–100 for InfoNCE training.

### 🔬 Monthly Research Milestone (Sunday 09:00–13:00)
* **Paper**: *"Anisotropy-Aware Vector Quantization: Dissecting the Interplay Between Embedding Cones, Hubness, and Quantization Loss Functions"*
* **Workspace**: `research/2026-10-anisotropy-hubness-bits/`
* **Publish Deadline**: **Sun Oct 25**
