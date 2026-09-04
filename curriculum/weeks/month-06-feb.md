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

#### 📋 Daily Action Items & Optional Activities (Week 21)
* **Mon Jan 19**:
  * `[ ]` **Core**: Implement GPU MaxSim kernel in CUTLASS computing batched GEMM followed by warp row-max and column-sum reduction.
  * `⭐ Optional / Stretch`: Derive the dual formulation of token alignment under convex regularized transportation costs.
* **Tue Jan 20**:
  * `[ ]` **Core**: Fuse GPU MaxSim query scoring and candidate document filtering into a single CUDA pipeline.
  * `⭐ Optional / Stretch`: Benchmark latency vs batch size for single-page visual tokens (1030 tokens per image page).
* **Wed Jan 21**:
  * `[ ]` **Core**: Implement GPU NN-Descent base-layer $k$-NN graph construction algorithm exchanging neighbor candidates across thread blocks.
  * `⭐ Optional / Stretch`: Measure convergence speed (graph recall vs iteration count) on 100K embedding vectors.
* **Thu Jan 22**:
  * `[ ]` **Core**: Implement 2-opt edge pruning heuristic in GPU NN-Descent graph construction.
  * `⭐ Optional / Stretch`: Verify Slater's condition for constrained graph sparsification optimization problems.
* **Fri Jan 23**:
  * `[ ]` **Core**: Ingest ColPali multimodal embeddings (text query $\to$ multi-vector document pages); evaluate visual search Recall@10.
  * `⭐ Optional / Stretch`: Route ColPali visual multi-vectors through MUVERA FDEs for instant 1-stage MIPS candidate retrieval.

#### ⛔ What NOT to Overspend Time On (Time Traps)
* ❌ **Do NOT** write a custom vision transformer model in C++—run ColPali image embeddings generation in Python/PyTorch.
* ❌ **Do NOT** optimize GPU NN-Descent beyond 10-15 iterations—NN-Descent achieves $>98\%$ $k$-NN graph quality quickly.
* ❌ **Do NOT** spend hours proving convex duality theorems for non-linear constraints—focus on KKT conditions for linear/quadratic programs.

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

#### 📋 Daily Action Items & Optional Activities (Week 22)
* **Mon Jan 26**:
  * `[ ]` **Core**: Implement metadata payload index (B-tree / sorted IDs); compare pre-filtering vs post-filtering; reproduce recall collapse at selectivity $< 1\%$.
  * `⭐ Optional / Stretch`: Derive the exact probability of graph search disconnection under Bernoulli predicate selection $p$.
* **Tue Jan 27**:
  * `[ ]` **Core**: Implement ACORN $N$-hop predicate-aware graph routing traversing predicate-satisfying subgraphs.
  * `⭐ Optional / Stretch`: Measure ACORN Recall@10 retention across low-selectivity regimes ($0.1\%$ to $5\%$) vs standard HNSW.
* **Wed Jan 28**:
  * `[ ]` **Core**: Implement soft vector deletion via atomic bitset tombstones; implement background graph vacuum rewiring neighbor edges.
  * `⭐ Optional / Stretch`: Measure graph routing degradation as tombstone percentage increases from 0% to 30% before vacuuming.
* **Thu Jan 29**:
  * `[ ]` **Core**: Pin memory allocations and worker threads to specific NUMA nodes using `libnuma` (`numa_alloc_onnode`).
  * `⭐ Optional / Stretch`: Measure cross-socket QPI/UPI interconnect traffic during high-concurrency multi-threaded queries.
* **Fri Jan 30**:
  * `[ ]` **Core**: Implement numeric range filtering (`timestamp >= t0 AND price < p1`) integrated into graph traversal. Tag `v1.5-production`.
  * `⭐ Optional / Stretch`: Implement Roaring Bitmaps for high-performance set operations on high-cardinality discrete payload tags.

#### ⛔ What NOT to Overspend Time On (Time Traps)
* ❌ **Do NOT** implement full SQL query parsing—simple metadata attribute dictionaries (`key == value`, `key < threshold`) cover 100% of filtering needs.
* ❌ **Do NOT** rebuild the entire HNSW graph on every deletion—use atomic bitset tombstones and periodic asynchronous vacuuming.
* ❌ **Do NOT** worry if your development machine is single-socket—simulate NUMA policies with `numactl --interleave` or `numactl --cpunodebind`.

> **📝 Essay 22 (Sat Jan 31)**: *"Graph Disconnection and Selectivity Cliffs: ACORN Predicate Subgraphs vs Post-Filtering"*  
> **🚀 Month 5 research PUBLISH (Sun Jan 31)**: freeze `research/2027-01-paging-vs-quantizing-kv/paper.md` + public post.

---

### Week 23 (Feb 2–6): Spectral Graph Theory, Cheeger's Inequality & ARM NEON

**Theme**: Spectral graph theory, Cheeger's inequality, ARM NEON SIMD, and cross-platform portability.

