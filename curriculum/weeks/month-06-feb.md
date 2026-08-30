# Month 6 — Feb (Weeks 21–24)

> Part of the [28-week curriculum](../README.md). Research: [`research/`](../../research/README.md).

| | |
|:---|:---|
| [← Month 5 — Jan](month-05-jan.md) | [Month 7 — Mar →](month-07-mar.md) |

---

# 📅 MONTH 6: Optimization, Spectral Graphs, Production Hardening & Master Release (Feb 2027)

> **🔬 Monthly research**: *Mitigating Recall Collapse in Filtered Approximate Nearest Neighbor Graphs: An Empirical Evaluation of ACORN vs. Iterative Post-Filtering Across Selectivity Spectrums* → publish **Sun Feb 28** · folder `research/2027-02-predicate-aware-graphs/`

---

### Week 21 (Jan 19–23): Convex Optimization, KKT, ColPali GPU Path

**Theme**: Convex optimization / KKT, ColPali multimodal retrieval, and **Week 15 FA-2 catch-up (Wed)**.

* **Pure Mathematics (Boyd & Vandenberghe - *Convex Optimization*)**: Convex sets/functions, duality, KKT.
* **C++ Engine (`secan`)**: GPU MaxSim (CUTLASS); GPU NN-Descent. **ColPali CLIP projector = Sat Jan 24.** FA-2 = Week 25.

| Day | Pure Mathematics (Boyd Convex Optimization) (90 min) | GPU / CUDA Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Jan 19** | **CONVEX §2.1–2.4**: Convex sets: affine sets, convex combinations, convex hulls, cones, hyperplanes, and Euclidean balls. | Re-read ColBERT/PLAID papers with GPU focus: mapping MaxSim to batched GEMM + reductions. | **secan**: Implement **GPU MaxSim kernel**: CUTLASS GEMM + warp row-max + column-sum. |
| **Tue Jan 20** | **CONVEX §3.1–3.4**: Convex functions: first/second-order conditions, Jensen. | CLIP / SigLIP contrastive alignment (image encoder ↔ text encoder). | **secan**: GPU MaxSim polish / fused pipeline. *(CLIP projector: Sat Jan 24.)* |
| **Wed Jan 21** | **CONVEX §4.1–4.4**: Convex optimization problems: LP, QP, SOCP. | NN-Descent / CAGRA neighbor exchange. | **secan**: GPU NN-Descent base-layer graph construction. **FA-2 → Week 25.** |
| **Thu Jan 22** | **CONVEX §5.1–5.4**: Duality: Lagrangian, weak/strong duality, Slater. | CAGRA / NN-Descent GPU neighbor exchange. | **secan**: GPU NN-Descent base-layer graph construction. |
| **Fri Jan 23** | **CONVEX §5.5**: KKT conditions: necessity and sufficiency for convex problems. | Review GPU ColBERT / ColPali integration. | **secan**: Ingest ColPali visual embeddings; text query → visual page search. **Stretch**: same tokens through MUVERA FDE + IP MIPS. |

> **📝 Essay 21 (Sat Jan 24)**: *"Duality and Multimodal Retrieval: Karush-Kuhn-Tucker Conditions, CLIP Alignment, and ColPali MaxSim"*  
> **🧠 DL weekend**: CLIP-style projector + ColPali head.

---

### Week 22 (Jan 26–30): Production Hardening — ACORN, Tombstones & NUMA

**Theme**: Filtered search as an **on-call product**: pre- vs post-filter, range predicates, ACORN, deletes, NUMA.

* **C++ Engine (`secan`)** — required:
  1. Pre-filter vs post-filter vs **ACORN**; **range** (`price < x`); selectivity vs recall
  2. Tombstone + vacuum
  3. NUMA pin

| Day | Systems Math (90 min) | Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Jan 26** | Filter selectivity $P(\text{pass})$; **post-filter recall collapse**. | Payload/B-tree + ANN; pre- vs post-filter. | **secan (required)**: Payload index (B-tree or sorted ids) + **pre-filter** candidate set; **post-filter** HNSW; plot recall vs selectivity. |
| **Tue Jan 27** | ACORN $N$-hop vs connectivity under filters. | ACORN paper §1–6. | **secan**: ACORN-style filtered graph search; compare to Mon's pre/post. |
| **Wed Jan 28** | Tombstone amortization vs vacuum. | Lock-free bitset / graph mutation. | **secan**: Tombstones + vacuum rewires. |
| **Thu Jan 29** | NUMA / PCIe budget. | `libnuma`; DiskANN under NUMA. | **secan**: NUMA pin; re-bench. |
| **Fri Jan 30** | Range predicates vs boolean bitmaps. | Production checklist. | **secan (required)**: **Range filter** (`payload < x`) on pre-filter path; smoke tests. Tag `v1.5-production`. |

> **📝 Essay 22 (Sat Jan 31)**: *"Graph Disconnection and Selectivity Cliffs: ACORN Predicate Subgraphs vs Post-Filtering"*  
> **🚀 Month 5 research PUBLISH (Sun Jan 31)**: freeze `research/2027-01-paging-vs-quantizing-kv/paper.md` + public post.

---

### Week 23 (Feb 2–6): Spectral Graph Theory, Cheeger's Inequality & ARM NEON

**Theme**: Spectral graph theory, Cheeger's inequality, ARM NEON SIMD, and cross-platform portability.

