# Month 2 Reading Syllabus: Domain-Specific Architectures & Metric Search Geometry (Dec 2026)

This month tackles the direct intersection of **Domain-Specific Hardware Architectures (DSA)** and **High-Dimensional Metric Search Algorithms**, providing the deep technical blueprint for designing search-specialized hardware.

---

## 📅 Week 5 (Dec 1 – Dec 7): Quantitative Hardware Design & Metric Space Foundations

| Day | Track | Book & Exact Reading Assignment | Core Takeaway / Questions to Answer |
| :--- | :--- | :--- | :--- |
| **Tue (Dec 1)** | Hardware DSA | **Hennessy & Patterson (6th Ed)**: §1.4–1.7 (pp. 21–48)<br>*Power, Energy, Cost & Amdahl's Law* | Dynamic vs static energy; power wall; Amdahl's Law limits on hardware acceleration. |
| | Metric Search | **Similarity Search (Zezula)**: §1.1–1.4 (pp. 1–24)<br>*Metric Space Axioms & Distance Functions* | Positivity, symmetry, triangle inequality; Minkowski metrics ($L_1, L_2, L_\infty$), Edit distance. |
| **Wed (Dec 2)** | Hardware DSA | **Hennessy & Patterson (6th Ed)**: §1.8–1.11 (pp. 49–78)<br>*Measuring Performance & Fallacies in Architecture* | Benchmarking pitfalls; geometric vs arithmetic mean; roofline model introduction. |
| | Metric Search | **Similarity Search (Zezula)**: §2.1–2.4 (pp. 25–48)<br>*Search Operations in Metric Spaces* | Range queries ($R(q, r)$); $k$-Nearest Neighbor ($k\text{NN}$); intrinsic dimensionality bounds. |
| **Thu (Dec 3)** | Hardware DSA | **Hennessy & Patterson (6th Ed)**: §2.1–2.2 (pp. 83–108)<br>*Advanced Cache Optimizations: Small & Fast First-Level Caches* | Critical word first; non-blocking caches to tolerate load latency; multi-banked caches. |
| | Metric Search | **Similarity Search (Zezula)**: §3.1–3.4 (pp. 49–76)<br>*Metric Indexing Principles & Pruning Rules* | Triangle inequality pruning conditions: Ball exclusion rule and Hyperplane exclusion rule. |
| **Fri (Dec 4)** | Hardware DSA | **Hennessy & Patterson (6th Ed)**: §2.3–2.5 (pp. 109–134)<br>*Compiler Optimizations & Hardware Prefetching* | Loop tiling (blocking) for 2D matrices; instruction vs data prefetchers; stride prefetchers. |
| | Metric Search | **Similarity Search (Zezula)**: §4.1–4.3 (pp. 77–102)<br>*Ball Partitioning: Vantage Point Trees (VP-Tree, MVP-Tree)* | Single pivot median partitioning; multiple vantage points per node; bounding spheres. |
| **Sat (Dec 5)** | Weekend Theory | **Hennessy & Patterson (6th Ed)**: Appendix B (pp. B-1–B-40)<br>*Review of Memory Hierarchies* | Cache coherence protocols (MESI / MOESI); snooping vs directory-based protocols. |
| | Metric Bounds | **Similarity Search (Zezula)**: §4.4–4.6 (pp. 103–128)<br>*Polynary & Excluded Middle VP-Trees* | Partitioning high-dimensional spaces without dimensional collapse. |
| **Sun (Dec 6)** | Weekend Theory | **TAOCP Vol 3 (Knuth)**: §6.2.1–6.2.2 (pp. 417–440)<br>*Searching an Ordered Table & Binary Search Bounds* | Information-theoretic lower bounds on comparisons ($O(\log N)$); Fibonacci search. |
| | Deep Sanctuary | **Gödel, Escher, Bach**: Ch 9 (pp. 231–272)<br>*Mumon and Gödel* | Self-reference, loops, and meta-mathematical truths. |

---

## 📅 Week 6 (Dec 8 – Dec 14): Vector/SIMD Hardware Architectures & Graph Search

