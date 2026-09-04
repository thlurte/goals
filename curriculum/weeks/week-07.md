# 🚀 Week 07 Execution Playbook

> **Theme**: Matrix Calculus, Backpropagation Foundations, ScaNN Anisotropic Loss & FastScan  
> **Calendar Dates**: Mon Oct 13 – Sun Oct 19 (2026-10-13 to 2026-10-19)  
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
| **Monday** | Mon Oct 13 | [`Day 043`](../days/month-02/day-043-2026-10-13.md) | ScaNN Paper §1–3: MIPS error decomposition: why orthogonal error $e_\perp$ has 0 expectation while parallel error $e_\parallel$ degrades inner products. | **Monthly Research: Planning & Literature Synthesis** | **secan**: Implement **ScaNN Anisotropic Loss** in `ProductQuantizer`: penalize parallel error with weight $h=5.0$. Compare codebooks. |
| **Tuesday** | Tue Oct 14 | [`Day 044`](../days/month-02/day-044-2026-10-14.md) | **INTEL Intrinsics & AGNER-INST**: Deep dive into `_mm256_shuffle_epi8` (PSHUFB) semantics and port mapping. | **DL Track (Part 1): Architecture & Tensor Shapes** | **secan**: Implement **plain BQ** (`bit = val > 0`): Hamming via XOR+POPCNT. **Do not** implement RaBitQ yet (needs QR — Week 10). |
| **Wednesday** | Wed Oct 15 | [`Day 045`](../days/month-02/day-045-2026-10-15.md) | Faiss FastScan documentation & André et al. (2015) paper §1–3. | **DL Track (Part 2): Training Loop & Verification** | **secan**: Implement 4-bit PQ encoding ($k=16$ centroids per subspace, packing 2 codes per byte). |
| **Thursday** | Thu Oct 16 | [`Day 046`](../days/month-02/day-046-2026-10-16.md) | AGNER-INST: Study `VPSHUFB`, `VPADDB`, `VPUNPCKLBW` instruction latency and accumulation chains. | **Monthly Research: Sweeps & Data Logging** | **secan**: Implement **FastScan kernel**: load 16 centroid distances into `__m128i` / `__m256i`. Execute table lookups **entirely in-register** via PSHUFB. |
| **Friday** | Fri Oct 17 | [`Day 047`](../days/month-02/day-047-2026-10-17.md) | **CSAPP §5.10–5.12**: Register spilling, store-load forwarding, pipeline limiting factors. | **Technical Essay: Lab-Note Drafting** | **secan (required)**: **OPQ** (rotate then PQ) *or* **residual PQ**. Compare Recall@10 vs plain PQ on SIFT. Asymmetric ADC remains FP32 query. *(DL: Sat Oct 18 MRL.)* |
| **Saturday** | Sat Oct 18 | [`Day 048`](../days/month-02/day-048-2026-10-18.md) | **09:00–13:00**: Pure Math Block 1 (Theory & Derivations) | **14:00–18:00**: FREE / Rest / Buffer | Weekend Deep Work |
| **Sunday** | Sun Oct 19 | [`Day 049`](../days/month-02/day-049-2026-10-19.md) | **09:00–13:00**: Pure Math Block 2 (Problem Sets & Proofs) | **13:00–14:00**: Maintenance | Rest & Buffer |

---

## 📋 Daily Action Items & Deliverables (Week 07)

### 🔹 Monday, Mon Oct 13 ([`Day 043`](../days/month-02/day-043-2026-10-13.md))
* `[ ]` **Core**: Implement ScaNN anisotropic loss in `ProductQuantizer` with parallel penalty weight $h=5.0$.
* `⭐ Optional / Stretch`: Sweep $h \in [1.0, 10.0]$ on 768-D text embeddings to find optimal MIPS Recall@10 vs $h$.

### 🔹 Tuesday, Tue Oct 14 ([`Day 044`](../days/month-02/day-044-2026-10-14.md))
* `[ ]` **Core**: Implement plain Binary Quantization (`_mm256_movemask_ps`) with Hamming distance via `_mm_popcnt_u64`.
* `⭐ Optional / Stretch`: Benchmark SIMD popcount (`_mm512_popcnt_epi64` / AVX-512 VPOPCNTDQ) vs hardware instruction `popcnt`.

### 🔹 Wednesday, Wed Oct 15 ([`Day 045`](../days/month-02/day-045-2026-10-15.md))
* `[ ]` **Core**: Implement 4-bit PQ codebook generator ($k=16$ centroids per subspace, packing 2 codes per byte).
* `⭐ Optional / Stretch`: Analyze code distribution uniformity across the 16 centroid buckets to detect subspace collapse.

