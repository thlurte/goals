# 📚 Primary Sources, Seminal Papers & Systems Canon

A comprehensive, primary-source engineering canon synthesized from seminal computer architecture literature, vendor microarchitecture manuals, and systems research (including the 304 primary entries from the CPU Performance Engineering repository).

Every entry represents an **absolute document, seminal paper, canonical textbook, or vendor hardware specification** directly linked to its primary source.

---

## 🧭 1. Foundational Architecture & Systems Canon (Textbooks)

| Absolute Title & Edition | Authors | Publisher / Citation | Core Technical Focus |
| :--- | :--- | :--- | :--- |
| **[Computer Architecture: A Quantitative Approach (7th ed)](https://shop.elsevier.com/books/computer-architecture/hennessy/978-0-443-15406-5)** | John L. Hennessy & David A. Patterson | Morgan Kaufmann / Elsevier (2024) | Quantitative cache performance ($	ext{AMAT}$), instruction-level parallelism, dynamic scheduling, branch prediction, vector processing, and memory hierarchy limits. |
| **[Computer Systems: A Programmer's Perspective (3rd ed)](https://csapp.cs.cmu.edu/)** | Randal E. Bryant & David R. O'Hallaron | Pearson (2015) | Machine-level representation, two's-complement arithmetic, pipeline mechanics, memory hierarchy, linking, and performance optimization. |
| **[Performance Analysis and Tuning on Modern CPUs (2nd ed)](https://github.com/dendibakh/perf-book)** | Denis Bakhvalov | Performance Tuning (2024) | Systematic performance engineering workflow: PMU hardware counters, Top-Down Microarchitecture Analysis (TMA), branch misprediction, and compiler code generation. |
| **[Systems Performance: Enterprise and the Cloud (2nd ed)](https://www.brendangregg.com/systems-performance-2nd-edition-book.html)** | Brendan Gregg | Addison-Wesley (2020) | USE method, CPU utilization vs saturation, off-CPU profiling, PMU counter architecture, and Flame Graphs. |
| **[Is Parallel Programming Hard, And, If So, What Can You Do About It? (Perfbook)](https://mirrors.edge.kernel.org/pub/linux/kernel/people/paulmck/perfbook/perfbook.html)** | Paul E. McKenney | Linux Foundation (2024) | Hardware cache coherence (MESI/MOESI), false sharing, memory barriers, read-copy update (RCU), and non-blocking synchronization. |
| **[Hacker's Delight (2nd ed)](https://en.wikipedia.org/wiki/Hacker%27s_Delight)** | Henry S. Warren, Jr. | Addison-Wesley (2012) | Branchless bitwise manipulation, fast population count algorithms, integer bit packing, and power-of-two arithmetic. |
| **[Database Internals: A Deep Dive into How Distributed Data Systems Work](https://www.oreilly.com/library/view/database-internals/9781492040330/)** | Alex Petrov | O'Reilly Media (2019) | B-Trees, LSM-Trees, immutable SSTables, memtables, write-ahead logs, and disk I/O optimization. |
| **[The Art of Computer Programming, Vol 3: Sorting and Searching (2nd ed)](https://www-cs-faculty.stanford.edu/~knuth/taocp.html)** | Donald E. Knuth | Addison-Wesley (1998) | External sorting, multiway search trees, optimal search algorithms, and exact algorithmic complexity. |

---

## ⚡ 2. Instruction Pipeline & Execution Engine (One Instruction End-to-End)

### A. Fetch, Decode & Branch Prediction
* **[Fetch Directed Instruction Prefetching](https://cseweb.ucsd.edu/~calder/papers/MICRO-99-FDP.pdf)** (Glenn Reinman, Brad Calder, Todd Austin, *MICRO 1999*) — The origin of the decoupled front end where the predictor runs ahead of fetch to drive L1I prefetching.
* **[Micro-Operation Cache: A Power Aware Frontend for Variable Instruction Length ISA](https://ieeexplore.ieee.org/document/945363)** (B. Solomon et al., *ISLPED 2001*) — Introduction of the decoded $\mu	ext{op}$ cache (Intel Decoded ICache / AMD Op Cache).
* **[A Case for (Partially) TAgged GEometric History Length Branch Prediction (TAGE)](https://jilp.org/vol8/v8paper1.pdf)** (André Seznec, Pierre Michaud, *JILP 2006*) — The foundational geometric history predictor architecture used in modern Zen and Intel cores.
* **[A 64-Kbytes ITTAGE Indirect Branch Predictor](https://jilp.org/jwac-2/program/cbp3_07_seznec.pdf)** (André Seznec, *CBP-3 2011*) — Tagged geometric branch prediction for indirect jumps, calls, and virtual method dispatch.

### B. Rename, Out-of-Order Issue & Execution Ports
* **[An Efficient Algorithm for Exploiting Multiple Arithmetic Units](https://ieeexplore.ieee.org/document/5392028)** (Robert Tomasulo, *IBM Journal 1967*) — The seminal paper introducing reservation stations, tag-based register renaming, and Common Data Bus (CDB).
* **[Focusing Processor Policies via Critical-Path Prediction](https://dl.acm.org/doi/10.1145/379240.379253)** (Eric Tune et al., *ISCA 2001*) — Dependency graph analysis of out-of-order execution and identifying loop-carried critical path chains.
* **[Measuring Reorder Buffer Capacity](https://blog.stuffedcow.net/2013/05/measuring-rob-capacity/)** (Henry Wong, *Stuffed Cow*) — User-space empirical measurement methodology for physical register files and ROB capacity limits.
* **[Optimizing Subroutines in Assembly Language](https://www.agner.org/optimize/optimizing_assembly.pdf)** (Agner Fog, *Technical University of Denmark*) — Register renaming hazards, partial register stalls, false dependencies, and zero-cost idiom eliminations (`xor eax, eax`).

### C. Memory Access, Forwarding & Retirement
* **[Memory Dependence Prediction Using Store Sets](https://people.csail.mit.edu/emer/media/papers/1990s/1998/1998.06.isca.storesets.pdf)** (George Z. Chrysos, Joel S. Emer, *ISCA 1998*) — Speculative load execution past unretired stores and memory disambiguation.
* **[Store-to-Load Forwarding and Memory Disambiguation in x86 Processors](https://blog.stuffedcow.net/2014/01/x86-memory-disambiguation/)** (Henry Wong, *Stuffed Cow*) — Empirical measurements of store forwarding stalls, address matching, and offset mismatch penalties.
* **[Microarchitecture Optimizations for Exploiting Memory-Level Parallelism](https://ieeexplore.ieee.org/document/1310765)** (Yuan Chou, Brian Fahs, Sanjay J. Patel, *ISCA 2004*) — Memory-level parallelism (MLP), Miss Status Holding Registers (MSHRs), and overlapping multiple cache misses.
* **[Implementing Precise Interrupts in Pipelined Processors](https://ieeexplore.ieee.org/document/4607)** (James E. Smith, Andrew R. Pleszkun, *IEEE Trans. Computers 1988*) — In-order retirement via Reorder Buffers (ROB) ensuring deterministic exception state.

---

## 💾 3. Memory Hierarchy, Prefetching & Coherence

* **[What Every Programmer Should Know About Memory](https://www.akkadia.org/drepper/cpumemory.pdf)** (Ulrich Drepper, *Red Hat 2007*) — Definitive monograph on cache line strides, TLB hierarchies, hardware stream prefetchers, and page translation overhead.
* **[Memory Barriers: A Hardware View for Software Hackers](http://www.rdrop.com/users/paulmck/scalability/paper/whymb.2010.07.23a.pdf)** (Paul E. McKenney, *IBM 2010*) — Hardware store buffers, invalidate queues, MESI cache coherence protocols, and memory ordering fences.
* **[Cache-Oblivious Algorithms](https://ieeexplore.ieee.org/document/814600)** (Matteo Frigo, Charles E. Leiserson, Harald Prokop, Sridhar Ramachandran, *FOCS 1999*) — Designing cache-efficient matrix and tree layouts without hardware-specific tuning.
* **[NUMA Memory Management in Linux](https://www.kernel.org/doc/html/latest/admin-guide/mm/numaperf.html)** (Linux Kernel Documentation) — First-touch memory allocation policies, inter-socket QPI/UPI traffic, and local node affinity.

---

## 🔬 4. Performance Models & Microarchitectural Measurement

* **[Roofline: An Insightful Visual Performance Model for Multicore Architectures](https://cacm.acm.org/research/roofline-an-insightful-visual-performance-model-for-multicore-architectures/)** (Samuel Williams, Andrew Waterman, David Patterson, *CACM 2009*) — Arithmetic intensity ($	ext{FLOPs/Byte}$), memory bandwidth bounds vs compute saturation ceilings.
* **[A Top-Down Method for Performance Analysis and Counters Architecture](https://sites.google.com/site/analysismethods/yasin-pubs)** (Ahmad Yasin, *Intel / IEEE ISPASS 2014*) — Top-Down Microarchitecture Analysis (TMA): Front-End Bound, Bad Speculation, Back-End Bound (Core vs Memory), and Retiring.
* **[How to Benchmark Code Execution Times on Intel IA-32 and IA-64](https://www.intel.com/content/dam/develop/external/us/en/documents/ia-32-ia-64-benchmark-code-execution-paper.pdf)** (Gabriele Paoloni, *Intel Whitepaper*) — Sub-nanosecond timing via `RDTSCP`, serialization barriers (`CPUID`), and eliminating out-of-order timing drift.
* **[Producing Wrong Data Without Doing Anything Wrong!](https://users.cs.northwestern.edu/~robby/courses/322-2013-spring/mytkowicz-asplos2009.pdf)** (Todd Mytkowicz, Amer Diwan, Matthias Hauswirth, Peter F. Sweeney, *ASPLOS 2009*) — Measurement bias, environment variable sizing, and link-order layout noise.

---

## 🏎️ 5. SIMD, Vectorization & High-Throughput Kernels

* **[Optimizing Software in C++](https://www.agner.org/optimize/optimizing_cpp.pdf)** (Agner Fog, *Technical University of Denmark*) — SIMD intrinsics, vector register blocking, alignment rules, and avoiding loop-carried dependency stalls.
* **[Instruction Tables: Lists of Instruction Latencies, Throughputs and Micro-operation Breakdowns](https://www.agner.org/optimize/instruction_tables.pdf)** (Agner Fog) — Cycle latencies, reciprocal throughputs, and port execution pipelines for x86 architectures.
* **[Intel 64 and IA-32 Architectures Optimization Reference Manual](https://www.intel.com/content/www/us/en/content-details/671488/intel-64-and-ia-32-architectures-optimization-reference-manual-volume-1.html)** (Intel Corporation) — Official guidelines on AVX2, AVX-512, AMX, and VNNI instructions.
* **[Software Optimization Guide for AMD Family 19h (Zen 4) / Family 1Ah (Zen 5)](https://docs.amd.com/v/u/en-US/58455_1.00)** (AMD) — Macro-fusion rules, dual 256-bit vs 512-bit vector pipelines, and branch prediction optimizations.
* **[Fast Integer Division by Constants Using Multiplication](https://gmplib.org/~tege/divcnst-pldi94.pdf)** (Torbjörn Granlund, Peter L. Montgomery, *PLDI 1994*) — Eliminating division instructions via reciprocal bitwise multiplication and shifts.
* **[Faster Population Counts Using AVX2 Instructions](https://arxiv.org/abs/1611.07612)** (Wojciech Muła, Nathan Kurz, Daniel Lemire, *The Computer Journal 2018*) — Harley-Seal vector popcount algorithm operating directly on AVX2 SIMD registers.

---

## 📐 6. Mathematical & Information-Theoretic Foundations

* **[High-Dimensional Probability: An Introduction with Applications in Data Science](https://www.math.uci.edu/~rvershyn/papers/HDP-book/HDP-book.html)** (Roman Vershynin, *Cambridge University Press 2018*) — Concentration of measure on hyperspheres, Johnson-Lindenstrauss lemma, sub-Gaussian random vectors, and covering numbers.
* **[Matrix Computations (4th ed)](https://jhupbooks.press.jhu.edu/title/matrix-computations)** (Gene H. Golub & Charles F. Van Loan, *Johns Hopkins 2013*) — Numerical linear algebra, singular value decomposition (SVD), QR factorization, Rayleigh quotients, and condition numbers.
* **[Numerical Optimization (2nd ed)](https://link.springer.com/book/10.1007/978-0-387-40065-5)** (Jorge Nocedal & Stephen J. Wright, *Springer 2006*) — Unconstrained optimization, line search methods, conjugate gradients, quasi-Newton (BFGS/L-BFGS), and trust-region algorithms.
* **[Elements of Information Theory (2nd ed)](https://www.wiley.com/en-us/Elements+of+Information+Theory%2C+2nd+Edition-p-9780471241959)** (Thomas M. Cover & Joy A. Thomas, *Wiley 2006*) — Shannon entropy, mutual information, Asymptotic Equipartition Property (AEP), rate-distortion theory $R(D)$, and vector quantization bounds.
* **[Probability Theory: The Logic of Science](https://bayes.wustl.edu/)** (Edwin T. Jaynes, *Cambridge University Press 2003*) — Probability as extended logic, Maximum Entropy Principle, and objective Bayesian foundations.
* **[Similarity Search: The Metric Space Approach](https://link.springer.com/book/10.1007/0-387-29151-2)** (Pavel Zezula et al., *Springer 2006*) — Metric postulates, triangle inequality pruning, vantage-point trees, and metric indexing.

---

## 🚀 7. GPU Architecture & Massively Parallel Systems

* **[Programming Massively Parallel Processors: A Hands-on Approach (4th ed)](https://www.sciencedirect.com/book/9780323912310/programming-massively-parallel-processors)** (David B. Kirk & Wen-mei W. Hwu, *Morgan Kaufmann 2022*) — GPU hardware architectures, CUDA warp scheduling, shared memory bank conflicts, and memory coalescing.
* **[CUDA C++ Programming Guide](https://docs.nvidia.com/cuda/cuda-c-programming-guide/)** (NVIDIA Corporation) — Memory hierarchy, asynchronous memory copies (`cuda::memcpy_async`), tensor cores, and cooperative groups.
* **[CUTLASS: Fast Linear Algebra Operations in CUDA C++](https://github.com/NVIDIA/cutlass)** (NVIDIA Corporation) — Templated CUDA C++ components for high-performance matrix multiplication and warp-specialized GEMM.
* **[FlashAttention-2: Faster Attention with Better Parallelism and Work Partitioning](https://arxiv.org/abs/2307.08691)** (Tri Dao, *ICLR 2024*) — Online softmax tiling, reducing HBM reads/writes, and forward/backward work partitioning on Tensor Cores.

---

## 📄 8. Seminal Vector Search Literature

* **[Product Quantization for Nearest Neighbor Search](https://inria.hal.science/inria-00514462/document)** (Hervé Jégou, Matthijs Douze, Cordelia Schmid, *IEEE TPAMI 2011*) — Foundational paper introducing subspace decomposition and Asymmetric Distance Computation (ADC).
* **[Efficient and Robust Approximate Nearest Neighbor Search Using Hierarchical Navigable Small World Graphs (HNSW)](https://arxiv.org/abs/1603.09320)** (Yu. A. Malkov, D. A. Yashunin, *IEEE TPAMI 2018*) — Multi-layer proximity graph with logarithmic search scaling.
* **[Accelerating Large-Scale Inference with Anisotropic Vector Quantization (ScaNN)](https://arxiv.org/abs/1908.10396)** (Ruiqi Guo et al., *ICML 2020*) — Directional loss function penalizing parallel quantization error over orthogonal error for Maximum Inner Product Search (MIPS).
* **[Billion-Scale Similarity Search with GPUs (FAISS)](https://arxiv.org/abs/1702.08734)** (Jeff Johnson, Matthijs Douze, Hervé Jégou, *IEEE Trans. Big Data 2019*) — Massively parallel IVF-PQ, bit-level warp k-selection, and GPU distance kernels.
* **[DiskANN: Fast Accurate Billion-Scale Nearest Neighbor Search on a Single Node](https://proceedings.neurips.cc/paper_files/paper/2019/file/09853c7fb1d15028508ccd914c52e457-Paper.pdf)** (Suhas Jayaram Subramanya et al., *NeurIPS 2019*) — Vamana graph layout, 2-hop compressed neighbor lists, and asynchronous SSD reads via `io_uring`.
* **[RaBitQ: Quantizing High-Dimensional Vectors with a Bit](https://arxiv.org/abs/2405.12497)** (Jianyang Gao, Cheng Long, *ACM SIGMOD 2024*) — 1-bit randomized binary quantization with bounded distance estimation.
* **[ColBERT: Efficient and Effective Passage Search via Contextualized Late Interaction over BERT](https://arxiv.org/abs/2004.12832)** (Omar Khattab, Matei Zaharia, *ACM SIGIR 2020*) — Multi-vector MaxSim scoring ($\sum_{i} \max_{j} E_{q,i} \cdot E_{d,j}^	op$).
* **[CAGRA: Highly Efficient GPU Graph-Based Approximate Nearest Neighbors Search](https://arxiv.org/abs/2308.15136)** (Hiroyuki Ootomo et al., *arXiv 2023*) — CUDA warp-centric graph traversal for batch query execution.
