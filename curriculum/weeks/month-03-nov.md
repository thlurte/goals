# Month 3 — Nov (Weeks 9–12)

> Part of the [28-week curriculum](../README.md). Research: [`research/`](../../research/README.md).

| | |
|:---|:---|
| [← Month 2 — Oct](month-02-oct.md) | [Month 4 — Dec →](month-04-dec.md) |

---

# 📅 MONTH 3: Linear Algebra from First Principles, ColBERT & LSM-Trees (Nov 2026)

> **🔬 Monthly research**: *Streaming Late Interaction: Evaluating PLAID Centroid Inverted Lists vs MUVERA Fixed-Dimensional Encodings in Dynamic LSM Vector Storage* (+ **BEIR/MS MARCO slice**) → publish **Sun Nov 29** · folder `research/2026-11-late-interaction-lsm/`

---

### Week 9 (Oct 27–31): Vector Spaces, Four Fundamental Subspaces, ColBERT & SIMD MaxSim

**Theme**: Rigorous linear algebra (Strang Ch 1–2), ColBERT dual-encoder architecture, and SIMD MaxSim.

* **Pure Math (Gilbert Strang Linear Algebra Ch 1–2)**:
  * Linear combinations, dot products, length and angles in $\mathbb{R}^n$, matrix elimination, triangular factorizations $A = LU$.
  * Vector spaces and subspaces, the Nullspace $N(A)$, the Column space $C(A)$, linear independence, basis, dimension.
  * The Four Fundamental Subspaces and the Fundamental Theorem of Linear Algebra ($r = \text{rank}(A)$).
* **C++ Track**: **Batch HNSW build** Mon–Tue; SIMD MaxSim Wed–Fri. ColBERT Python = Sat Nov 1.

| Day | Pure Mathematics (Strang) (90 min) | Systems / C++ Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Oct 27** | **STRANG §1.1–1.6**: Vector geometry, matrix multiplication from 4 perspectives, Gaussian elimination, $LU$ factorization. | Research paper: *"ColBERT: Efficient and Effective Passage Search via Late Interaction"* (Khattab & Zaharia 2020). | **secan (required)**: **Batch HNSW build**: insert $N$ in one pass (level assignment + sequential connect). Compare build time vs one-by-one insert. |
| **Tue Oct 28** | **STRANG §2.1–2.2**: Vector spaces, column space $C(A)$, nullspace $N(A)$. | PLAID paper §1–4; HNSW bulk-construction notes. | **secan**: Parallel batch graph construction (shard-then-merge or lock-free insert). Measure Recall@10 vs sequential insert. |
| **Wed Oct 29** | **STRANG §2.3–2.4**: Linear independence, spanning sets, basis, dimension of vector spaces. Computing rank from echelon form. | **INTEL Intrinsics Guide**: Study `_mm256_max_ps`, `_mm256_permute2f128_ps`, cross-lane max reduction. | **secan**: Implement **SIMD-vectorized MaxSim kernel** in C++: process 8 document tokens in parallel with AVX2 FMA + horizontal max reduction. |
| **Thu Oct 30** | **STRANG §2.5–2.6**: The Four Fundamental Subspaces ($C(A), N(A), C(A^T), N(A^T)$). The Fundamental Theorem of Linear Algebra (Part 1). | **AGNER Ch 13**: Data parallelism, cache layout for multi-vector matrices. | **secan**: Build **token centroid index**: cluster document tokens into centroids ($C=32\text{K}$). Build inverted lists `centroid_id → (doc_id, token_idx)`. |
| **Fri Oct 31** | **STRANG §2.6**: Matrix rank and dimensions of the 4 subspaces: $\dim C(A) = \dim C(A^T) = r$, $\dim N(A) = n - r$, $\dim N(A^T) = m - r$. | Re-read PLAID paper §3 "Centroid Interaction" + §4 "Decompression and Scoring". | **secan**: Implement centroid candidate pruning: query tokens retrieve candidate documents from centroid inverted lists. Score candidates with MaxSim. |

