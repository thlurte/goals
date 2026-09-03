# Essay / Lab-Note Schedule

Weekly Sat 09:00–13:00 lab notes. Polish **7 monthlies** in [`../research/`](../research/README.md), not all 28 essays.

| Week | Essay Date | Essay / Lab-Note Title | Systems & Theoretical Focus |
|:---:|:---|:---|:---|
| **1** | Sat Sep 6 | *The Geometry of High-Dimensional Retrieval: Trigonometric Projections, NDCG Ranking, and Hardware Performance Counters* | Radian geometry, unit circle projections, metric equivalence on $\mathcal{S}^{d-1}$, Google Benchmark & `perf stat` |
| **2** | Sat Sep 13 | *Breaking Dependency Chains: Multi-Register Accumulator Unrolling and Port Saturation in AVX2/AVX-512* | FMA latency hiding ($L=4$), Intel Execution Ports 0/1 contention, 4-way register unrolling |
| **3** | Sat Sep 20 | *Integrals, Accumulation, and CPU Cache Hierarchies: Cache Tiling and Autograd from Scratch* | Fubini's theorem, L1/L2 cache tiling, zero-copy contiguous memory, reverse-mode autodiff engine |
| **4** | Sat Sep 27 | *From Complex Rotations to RoPE and Voronoi Cells: The Geometry of Spherical Inverted Files* | Euler's formula, rotary position embeddings, spherical $k$-means, Voronoi cell partitioning |
| **5** | Sat Oct 4 | *Low-Bit Compression Under Outliers: Gradients, Percentile Clipping, and SIMD Integer Saturation* | Outlier coordinate dynamics, percentile clipping, SQ8/SQ4 quantization, SIMD integer saturation |
| **6** | Sat Oct 11 | *Constrained Optimization and Subspace Codebooks: Lagrange Multipliers in Product Quantization* | Lagrange multipliers $\nabla f = \lambda \nabla g$, subspace splitting, asymmetric distance computation (ADC LUTs) |
| **7** | Sat Oct 18 | *Anisotropic Loss and In-Register SIMD Lookups: Directional Error Weighting and FastScan PSHUFB* | ScaNN anisotropic error decomposition ($h \|\mathbf{e}_\parallel\|^2 + \|\mathbf{e}_\perp\|^2$), in-register PSHUFB lookups |
| **8** | Sat Oct 25 | *Graph Laplacians, Hubness Skewness, and Navigable Small-World Routing: Building HNSW from Scratch* | Kleinberg small-world routing ($r=D$), spectral graph Laplacian, skip-list hierarchy, hubness reduction |
| **9** | Sat Nov 1 | *Beyond Single Vectors: The Linear Algebra, Matrix Decompositions, and SIMD Architecture of ColBERT Late Interaction* | Token-level embeddings, Chamfer similarity, batched MaxSim kernel vectorization, margin MSE loss |
| **10** | Sat Nov 8 | *Orthogonal Projections and Fixed-Dimensional Encodings: Reducing ColBERT MaxSim to MIPS via MUVERA* | Fast Walsh-Hadamard Transform (FWHT), randomized orthogonal projections, Fixed-Dimensional Encodings |
| **11** | Sat Nov 15 | *Eigenvalues, Spectral Decompositions, and LSM Storage Engines: Write-Ahead Logs and Vector Compaction* | Spectral decomposition, append-only WAL crash recovery, MemTable-to-SSTable compaction amplification |
| **12** | Sat Nov 22 | *Singular Value Decomposition and Composed Vector Indexes: Pareto Evaluation of IVF-PQ and HNSW-SQ vs Faiss* | SVD low-rank approximation, IVF-PQ coarse list routing, Pareto frontier optimization vs Faiss/HNSWLib |
| **13** | Sat Nov 29 | *The SIMT Execution Model: Why Naive GPU Distance Kernels Lose to CPU AVX2* | GPU warp divergence, memory coalescing, latency hiding, SIMT vs SIMD hardware execution profiles |
| **14** | Sat Dec 6 | *Warp Shuffles and Parallel Reductions: Saturating GPU Memory Bandwidth in Batch Vector Scanning* | In-register warp shuffles (`__shfl_down_sync`), shared memory banks, DRAM bus saturation |
| **15** | Sat Dec 13 | *IO-Aware Tiling and Online Softmax: Constructing a FlashAttention-1 CUDA Kernel from First Principles* | GPU memory hierarchy, shared memory circular buffers, online softmax numerical invariant |
| **16** | Sat Dec 20 | *Closing the Vector Search Spine: GPU IVF Streaming, Vamana Graph Pruning, and Out-of-Core `io_uring`* | Vamana geometric $\alpha$-spanner pruning, Linux kernel-bypass asynchronous direct I/O (`io_uring`) |
| **17** | Sat Dec 27 | *Warp-Scale Graph Traversal: Overcoming Random Memory Access Bottlenecks in GPU CAGRA* | Single-warp cooperative beam search, coalesced routing table lookups, GPU graph memory latency |
| **18** | Sat Jan 3 | *Markov Chains, Graph Random Walks, and High-Throughput GPU Quantized FastScan* | Random walks on small-world graphs, Markov stationary distributions, GPU in-register FastScan |
| **19** | Sat Jan 10 | *Virtual Memory for Attention: Paged KV Blocks and Extreme PolarQuant 3-Bit Compression* | Memory fragmentation analysis, page table lookups, 3-bit spherical quantization for KV caches |
| **20** | Sat Jan 17 | *Information Theory and Ring Collectives: Shannon Entropy, KL-Divergence, and Multi-GPU NCCL Search* | Shannon entropy, KL divergence, distributed ring-allreduce collectives, multi-GPU scaling efficiency |
| **21** | Sat Jan 24 | *Duality and Multimodal Retrieval: Karush-Kuhn-Tucker Conditions, CLIP Alignment, and ColPali MaxSim* | KKT optimality conditions, cross-modal contrastive alignment, multi-vector visual late interaction |
| **22** | Sat Jan 31 | *Graph Disconnection and Selectivity Cliffs: ACORN Predicate Subgraphs vs Post-Filtering* | Small-world graph percolation, 2-hop predicate routing, SIMD Roaring Bitmaps, recall collapse mitigation |
| **23** | Sat Feb 7 | *Spectral Graph Theory and Cross-Platform SIMD: Cheeger's Inequality, Conductance, and ARM NEON Portability* | Cheeger isoperimetric constant $h(G)$, ARM NEON intrinsics (`vfmaq_f16`, `vqtbl1q_u8`, `vcntq_u8`) |
| **24** | Sat Feb 14 | *Portable Vector Intrinsics and Production Graph Systems: Closing Block II Systems Hardening* | Dynamic runtime architecture dispatch (`getauxval`), zero-copy serialization, production hardening |
| **25** | Sat Feb 21 | *Warp Partitioning and Register Rescaling: Implementing FlashAttention-2 with Grouped-Query Attention* | Warpgroup specialization, register accumulator rescaling, grouped-query attention (GQA) kernel fusion |
| **26** | Sat Feb 28 | *Memory Fragmentation Under Autoregressive Generation: A/B Profiling Naive vs Paged KV Caches* | Autoregressive generation memory curves, PagedAttention block reuse, latency-throughput trade-offs |
| **27** | Sat Mar 7 | *Distributed Multi-GPU Partitioning and Visual Late Interaction: Scaling Document Page Retrieval* | Multi-GPU document sharding, visual token aggregation, end-to-end multi-modal retrieval pipeline |
| **28** | Sat Mar 14 | *Seven Months from First Principles: Vector Spaces, Modern SIMD/GPU Architectures, and the `v2.0` Engine* | Grand synthesis of vector retrieval and LLM serving, $4.9 \times 10^6 \times$ cumulative speedup release |
