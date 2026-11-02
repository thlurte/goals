# Month 1 Reading Syllabus: Silicon-Software Boundary & Cache-Conscious C++ (Nov 2026)

This month lays the foundational bridge between high-performance C++20 and physical computer hardware.

---

## 📅 Week 1 (Nov 2 – Nov 8): Memory Hierarchy, Caching & Custom Allocators

| Day | Track | Book & Exact Reading Assignment | Core Takeaway / Questions to Answer |
| :--- | :--- | :--- | :--- |
| **Mon (Nov 2)** | Core Systems | **CS:APP (3rd Ed)**: §6.1–6.2 (pp. 599–620)<br>*Storage Technologies & Locality* | SRAM vs DRAM cell physics; volatile vs non-volatile; temporal vs spatial locality in loops. |
| | Bitwise ALU | **Hacker's Delight**: §2.1–2.2 (pp. 11–18)<br>*Manipulating rightmost bits* | Turn off rightmost 1-bit (`x & (x - 1)`), isolate rightmost 1-bit (`x & (-x)`). |
| **Tue (Nov 3)** | Core Systems | **CS:APP (3rd Ed)**: §6.3–6.4 (pp. 621–648)<br>*The Memory Hierarchy & Cache Memories* | Direct-mapped, set-associative, fully-associative caches. Cache line indexing, tags, and dirty bits. |
| | Bitwise ALU | **Hacker's Delight**: §2.3–2.5 (pp. 19–26)<br>*Bit testing, sign extension & power-of-two rounding* | Rounding up to powers of two; bitwise alignment `(x + a - 1) & ~(a - 1)`. |
| **Wed (Nov 4)** | Core Systems | **CS:APP (3rd Ed)**: §6.5–6.7 (pp. 649–674)<br>*Writing Cache-Friendly Code & Cache Miss Metrics* | Cache line splits; stride-1 vs stride-$k$ miss rates; impact of cache size on blocking algorithms. |
| | Bitwise ALU | **Hacker's Delight**: §2.6–2.9 (pp. 27–36)<br>*Conditional moves, absolute value without branching* | Branch-free sign detection; computing absolute value using bitwise XOR and shift. |
| **Thu (Nov 5)** | C++ Performance | **The Art of Writing Efficient C++**: Ch 3 (pp. 55–82)<br>*Memory Architecture & Data Locality* | Cache-conscious data structures; avoiding pointer chasing; flattening object graphs. |
| | Bitwise ALU | **Hacker's Delight**: §2.10–2.12 (pp. 37–44)<br>*Bounds checking without branches* | Unsigned comparison trick for range verification (`(unsigned)(x - a) < (b - a)`). |
| **Fri (Nov 6)** | C++ Performance | **The Art of Writing Efficient C++**: Ch 4 (pp. 83–114)<br>*Custom Allocators & Lifetime Management* | When `malloc` fails; monotonic arenas vs slab pools; eliminating heap locking. |
| | Bitwise ALU | **Hacker's Delight**: §3.1–3.2 (pp. 45–56)<br>*Two's complement arithmetic & bit flags* | Addition with overflow detection; hardware adder ALU carry flags. |
| **Sat (Nov 7)** | Weekend Theory | **Elements of Information Theory**: Ch 1 & §2.1–2.4 (pp. 1–28)<br>*Entropy, Relative Entropy & Mutual Information* | Definition of Entropy $H(X)$; information content; Venn diagram of mutual information $I(X; Y)$. |
| | Systems Profiling | **Systems Performance**: Ch 2 (pp. 25–58)<br>*Performance Methodologies* | The USE Method (Utilization, Saturation, Errors); latency analysis; benchmarking pitfalls. |
| **Sun (Nov 8)** | Weekend Theory | **Elements of Information Theory**: §2.5–2.9 (pp. 29–54)<br>*Chain Rules, Jensen's Inequality & Information Divergence* | Proof of $D(p \| q) \ge 0$ (KL divergence non-negativity); conditioning reduces entropy. |
| | Deep Sanctuary | **Gödel, Escher, Bach**: Ch 1 (pp. 3–32)<br>*The MU-puzzle and Formal Systems* | Axiomatic systems, typographical rules vs semantic reality. |

