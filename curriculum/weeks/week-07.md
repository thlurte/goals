# 🚀 Week 07 Execution Playbook

> **Theme**: Matrix Calculus, Backpropagation Foundations, ScaNN Anisotropic Loss & FastScan  
> **Calendar Dates**: Sat Oct 17 – Fri Oct 23 (2026-10-17 to 2026-10-23)
> **Parent Month Dashboard**: [Month 2 (Oct 2026)](month-02-oct.md) · **Block**: I — Vector Search Engine

| | | |
|:---|:---|:---|
| [← Week 06](week-06.md) | [Month 2 (Oct 2026) Dashboard](month-02-oct.md) | [Week 08 →](week-08.md) |

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
| **Saturday** | Sat Oct 17 | [`Day 043`](../days/month-02/day-043-2026-10-17.md) | **09:00–13:00**: Pure Math Block 1 (Theory & Derivations) | **15:00–16:30**: Literature Sanctuary | **18:00–19:30**: Information Theory (Cover & Thomas) · **19:30–21:00**: Thought Leadership (Richard W. Hamming) · **21:00+**: Free / Rest|
| **Sunday** | Sun Oct 18 | [`Day 044`](../days/month-02/day-044-2026-10-18.md) | **09:00–13:00**: Pure Math Block 2 (Problem Sets & Proofs) | **13:00**: Maint · **15:00**: Penrose | **18:00–19:30**: Dist Systems (DDIA Ch 6) · **19:30–21:00**: Systems Lab (Gregg Ch 7) |
| **Monday** | Mon Oct 19 | [`Day 045`](../days/month-02/day-045-2026-10-19.md) | ScaNN Paper §1–3: MIPS error decomposition: why orthogonal error $e_\perp$ has 0 expectation while parallel error $e_\parallel$ degrades inner products. | **Hardware Profiling & Benchmark Sweeps** | **secan**: Implement **ScaNN Anisotropic Loss** in `ProductQuantizer`: penalize parallel error with weight $h=5.0$. Compare codebooks. |
| **Tuesday** | Tue Oct 20 | [`Day 046`](../days/month-02/day-046-2026-10-20.md) | **INTEL Intrinsics & AGNER-INST**: Deep dive into `_mm256_shuffle_epi8` (PSHUFB) semantics and port mapping. | **DL Track (Part 1): Architecture & Tensor Shapes** | **secan**: Implement **plain BQ** (`bit = val > 0`): Hamming via XOR+POPCNT. **Do not** implement RaBitQ yet (needs QR — Week 10). |
| **Wednesday** | Wed Oct 21 | [`Day 047`](../days/month-02/day-047-2026-10-21.md) | Faiss FastScan documentation & André et al. (2015) paper §1–3. | **DL Track (Part 2): Training Loop & Verification** | **secan**: Implement 4-bit PQ encoding ($k=16$ centroids per subspace, packing 2 codes per byte). |
| **Thursday** | Thu Oct 22 | [`Day 048`](../days/month-02/day-048-2026-10-22.md) | AGNER-INST: Study `VPSHUFB`, `VPADDB`, `VPUNPCKLBW` instruction latency and accumulation chains. | **DL / Vector Retrieval Integration & Profiling** | **secan**: Implement **FastScan kernel**: load 16 centroid distances into `__m128i` / `__m256i`. Execute table lookups **entirely in-register** via PSHUFB. |
| **Friday** | Fri Oct 23 | [`Day 049`](../days/month-02/day-049-2026-10-23.md) | **CSAPP §5.10–5.12**: Register spilling, store-load forwarding, pipeline limiting factors. | **Weekly Technical Article: Drafting & Publishing** | **secan (required)**: **OPQ** (rotate then PQ) *or* **residual PQ**. Compare Recall@10 vs plain PQ on SIFT. Asymmetric ADC remains FP32 query. *(DL: Sat Oct 18 MRL.)* |

---

## 📋 Daily Action Items & Deliverables (Week 07)

### 🔹 Saturday, Sat Oct 17 ([`Day 043`](../days/month-02/day-043-2026-10-17.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 1**: Theory, concepts, and analytical derivations (textbook chapters & core proofs).
* `[ ]` **Core (15:00–16:30)**: **Weekend Reading Sanctuary**: Literature / Philosophy deep reading.
* `[ ]` **Core (16:30–18:00)**: **Physical Break & Mental Decompression**: Walk, tea, and recovery.
* `[ ]` **Core (18:00–19:30)**: **Information Theory Track**: Thomas M. Cover & Joy A. Thomas, *Elements of Information Theory* — **Ch 7.1–7.4** (Channel Capacity & Symmetric Channels).
* `[ ]` **Core (19:30–21:00)**: **Thought Leadership Masterclass**: Richard W. Hamming, *The Art of Doing Science and Engineering* — **Ch 13–17: Insight, Filters & Simulation** (Formulas to Ideas ('The purpose of computing is insight, not numbers'), Digital Filters, Simulation).
* `⭐ Optional / Stretch`: 21:00 onwards 100% Free / Rest.