* **Pure Mathematics (Spectral Graph Theory - Fan Chung / Spielman)**:
  * Normalized Graph Laplacian $\mathcal{L} = D^{-1/2} L D^{-1/2} = I - D^{-1/2} A D^{-1/2}$.
  * Eigenvalues of Normalized Laplacian: $0 = \lambda_1 \leq \lambda_2 \leq \dots \leq \lambda_n \leq 2$. Multiplicity of $\lambda=0$ equals number of connected components.
  * **Cheeger's Inequality**: $\frac{\lambda_2}{2} \leq h(G) \leq \sqrt{2\lambda_2}$, where $h(G)$ is the Cheeger isoperimetric constant (conductance of the graph). Rigorous connection between spectral gap and graph bottleneck cuts.
* **C++ Engine (`secan`)**: ARM NEON distance kernels (FP32 `vfmaq_f32`, Native FP16 `vfmaq_f16`, SQ8 `vdotq_u32`, 4-bit FastScan `vqtbl1q_u8`, 1-bit BQ `vcntq_u8`), compile-time and runtime CPU feature detection (`getauxval`), cross-platform CMake CI.

| Day | Pure Mathematics (Spectral Graph Theory) (90 min) | Systems / ARM Reading (45 min) | Afternoon Implementation (2.5 hrs) |
|:---|:---|:---|:---|
| **Mon Feb 2** | **SPECTRAL §1.1–1.3**: The Graph Laplacian $L = D - A$ revisited. Quadratic form $x^T L x = \sum_{(u, v) \in E} (x_u - x_v)^2$. Proof that $L$ is positive semidefinite. | ARM NEON Intrinsics Guide: `vld1q_f32`, `vfmaq_f32`, `vaddvq_f32`, `vmaxvq_f32`. | **secan**: Design unified SIMD abstraction layer: `namespace simd { float l2_squared(const float*, const float*, int); }` with dispatch. |
| **Tue Feb 3** | **SPECTRAL §1.4–1.6**: The Normalized Graph Laplacian $\mathcal{L} = I - D^{-1/2} A D^{-1/2}$. Bounds on eigenvalues ($0 \leq \lambda_i \leq 2$), bipartiteness and $\lambda_n = 2$. | ARM NEON programming manual: 128-bit vector types (`float32x4_t`, `float16x8_t`), FMA instruction throughput. | **secan**: Implement `l2_squared_neon()` and `cosine_distance_neon()` using ARM NEON intrinsics with 4-way accumulator unrolling. |
| **Wed Feb 4** | **SPECTRAL §2.1–2.3**: Graph cuts and Conductance (Cheeger constant) $h(G) = \min_{S \subset V} \frac{|\partial S|}{\min(\text{vol}(S), \text{vol}(S^c))}$. | **AGNER Ch 14**: Cross-platform optimization, compiler-specific intrinsics differences. | **secan**: Implement NEON integer & quantized kernels: SQ8 `vdotq_u32`, FastScan `vqtbl1q_u8`, and BQ `vcntq_u8`. |
| **Thu Feb 5** | **SPECTRAL §2.4**: Cheeger's Inequality: Rigorous proof connecting the spectral gap $\lambda_2$ to the conductance $h(G)$ via Fiedler vector sweep cuts. | Research: runtime CPU dispatch patterns in Faiss and HNSWLib (`platform_macros.h`). | **secan**: Implement runtime CPU feature detection: `cpuid` on x86, `/proc/cpuinfo` / `sysctl` on ARM. Configure dynamic dispatch. |
| **Fri Feb 6** | **SPECTRAL §3.1**: Expander graphs: Spectral expansion vs edge expansion. Why Ramanujan graphs have optimal small-world routing properties. | Set up cross-platform CI matrix: Ubuntu x86_64, macOS Apple Silicon (ARM64). | **secan**: Verify builds and tests on x86_64 and ARM64. |

#### 📋 Daily Action Items & Optional Activities (Week 23)
* **Mon Feb 2**:
  * `[ ]` **Core**: Design unified SIMD abstraction namespace with compile-time and runtime dispatch architecture.
  * `⭐ Optional / Stretch`: Compute the spectrum (all eigenvalues) of the normalized Laplacian on an HNSW graph component.
* **Tue Feb 3**:
  * `[ ]` **Core**: Implement ARM NEON FP32 distance kernels (`l2_squared_neon`, `cosine_distance_neon`) with 4-way unrolling.
  * `⭐ Optional / Stretch`: Implement native ARMv8.2-A FP16 distance kernel `l2_squared_fp16_neon` using `float16x8_t` and `vfmaq_f16`; benchmark on Apple Silicon / Jetson Orin.
* **Wed Feb 4**:
  * `[ ]` **Core**: Implement ARM NEON integer quantized kernels (`l2_squared_sq8_neon`, `cosine_distance_sq8_neon`) using `vdotq_u32` (dot product instructions).
  * `⭐ Optional / Stretch`: Implement ARM NEON FastScan 4-bit LUT kernel using `vqtbl1q_u8` and NEON 1-bit Hamming popcount using `vcntq_u8`.
* **Thu Feb 5**:
  * `[ ]` **Core**: Implement runtime CPU capability probe (`cpuid` on x86, `getauxval` on Linux ARM, `sysctlbyname` on macOS); configure automatic dynamic function pointers.
  * `⭐ Optional / Stretch`: Write a microbenchmark measuring dispatch function pointer overhead vs direct inlined function call.