---

## 📅 Week 2 (Nov 9 – Nov 15): Virtual Memory, Object Lifecycle & Machine-Level Code

| Day | Track | Book & Exact Reading Assignment | Core Takeaway / Questions to Answer |
| :--- | :--- | :--- | :--- |
| **Mon (Nov 9)** | Core Systems | **CS:APP (3rd Ed)**: §9.1–9.4 (pp. 805–826)<br>*Virtual Memory as a Tool for Caching & Memory Management* | Page tables, multi-level paging, virtual address translation, page faults. |
| | Bitwise ALU | **Hacker's Delight**: §5.1 (pp. 81–90)<br>*Counting 1-Bits (Population Count)* | Parallel bit counting algorithms; the software foundation of hardware `POPCNT`. |
| **Tue (Nov 10)** | Core Systems | **CS:APP (3rd Ed)**: §9.5–9.7 (pp. 827–852)<br>*Address Translation, TLBs & Core i7 Memory System* | Translation Lookaside Buffer (TLB); TLB miss penalties; physical vs virtual indexing. |
| | Bitwise ALU | **Hacker's Delight**: §5.2–5.3 (pp. 91–102)<br>*Counting Leading & Trailing Zeros* | Binary search methods for `LZCNT` / `TZCNT`; finding vector sparse indices. |
| **Wed (Nov 11)** | Core Systems | **CS:APP (3rd Ed)**: §9.8–9.10 (pp. 853–880)<br>*Memory Mapping (mmap) & Dynamic Memory Allocation* | Zero-copy `mmap` mechanics; internal vs external fragmentation; allocator coalescing. |
| | Bitwise ALU | **Hacker's Delight**: §5.4–5.5 (pp. 103–114)<br>*Parity computation* | Parity of words; single-bit error detection in hardware registers. |
| **Thu (Nov 12)** | Core Systems | **CS:APP (3rd Ed)**: §3.1–3.7 (pp. 165–214)<br>*Machine-Level Representation of Programs (x86-64)* | 16 general-purpose registers; operand specifiers; ALU instructions; condition codes. |
| | Data-Oriented | **Data-Oriented Design**: Ch 1 & 2 (pp. 11–38)<br>*Hardware-Informed Architecture* | Array of Structs (AoS) vs Struct of Arrays (SoA); why OOP leads to poor cache utilization. |
| **Fri (Nov 13)** | Core Systems | **CS:APP (3rd Ed)**: §3.8–3.10 (pp. 215–262)<br>*Control Flow, Procedures & Stack Frames* | Return addresses; stack alignment (16-byte boundary); register saving conventions. |
| | Data-Oriented | **Data-Oriented Design**: Ch 3 (pp. 39–68)<br>*Component-Based Design* | Stream processing; separating cold metadata from hot vector components. |
| **Sat (Nov 14)** | Weekend Theory | **Elements of Information Theory**: Ch 8 (pp. 243–262)<br>*Differential Entropy & Gaussian Channels* | Entropy of continuous distributions; why the Gaussian maximizes entropy for a given variance. |
| | Systems Profiling | **Systems Performance**: Ch 6 (pp. 215–260)<br>*CPUs & Performance Monitoring Counters (PMCs)* | Instructions per cycle (IPC); branch misprediction counters; CPU pipeline stall cycles. |
| **Sun (Nov 15)** | Weekend Theory | **Elements of Information Theory**: §8.5–8.7 (pp. 263–278)<br>*Joint & Conditional Differential Entropy* | Relative entropy in continuous space; geometry of probability densities. |
| | Deep Sanctuary | **Gödel, Escher, Bach**: Ch 4 (pp. 82–126)<br>*Consistency, Completeness, and Geometry* | Non-Euclidean geometry and formal consistency. |

---