* **Pure Mathematics (Spectral Graph Theory - Fan Chung / Spielman)**:
  * Normalized Graph Laplacian $\mathcal{L} = D^{-1/2} L D^{-1/2} = I - D^{-1/2} A D^{-1/2}$.
  * Eigenvalues of Normalized Laplacian: $0 = \lambda_1 \leq \lambda_2 \leq \dots \leq \lambda_n \leq 2$. Multiplicity of $\lambda=0$ equals number of connected components.
  * **Cheeger's Inequality**: $\frac{\lambda_2}{2} \leq h(G) \leq \sqrt{2\lambda_2}$, where $h(G)$ is the Cheeger isoperimetric constant (conductance of the graph). Rigorous connection between spectral gap and graph bottleneck cuts.
* **C++ Engine (`secan`)**: ARM NEON distance kernels (`float32x4_t`, `vfmaq_f32`, `vaddvq_f32`), compile-time and runtime CPU feature detection (`cpuid`), cross-platform CMake CI.

| Day | Pure Mathematics (Spectral Graph Theory) (90 min) | Systems / ARM Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Feb 2** | **SPECTRAL §1.1–1.3**: The Graph Laplacian $L = D - A$ revisited. Quadratic form $x^T L x = \sum_{(u, v) \in E} (x_u - x_v)^2$. Proof that $L$ is positive semidefinite. | ARM NEON Intrinsics Guide: `vld1q_f32`, `vfmaq_f32`, `vaddvq_f32`, `vmaxvq_f32`. | **secan**: Design unified SIMD abstraction layer: `namespace simd { float l2_squared(const float*, const float*, int); }` with dispatch. |
| **Tue Feb 3** | **SPECTRAL §1.4–1.6**: The Normalized Graph Laplacian $\mathcal{L} = I - D^{-1/2} A D^{-1/2}$. Bounds on eigenvalues ($0 \leq \lambda_i \leq 2$), bipartiteness and $\lambda_n = 2$. | ARM NEON programming manual: 128-bit vector types (`float32x4_t`, `uint8x16_t`), FMA instruction throughput. | **secan**: Implement `l2_squared_neon()` and `cosine_distance_neon()` using ARM NEON intrinsics with 4-way accumulator unrolling. |
| **Wed Feb 4** | **SPECTRAL §2.1–2.3**: Graph cuts and Conductance (Cheeger constant) $h(G) = \min_{S \subset V} \frac{|\partial S|}{\min(\text{vol}(S), \text{vol}(S^c))}$. | **AGNER Ch 14**: Cross-platform optimization, compiler-specific intrinsics differences. | **secan**: Implement NEON integer kernels: `l2_squared_sq8_neon()` and `cosine_distance_sq8_neon()`. |
| **Thu Feb 5** | **SPECTRAL §2.4**: Cheeger's Inequality: Rigorous proof connecting the spectral gap $\lambda_2$ to the conductance $h(G)$ via Fiedler vector sweep cuts. | Research: runtime CPU dispatch patterns in Faiss and HNSWLib (`platform_macros.h`). | **secan**: Implement runtime CPU feature detection: `cpuid` on x86, `/proc/cpuinfo` / `sysctl` on ARM. Configure dynamic dispatch. |
| **Fri Feb 6** | **SPECTRAL §3.1**: Expander graphs: Spectral expansion vs edge expansion. Why Ramanujan graphs have optimal small-world routing properties. | Set up cross-platform CI matrix: Ubuntu x86_64, macOS Apple Silicon (ARM64). | **secan**: Verify builds and tests on x86_64 and ARM64. |

> **📝 Essay 23 (Sat Feb 7)**: *"Spectral Graph Theory, Cheeger's Inequality, and Cross-Platform ARM NEON Optimization"*  
> **🧠 DL stretch**: Same Week 12 ONNX graph under ORT on an ARM host (parity with x86).

---

### Week 24 (Feb 9–13): Spectral Synthesis, CLI Scaffold & GPU Occupancy

**Theme**: Close Month 6 math; **do not** tag `v2.0` yet — GPU specialization still has March.

* **secan**: CLI scaffold + occupancy/`ncu` pass. Full release → Week 28.

| Day | Pure Mathematics (90 min) | Systems Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Feb 9** | Spectral + production recap (Cheeger, ACORN, tombstones). | **PIKUS Ch 12** retrospective. | **secan**: CLI scaffold `secan build/search/bench` (complete Week 28). |
| **Tue Feb 10** | Convexity recap: KKT complementary slackness. | Occupancy calculator / `__launch_bounds__`. | **CUDA**: Occupancy tune on IVF + graph kernels. |
| **Wed Feb 11** | Fourier skim (optional): convolution as GEMM intuition. | CUB/Thrust fusion notes. | **CUDA**: Fused distance+topk kernel (was former Week 22 GPU polish). |
| **Thu Feb 12** | Info-theory recap: CE = $H+D_{KL}$ (ties to InfoNCE). | `-Wall -Wextra -Wpedantic`. | **secan**: Warning cleanup; examples/ stubs. |
| **Fri Feb 13** | — | Month 6 paper freeze checklist. | **secan/CUDA**: Occupancy/`ncu` leftover polish. *(Naive KV re-bench: Saturday DL if needed.)* |

> **📝 Essay 24 (Sat Feb 14)**: *"Portable Vector Intrinsics and Production Graph Systems: Closing Block II Systems Hardening"*  
> **🚀 Month 6 research PUBLISH (Sun Feb 28)**: `research/2027-02-predicate-aware-graphs/paper.md` (use remaining Feb weekends).

---