| Day | Track | Book & Exact Reading Assignment | Core Takeaway / Questions to Answer |
| :--- | :--- | :--- | :--- |
| **Mon (Dec 8)** | Hardware DSA | **Hennessy & Patterson (6th Ed)**: §4.1–4.3 (pp. 282–306)<br>*Vector Architecture & Data-Level Parallelism* | Vector register files; vector load-store units; stride and gather-scatter hardware. |
| | Metric Search | **Similarity Search (Zezula)**: §5.1–5.3 (pp. 129–156)<br>*Generalized Hyperplane Partitioning (GH-Tree, GNAT)* | Hyperplane bisectors between two pivots; Generalized Non-metric Tree geometry. |
| **Tue (Dec 9)** | Hardware DSA | **Hennessy & Patterson (6th Ed)**: §4.4–4.6 (pp. 307–334)<br>*Vector Execution Units & Chaining* | Vector length registers (VLR); vector mask registers; vector chaining in pipelines. |
| | Metric Search | **Similarity Search (Zezula)**: §6.1–6.4 (pp. 157–188)<br>*Dynamic Metric Trees: The M-Tree* | Dynamic insertions, node splitting algorithms, routing objects, covering radii. |
| **Wed (Dec 10)** | Hardware DSA | **Hennessy & Patterson (6th Ed)**: §4.7–4.9 (pp. 335–362)<br>*SIMD Instruction Set Extensions for Multimedia & Systems* | x86 AVX vs ARM NEON vs RISC-V Vector (RVV); packed arithmetic; alignment traps. |
| | Metric Search | **Similarity Search (Zezula)**: §7.1–7.3 (pp. 189–214)<br>*Pivot-Based Methods & Distance Matrix Compression* | Global pivot selection strategies; distance lower-bound tables; coordinate reduction. |
| **Thu (Dec 11)** | Hardware DSA | **Hennessy & Patterson (6th Ed)**: §4.10–4.12 (pp. 363–390)<br>*GPU Architectures & Streaming Multiprocessors* | SIMT execution model; warp divergence; memory coalescing across threads. |
| | Metric Search | **Similarity Search (Zezula)**: §8.1–8.4 (pp. 215–244)<br>*Permutation-Based Search & Inverted Lists* | Representing objects as permutations of nearest pivots; Kendall-tau distance approximations. |
| **Fri (Dec 12)** | Hardware DSA | **Hennessy & Patterson (6th Ed)**: Case Studies (pp. 391–410)<br>*Roofline Model Analysis on Vector Silicon* | Arithmetic intensity (FLOPs/byte); calculating memory bandwidth ceiling vs compute ceiling. |
| | Bitwise ALU | **Hacker's Delight**: §7.7–7.8 (pp. 167–182)<br>*Matrix Transposition in Hardware* | Transposing a $32 \times 32$ bit matrix using 256-bit SIMD registers in 15 instructions. |
| **Sat (Dec 13)** | Weekend Theory | **Hennessy & Patterson (6th Ed)**: Ch 7 (pp. 535–565)<br>*Domain-Specific Architectures (DSAs): Google TPU v1* | Matrix Multiply Unit (MXU); 2D systolic array; weight streaming vs activation streaming. |
| | Graph Theory | **Small-World Networks & HNSW Research Papers**<br>*Navigable Small World Properties* | Logarithmic diameter, greedy routing termination bounds, clustering coefficient. |
| **Sun (Dec 14)** | Weekend Theory | **Hennessy & Patterson (6th Ed)**: Ch 7 cont. (pp. 566–595)<br>*Domain-Specific Architectures: Google TPU v2/v3 & Interconnects* | High-Bandwidth Memory (HBM); 2D Torus interconnect topology; thermal dissipation. |
| | Deep Sanctuary | **The Road to Reality**: Ch 11 & 12 (pp. 179–216)<br>*Riemann Surfaces & Complex Manifolds* | Conformal mapping; why complex numbers describe physical fields. |

---

## 📅 Week 7 (Dec 15 – Dec 21): Custom Silicon for Search & Quantization Hardware

