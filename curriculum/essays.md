# Weekly Technical Essay & Tactical Defense Lab-Note Schedule

Weekly Saturday morning lab notes (09:00–13:00).  
Every essay is an empirical, silicon-verified technical postmortem of that week's systems implementation.  
Together, they establish the experimental foundations for the **7 Conference-Grade Preprints** in [`../research/`](../research/README.md).

---

## 🏛️ Tactical Defense Architecture of the 28 Lab Notes

Every essay is engineered with **Dual-Use Defense Applicability**, bridging mathematical theorems, low-level CPU/GPU microarchitecture, and contested military operating environments:

* **Pillar A: Electronic Warfare (EW) & Radar Pulse De-Interleaving** (Weeks 1, 2, 7, 9, 13)
* **Pillar B: Tactical Data Links & Jam-Resistant Compression (Link-16 / TTNT)** (Weeks 4, 5, 6, 10, 12)
* **Pillar C: Autonomous Drone Swarms & Kinetic Guidance Physics** (Weeks 3, 8, 14, 17, 19, 20, 23, 25)
* **Pillar D: Multi-Domain JADC2 Reconnaissance & Sensor Fusion** (Weeks 11, 15, 16, 18, 21, 22, 26, 27, 28)

---

## 📅 The 28-Week Master Schedule

