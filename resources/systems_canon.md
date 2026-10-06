# 📚 Primary Sources, Seminal Papers & Systems Canon

A rigorous, authoritative bibliography of primary textbooks, vendor microarchitectural manuals, and seminal papers anchoring all algorithmic choices, SIMD kernels, cache layouts, and hardware performance metrics across `secan` and `cennan`.

---

## 🏛️ 1. Foundational Computer Architecture & Systems Books

| Absolute Title & Edition | Authors | Publisher / Standard Citation | Core Technical Application |
| :--- | :--- | :--- | :--- |
| **[Computer Systems: A Programmer's Perspective (3rd ed)](https://csapp.cs.cmu.edu/)** | Randal E. Bryant & David R. O'Hallaron | Pearson (2015) | Machine-level representation of programs, memory hierarchy, cache organization, processor architecture, and linking. |
| **[Computer Architecture: A Quantitative Approach (6th/7th ed)](https://shop.elsevier.com/books/computer-architecture/hennessy/978-0-443-15406-5)** | John L. Hennessy & David A. Patterson | Morgan Kaufmann / Elsevier | Quantitative cache performance ($	ext{AMAT}$), instruction-level parallelism, branch prediction, vector processing, and memory bandwidth bounds. |
| **[Performance Analysis and Tuning on Modern CPUs (2nd ed)](https://github.com/dendibakh/perf-book)** | Denis Bakhvalov | Performance Tuning (2024) | Top-Down Microarchitecture Analysis (TMA), PMU hardware counters, compiler optimizations, branch misprediction mitigation, and memory profiling. |
| **[Systems Performance: Enterprise and the Cloud (2nd ed)](https://www.brendangregg.com/systems-performance-2nd-edition-book.html)** | Brendan Gregg | Addison-Wesley (2020) | USE method, CPU utilization vs saturation, off-CPU profiling, PMU counter architecture, and Flame Graphs. |
| **[Is Parallel Programming Hard, And, If So, What Can You Do About It? (Perfbook)](https://mirrors.edge.kernel.org/pub/linux/kernel/people/paulmck/perfbook/perfbook.html)** | Paul E. McKenney | Linux Foundation (2024) | Hardware cache coherence (MESI/MOESI), false sharing, memory barriers, read-copy update (RCU), and non-blocking synchronization. |
| **[Hacker's Delight (2nd ed)](https://en.wikipedia.org/wiki/Hacker%27s_Delight)** | Henry S. Warren, Jr. | Addison-Wesley (2012) | Branchless bitwise manipulation, fast population count algorithms, integer bit packing, and power-of-two arithmetic. |
| **[Database Internals: A Deep Dive into How Distributed Data Systems Work](https://www.oreilly.com/library/view/database-internals/9781492040330/)** | Alex Petrov | O'Reilly Media (2019) | B-Trees, LSM-Trees, immutable SSTables, memtables, write-ahead logs, and disk I/O optimization. |
| **[The Art of Computer Programming, Vol 3: Sorting and Searching (2nd ed)](https://www-cs-faculty.stanford.edu/~knuth/taocp.html)** | Donald E. Knuth | Addison-Wesley (1998) | External sorting, multiway search trees, optimal search algorithms, and exact algorithmic complexity. |

---

## 📐 2. Mathematical, Statistical & Algorithmic Foundations

| Absolute Title & Edition | Authors | Publisher / Citation | Core Technical Application |
| :--- | :--- | :--- | :--- |
| **[High-Dimensional Probability: An Introduction with Applications in Data Science](https://www.math.uci.edu/~rvershyn/papers/HDP-book/HDP-book.html)** | Roman Vershynin | Cambridge University Press (2018) | Concentration of measure, Johnson-Lindenstrauss lemma, sub-Gaussian random vectors, covering numbers, and bounding quantization distortion. |
| **[Matrix Computations (4th ed)](https://jhupbooks.press.jhu.edu/title/matrix-computations)** | Gene H. Golub & Charles F. Van Loan | Johns Hopkins University Press (2013) | Numerical linear algebra, singular value decomposition (SVD), QR factorization, Rayleigh quotients, and numerical stability. |
| **[Numerical Optimization (2nd ed)](https://link.springer.com/book/10.1007/978-0-387-40065-5)** | Jorge Nocedal & Stephen J. Wright | Springer (2006) | Unconstrained optimization, line search methods, conjugate gradients, quasi-Newton (BFGS/L-BFGS), and trust-region algorithms. |
| **[Linear Algebra and Learning from Data](https://math.mit.edu/~gs/learningfromdata/)** | Gilbert Strang | Wellesley-Cambridge Press (2019) | Low-rank matrix approximations, eigenvalues/eigenvectors, principal component analysis (PCA), and deep learning mathematics. |
| **[Elements of Information Theory (2nd ed)](https://www.wiley.com/en-us/Elements+of+Information+Theory%2C+2nd+Edition-p-9780471241959)** | Thomas M. Cover & Joy A. Thomas | Wiley-Interscience (2006) | Shannon entropy, mutual information, Asymptotic Equipartition Property (AEP), rate-distortion theory $R(D)$, and optimal vector quantization bounds. |
| **[Probability Theory: The Logic of Science](https://bayes.wustl.edu/)** | Edwin T. Jaynes | Cambridge University Press (2003) | Bayesian inference as extended Boolean logic, Maximum Entropy Principle, and objective priors. |
| **[Similarity Search: The Metric Space Approach](https://link.springer.com/book/10.1007/0-387-29151-2)** | Pavel Zezula, Giuseppe Amato, Vlastislav Dohnal, Michal Batko | Springer (2006) | Metric postulates, triangle inequality pruning, vantage-point trees, and high-dimensional space partitioning. |
| **[Introduction to Information Retrieval](https://nlp.stanford.edu/IR-book/)** | Christopher D. Manning, Prabhakar Raghavan, Hinrich Schütze | Cambridge University Press (2008) | Inverted index architectures, posting list compression, dynamic index pruning, and scoring models. |

---

## ⚡ 3. Hardware Vendor Manuals & Microarchitectural Guides

| Absolute Document Title | Publisher / Author | Reference URL |
| :--- | :--- | :--- |
| **Optimizing Software in C++** | Agner Fog | [agner.org/optimize/optimizing_cpp.pdf](https://www.agner.org/optimize/optimizing_cpp.pdf) |
| **Instruction Tables: Lists of Instruction Latencies, Throughputs and Micro-operation Breakdowns** | Agner Fog | [agner.org/optimize/instruction_tables.pdf](https://www.agner.org/optimize/instruction_tables.pdf) |
| **Intel 64 and IA-32 Architectures Optimization Reference Manual** | Intel Corporation | [Intel Optimization Manual](https://www.intel.com/content/www/us/en/content-details/671488/intel-64-and-ia-32-architectures-optimization-reference-manual-volume-1.html) |
| **Software Optimization Guide for AMD Family 19h (Zen 4) / Family 1Ah (Zen 5)** | AMD | [AMD Zen 4 Guide](https://docs.amd.com/v/u/en-US/58455_1.00) |
| **What Every Programmer Should Know About Memory** | Ulrich Drepper | [akkadia.org/drepper/cpumemory.pdf](https://www.akkadia.org/drepper/cpumemory.pdf) |
| **Memory Barriers: A Hardware View for Software Hackers** | Paul E. McKenney | [whymb.2010.07.23a.pdf](http://www.rdrop.com/users/paulmck/scalability/paper/whymb.2010.07.23a.pdf) |

---

## 🚀 4. GPU Architecture & Massively Parallel Computing

| Absolute Title & Edition | Authors | Publisher / Standard Citation |
| :--- | :--- | :--- |
| **[Programming Massively Parallel Processors: A Hands-on Approach (4th ed)](https://www.sciencedirect.com/book/9780323912310/programming-massively-parallel-processors)** | David B. Kirk & Wen-mei W. Hwu | Morgan Kaufmann (2022) |
| **[CUDA C++ Programming Guide](https://docs.nvidia.com/cuda/cuda-c-programming-guide/)** | NVIDIA Corporation | NVIDIA Developer Documentation |
| **[CUDA C++ Best Practices Guide](https://docs.nvidia.com/cuda/cuda-c-best-practices-guide/)** | NVIDIA Corporation | NVIDIA Developer Documentation |
| **[CUTLASS: Fast Linear Algebra Operations in CUDA C++](https://github.com/NVIDIA/cutlass)** | NVIDIA Corporation | NVIDIA Developer Documentation |

---

## 📄 5. Seminal Vector Search & Systems Papers

| Paper Title | Authors | Conference / Journal |
| :--- | :--- | :--- |
| **Product Quantization for Nearest Neighbor Search** | Hervé Jégou, Matthijs Douze, Cordelia Schmid | IEEE TPAMI (2011) |
| **Efficient and Robust Approximate Nearest Neighbor Search Using Hierarchical Navigable Small World Graphs (HNSW)** | Yu. A. Malkov, D. A. Yashunin | IEEE TPAMI (2018) |
| **Billion-Scale Similarity Search with GPUs (FAISS)** | Jeff Johnson, Matthijs Douze, Hervé Jégou | IEEE Transactions on Big Data (2019) |
| **Accelerating Large-Scale Inference with Anisotropic Vector Quantization (ScaNN)** | Ruiqi Guo, Philip Sun, Erik Lindgren, Quan Geng, David Simcha, Felix Chern, Sanjiv Kumar | ICML (2020) |
| **DiskANN: Fast Accurate Bil-Scale Nearest Neighbor Search on a Single Node** | Suhas Jayaram Subramanya, Devvrit, Rohan Kadekodi, Ravishankar Krishaswamy, Ravishankar Narayanan | NeurIPS (2019) |
| **RaBitQ: Quantizing High-Dimensional Vectors with a Bit** | Jianyang Gao, Cheng Long | ACM SIGMOD (2024) |
| **ColBERT: Efficient and Effective Passage Search via Contextualized Late Interaction over BERT** | Omar Khattab, Matei Zaharia | ACM SIGIR (2020) |
| **FlashAttention-2: Faster Attention with Better Parallelism and Work Partitioning** | Tri Dao | ICLR (2024) |
| **CAGRA: Highly Efficient GPU Graph-Based Approximate Nearest Neighbors Search** | Hiroyuki Ootomo, Akira Naruse, Corey Nolet, Ray Wang | arXiv (2023) |
