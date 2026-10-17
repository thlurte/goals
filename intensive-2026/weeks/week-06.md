# Week 6: Systems Profiling, Zero-Copy I/O (`mmap`), Sanitizers & Interview Defense
> **Dates**: November 23 – November 30, 2026  
> **Core Focus**: Linux `mmap` zero-copy persistence, hardware performance counters (`perf`), AddressSanitizer/UBSan defense, mock coding interviews, and systems design defense.

---

### Day 36 (Mon, Nov 23): Zero-Copy Index Persistence with `mmap`
- 📖 **Reading**: **[CS:APP]** — **§9.8 Memory Mapping** (Pages 855–864).
- 💻 **Drills (`day_36_drills.md`)**:
  1. `drill_36a_mmap_reader.cpp`: Open a 50 MB binary vector file using `open()`, `mmap(..., PROT_READ, MAP_SHARED, fd, 0)`, and `madvise(..., MADV_WILLNEED)`. Access vectors directly through pointer casting without `fread()`.
  2. `drill_36b_mmap_raii_wrapper.cpp`: Write an RAII `MmapBuffer` class that calls `munmap()` upon destruction.
  3. `drill_36c_mmap_vs_fread_bench.cpp`: Benchmark engine startup latency using `mmap()` (instantaneous) vs `fread()` (slow buffer copying).
- 🛠️ **`secan`**: Implement zero-copy index loading in `secan/include/secan/storage/mmap_storage.hpp`.

---

### Day 37 (Tue, Nov 24): Hardware Performance Counters (`perf`) & IPC
- 📖 **Reading**: **[Systems Performance]** (Brendan Gregg) — **Chapter 6 ("CPUs")** & **Chapter 2 ("Methodologies")**. Instructions per cycle (IPC), branch mispredictions, cache misses.
- 💻 **Drills (`day_37_drills.md`)**:
  1. `drill_37a_perf_stat_analysis.cpp`: Write a driver program. Run `perf stat -e cycles,instructions,cache-misses,branch-misses ./drill_37a`. Calculate Instructions Per Cycle (IPC).
  2. `drill_37b_branch_mispredict_elimination.cpp`: Measure latency of branchy code vs branchless code using `perf stat -e branch-misses`.
  3. `drill_37c_flamegraph_generation.cpp`: Profile your HNSW search using `perf record -F 99 -g` and generate a FlameGraph. Identify the primary CPU bottleneck.
- 🛠️ **`secan`**: Generate a flamegraph of `secan` search traversal under 12-thread load.

---

### Day 38 (Wed, Nov 25): Data Integrity, Headers & Checksums
- 📖 **Reading**: Atomic file updates, CRC32 checksums, and read-only file immutability.
- 💻 **Drills (`day_38_drills.md`)**:
  1. `drill_38a_binary_header_footer.cpp`: Design a binary format with a header (`magic_number`, `version`, `dim`, `count`) and footer (`footer_crc32`).
  2. `drill_38b_crc32_validation.cpp`: Implement fast CRC32 checksum calculation. Verify data corruption detection.
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

### Day 40 (Fri, Nov 27): Mock Coding Interview 1 (High-Performance Data Structures)
- ⏱️ **45-minute timed mock interview (No Notes)**:
  - **Problem**: Implement a thread-safe LRU Cache with $O(1)$ `get()` and `put()`, supporting concurrent reads and fine-grained writes.
  - Deliver clean, bug-free C++20 code with complete unit tests in 45 minutes.

---

### Day 41 (Sat, Nov 28): Mock Systems Design Interview (Vector Database Architecture)
- 🎤 **Systems Design Defense**:
  - Deliver a complete architectural specification for a 100M-vector search service:
    1. Memory Budgeting (FP32 vs SQ8 vs PQ).
    2. Write-Ahead Log (WAL) & Ingestion pipeline.
    3. Graph index partitioning across NUMA nodes.
    4. SIMD distance acceleration and query routing.
    5. Cache hierarchies and tail latency guarantees ($p99 < 10\text{ ms}$).

---

### Day 42 (Sun, Nov 29) & Final Milestone (Mon, Nov 30): Capstone Solo Build
- 🏆 **The Final Solo Capstone**:
  - Open a blank directory on your machine.
  - Implement a complete, high-performance **Flat SIMD + SQ8 Vector Engine** with multi-threaded querying and binary file persistence completely from scratch in under 90 minutes.
  - Tag release `secan v0.2.0`.
  - You are now 100% ready to pass top-tier Systems Engineer interviews on your own merits.