* **Fri Feb 6**:
  * `[ ]` **Core**: Configure GitHub Actions / local cross-platform CI matrix building and running test suite on x86_64 and ARM64.
  * `⭐ Optional / Stretch`: Validate bitwise floating-point score equivalence across x86 AVX2 and ARM NEON kernels.

#### ⛔ What NOT to Overspend Time On (Time Traps)
* ❌ **Do NOT** write manual assembly for ARM NEON—compiler intrinsics (`arm_neon.h`) generate clean instructions.
* ❌ **Do NOT** spend days attempting exact Cheeger constant calculations on 1M node graphs (it is NP-hard)—use Fiedler sweep-cut approximations.
* ❌ **Do NOT** support ancient instruction sets (SSE2, MMX)—focus strictly on modern AVX2, AVX-512, and ARM NEON.

> **📝 Essay 23 (Sat Feb 7)**: *"Spectral Bottlenecks and Cross-Platform SIMD: Cheeger's Inequality, Graph Conductance, and ARM NEON Portability"*

---

### Week 24 (Feb 9–13): Spectral Synthesis, CLI Scaffold & GPU Occupancy

**Theme**: Close Month 6 math; **do not** tag `v2.0` yet — GPU specialization still has March.

* **secan**: CLI scaffold + occupancy/`ncu` pass. Full release → Week 28.

| Day | Systems Reading (05:30–06:30) | Morning Builder Track (06:30–08:30) | Night Hands-On C++/CUDA (20:30–23:00) |
|:---|:---|:---|:---|
| **Mon Feb 9** | **PIKUS Ch 12** retrospective. | **Monthly Research: Planning & Literature Synthesis** | **secan**: CLI scaffold `secan build/search/bench` (complete Week 28). |
| **Tue Feb 10** | Occupancy calculator / `__launch_bounds__`. | **DL Track (Part 1): Architecture & Forward Pass** | **CUDA**: Occupancy tune on IVF + graph kernels. |
| **Wed Feb 11** | CUB/Thrust fusion notes. | **DL Track (Part 2): Training, Loss & Verification** | **CUDA**: Fused distance+topk kernel (was former Week 22 GPU polish). |
| **Thu Feb 12** | `-Wall -Wextra -Wpedantic`. | **Monthly Research: Sweeps & Data Logging** | **secan**: Warning cleanup; examples/ stubs. |
| **Fri Feb 13** | Month 6 paper freeze checklist. | **Monthly Research: Planning & Literature Synthesis** | **secan/CUDA**: Occupancy/`ncu` leftover polish. *(Naive KV re-bench: Saturday DL if needed.)* |

#### 📋 Daily Action Items & Optional Activities (Week 24)
* **Mon Feb 9**:
  * `[ ]` **Core**: Build unified CLI framework (`secan build`, `secan search`, `secan bench`) with argument parsing.
  * `⭐ Optional / Stretch`: Implement JSON-formatted stdout output mode for easy benchmarking script integration.
* **Tue Feb 10**:
  * `[ ]` **Core**: Tune GPU thread block occupancy using `__launch_bounds__` directives across all IVF and graph search kernels.
  * `⭐ Optional / Stretch`: Analyze register spilling to local memory in Nsight Compute and tune max registers per thread (`-maxrregcount`).
* **Wed Feb 11**:
  * `[ ]` **Core**: Implement fused GPU distance calculation + top-$k$ warp selection kernel eliminating intermediate global memory roundtrip.
  * `⭐ Optional / Stretch`: Compare fused kernel throughput against separated distance + CUB DeviceRadixSort.
* **Thu Feb 12**:
  * `[ ]` **Core**: Enable `-Wall -Wextra -Wpedantic -Werror`; resolve all compiler warnings across CPU and GPU codebases.
  * `⭐ Optional / Stretch`: Run `clang-tidy` static analyzer across all header and source files in `secan`.
* **Fri Feb 13**:
  * `[ ]` **Core**: Finalize Month 6 experimental benchmarks; verify all automated test suites pass with 0 errors.
  * `⭐ Optional / Stretch`: Profile end-to-end P99 latency jitter under variable query concurrency ($QPS \in [100, 10000]$).

#### ⛔ What NOT to Overspend Time On (Time Traps)
* ❌ **Do NOT** tag `v2.0` release yet—Month 7 (March) is the dedicated release and closeout phase.
* ❌ **Do NOT** over-tune CLI flags or build fancy terminal TUI animations—a clean POSIX CLI (`getopt` or `CLI11`) is sufficient.
* ❌ **Do NOT** spend hours eliminating benign 3rd-party library warnings—suppress external warnings with `-isystem`.

> **📝 Essay 24 (Sat Feb 14)**: *"Portable Vector Intrinsics and Production Graph Systems: Closing Block II Systems Hardening"*  
> **🚀 Month 6 research PUBLISH (Sun Feb 28)**: `research/2027-02-predicate-aware-graphs/paper.md` (use remaining Feb weekends).

---