## 📅 Week 3 (Nov 16 – Nov 22): Optimizing Performance & Instruction-Level Parallelism (SIMD)

| Day | Track | Book & Exact Reading Assignment | Core Takeaway / Questions to Answer |
| :--- | :--- | :--- | :--- |
| **Mon (Nov 16)** | Core Systems | **CS:APP (3rd Ed)**: §5.1–5.6 (pp. 531–556)<br>*Optimizing Program Performance & Modern Processors* | Out-of-order execution engines; functional units; latency vs throughput bounds. |
| | Bitwise ALU | **Hacker's Delight**: §7.1–7.2 (pp. 129–140)<br>*Bit Permutation & Reversal* | Reversing bits in a word; hardware bit-swapping matrices. |
| **Tue (Nov 17)** | Core Systems | **CS:APP (3rd Ed)**: §5.7–5.10 (pp. 557–580)<br>*Loop Unrolling & Parallel Execution Units* | Breaking dependency chains; $k \times k$ unrolling; utilizing multiple execution ports. |
| | Bitwise ALU | **Hacker's Delight**: §7.3–7.4 (pp. 141–152)<br>*Bit Gathering and Scattering* | Software parallel extract and deposit (`PEXT` / `PDEP` hardware instructions). |
| **Wed (Nov 18)** | Core Systems | **CS:APP (3rd Ed)**: §5.11–5.15 (pp. 581–600)<br>*Branch Prediction & Limiting Factors* | Speculative execution; branch penalty recovery; memory throughput bottlenecks. |
| | Bitwise ALU | **Hacker's Delight**: §7.5–7.6 (pp. 153–166)<br>*Byte Permutations & Shuffle* | The algorithm behind `_mm256_shuffle_epi8` (`pshufb`); 4-bit nibble lookups. |
| **Thu (Nov 19)** | C++ Performance | **The Art of Writing Efficient C++**: Ch 5 (pp. 115–144)<br>*Vectorization & SIMD Programming* | Auto-vectorization failure modes; explicit intrinsics; AVX2 vs AVX-512 register layout. |
| | Data-Oriented | **Data-Oriented Design**: Ch 4 (pp. 69–96)<br>*Searching & Sorting Data* | Cache-line aligned linear scans vs binary search; branchless search layouts. |
| **Fri (Nov 20)** | C++ Performance | **The Art of Writing Efficient C++**: Ch 6 (pp. 145–178)<br>*High-Performance Arithmetic & FMA* | Fused Multiply-Add instruction scheduling; register pressure; loop tiling. |
| | Data-Oriented | **Data-Oriented Design**: Ch 5 (pp. 97–120)<br>*Data Transformations* | Streaming SIMD transforms; in-place data rearrangement. |
| **Sat (Nov 21)** | Weekend Theory | **Elements of Information Theory**: §10.1–10.4 (pp. 303–324)<br>*Rate Distortion Theory: Foundations* | Distortion metrics; rate-distortion function $R(D)$; theoretical minimum bits for fidelity. |
| | Systems Profiling | **Systems Performance**: Ch 7 (pp. 261–308)<br>*Memory Performance & Bus Saturation* | Memory bus bandwidth limits; NUMA node latency; cache miss profiling with `perf`. |
| **Sun (Nov 22)** | Weekend Theory | **Elements of Information Theory**: §10.5–10.8 (pp. 325–348)<br>*Rate Distortion for Gaussian Sources* | Analytical proof of $R(D) = \frac{1}{2} \log_2(\sigma^2 / D)$; why vector quantization beats scalar. |
| | Deep Sanctuary | **The Road to Reality**: Ch 1 & 2 (pp. 7–34)<br>*The Roots of Science & Pythagorean Theorem* | Foundations of geometry; mathematical realism vs physical manifestation. |

---

## 📅 Week 4 (Nov 23 – Nov 30): Concurrency, Atomics & Multi-Core Hardware

