# Week 1: C++ Memory Mastery, RAII & Custom Allocators
> **Dates**: October 19 – October 25, 2026  
> **Cadence**: Weekdays (3 drills/day) | **Weekends (Double Workload: 5–6 drills/day)** + Timed Exam + `secan` Component.

---

### Day 1: Monday, Oct 19, 2026 — Dynamic Memory & Custom Allocators
- 📖 **Reading**: **[CS:APP]** §9.9 (pp. 864–882). Heap mechanics, `brk` vs `mmap`, alignment padding, $O(1)$ bump allocators.
- 💻 **Drills**:
  1. `drill_01a_arena.cpp`: Bump `ArenaAllocator` with power-of-two alignment and placement `new`.
  2. `drill_01b_arena_benchmark.cpp`: Benchmark 1,000,000 allocations of Arena vs `malloc/free` using `asm volatile`.
  3. `drill_01c_growable_arena.cpp`: Chained/growable arena with dynamic chunk linked lists.
- 🛠️ **`secan`**: Scaffold `secan/include/secan/memory/arena.hpp`.

---

### Day 2: Tuesday, Oct 20, 2026 — RAII, Smart Pointers & Move Semantics
- 📖 **Reading**: **[ArtOfProg]** Chapter 2 (pp. 25–45). Rule of 5/0, move constructors, value types.
- 💻 **Drills**:
  1. `drill_02a_unique_ptr.cpp`: Custom `UniquePtr<T>` with custom deleters and move semantics.
  2. `drill_02b_shared_ptr.cpp`: Custom `SharedPtr<T>` with atomic control block ref-counting.
  3. `drill_02c_rule_of_five.cpp`: Rule-of-Five aligned buffer container with copy-and-swap idiom.
- 🛠️ **`secan`**: Audit ownership across all index headers in `secan/include/secan/`.

---

### Day 3: Wednesday, Oct 21, 2026 — Cache Lines, Strides & Memory Hierarchy
- 📖 **Reading**: **[CS:APP]** §6.1–6.4 (pp. 605–645). Memory hierarchy, spatial/temporal locality, cache misses.
- 💻 **Drills**:
  1. `drill_03a_cache_strides.cpp`: Row-major vs column-major stride cache miss measurement via `perf stat`.
  2. `drill_03b_cache_blocking.cpp`: Tiled $B \times B$ cache-blocked matrix transpose.
  3. `drill_03c_contiguous_dataset.cpp`: AoS vs flat contiguous 64-byte aligned vector storage.
- 🛠️ **`secan`**: Implement `secan/include/secan/common/dataset.hpp`.

---

### Day 4: Thursday, Oct 22, 2026 — Stack Storage, Placement New & Custom Vector
- 📖 **Reading**: **[AgnerFog]** §7 & §8 (pp. 35–55). Memory access, stack frames, placement `new`.
- 💻 **Drills**:
  1. `drill_04a_fixed_vector.cpp`: Zero-heap stack `FixedVector<T, Capacity>` with manual destructor calls.
  2. `drill_04b_small_vector.cpp`: Small Buffer Optimization (SBO) `SmallVector<T, SmallCap>`.
  3. `drill_04c_aligned_allocator.cpp`: C++20 standard-compliant `AlignedAllocator<T, 64>`.
- 🛠️ **`secan`**: Implement `secan/include/secan/memory/fixed_vector.hpp`.

---

### Day 5: Friday, Oct 23, 2026 — False Sharing, Memory Alignment & Cache Coherence
- 📖 **Reading**: **[ArtOfProg]** Chapter 3 (pp. 55–80). MESI coherence, false sharing, cache line isolation.
- 💻 **Drills**:
  1. `drill_05a_false_sharing.cpp`: Reproduce false sharing penalty across 4 threads.
  2. `drill_05b_false_sharing_fixed.cpp`: Eliminate false sharing with `alignas(64)` padding (3x–8x speedup).
  3. `drill_05c_struct_reordering.cpp`: Struct field reordering and memory footprint minimization.
- 🛠️ **`secan`**: Pad search thread statistics in `secan/include/secan/utils/stats.hpp`.

---

### 💥 Day 6: Saturday, Oct 24, 2026 — DOUBLE WORKLOAD: Memory Pools, HugePages & Sanitizers (6 Drills)
- 📖 **Reading**: **[CS:APP]** §9.9.6–9.9.12 (pp. 882–892). Explicit free lists, segregated lists, and coalescing.
- 💻 **Drills**:
  1. `drill_06a_freelist_pool.cpp`: Fixed-size slab object pool using an intrusive freelist (`union/next` in free nodes).
  2. `drill_06b_pool_benchmark.cpp`: Benchmark object pool vs glibc `new/delete` across 1,000,000 allocations.
  3. `drill_06c_huge_pages_madvise.cpp`: Allocate 500 MB buffer using `madvise(MADV_HUGEPAGE)` (2MB Transparent Huge Pages) vs standard 4KB pages. Measure page fault reduction.
  4. `drill_06d_pmr_monotonic_resource.cpp`: Implement C++17/20 `std::pmr::monotonic_buffer_resource` with custom upstream fallback.
  5. `drill_06e_asan_ubsan_stress.cpp`: Write an intentional double-free, buffer overread, and misaligned pointer; debug and fix using `-fsanitize=address,undefined`.
  6. `drill_06f_circular_buffer.cpp`: Bounded cache-aligned ring buffer with head/tail tracking for task batching.
- 🛠️ **`secan`**: Add `AlignedAllocator` and object pool memory containers to `secan`.

---

### 💥 Day 7: Sunday, Oct 25, 2026 — DOUBLE WORKLOAD: Advanced Memory Primitives + Timed Exam (5 Drills + Exam)
- 💻 **Drills**:
  1. `drill_07a_intrusive_ref_count.cpp`: Intrusive reference counting (`IntrusivePtr<T>`) where ref-count lives inside the object (avoiding separate control block allocations).
  2. `drill_07b_custom_new_delete_overload.cpp`: Global and class-specific `operator new` / `operator delete` overload tracking allocated byte metrics.
  3. `drill_07c_scope_guard_defer.cpp`: Zero-overhead RAII `ScopeGuard` / `defer` macro for exception-safe cleanup.
  4. `drill_07d_vector_pitch_padding.cpp`: 2D matrix pitch-padding (padding rows to multiples of 64 bytes so every row starts on a clean cache line).
  5. `drill_07e_memory_leak_tracker.cpp`: Custom memory leak detector printing leaked allocation call sites.
- ⏱️ **TIMED EXAM (45 Minutes, Blank File, No Notes, No AI)**:
  - Code `ArenaAllocator` (with alignment and reset) + `UniquePtr<T>` + `PaddedCounter` from a blank file with zero compiler warnings under `-Wall -Wextra -Werror`.
- 🛠️ **`secan`**: Run full test suite with AddressSanitizer and verify 100% clean passes.