> **📝 Essay 9 (Sat Nov 1)**: *"Beyond Single Vectors: The Linear Algebra, Matrix Decompositions, and SIMD Architecture of ColBERT Late Interaction"*  
> **🧠 DL weekend**: ColBERT dual encoder + MaxSim + tiny Margin MSE. **Knowledge distillation**: implement cross-encoder reranker score as teacher → distill into bi-encoder student (MSE on logits). Compare embedding quality vs Week 6 InfoNCE-only training.  
> **🔬 Month 3 Sundays**: BEIR or MS MARCO **slice** (dense + ColBERT MaxSim + **MUVERA** FDE candidates).

---

### Week 10 (Nov 3–7): Orthogonality, MUVERA FDEs, PLAID, RaBitQ & TurboQuant

**Theme**: Projections / $A=QR$; **MUVERA** reduces MaxSim to IP MIPS; PLAID is the cascade alternative; RaBitQ + TurboQuant 1@k.

* **Pure Math (Gilbert Strang Linear Algebra Ch 3)**:
  * Orthogonality of the four fundamental subspaces ($C(A^T) \perp N(A)$ and $C(A) \perp N(A^T)$).
  * Projections onto lines and subspaces, Projection Matrix $P = A(A^T A)^{-1} A^T$ ($P^2 = P, P^T = P$).
  * Least squares approximations, normal equations $A^T A \hat{x} = A^T b$.
  * Orthonormal bases, Gram-Schmidt orthogonalization process, $A = QR$ factorization.
