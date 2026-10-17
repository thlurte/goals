# 🚀 Systems & Vector Search Engineering Intensive (Oct 17 – Nov 30, 2026)
### Comprehensive Proposal & Executive Syllabus for Technical Review

---

## 1. Executive Summary & Objective

- **Candidate**: Systems / Vector Search / High-Performance Computing (HPC) Engineer Candidate.
- **Core Mission**: Build deep, first-principles systems engineering mastery in modern C++20, CPU microarchitecture, concurrency, SIMD vectorization, and vector search algorithms.
- **Duration**: **6.5 Weeks** (Saturday, October 17, 2026 – Monday, November 30, 2026).
- **Core Doctrine (No "Vibe Coding")**:
  - **Zero AI-generated boilerplate**: Every drill is implemented from a completely blank `.cpp` file by the candidate.
  - **No blind library usage**: Primitives (smart pointers, bump allocators, thread pools, SIMD distance kernels, Voronoi coarse quantizers, HNSW priority search) are built from scratch before using library versions.
  - **Deliberate Portfolio Deliverable**: Incremental, verified contributions to [`secan`](https://github.com/thlurte/secan) (a high-performance C++20 vector search engine library).

---

## 2. Workload & Cadence Breakdown

- **Weekdays (Mon – Fri)**: **3 Standalone Drills / day** (~2 to 2.5 hours) + 1 deliberate `secan` task.
- **Weekends (Sat & Sun)**: **Double Workload (5 to 6 Standalone Drills / day)** (~4 to 5 hours) + **45-minute timed exam (No Notes, No AI)** + major subsystem integration in `secan`.
- **Total Output**: **168 standalone C++ systems drills** + **6 weekly timed exams** + **production release of `secan v0.2.0`**.

---

## 3. Canonical Bibliography (Textbooks & Primary Sources)

| Code | Title & Edition | Authors | Publisher | Core Focus Area |
| :--- | :--- | :--- | :--- | :--- |
| **[CS:APP]** | *Computer Systems: A Programmer's Perspective (3rd ed)* | Bryant & O'Hallaron | Pearson (2015) | Machine-level representation, cache lines, virtual memory, `mmap`, and dynamic allocation. |
| **[ArtOfProg]** | *The Art of Writing Efficient Programs* | Fedor Pikus | Packt (2021) | Modern C++ performance, RAII, memory layouts, false sharing, and concurrency models. |
| **[C++Concurrency]** | *C++ Concurrency in Action (2nd ed)* | Anthony Williams | Manning (2019) | Thread lifecycles, atomics, `std::memory_order`, lock-free queues, and thread pools. |
| **[AgnerFog]** | *Optimizing Software in C++ & Instruction Tables* | Agner Fog | Technical University of Denmark | SIMD intrinsics, execution port throughput, cycle latencies, and branch prediction. |
| **[Hacker's Delight]** | *Hacker's Delight (2nd ed)* | Henry S. Warren | Addison-Wesley (2012) | Bitwise arithmetic, population count, trailing zero count (`_tzcnt_u64`), bit-packing. |
| **[Systems Perf]** | *Systems Performance: Enterprise and the Cloud (2nd ed)* | Brendan Gregg | Addison-Wesley (2020) | PMU hardware counters, IPC, cache miss analysis with Linux `perf`, FlameGraphs. |
| **[Seminal Paper 1]**| *Product Quantization for Nearest Neighbor Search* | Jégou, Douze, Schmid | IEEE TPAMI (2011) | Subspace decomposition, Voronoi cells, and Asymmetric Distance Computation (ADC). |
| **[Seminal Paper 2]**| *Efficient & Robust Approx Nearest Neighbor Search (HNSW)* | Malkov & Yashunin | IEEE TPAMI (2018) | Hierarchical small-world graphs, greedy routing, and heuristic diversity pruning. |

---

## 4. Master 6.5-Week Day-by-Day Syllabus

### 🏁 Weekend Kickoff: Oct 17 – 18, 2026 (Memory Fundamentals)
- **Reading**: **[CS:APP]** §9.9 (Dynamic Memory Allocation, pp. 864–892) & **[ArtOfProg]** Ch 3 (Memory Architecture, pp. 55–80).
- **Saturday, Oct 17 (3 Drills)**:
  1. `drill_w0_1_bump_arena.cpp`: Bump arena with power-of-two alignment calculation and placement `new`.
  2. `drill_w0_2_arena_bench.cpp`: 2,000,000 allocations benchmark vs `malloc/free` using `asm volatile`.
  3. `drill_w0_3_chained_arena.cpp`: Growable chained arena with dynamic chunk linked lists.
  - 🛠️ **`secan`**: Scaffold `secan/include/secan/memory/arena.h`.
- **Sunday, Oct 18 (3 Drills)**:
  4. `drill_w0_4_unique_ptr.cpp`: `UniquePtr<T>` with move semantics, custom deleters, and self-move protection.
  5. `drill_w0_5_cache_stride.cpp`: Row-major vs column-major $4096 \times 4096$ float matrix cache stride profiling via `perf stat`.
  6. `drill_w0_6_false_sharing.cpp`: 4-thread false sharing reproduction & `alignas(64)` cache line elimination.
  - 🛠️ **`secan`**: Commit `secan/tests/test_arena.cpp` (clean passes under `-fsanitize=address`).

---

### Week 1: Oct 19 – 25, 2026 (C++ Memory Mastery, RAII & Custom Allocators)
- **Mon, Oct 19**:
  - 📖 **[ArtOfProg]** Ch 2 (Value types, moves, pp. 25–45).
  - 💻 Drills: `SharedPtr<T>` with atomic control block, Rule-of-Five aligned buffer container, `ScopeGuard` / `defer` RAII macro.
  - 🛠️ **`secan`**: Audit ownership semantics across `secan` index headers.
- **Tue, Oct 20**:
  - 📖 **[CS:APP]** §6.1–6.4 (Locality, Cache Memories, pp. 605–645).
  - 💻 Drills: Tiled $B \times B$ cache-blocked matrix transpose, AoS vs flat contiguous SoA vector storage, vector dimension pitch-padding (padding rows to 64 bytes).
  - 🛠️ **`secan`**: Implement `secan/include/secan/common/dataset.h`.
- **Wed, Oct 21**:
  - 📖 **[AgnerFog]** §7 & §8 (Memory access, stack frames, pp. 35–55).
  - 💻 Drills: Zero-heap stack `FixedVector<T, Capacity>`, Small Buffer Optimization `SmallVector<T, SmallCap>`, C++20 `AlignedAllocator<T, 64>`.
  - 🛠️ **`secan`**: Implement `secan/include/secan/memory/fixed_vector.h`.
- **Thu, Oct 22**:
  - 📖 **[ArtOfProg]** Ch 3 (MESI cache coherence, pp. 55–80).
  - 💻 Drills: Struct field reordering for minimal padding, cache-aligned circular queue, intrusive reference counting (`IntrusivePtr<T>`).
  - 🛠️ **`secan`**: Pad search stats structs in `secan/include/secan/utils/stats.h` to 64 bytes.
- **Fri, Oct 23**:
  - 📖 **[CS:APP]** §9.9.6–9.9.12 (Free lists & segregated lists, pp. 882–892).
  - 💻 Drills: Fixed-size slab object pool with intrusive freelist, pool vs glibc `new/delete` benchmark, custom global `operator new` byte tracker.
  - 🛠️ **`secan`**: Add object pool memory containers to `secan`.
- **💥 Sat, Oct 24 (Double Workload - 6 Drills)**:
  - 💻 Drills: Transparent Huge Pages (`madvise(MADV_HUGEPAGE)` vs 4KB pages), AddressSanitizer stress test (double-free / heap overread debugging), `std::pmr::monotonic_buffer_resource` custom upstream, strict aliasing & `std::bit_cast`, runtime memory leak detector, cache-oblivious matrix transposition.
  - 🛠️ **`secan`**: Integrate `FixedVector` into search candidate queues.
- **💥 Sun, Oct 25 (Double Workload + Exam)**:
  - 💻 Drills: 5 edge-case memory drills (custom deleters with `mmap`, placement `new` array destruction, non-temporal streaming stores `_mm_stream_ps`).
  - ⏱️ **TIMED EXAM (45 min, Blank Slate, No AI, No Notes)**: Code `ArenaAllocator` + `UniquePtr<T>` + `PaddedCounter` from a blank file under `-Wall -Wextra -Werror`.
  - 🛠️ **`secan`**: Run full test suite under AddressSanitizer (100% clean passes).

---

### Week 2: Oct 26 – Nov 1, 2026 (Multi-Threading, Concurrency & Atomics)
- **Mon, Oct 26**:
  - 📖 **[C++Concurrency]** Ch 2 & 3 (Managing threads, mutexes, pp. 15–72).
  - 💻 Drills: RAII `ThreadGuard`, deadlock reproduction & `std::scoped_lock` resolution, thread-safe stack with condition variable.
  - 🛠️ **`secan`**: Design thread lifecycle abstraction in `secan`.
- **Tue, Oct 27**:
  - 📖 **[C++Concurrency]** Ch 5 (Atomic types & C++ memory model, pp. 115–150).
  - 💻 Drills: Spinlock via `std::atomic_flag` (`acquire/release`), two-thread atomic message handshake without mutexes, lock-free saturating counter via `compare_exchange_weak`.
  - 🛠️ **`secan`**: Implement lock-free index state tracking (`secan/include/secan/common/status.h`).
- **Wed, Oct 28**:
  - 📖 **[C++Concurrency]** Ch 9 (Advanced thread management, thread pools, pp. 275–305).
  - 💻 Drills: Bounded blocking queue, production `ThreadPool` with `submit()` returning `std::future<R>`, `parallel_for` range partitioner.
  - 🛠️ **`secan`**: Implement `secan/include/secan/concurrency/thread_pool.h`.
- **Thu, Oct 29**:
  - 📖 **[ArtOfProg]** Ch 9 & 10 (Concurrency, lock contention, pp. 280–340).
  - 💻 Drills: Readers-writer benchmark (`std::shared_mutex` vs `std::mutex`), `ConcurrentBitset` using atomic words (`std::atomic<uint64_t>`), lock-free SPSC ring buffer.
  - 🛠️ **`secan`**: Implement `secan/include/secan/concurrency/concurrent_bitset.h`.
- **Fri, Oct 30**:
  - 📖 **[C++Concurrency]** Ch 6 (Concurrent data structure design, pp. 165–190).
  - 💻 Drills: Sharded / striped mutex hash map (16 independent bucket locks), thread affinity pinning via `pthread_setaffinity_np`, TSAN data race diagnosis and fix.
  - 🛠️ **`secan`**: Wire `ThreadPool` into batch vector ingestion.
- **💥 Sat, Oct 31 (Double Workload - 6 Drills)**:
  - 💻 Drills: Treiber's lock-free stack, ABA problem reproduction, tagged pointer ABA resolution, lock-free read-copy-update (RCU) prototype, `std::counting_semaphore` query throttling, double-checked locking with acquire/release.
  - 🛠️ **`secan`**: Ingest 100,000 vectors across 12 threads with zero race conditions.
- **💥 Sun, Nov 1 (Double Workload + Exam)**:
  - 💻 Drills: 5 lock-free edge cases (lock hierarchy ranking, CAS weak vs strong loops, atomic bitwise bit-hopping).
  - ⏱️ **TIMED EXAM (45 min, Blank Slate)**: Code a bounded thread-safe queue and a functional thread pool from scratch.
  - 🛠️ **`secan`**: Run full test suite under ThreadSanitizer (`-fsanitize=thread`) with 0 data races.

---

### Week 3: Nov 2 – 8, 2026 (SIMD Intrinsics, FastScan & ColBERT MaxSim)
- **Mon, Nov 2**:
  - 📖 **[AgnerFog]** §12 & §13 (SIMD vector programming, pp. 95–130).
  - 💻 Drills: Aligned vs unaligned loads (`_mm256_load_ps` vs `_mm256_loadu_ps`), AVX2 dot product, fast horizontal shuffle sum (`_mm256_extractf128_ps`, `_mm_movehdup_ps`, `_mm_add_ss`).
  - 🛠️ **`secan`**: Scaffold `secan/include/secan/search/distance_avx2.h`.
- **Tue, Nov 3**:
  - 📖 **[ArtOfProg]** Ch 6 (Vectorization & loop optimizations, pp. 160–190).
  - 💻 Drills: 1-acc vs 2-acc vs 4-acc unrolling benchmark (proving 1.6x–1.8x gain by saturating 0.5-cycle FMA ports), disassembly inspection for zero register spills, 4-way unrolled Inner Product kernel.
  - 🛠️ **`secan`**: Integrate 4-accumulator unrolled FP32 distance kernels into `secan`.
- **Wed, Nov 4**:
  - 📖 **[CS:APP]** §5.1–5.7 (Loop unrolling & branch penalties, pp. 531–558).
  - 💻 Drills: Branch-predictable remainder handling (`+16`, `+8`, scalar tail), unaligned dimension benchmark ($D=63, 127, 768, 775$), Cosine distance delegation.
  - 🛠️ **`secan`**: Handle non-multiple-of-8 vector dimensions cleanly without scalar performance drops.
- **Thu, Nov 5**:
  - 📖 **[Intel Optimization Reference Manual]** / **[AgnerFog]** (AVX-512 masking & ZMM registers).
  - 💻 Drills: AVX-512 masked tail load (`_mm512_maskz_loadu_ps`), folded masked tail into `acc3` before single reduction, runtime CPUID dynamic feature dispatching.
  - 🛠️ **`secan`**: Add `secan/include/secan/search/distance_avx512.h` with folded masked tail.
- **Fri, Nov 6**:
  - 📖 **FastScan Architecture** (FAISS FastScan & Muła/Lemire SIMD lookup tables).
  - 💻 Drills: In-register 16-entry LUT evaluation with `_mm256_shuffle_epi8` (`vpshufb`), 4-bit nibble unpacking (`_mm256_and_si256`, `_mm256_srli_epi16`), FastScan distance accumulation in 16-bit integers.
  - 🛠️ **`secan`**: Implement `secan/include/secan/quantization/fastscan.h`.
- **💥 Sat, Nov 7 (Double Workload - 6 Drills)**:
  - 💻 Drills: **ColBERT MaxSim Multi-Vector scoring kernel** ($\sum \max Q_i \cdot D_j$), AVX2 Harley-Seal vector popcount, Hamming distance via `_mm256_xor_si256`, Jaccard distance on bitsets, 1-to-4 batch distance kernel, software prefetching (`_mm_prefetch`).
  - 🛠️ **`secan`**: Add 1-to-N batch distance routines for top-$k$ candidate scoring.
- **💥 Sun, Nov 8 (Double Workload + Exam)**:
  - 💻 Drills: 5 SIMD edge cases (unaligned loop peeling, AVX2 `_mm256_movemask_ps` threshold filtering, FP16 conversions `_mm256_cvtph_ps`).
  - ⏱️ **TIMED EXAM (45 min, Blank Slate)**: Code an AVX2 L2 distance kernel with 4 accumulators AND a `vpshufb` FastScan LUT lookup from scratch.
  - 🛠️ **`secan`**: Benchmark distance kernels across $D \in \{64, 128, 256, 512, 768, 775, 1024, 1536\}$.

---

### Week 4: Nov 9 – 15, 2026 (Inverted File / IVF, SQ4/SQ2 Bit-Packing & FastScan)
- **Mon, Nov 9**:
  - 📖 **[Zezula et al.]** & FAISS IVF documentation.
  - 💻 Drills: Inverted posting list container from scratch, coarse Voronoi quantizer (k-means clustering to route queries to top-$n_{\text{probe}}$ lists), IVF Recall vs $n_{\text{probe}}$ benchmark.
  - 🛠️ **`secan`**: Scaffold `secan/include/secan/index/ivf_fastscan.h`.
- **Tue, Nov 10**:
  - 📖 Sub-byte quantization: 4-bit nibbles and 2-bit codes.
  - 💻 Drills: SQ4 nibble packing (`(a & 0xF) | (b << 4)`), SQ2 bit-packing (4 values/byte), strided 32-byte layout transformation (rearranging data so byte $i$ holds dimension $k$ for vector $i$).
  - 🛠️ **`secan`**: Implement `secan/include/secan/quantization/bit_packing.h`.
- **Wed, Nov 11**:
  - 📖 In-Register FastScan lookups.
  - 💻 Drills: FastScan query distance quantization to 8-bit LUTs, scanning 32 vectors simultaneously via `vpshufb`, FastScan vs FP32 throughput benchmark (proving **4x to 8x throughput gain**).
  - 🛠️ **`secan`**: Wire FastScan matcher into inverted posting list traversal.
- **Thu, Nov 12**:
  - 📖 **[Jégou et al. (2011)]** PQ with $K=16$ centroids (PQ4 FastScan).
  - 💻 Drills: Training $M=16$ subvector codebooks with $K=16$ centroids, PQ4 strided encoding, back-to-back `vpshufb` cycles without main memory loads during accumulation.
  - 🛠️ **`secan`**: Combine Product Quantization with FastScan in `secan`.
- **Fri, Nov 13**:
  - 📖 End-to-end IVF-FastScan index architecture.
  - 💻 Drills: `IVFFastScanIndex` build (partition 100k vectors into 128 lists), query traversal (coarse routing $\to$ LUT generation $\to$ FastScan streaming), bounded top-$k$ heap accumulation.
  - 🛠️ **`secan`**: Full implementation of `secan::index::IvfFastScanIndex`.
- **💥 Sat, Nov 14 (Double Workload - 6 Drills)**:
  - 💻 Drills: SQ8 affine scalar quantizer, symmetric vs asymmetric SQ8 integer distance, outlier percentile clipping (99.9% clipping), memory bandwidth saturation proof (showing FastScan shifts search from memory-bound to compute-bound), IVF-FastScan Recall@10 vs QPS Pareto frontier, empty cluster handling in k-means.
  - 🛠️ **`secan`**: Add comprehensive IVF-FastScan benchmarks to `secan/benchmarks/`.
- **💥 Sun, Nov 15 (Double Workload + Exam)**:
  - 💻 Drills: 5 quantization edge cases (handling zero-variance dimensions, NaN detection in centroids, residual vector quantization basics).
  - ⏱️ **TIMED EXAM (45 min, Blank Slate)**: Code an AVX2 `vpshufb` 32-vector FastScan kernel and strided bit unpacker from scratch.
  - 🛠️ **`secan`**: Commit clean IVF-FastScan subsystem to `secan`.

---

### Week 5: Nov 16 – 22, 2026 (HNSW Graph, Filtered Search & Low-Selectivity Bypass)
- **Mon, Nov 16**:
  - 📖 **[Malkov & Yashunin (2018)]** §1 & §2 (NSW topology, greedy routing).
  - 💻 Drills: Basic adjacency graph struct, `greedy_search` loop (hop to closest neighbor until local minimum), local minima trapping demonstration on poorly connected graphs.
  - 🛠️ **`secan`**: Design HNSW graph representation in `secan/include/secan/index/hnsw.h`.
- **Tue, Nov 17**:
  - 📖 **[Malkov & Yashunin (2018)]** §3 (Algorithm 1: `SEARCH-LAYER`).
  - 💻 Drills: Twin candidate heaps (`candidates` min-heap, `results` max-heap bounded by $ef$), full `SEARCH-LAYER` implementation, Recall vs $ef$ benchmark on 10,000 vectors.
  - 🛠️ **`secan`**: Implement `search_layer` in `secan`.
- **Wed, Nov 18**:
  - 📖 Filtered Vector Search Architecture (Single-stage vs post-filtering).
  - 💻 Drills: Integrating `ConcurrentBitset` into HNSW `SEARCH-LAYER` (ensuring invalid nodes still remain in candidate queue to maintain graph path connectivity), filtered recall benchmark, measuring graph path disconnection when selectivity drops below 2%.
  - 🛠️ **`secan`**: Add `FilteredSearch` API to `secan::index::HnswIndex`.
- **Thu, Nov 19**:
  - 📖 Adaptive Filtered Search Strategy.
  - 💻 Drills: Filter selectivity estimator ($\text{popcount} / N$), **The $< 2\%$ Low-Selectivity SIMD Flat Bypass** (bypassing HNSW entirely and bit-hopping surviving candidates via `_tzcnt_u64`), adaptive switch benchmark proving **100% recall and 10x higher QPS** on 0.5% selectivity.
  - 🛠️ **`secan`**: Implement adaptive low-selectivity bypass in `secan/src/search/filtered_search.cpp`.
- **Fri, Nov 20**:
  - 📖 Cache-friendly graph serialization.
  - 💻 Drills: Scattered pointer graph vs flat contiguous buffer (`uint32_t* edges` with fixed capacity $M$), `SEARCH-LAYER` on flat buffer with offset math, measuring 2x–3x speedup via `perf stat -e L1-dcache-load-misses`.
  - 🛠️ **`secan`**: Refactor `secan` HNSW storage to a single contiguous flattened buffer.
- **💥 Sat, Nov 21 (Double Workload - 6 Drills)**:
  - 💻 Drills: Exponential level assignment ($l = \lfloor -\ln(u) \cdot m_L \rfloor$), top-down hierarchical entry-point navigation, heuristic neighbor diversity pruning (triangle inequality check), multi-threaded HNSW insertion using `ThreadPool`, graph connectivity degree distribution verification, dynamic vector deletion via `TombstoneBitset`.
  - 🛠️ **`secan`**: End-to-end HNSW verification on SIFT1M subset (verify Recall@10 $> 0.95$).
- **💥 Sun, Nov 22 (Double Workload + Exam)**:
  - 💻 Drills: 5 graph edge cases (isolated node recovery, handling empty search results, dynamic entry point updates).
  - ⏱️ **TIMED EXAM (45 min, Blank Slate)**: Code `SEARCH-LAYER` with `ConcurrentBitset` filtering AND the $< 2\%$ SIMD flat bypass from a blank file.
  - 🛠️ **`secan`**: Commit clean HNSW module to `secan`.

---

### Week 6: Nov 23 – 30, 2026 (Systems Profiling, Zero-Copy `mmap`/`io_uring` & Interview Defense)
- **Mon, Nov 23**:
  - 📖 **[CS:APP]** §9.8 (Memory Mapping, pp. 855–864) & Linux `io_uring` design.
  - 💻 Drills: Zero-copy `mmap` binary vector reader with `madvise(MADV_WILLNEED)`, streaming IVF posting lists via `mmap` + `MADV_SEQUENTIAL`, sector-aligned (4096 bytes) asynchronous SSD reads via `io_uring` vs `mmap` benchmark.
  - 🛠️ **`secan`**: Implement zero-copy index streaming in `secan/include/secan/storage/mmap_storage.h`.
- **Tue, Nov 24**:
  - 📖 **[Systems Perf]** Ch 2 & 6 (CPUs, IPC, profiling methodologies).
  - 💻 Drills: `perf stat` IPC calculation & cache miss analysis, branch mispredict elimination (branchy vs branchless selection), FlameGraph generation of query traversal under load.
  - 🛠️ **`secan`**: Generate and save flamegraphs of `secan` search traversal under 12-thread load.
- **Wed, Nov 25**:
  - 📖 Data integrity & atomic file updates.
  - 💻 Drills: Binary format with magic number, version, and `footer_crc32`, fast CRC32 checksum verification, verifying SHA-256 byte immutability across `open()` and `close()` in read-only mode (reproducing and verifying the Alibaba zvec Issue #815 fix!).
  - 🛠️ **`secan`**: Implement persistent save/load with CRC32 verification in `secan`.
- **Thu, Nov 26**:
  - 📖 Compiler sanitizers & memory safety.
  - 💻 Drills: AddressSanitizer buffer overflow diagnosis, UndefinedBehaviorSanitizer signed overflow & alignment check, ThreadSanitizer concurrent ingestion audit.
  - 🛠️ **`secan`**: Run full test suite across ASan, UBSan, and TSan (achieve 100% clean passes).
- **Fri, Nov 27**:
  - ⏱️ **MOCK CODING INTERVIEW (45 min, Blank Slate, Timed)**:
    - **Problem**: Implement a thread-safe LRU Cache with $O(1)$ get/put supporting concurrent reads and fine-grained writes.
  - 🛠️ **`secan`**: Complete `secan/docs/architecture.md` detailing memory layout, concurrency model, SIMD kernels, FastScan, and filtering.
- **💥 Sat, Nov 28**:
  - 🎤 **SYSTEMS DESIGN DEFENSE (Mock Whiteboard Round)**:
    - Deliver complete architectural specification for a 100M-vector vector database:
      1. Memory budgeting (SQ4 FastScan vs HNSW RAM footprints).
      2. Ingestion pipeline & Write-Ahead Log (WAL).
      3. Filtered Search: `ConcurrentBitset` graph routing with $< 2\%$ SIMD Flat Bypass.
      4. Out-of-Core Storage: `mmap` posting list streaming with `madvise`.
      5. Tail Latency: Port saturation and $p99 < 10\text{ ms}$ query execution.
  - 🛠️ **`secan`**: Polish `secan/README.md` with architecture diagrams and benchmark reproducibility commands.
- **💥 Sun, Nov 29 & Mon, Nov 30 (Final Capstone Release)**:
  - 🏆 **The Final Solo Capstone**:
    - Open a blank directory.
    - Implement a complete, high-performance **IVF-FastScan + HNSW Filtered Search Engine** completely from scratch in under 90 minutes.
  - 🚀 **Tag Release `secan v0.2.0`**.
  - Candidate is 100% interview-ready for Systems / HPC / Vector Search roles on personal merit.

---

## 5. Formal Verification & Defense Criteria

Before any candidate can be signed off as interview-ready, they must pass three verifiable milestones:
1. **The Blank-Slate Test**: Able to implement an arena allocator, a thread-safe queue, an AVX2 unrolled dot product, and an HNSW search loop from memory on a blank screen without external references.
2. **The Sanitizer Standard**: 100% of all drill code and `secan` test suites must compile with `-Wall -Wextra -Werror` and run with 0 errors under AddressSanitizer and ThreadSanitizer.
3. **The Empirical Metric Bar**: Benchmarked performance numbers must demonstrate:
   - Arena allocation is $\ge 5\text{x}$ faster than `malloc/free`.
   - 4-accumulator unrolled AVX2 FMA kernel is $\ge 1.5\text{x}$ faster than naive 1-accumulator code.
   - AVX2 `vpshufb` FastScan is $\ge 4\text{x}$ faster than standard FP32 distance scan.
   - Filtered Search with $< 2\%$ SIMD Flat Bypass achieves $100\%$ recall and $\ge 5\text{x}$ higher QPS than traversing a broken graph.
