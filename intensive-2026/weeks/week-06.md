# Week 6: Systems Profiling, Zero-Copy `mmap` Streaming & Interview Defense
> **Dates**: November 23 – November 30, 2026  
> **Core Focus**: Zero-copy `mmap` streaming for out-of-core IVF/HNSW indexes, `perf` hardware counter analysis, data integrity checksums, and mock systems interview defense.

---

### Day 36 (Mon, Nov 23): Zero-Copy Index Persistence & Streaming with `mmap`
- 📖 **Reading**: **[CS:APP]** — **§9.8 Memory Mapping** (Pages 855–864).
- 💻 **Drills (`day_36_drills.md`)**:
  1. `drill_36a_mmap_reader.cpp`: Open a 100 MB binary vector file using `open()`, `mmap(..., PROT_READ, MAP_SHARED, fd, 0)`, and `madvise(..., MADV_WILLNEED)`. Access vectors directly through pointer arithmetic without heap copies.
  2. `drill_36b_mmap_ivf_posting_stream.cpp`: Memory-map an IVF inverted index. Stream target inverted lists directly from disk using `madvise(MADV_SEQUENTIAL)` for fast asynchronous OS page faulting.
  3. `drill_36c_mmap_vs_fread_bench.cpp`: Benchmark engine startup latency using `mmap()` (instantaneous, 0 ms) vs `fread()` (slow copying, seconds).
- 🛠️ **`secan`**: Implement zero-copy index streaming in `secan/include/secan/storage/mmap_storage.hpp`.

---

### Day 37 (Tue, Nov 24): Hardware Performance Counters (`perf`) & IPC Analysis
- 📖 **Reading**: **[Systems Performance]** (Brendan Gregg) — **Chapter 6 ("CPUs")** & **Chapter 2 ("Methodologies")**.
- 💻 **Drills (`day_37_drills.md`)**:
  1. `drill_37a_perf_stat_analysis.cpp`: Run `perf stat -e cycles,instructions,cache-misses,branch-misses ./drill_37a`. Calculate Instructions Per Cycle (IPC).
  2. `drill_37b_branch_mispredict_elimination.cpp`: Measure latency of branchy code vs branchless selection using `perf stat -e branch-misses`.
  3. `drill_37c_flamegraph_generation.cpp`: Profile your IVF-FastScan and HNSW queries using `perf record -F 99 -g` and generate a FlameGraph. Identify CPU pipeline bottlenecks.
- 🛠️ **`secan`**: Generate and save flamegraphs of `secan` search traversal under 12-thread load.

---

### Day 38 (Wed, Nov 25): Data Integrity, Headers & Read-Only Immutability
- 📖 **Reading**: Atomic file updates, CRC32 checksums, and read-only file immutability.
- 💻 **Drills (`day_38_drills.md`)**:
  1. `drill_38a_binary_header_footer.cpp`: Design a binary format with a header (`magic_number`, `version`, `dim`, `count`) and footer (`footer_crc32`).
  2. `drill_38b_crc32_validation.cpp`: Implement fast CRC32 checksum calculation. Verify corruption detection when bits are flipped.
  3. `drill_38c_read_only_immutability.cpp`: Verify SHA-256 byte immutability across `open()` and `close()` in read-only mode (reproducing and verifying the fix for Alibaba zvec Issue #815!).
- 🛠️ **`secan`**: Implement persistent save/load with CRC32 verification in `secan`.

---

### Day 39 (Thu, Nov 26): Sanitizer Defense (ASan, UBSan, TSan)
- 📖 **Reading**: Compiler sanitizers and memory safety in C++.
- 💻 **Drills (`day_39_drills.md`)**:
  1. `drill_39a_asan_buffer_overflow.cpp`: Catch and diagnose stack and heap buffer overflows with AddressSanitizer.
  2. `drill_39b_ubsan_undefined_behavior.cpp`: Catch signed integer overflow and misaligned pointer dereferences with UndefinedBehaviorSanitizer (`-fsanitize=undefined`).
  3. `drill_39c_tsan_concurrent_audit.cpp`: Run ThreadSanitizer on a multi-threaded vector ingestion loop and fix every warning.
- 🛠️ **`secan`**: Run full test suite with all three sanitizers enabled. Achieve 100% clean passes.

---

### Day 40 (Fri, Nov 27): Mock Coding Interview (High-Performance Systems Primitives)
- ⏱️ **45-minute timed mock interview (No Notes)**:
  - **Problem**: Implement a thread-safe LRU Cache with $O(1)$ `get()` and `put()`, supporting concurrent reads and fine-grained writes.
  - Deliver clean, bug-free C++20 code with complete unit tests in 45 minutes.

---

### Day 41 (Sat, Nov 28): Mock Systems Design Defense (Vector Database Engine)
- 🎤 **Systems Design Defense**:
  - Deliver a complete architectural whiteboard presentation for a 100M-vector vector database:
    1. **Memory Budgeting**: SQ4/SQ2 FastScan vs HNSW memory footprint.
    2. **Write-Ahead Log (WAL)** & Ingestion pipeline.
    3. **Filtered Search**: `ConcurrentBitset` graph routing with $< 2\%$ SIMD Flat Bypass.
    4. **Out-of-Core Storage**: `mmap` inverted posting list streaming with `madvise`.
    5. **Tail Latency Guarantees**: Port saturation and $p99 < 10\text{ ms}$ query execution.

---

### Day 42 (Sun, Nov 29) & Final Milestone (Mon, Nov 30): Capstone Solo Build
- 🏆 **The Final Solo Capstone**:
  - Open a blank directory on your machine.
  - Implement a complete, high-performance **IVF-FastScan + HNSW Filtered Search Engine** with multi-threaded querying and binary file persistence completely from scratch in under 90 minutes.
  - Tag release `secan v0.2.0`.
  - You are now 100% ready to pass top-tier Systems Engineer interviews on your own merits.