| Day | Track | Book & Exact Reading Assignment | Core Takeaway / Questions to Answer |
| :--- | :--- | :--- | :--- |
| **Mon (Nov 23)** | Core Systems | **CS:APP (3rd Ed)**: §12.1–12.4 (pp. 1017–1046)<br>*Concurrent Programming: Processes & Threads* | Thread execution models; shared variables; synchronization races. |
| | Bitwise ALU | **Hacker's Delight**: §11.1–11.2 (pp. 241–254)<br>*Integer Division by Constants* | Replacing expensive `div` instructions with multiplication by magic constants and shifts. |
| **Tue (Nov 24)** | Core Systems | **CS:APP (3rd Ed)**: §12.5–12.8 (pp. 1047–1080)<br>*Synchronizing Threads with Semaphores & Mutexes* | Deadlock conditions; mutual exclusion invariants; thread-safe libraries. |
| | Bitwise ALU | **Hacker's Delight**: §11.3–11.4 (pp. 255–268)<br>*Unsigned Division by Constants* | Hardware implementation of constant dividers in ALUs and address decoders. |
| **Wed (Nov 25)** | C++ Performance | **The Art of Writing Efficient C++**: Ch 9 (pp. 235–270)<br>*Concurrency & The C++ Memory Model* | Sequential consistency vs relaxed orders; atomic operations; memory fences. |
| | Bitwise ALU | **Hacker's Delight**: §12.1–12.2 (pp. 273–286)<br>*Floating-Point Bit Tricks* | IEEE 754 bit layout; extracting exponent and mantissa directly in integer registers. |
| **Thu (Nov 26)** | C++ Performance | **The Art of Writing Efficient C++**: Ch 10 (pp. 271–310)<br>*Lock-Free Programming & Atomic Queues* | Compare-And-Swap (CAS) loops; ABA problem; SPSC lock-free ring buffer design. |
| | Bitwise ALU | **Hacker's Delight**: §13.1–13.2 (pp. 291–304)<br>*Formulas for powers of two & mod operations* | Modulo arithmetic for ring buffers with $2^k$ capacities (`idx & (cap - 1)`). |
| **Fri (Nov 27)** | Systems Profile | **Systems Performance**: Ch 3 (pp. 59–106)<br>*Operating System Internals* | Context switching overhead; kernel scheduler queues; CPU affinity / pinning. |
| | Bitwise ALU | **Hacker's Delight**: §14.1–14.3 (pp. 309–320)<br>*Hilbert Curves & Space-Filling Curves* | Generating 2D/3D space-filling coordinates for spatial index locality. |
| **Sat (Nov 28)** | Weekend Theory | **Elements of Information Theory**: Ch 14 (pp. 409–438)<br>*Kolmogorov Complexity & Algorithmic Information* | The shortest program that outputs a string; entropy as expected Kolmogorov complexity. |
| | Systems Profiling | **Systems Performance**: Ch 11 (pp. 505–550)<br>*Profiling Tools: perf, eBPF & Flame Graphs* | CPU flame graphs; identifying instruction stall hotspots and kernel locks. |
| **Sun (Nov 29)** | Weekend Theory | **Elements of Information Theory**: Ch 14 cont. (pp. 439–460)<br>*Universal Compression Limits* | Minimum description length principle; limits of lossless vs lossy index compression. |
| | Deep Sanctuary | **The Road to Reality**: Ch 3 & 4 (pp. 35–65)<br>*Complex Numbers & Geometry of Logarithms* | Complex plane geometry; Riemann surfaces as the root of analytic functions. |
| **Mon (Nov 30)** | Architecture Prep | **Hennessy & Patterson (6th Ed)**: §1.1–1.3 (pp. 2–20)<br>*Introduction to Quantitative Computer Architecture* | Classes of computers; technology trends; transistor scaling and the end of Dennard scaling. |
| | Bitwise ALU | **Hacker's Delight**: Review Chapter 2 & 5<br>*Synthesis of bitwise ALU instructions* | Reviewing bit manipulation patterns before starting computer architecture in Month 2. |