| Day | Track | Book & Exact Reading Assignment | Core Takeaway / Questions to Answer |
| :--- | :--- | :--- | :--- |
| **Mon (Dec 15)** | Hardware DSA | **Hennessy & Patterson (6th Ed)**: Ch 7 (pp. 596–625)<br>*Sparse Processing Architectures & Specialized Memory* | Hardware acceleration for sparse tensors; compressed sparse row (CSR) decoders in silicon. |
| | Bitwise ALU | **Hacker's Delight**: §14.4–14.6 (pp. 321–338)<br>*Morton Space-Filling Curves & Bit Interleaving* | Interleaving bits of $(x, y, z)$ coordinates in hardware for Z-order spatial indexing. |
| **Tue (Dec 16)** | Hardware DSA | **Near-Memory Computing & Custom Silicon Case Studies**<br>*Processing-in-Memory (PIM) for Vector Search* | Overcoming the "Memory Wall"; placing distance ALUs directly inside DRAM/HBM dies. |
| | Metric Search | **Similarity Search (Zezula)**: §9.1–9.4 (pp. 245–278)<br>*Parallel & Distributed Similarity Search* | Partitioning strategies (data parallel vs space parallel); routing network bottlenecks. |
| **Wed (Dec 17)** | Hardware DSA | **Specialized Vector Search Silicon Architecture**<br>*FastScan 4-bit LUT Hardware Units* | Designing custom SRAM register files for parallel 4-bit nibble lookups without cache stalls. |
| | Bitwise ALU | **Hacker's Delight**: §15.1–15.3 (pp. 343–358)<br>*Bit Gathering/Scattering for Compressed Codebooks* | Hardware bit-extraction logic for sub-byte quantized embeddings ($2\text{-bit}, 4\text{-bit}$). |
| **Thu (Dec 18)** | Hardware DSA | **Hardware Accelerators for Graph Search**<br>*HNSW on Custom Silicon: Memory Access Patterns* | Handling random memory access in graph traversal; hardware visited bitset buffers. |
| | Metric Search | **Similarity Search (Zezula)**: §10.1–10.4 (pp. 279–310)<br>*Approximate Similarity Search & Trade-off Bounds* | Error metrics; Recall vs Latency curves; early stopping radius bounds. |
| **Fri (Dec 19)** | Hardware DSA | **Energy-Efficiency in Search Silicon**<br>*Joules per Query Metric* | Calculating dynamic energy per vector comparison; integer vs floating point energy costs. |
| | Bitwise ALU | **Hacker's Delight**: §16.1–16.3 (pp. 363–380)<br>*Fast CRC and Hash Generators in Silicon* | Hardware hashing pipelines for coarse centroid bucketing. |
| **Sat (Dec 20)** | Weekend Theory | **TAOCP Vol 3 (Knuth)**: §6.3 (pp. 471–505)<br>*Optimal Search Trees & Dynamic Programming* | Constructing trees with minimal weighted path length under non-uniform query frequencies. |
| | Systems Profiling | **Systems Performance**: Ch 12 (pp. 551–590)<br>*Hardware Microbenchmarks & Latency Profiling* | Isolating memory bus saturation from ALU pipeline stall limits using micro-benchmarks. |
| **Sun (Dec 21)** | Weekend Theory | **TAOCP Vol 3 (Knuth)**: §6.5 (pp. 559–590)<br>*Multi-attribute Retrieval & Inverted Lists* | Mathematical limits of intersecting sparse inverted postings; combinatorial bounds. |
| | Deep Sanctuary | **The Road to Reality**: Ch 17 & 18 (pp. 383–438)<br>*Spacetime & The Minkowski Metric* | Invariant intervals; metric tensor $g_{\mu\nu}$; geometry as the structure of physical law. |

---

## 📅 Week 8 (Dec 22 – Dec 31): Hardware-Software Co-Design Capstone

| Day | Track | Book & Exact Reading Assignment | Core Takeaway / Questions to Answer |
| :--- | :--- | :--- | :--- |
| **Mon (Dec 22)** | Architecture | **Hennessy & Patterson (6th Ed)**: Review §1.5, §2.2, §4.3<br>*Silicon Architecture Synthesis* | Synthesizing the 3 key hardware parameters: Memory Bandwidth, Vector Width, ALU latency. |
| | Hardware Spec | *Drafting the Hardware Search Specification* | Defining instruction sets for a domain-specific search co-processor (ISA extensions). |
| **Tue (Dec 23)** | Metric Space | **Similarity Search (Zezula)**: Review Chapters 3, 5, 7<br>*Metric Pruning Synthesis* | How hardware exclusion rules map to parallel execution pipelines. |
| | Hardware Spec | *Drafting Near-Memory Compute Units* | Mapping Product Quantization (ADC) lookups directly to on-chip SRAM banks. |
| **Wed (Dec 24)** | Synthesis | **Data-Oriented Design (Fabian)**: Review Ch 2, 4, 5<br>*Memory-First Architecture* | Designing the memory bus protocol: zero pointer indirection in hardware streaming. |
| **Thu (Dec 25)** | Founder Vision | **Hennessy & Patterson Turing Lecture (2018)**<br>*A New Golden Age for Computer Architecture* | Why general CPUs have reached physical scaling limits and why domain-specific accelerators win. |
| **Fri (Dec 26)** | Synthesis | **Systems Performance (Gregg)**: Review Ch 6 & 7<br>*Validating Hardware Bottlenecks* | Comparing CPU baseline execution against custom hardware theoretical speedup limits. |
| **Sat (Dec 27)** | Weekend Theory | **Elements of Information Theory**: Review Ch 1, 2, 10<br>*The Mathematical Ceiling* | The fundamental limits: Shannon entropy, Kolmogorov complexity, rate-distortion bounds. |
| **Sun (Dec 28)** | Deep Sanctuary | **Gödel, Escher, Bach**: Ch 20 (pp. 719–742)<br>*Strange Loops and Artificial Intelligence* | Synthesis of formal logic, hardware substrates, and cognitive intelligence. |
| **Mon (Dec 29)** | Architecture | *Hardware Search Accelerator Architecture Manifesto* | Finalize architectural design document: ISA, memory hierarchy, and software driver model. |
| **Tue (Dec 30)** | Verification | *Reviewing `secan` & `cennan` Benchmarks against Hardware Models* | Grounding theoretical hardware speedups against actual C++20 software baselines. |
| **Wed (Dec 31)** | Capstone | *The 2027 Hardware Founder Roadmap* | Establishing Q1 2027 plan: FPGA prototyping, Verilog/Chisel hardware description, venture pitch. |