### 🔹 Sunday, Sun Oct 18 ([`Day 044`](../days/month-02/day-044-2026-10-18.md))
* `[ ]` **Core (09:00–13:00)**: **Pure Math Block 2**: Advanced theorems, problem sets, and chalkboard proof defense.
* `[ ]` **Core (13:00–14:00)**: **Runtime Maintenance**: Quick 30–60 min check for `limbed` / `ggmbed` (`embed-runtimes`).
* `[ ]` **Core (15:00–16:45)**: **Penrose Sunday**: *The Road to Reality* (1 chapter/week, visual geometry focus).
* `[ ]` **Core (18:00–19:30)**: **Distributed Systems & IR Track**: **DDIA Ch 6** (Partitioning / Sharding: Key-Range vs Hash Partitioning & Vector Sharding Strategies).
* `[ ]` **Core (19:30–21:00)**: **Graduate Systems & GPU Architecture Lab**: Microarchitecture analysis and CUDA exercises in **Gregg Ch 7** (Memory bus saturation, TLB reach, huge pages (`madvise`) & zero-copy memory mapping).
* `⭐ Optional / Stretch`: 21:00 onwards Weekly review & recovery.

### 🔹 Monday, Mon Oct 19 ([`Day 045`](../days/month-02/day-045-2026-10-19.md))
* `[ ]` **Core**: Implement ScaNN anisotropic loss in `ProductQuantizer` with parallel penalty weight $h=5.0$.
* `⭐ Optional / Stretch`: Sweep $h \in [1.0, 10.0]$ on 768-D text embeddings to find optimal MIPS Recall@10 vs $h$.


### 🔹 Tuesday, Tue Oct 20 ([`Day 046`](../days/month-02/day-046-2026-10-20.md))
* `[ ]` **Core**: Implement plain Binary Quantization (`_mm256_movemask_ps`) with Hamming distance via `_mm_popcnt_u64`.
* `⭐ Optional / Stretch`: Benchmark SIMD popcount (`_mm512_popcnt_epi64` / AVX-512 VPOPCNTDQ) vs hardware instruction `popcnt`.


### 🔹 Wednesday, Wed Oct 21 ([`Day 047`](../days/month-02/day-047-2026-10-21.md))
* `[ ]` **Core**: Implement 4-bit PQ codebook generator ($k=16$ centroids per subspace, packing 2 codes per byte).
* `⭐ Optional / Stretch`: Analyze code distribution uniformity across the 16 centroid buckets to detect subspace collapse.


### 🔹 Thursday, Thu Oct 22 ([`Day 048`](../days/month-02/day-048-2026-10-22.md))
* `[ ]` **Core**: Implement AVX2 FastScan kernel executing 16-centroid distance lookups **entirely in-register** via `_mm256_shuffle_epi8` (PSHUFB).
* `⭐ Optional / Stretch`: Measure L1 cache read bandwidth during FastScan to prove table lookups do not hit cache memory.


### 🔹 Friday, Fri Oct 23 ([`Day 049`](../days/month-02/day-049-2026-10-23.md))
* `[ ]` **Core**: Implement Optimized Product Quantization (OPQ) orthogonal rotation matrix $R$ before PQ (compute $R$ via numerical Orthogonal Procrustes / SVD rotation matrix in offline codebook training); benchmark Recall@10 vs plain PQ on SIFT.
* `⭐ Optional / Stretch`: Implement residual PQ (2-stage PQ where stage 2 quantizes stage 1 residual error vector).


---

## ⛔ What NOT to Overspend Time On (Week 07 Time Traps)

* ❌ **Do NOT** try to derive the analytical SVD eigensolver from first principles this week—use numerical Orthogonal Procrustes (`scipy.linalg.orthogonal_procrustes` or a minimal 2x2 Jacobi rotation) to compute the OPQ rotation matrix $R$ (first-principles SVD theory lands in Month 3).
* ❌ **Do NOT** hand-write assembly for PSHUFB—use intrinsic `_mm256_shuffle_epi8`.
* ❌ **Do NOT** implement RaBitQ this week—RaBitQ relies on Householder reflections and QR decomposition (scheduled for Week 10).
* ❌ **Do NOT** spend time proving classical 3D fluid or physical vector theorems (Stokes/Divergence)—all physics vector calculus has been purged in favor of neural network matrix calculus.
* ❌ **Do NOT** write a custom matrix optimizer for OPQ—a basic alternating least squares (ALS) rotation or residual PQ is 100% fine.

---

## 📝 Weekend Deliverables

### ✍️ Technical Essay 07 (Drafted Friday 06:30–08:30)
* **Title**: *"Anisotropic Loss and In-Register SIMD Lookups: Directional Error Weighting and FastScan PSHUFB"*
* **Target File**: `~/personal/goals/essays/essay_07.md`
* **5-Part Structure**:
  1. **Mathematical Foundation**: Core theorems, derivations, and formal definitions.
  2. **The Systems Bottleneck**: Hardware limitation (memory bandwidth, port contention, cache line splits, warp stalls).
  3. **The Engine Architecture**: Exact data structures and SIMD/CUDA kernel design implemented in `secan`.
  4. **Empirical Benchmarks**: Perf counter tables, latency percentiles ($p50/p95/p99$), and QPS curves.
  5. **Key Takeaway**: Architectural rule of thumb for production AI systems.

### 🧠 Deep Learning Track (Tue/Wed 06:30–08:30 Morning Builder)
* **Task**: **🧠 DL Builder Track (Tue/Wed)**: MRL nested dims on tiny corpus.

### 🔬 Empirical Systems & Benchmarking Focus (Mon/Thu 06:30–08:30 Morning Builder)
* **Focus**: Geometry-Aware Anisotropic Polar Quantization: The Adaptive Ellipsoidal Lattice & Unbiased QJL Proof
* **Workspace**: `research/2026-10-anisotropic-quantization/`
* **Artifact Target**: Empirical benchmark and profiling data feeding into Friday's technical articles.