| Week | Date | Publication-Grade Essay / Lab-Note Title | Advanced Military & Tactical Defense Application |
|:---:|:---|:---|:---|
| **1** | Sat Sep 6 | *The Geometry of High-Dimensional Retrieval: Trigonometric Projections, Pulse Descriptors, and Hardware Counters* | **Radar Pulse De-Interleaving & ESM Threat Matching**: Geometric mapping of intercepted Pulse Descriptor Words (PDWs) against threat radar emitter databases under sub-microsecond deadlines. |
| **2** | Sat Sep 13 | *Breaking Dependency Chains: Multi-Register Accumulator Unrolling and Port Saturation in AVX2/AVX-512* | **Real-Time Electronic Warfare (EW) Jammer Triggering**: Maximizing IPC and saturating Execution Ports 0/1 to evaluate threat distance before an inbound missile radar locks. |
| **3** | Sat Sep 20 | *Integrals, Accumulation, and CPU Cache Hierarchies: Cache Tiling and Deterministic Autograd from Scratch* | **Deterministic Guidance Physics & Signal Integration**: Eliminating cache misses and memory stalls in real-time trajectory optimization for autonomous kinetic interceptors. |
| **4** | Sat Sep 27 | *From Complex Rotations to RoPE and Voronoi Cells: The Geometry of Spherical Inverted Files* | **Airborne Phased-Array Radar Tracking**: Spherical Voronoi cell clustering and rotary coordinate encoding for dynamic multi-target aerial formations. |
| **5** | Sat Oct 4 | *Low-Bit Compression Under Outliers: Gradients, Percentile Clipping, and SIMD Integer Saturation* | **Missile Seeker FLIR Compression**: Quantizing thermal infrared sensor streams on SWaP-constrained edge avionics without clipping critical target signatures. |
| **6** | Sat Oct 11 | *Constrained Optimization and Subspace Codebooks: Lagrange Multipliers in Product Quantization* | **Tactical Radio Bandwidth Allocation (Link-16 / TTNT)**: Subspace vector codebook optimization constrained by strict 28.8 kbps packet payload sizes under electronic jamming. |
| **7** | Sat Oct 18 | *Anisotropic Loss and In-Register SIMD Lookups: Directional Error Weighting and FastScan PSHUFB* | **EW Emitter Identification Under Hostile Jamming**: In-register FastScan PSHUFB evaluation of 4-bit radar signatures with ScaNN directional loss to prevent false positives. |
| **8** | Sat Oct 25 | *Graph Laplacians, Hubness Skewness, and Navigable Small-World Routing: Building HNSW from Scratch* | **Decentralized Drone Swarm Topology**: Using small-world graph theory and algebraic connectivity $\lambda_2$ to maintain communication routing when swarm nodes are kinetically destroyed. |
| **9** | Sat Nov 1 | *Beyond Single Vectors: Linear Algebra, Matrix Decompositions, and SIMD Architecture of ColBERT Late Interaction* | **Electronic Order of Battle (EOB) Signature Matching**: Multi-token MaxSim search over millions of irregular, agile frequency-hopping radar pulses. |
| **10** | Sat Nov 8 | *Orthogonal Projections and Fixed-Dimensional Encodings: Reducing ColBERT MaxSim to MIPS via MUVERA* | **Real-Time Reconnaissance Sensor Stream Compression**: Projecting variable-length acoustic/radar tracks into single fixed-dimensional MIPS vectors for high-speed edge filtering. |
| **11** | Sat Nov 15 | *Eigenvalues, Spectral Decompositions, and LSM Storage Engines: Write-Ahead Logs and Vector Compaction* | **Airborne High-Bandwidth SIGINT Ingestion**: Zero-loss append-only WAL and asynchronous SSTable compaction for gigabit-rate electronic warfare intercept recording. |
| **12** | Sat Nov 22 | *Singular Value Decomposition and Composed Vector Indexes: Pareto Evaluation of IVF-PQ and HNSW-SQ vs Faiss* | **Threat Library Search Optimization**: Truncating redundant RF spectrum dimensions via SVD and evaluating search recall on classified 768-D emitter threat libraries. |
| **13** | Sat Nov 29 | *The SIMT Execution Model: Why Naive GPU Distance Kernels Lose to CPU AVX2 in Edge Defense Computing* | **Edge Avionics Hardware Selection**: Microarchitectural analysis of when to dispatch radar pulse de-interleaving to low-power CPU SIMD vs onboard GPU Tensor Cores. |
| **14** | Sat Dec 6 | *Warp Shuffles and Parallel Reductions: Saturating GPU Memory Bandwidth in Batch Target Track Scanning* | **Massive Sonar/Radar Array Cross-Correlation**: Using intra-warp register shuffles (`__shfl_down_sync`) to correlate thousands of hydrophone streams without shared-memory bank stalls. |
| **15** | Sat Dec 13 | *IO-Aware Tiling and Online Softmax: Constructing a FlashAttention-1 CUDA Kernel from First Principles* | **Anti-Submarine Warfare (ASW) Acoustic Detection**: Tiled SRAM attention over hours-long continuous passive acoustic arrays to detect silent submarine propulsion transients. |
| **16** | Sat Dec 20 | *Closing the Vector Search Spine: GPU IVF Streaming, Vamana Graph Pruning, and Out-of-Core `io_uring`* | **Aerospace Wide-Area Motion Imagery (WAMI) Archival Search**: Out-of-core NVMe retrieval of 100M+ vehicle trajectory embeddings directly from aircraft SSDs via `io_uring`. |
| **17** | Sat Dec 27 | *Warp-Scale Graph Traversal: Overcoming Random Memory Access Bottlenecks in GPU CAGRA* | **Air Defense Fire-Control Target Assignment**: Sub-millisecond beam search over massive target graphs inside GPU VRAM to compute optimal intercept assignments against incoming missile salvos. |
| **18** | Sat Jan 3 | *Markov Chains, Graph Random Walks, and High-Throughput GPU Quantized FastScan* | **Predictive Battlefield Track Estimation**: Modeling enemy movement across terrain graph states and accelerating candidate retrieval via GPU-accelerated quantized FastScan. |
| **19** | Sat Jan 10 | *Virtual Memory for Attention: Paged KV Blocks and Extreme PolarQuant 3-Bit Compression* | **Edge UCAV Mission Autonomy (DARPA ACE)**: Paged KV cache memory management allowing 32K context rules-of-engagement reasoning inside a 16GB Jetson Orin envelope. |
| **20** | Sat Jan 17 | *Information Theory and Ring Collectives: Shannon Entropy, KL-Divergence, and Multi-GPU NCCL Search* | **Distributed Drone Swarm Target Consensus**: Multi-node ring-allreduce collective search over ad-hoc tactical Wi-Fi/RF mesh networks without central command vulnerability. |
| **21** | Sat Jan 24 | *Duality and Multimodal Retrieval: Karush-Kuhn-Tucker Conditions, CLIP Alignment, and ColPali MaxSim* | **Multimodal Reconnaissance & SAR Exploitation**: Cross-modal retrieval matching natural-language intelligence briefs against satellite Synthetic Aperture Radar (SAR) imagery. |
| **22** | Sat Jan 31 | *Graph Disconnection and Selectivity Cliffs: ACORN Predicate Subgraphs vs Post-Filtering* | **JADC2 Multilevel Security (MLS) Target Clearance Filtering**: Preventing search collapse in command systems when 99.9% of targets are masked out by classification clearance filters. |
| **23** | Sat Feb 7 | *Spectral Graph Theory and Cross-Platform SIMD: Cheeger's Inequality, Conductance, and ARM NEON Portability* | **Tactical Edge Drone Avionics Portability**: Handcrafted ARM NEON kernels (`vfmaq_f16`, `vqtbl1q_u8`, `vcntq_u8`) running natively on Cortex-A78 drone autopilots with zero cloud reliance. |
| **24** | Sat Feb 14 | *Portable Vector Intrinsics and Production Graph Systems: Closing Block II Hardening* | **DO-178C Airborne Systems Verification**: Deterministic static allocation, fault-tolerant memory bounds, and automated testing across heterogeneous combat computing hardware. |
| **25** | Sat Feb 21 | *Warp Partitioning and Register Rescaling: Implementing FlashAttention-2 with Grouped-Query Attention* | **Real-Time Dogfight Autonomy & Electronic Countermeasure Selection**: Squeezing maximum Tensor Core FLOPs out of edge GPUs to evaluate countermeasures in dynamic combat environments. |
| **26** | Sat Feb 28 | *Memory Fragmentation Under Autoregressive Generation: A/B Profiling Naive vs Paged KV Caches* | **Long-Duration Unmanned ISR Mission Caching**: Preventing memory fragmentation crashes during 24-hour continuous surveillance operations on edge flight controllers. |
| **27** | Sat Mar 7 | *Distributed Multi-GPU Partitioning and Visual Late Interaction: Scaling Document Page Retrieval* | **Theater-Scale Battlefield Common Operating Picture (COP)**: Distributed multi-GPU visual retrieval scanning entire theaters of operation for emerging enemy assets. |
| **28** | Sat Mar 14 | *Seven Months from First Principles: Vector Spaces, Modern SIMD/GPU Architectures, and the `v2.0` Engine* | **Grand Synthesis: The Sovereign AI Defense Engine**: Comprehensive technical postmortem of building an air-gapped, zero-cloud C++20/CUDA sovereign vector retrieval and generative reasoning stack. |