### 🔹 Thursday, Thu Oct 16 ([`Day 046`](../days/month-02/day-046-2026-10-16.md))
* `[ ]` **Core**: Implement AVX2 FastScan kernel executing 16-centroid distance lookups **entirely in-register** via `_mm256_shuffle_epi8` (PSHUFB).
* `⭐ Optional / Stretch`: Measure L1 cache read bandwidth during FastScan to prove table lookups do not hit cache memory.

### 🔹 Friday, Fri Oct 17 ([`Day 047`](../days/month-02/day-047-2026-10-17.md))
* `[ ]` **Core**: Implement Optimized Product Quantization (OPQ) orthogonal rotation matrix $R$ before PQ (compute $R$ via numerical Orthogonal Procrustes / SVD rotation matrix in offline codebook training); benchmark Recall@10 vs plain PQ on SIFT.
* `⭐ Optional / Stretch`: Implement residual PQ (2-stage PQ where stage 2 quantizes stage 1 residual error vector).

### 🔹 Saturday, Sat Oct 18 ([`Day 048`](../days/month-02/day-048-2026-10-18.md))
* `[ ]` **Core (09:00–13:00)**: Write and ship **Technical Essay 7**: *"Anisotropic Loss and In-Register SIMD Lookups: Directional Error Weighting and FastScan PSHUFB"* to `goals/essays/essay_07.md`.
* `[ ]` **Core (14:00–18:00)**: Execute Saturday Deep Learning from Scratch track (**🧠 DL weekend**: MRL nested dims on tiny corpus.).
* `⭐ Optional / Stretch`: Run automated test suite validating PyTorch numerical gradient and attention equivalence.

### 🔹 Sunday, Sun Oct 19 ([`Day 049`](../days/month-02/day-049-2026-10-19.md))
* `[ ]` **Core (09:00–13:00)**: Execute Monthly Research Milestone for Month 2 (`research/2026-10-anisotropy-hubness-bits/`): run empirical benchmarks and record data tables.
* `⭐ Optional / Stretch`: Draft / update section figures and experimental limitations.

---

## ⛔ What NOT to Overspend Time On (Week 07 Time Traps)

* ❌ **Do NOT** try to derive the analytical SVD eigensolver from first principles this week—use numerical Orthogonal Procrustes (`scipy.linalg.orthogonal_procrustes` or a minimal 2x2 Jacobi rotation) to compute the OPQ rotation matrix $R$ (first-principles SVD theory lands in Month 3).
* ❌ **Do NOT** hand-write assembly for PSHUFB—use intrinsic `_mm256_shuffle_epi8`.
* ❌ **Do NOT** implement RaBitQ this week—RaBitQ relies on Householder reflections and QR decomposition (scheduled for Week 10).
* ❌ **Do NOT** spend time proving classical 3D fluid or physical vector theorems (Stokes/Divergence)—all physics vector calculus has been purged in favor of neural network matrix calculus.
* ❌ **Do NOT** write a custom matrix optimizer for OPQ—a basic alternating least squares (ALS) rotation or residual PQ is 100% fine.

---

## 📝 Weekend Deliverables

### ✍️ Technical Essay 07 (Saturday 09:00–13:00)
* **Title**: *"Anisotropic Loss and In-Register SIMD Lookups: Directional Error Weighting and FastScan PSHUFB"*
* **Target File**: `~/personal/goals/essays/essay_07.md`
* **5-Part Structure**:
  1. **Mathematical Foundation**: Core theorems, derivations, and formal definitions.
  2. **The Systems Bottleneck**: Hardware limitation (memory bandwidth, port contention, cache line splits, warp stalls).
  3. **The Engine Architecture**: Exact data structures and SIMD/CUDA kernel design implemented in `secan`.
  4. **Empirical Benchmarks**: Perf counter tables, latency percentiles ($p50/p95/p99$), and QPS curves.
  5. **Key Takeaway**: Architectural rule of thumb for production AI systems.

### 🧠 Deep Learning Track (Saturday 14:00–18:00)
* **Task**: **🧠 DL weekend**: MRL nested dims on tiny corpus.

### 🔬 Monthly Research Milestone (Sunday 09:00–13:00)
* **Paper**: *"Anisotropy-Aware Vector Quantization: Dissecting the Interplay Between Embedding Cones, Hubness, and Quantization Loss Functions"*
* **Workspace**: `research/2026-10-anisotropy-hubness-bits/`
* **Publish Deadline**: **Sun Oct 25**