* **Queuing Theory (light)**: Poisson load generator = **Week 11 stretch** (deep $M/M/k$ in Month 4).
* **MUVERA** ([NeurIPS 2024](https://arxiv.org/abs/2405.19504)): asymmetric **Fixed Dimensional Encodings** so $\langle \mathrm{FDE}(Q), \mathrm{FDE}(P) \rangle$ approximates Chamfer/MaxSim; retrieve with Week 4/8 **IP** index; re-rank with exact MaxSim. Same family as asymmetric PQ (FP32 query vs compressed db).
* **Frontier compression**: [TurboQuant](https://research.google/blog/turboquant-redefining-ai-efficiency-with-extreme-compression/) — PolarQuant + QJL. **1@k Fri required.**
* **C++ Track**: **MUVERA Mon–Tue**; **PLAID 3-stage Wed**; **RaBitQ Thu**; **TurboQuant Fri**.
  * **Deferred (required Week 16 Fri)**: BM25, WAND, **RRF**.

| Day | Pure Mathematics (Strang) (90 min) | Systems / C++ Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Nov 3** | **STRANG §3.1**: Orthogonal vectors, orthogonal subspaces. Proving row space is orthogonal to nullspace in $\mathbb{R}^n$. | [MUVERA](https://arxiv.org/abs/2405.19504) §1–3: FDE construction, SimHash buckets, **asymmetric** query vs doc encode. | **secan (required)**: `fde_encode` — hash tokens into $B$ buckets, per-bucket aggregate, $R$ repetitions. Query FDE $\neq$ doc FDE. |
| **Tue Nov 4** | **STRANG §3.2**: Projection onto a 1D line: $P = \frac{a a^T}{a^T a}$. Cauchy-Schwarz from projection error. | MUVERA §4–5: FDE MIPS + MaxSim re-rank; candidate count vs heuristics. | **secan (required)**: Index doc FDEs with **IP** HNSW or IVF (Week 4/8). Retrieve then **MaxSim re-rank**. Plot Recall vs candidates vs Week 9 centroid prune. |
| **Wed Nov 5** | **STRANG §3.3**: Projection onto a subspace; $A^T A \hat{x} = A^T b$. | PLAID §3–5: centroid → quantized MaxSim → FP32. | **secan (required)**: **PLAID 3-stage** (2/4-bit residual MaxSim). Same slice: PLAID vs MUVERA candidate efficiency. Poisson load gen = stretch. |
| **Thu Nov 6** | **STRANG §3.4**: Orthonormal $Q$, Gram-Schmidt, $A = QR$. | RaBitQ: random orthogonal + error correction. **PIKUS Ch 8** concurrency skim. | **secan**: QR rotation helper + **RaBitQ**. Recall vs plain BQ (Week 7). |
| **Fri Nov 7** | **STRANG §3.4**: Least squares via QR: $\hat{x} = R^{-1} Q^T b$. | [TurboQuant](https://research.google/blog/turboquant-redefining-ai-efficiency-with-extreme-compression/): PolarQuant + QJL; 1@k vs PQ/RaBitQ. | **secan (required)**: **TurboQuant/PolarQuant or QJL 1@k** vs RaBitQ vs PQ on **GloVe-200 or 768-D**. Plot Recall@1. |

> **📝 Essay 10 (Sat Nov 8)**: *"Orthogonal Projections and Fixed-Dimensional Encodings: Reducing ColBERT MaxSim to MIPS via MUVERA"*

---

### Week 11 (Nov 10–14): Determinants, Eigenvalues, Spectral Theorem & LSM-Tree Engine

**Theme**: Determinants, eigenvalues, the Spectral Theorem, and LSM-Tree storage (DiskANN = stretch).

* **Pure Math (Gilbert Strang Linear Algebra Ch 4–5)**:
  * Determinants: 3 fundamental properties, algebraic formulas, cofactors, Cramer's rule.
  * Eigenvalues and Eigenvectors: $\det(A - \lambda I) = 0$, trace and determinant formulas, matrix diagonalization $A = S \Lambda S^{-1}$.
  * Symmetric Matrices: Proof that eigenvalues are all real and eigenvectors are orthogonal. The Spectral Theorem $A = Q \Lambda Q^T$.
* **Storage Engine Internals**: LSM-Tree for vectors: WAL, mutable MemTable HNSW, immutable disk segments (Arrow/Lance layout), background compaction.
* **C++ Engine (`secan`)**: `LSMVectorEngine` core this week. **DiskANN + `io_uring` = required Week 16 Thu**. **ACORN = Week 22**.

| Day | Pure Mathematics (Strang) (90 min) | Systems / C++ Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Nov 10** | **STRANG §4.1–4.4**: Determinants: axiomatic definition (linearity, sign change, $\det I = 1$), cofactor expansions, formula for $A^{-1}$. | Research paper: *"DiskANN: Fast Accurate Billion-point NN Search on a Single Node"* (Subramanya et al. 2019) — architecture skim (**build Week 16 Thu**). | **secan**: Implement `WriteAheadLog` (`wal.bin`) and in-memory mutable `MemTable` (dynamic HNSW absorbing live writes). |
| **Tue Nov 11** | **STRANG §5.1–5.2**: Eigenvalues and eigenvectors: characteristic polynomial $\det(A - \lambda I) = 0$. Matrix diagonalization $S^{-1} A S = \Lambda$. | Apache Arrow / Lance columnar layout notes for segment files. | **secan**: Implement Segment Flusher: when MemTable reaches threshold, flush to immutable disk segment (flat Arrow/Lance layout). |
| **Wed Nov 12** | **STRANG §5.3–5.4**: Systems of differential equations $\frac{du}{dt} = Au$, matrix exponential $e^{At}$, stability of linear dynamical systems. | Linux `io_uring` tutorial: SQ/CQ basics (**implement Week 16 Thu**). | **secan**: Background compaction: merge **segments and HNSW graphs** (not only LSM files). Rebuild/compact graph edges after merge. |
| **Thu Nov 13** | **STRANG §5.5**: Real symmetric matrices: proof that eigenvalues are real and eigenvectors are orthogonal. The Spectral Theorem $A = Q \Lambda Q^T$. | **ASYNC Ch 6 & Ch 9**: Boost.Asio I/O concepts, profiling asynchronous workflows. | **secan**: Concurrent search-while-ingest smoke test. **Stretch**: Poisson load gen ($p50/p95/p99$) moved from Week 10. Add ThreadSanitizer CI job. |
| **Fri Nov 14** | **STRANG §5.6**: Positive definite matrices: tests via eigenvalues, pivots, determinants, and energy $x^T A x > 0$. Cholesky factorization $A = L L^T$. | **FINSY Ch 3**: High-performance system measurement, scaling modules, latency distributions. | **secan**: Crash-recovery test: kill process mid-write; verify WAL replay restores MemTable. Benchmark inserts/sec under search traffic. |

> **📝 Essay 11 (Sat Nov 15)**: *"Eigenvalues, Spectral Decompositions, and LSM Storage Engines: Write-Ahead Logs and Vector Compaction"*

---

### Week 12 (Nov 17–21): SVD, Whitening, Composed Indexes & Pareto vs Faiss

**Theme**: SVD / query-side PCA, HNSW heap opts, **`IVFPQIndex` + `HNSWSQIndex`**, Pareto vs Faiss. **Sat: ONNX→ORT dense encode path.**

* **Pure Math**: Strang Ch 6 (unchanged).
* **C++ Engine (`secan`)**: Whitening / query PCA; Week 8 heap catch-up; **compose IVF-PQ and HNSW-SQ**; Pareto vs Faiss/hnswlib. **No REST.** nanobind + CLI.
* **DL (Sat Nov 22)**: InfoNCE bi-encoder → ONNX → ORT → `.fvecs` → `secan` (parity required).

| Day | Pure Mathematics (Strang) (90 min) | Systems / Architecture Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Nov 17** | **STRANG §6.3**: SVD: $A = U \Sigma V^T$. | Query-side PCA / OPQ literature. | **secan**: **Whitening + query-side PCA**. Hubness $S_{N_k}$ before/after. |
| **Tue Nov 18** | **STRANG §6.3**: Truncated SVD / Eckart–Young. | **PIKUS Ch 6**: RW locks. | **secan**: `nanobind` + CLI: expose `HNSWIndex`, **`IVFPQIndex`**, **`HNSWSQIndex`**, `LSMIndex`. |
| **Wed Nov 19** | **STRANG §6.7**: PCA. | Branchless heap; bitset visited. | **secan (required)**: Bounded flat heap + **bitset visited**. Then concurrent HNSW locks. |
| **Thu Nov 20** | **STRANG §6.7**: Matrix norms, $\kappa(A)$. | `ann-benchmarks` protocol (required, not stretch). | **secan (required)**: Finish **`IVFPQIndex`** (IVF + PQ ADC + optional OPQ). Recall–QPS vs **Faiss IVFPQ** on SIFT. |
| **Fri Nov 21** | **PURE LINALG SYNTHESIS**: Strang Ch 1–6. | hnswlib SQ / Faiss HNSW+SQ notes. | **secan (required)**: **`HNSWSQIndex`** (HNSW over SQ8/SQ4). Pareto vs **hnswlib/Faiss** on **SIFT + 768-D**. Tag `v1.0-cpu-complete`. |

> **📝 Essay 12 (Sat Nov 22)**: *"Singular Value Decomposition and Composed Vector Indexes: Pareto Evaluation of IVF-PQ and HNSW-SQ vs Faiss"*  
> **🧠 DL weekend (required)**: Export Week 6 InfoNCE bi-encoder with `torch.onnx.export` (dynamic batch). Run **ONNX Runtime** `InferenceSession`; max abs / cosine error vs PyTorch on a fixed batch. Emit 768-D query/doc `.fvecs` via ORT and re-ingest into `HNSWSQIndex` / `IVFPQIndex` — confirm Recall@10 matches the Week 8 Fri PyTorch path within tolerance. **No** onnxruntime C++ inside `secan` (nanobind + ORT Python is enough). ColBERT ONNX = stretch later.

---
