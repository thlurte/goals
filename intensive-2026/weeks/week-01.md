# Week 1: C++ Memory Mastery, RAII & Custom Allocators
> **Dates**: October 19 – October 25, 2026  
> **Cadence**: 3–4 Standalone Drills Per Day + Exact Reading + Deliberate `secan` Component.

---

### Day 1: Monday, Oct 19, 2026 — Dynamic Memory & Custom Allocators

#### 📖 Exact Reading (30–45 min)
- **Book**: **[CS:APP]** (Computer Systems: A Programmer's Perspective, 3rd ed)
- **Section**: **§9.9 Dynamic Memory Allocation** (Pages 864–882).
- **Core Focus**: Heap mechanics, `brk` vs `mmap`, alignment padding, why bump allocators have $O(1)$ allocation and zero per-object deallocation cost.

#### 💻 Standalone Daily Drills (You write all 3 from scratch)
1. **Drill 01-A (`drill_01a_arena.cpp`)**: **The Classic Bump Arena**
   - Implement `ArenaAllocator` with a contiguous buffer.
   - Support arbitrary power-of-two alignment (`(current + align - 1) & ~(align - 1)`).
   - Templated `create<T, Args...>(Args&&...)` with in-place placement `new`.
   - Implement `reset()` to reuse memory without freeing the buffer.
2. **Drill 01-B (`drill_01b_arena_benchmark.cpp`)**: **Throughput vs `malloc` / `std::pmr`**
   - Benchmark allocating 1,000,000 small objects (32 bytes each) using `malloc` / `free` vs `ArenaAllocator`.
   - Measure execution time, instruction count, and observe the 5x–15x throughput difference.
3. **Drill 01-C (`drill_01c_growable_arena.cpp`)**: **Chained / Growable Arena**
   - A real production arena cannot have a fixed hard limit.
   - Implement a linked list of chunk blocks (`Chunk { std::byte* data; size_t capacity; size_t offset; Chunk* next; }`).
   - If current chunk overflows, allocate a new chunk of size `std::max(requested, chunk_size)` and link it.
   - On `reset()`, reset offsets or free extra chunks back to initial capacity.

#### 🛠️ Secan Deliberate Task
- Create `secan/include/secan/memory/arena.hpp` (implementing your chained arena).
- Write Catch2 / GoogleTest unit tests verifying SIMD 64-byte alignment and zero memory leaks.

---

### Day 2: Tuesday, Oct 20, 2026 — RAII, Smart Pointers & Move Semantics

#### 📖 Exact Reading (30–45 min)
- **Book**: **[ArtOfProg]** (The Art of Writing Efficient Programs by Fedor Pikus)
- **Section**: **Chapter 2 ("Performance and Concurrency")**, pages 25–45 (Focus on "RAII", "Move semantics", and "Value types").
- **Core Focus**: The Rule of Five vs Rule of Zero, temporary materialization, move constructors vs move assignment, why `std::move` is just a static cast to rvalue reference.

#### 💻 Standalone Daily Drills (You write all 3 from scratch)
1. **Drill 02-A (`drill_02a_unique_ptr.cpp`)**: **`UniquePtr<T>` from Scratch**
   - Implement explicit constructor, deleted copy operations, move constructor, and move assignment.
   - Support custom deleters (`template <typename T, typename Deleter = std::default_delete<T>>`).
   - Implement `release()`, `reset()`, `operator*()`, `operator->()`, and `operator bool()`.
   - Handle self-move-assignment edge case cleanly.
2. **Drill 02-B (`drill_02b_shared_ptr.cpp`)**: **`SharedPtr<T>` & Control Block**
   - Implement a reference-counted smart pointer with a separate control block (`struct ControlBlock { std::atomic<long> ref_count; };`).
   - Implement copy constructor (increment ref count), move constructor (transfer ownership, zero ref count), and destructor (decrement ref count, delete object and control block if 0).
3. **Drill 02-C (`drill_02c_rule_of_five.cpp`)**: **Rule of Five Matrix Container**
   - Implement a non-trivial `VectorBuffer` holding an aligned float buffer.
   - Implement all 5 special member functions:
     1. Destructor
     2. Copy constructor (deep copy)
     3. Copy assignment operator (using copy-and-swap idiom)
     4. Move constructor (`noexcept`)
     5. Move assignment operator (`noexcept`)
   - Verify move semantics prevent memory reallocations during `std::vector<VectorBuffer>::push_back`.

#### 🛠️ Secan Deliberate Task
- Audit `secan/include/secan/`: Replace any raw owning pointers with explicit RAII containers. Ensure all index entities have explicit `noexcept` move constructors.

---

### Day 3: Wednesday, Oct 21, 2026 — Cache Lines, Strides & Memory Hierarchy

#### 📖 Exact Reading (30–45 min)
- **Book**: **[CS:APP]**
- **Section**: **§6.1 – §6.4 The Memory Hierarchy, Locality & Cache Memories** (Pages 605–645).
- **Core Focus**: L1/L2/L3 cache architectures, spatial vs temporal locality, cache line eviction policies, hardware prefetching.

#### 💻 Standalone Daily Drills (You write all 3 from scratch)
1. **Drill 03-A (`drill_03a_cache_strides.cpp`)**: **Row-Major vs Column-Major Penalty**
   - Matrix of size $4096 \times 4096$ floats (~67 MB, exceeds L3 cache).
   - Measure stride-1 access (row-major) vs stride-4096 access (col-major).
   - Profile with `perf stat -e L1-dcache-load-misses,LLC-load-misses`.
2. **Drill 03-B (`drill_03b_cache_blocking.cpp`)**: **Tiled / Blocked Matrix Transposition**
   - Implement naive matrix transpose ($A[j][i] = B[i][j]$).
   - Implement cache-blocked / tiled matrix transpose using $B \times B$ submatrices (e.g. $B=64$, fitting in L1 cache).
   - Measure the 2x–5x performance speedup from cache blocking.
3. **Drill 03-C (`drill_03c_contiguous_dataset.cpp`)**: **AoS vs SoA Vector Storage**
   - Benchmark Array-of-Structures (`struct Vector { float d[128]; }; std::vector<Vector>`) vs Structure-of-Arrays / Flat contiguous buffer (`float* data`).
   - Implement slicing and contiguous vector access with 64-byte alignment.

#### 🛠️ Secan Deliberate Task
- Verify `secan/include/secan/common/dataset.hpp`: Guarantee that all raw vector data is stored in a single contiguous flat buffer with 64-byte alignment (`std::aligned_alloc(64, num_vectors * dim * sizeof(float))`).

---

### Day 4: Thursday, Oct 22, 2026 — Stack Storage, Placement New & Custom Vector

#### 📖 Exact Reading (30–45 min)
- **Book**: **[AgnerFog]** (`goals/agner_cpp.pdf`)
- **Section**: **§7 "Memory access"** and **§8 "Data structures"** (Pages 35–55).
- **Core Focus**: Stack frame layout, avoiding heap allocation in latency-critical code paths, placement `new` mechanics, manual destructor calls.

#### 💻 Standalone Daily Drills (You write all 3 from scratch)
1. **Drill 04-A (`drill_04a_fixed_vector.cpp`)**: **Zero-Heap `FixedVector<T, Capacity>`**
   - Implement a fixed-capacity vector that allocates its buffer entirely inline on the stack using `alignas(alignof(T)) std::byte storage_[Capacity * sizeof(T)]`.
   - Implement `push_back(const T&)`, `push_back(T&&)`, `pop_back()`, and `clear()`.
   - Correctly call `reinterpret_cast<T*>(storage_)[i].~T()` for every active object upon removal or destruction.
2. **Drill 04-B (`drill_04b_small_vector.cpp`)**: **Small Buffer Optimization (SBO)**
   - Implement `SmallVector<T, SmallCap>`:
     - When `size <= SmallCap`, data lives in an inline stack buffer.
     - When `size > SmallCap`, dynamically allocate on the heap and migrate existing elements via `std::move_if_noexcept`.
   - Benchmark `SmallVector` vs `std::vector` for small neighbor lists ($\le 32$ elements).
3. **Drill 04-C (`drill_04c_aligned_allocator.cpp`)**: **C++20 STL-Compliant Aligned Allocator**
   - Implement a standard-compliant allocator:
     ```cpp
     template <typename T, size_t Alignment = 64>
     struct AlignedAllocator {
         using value_type = T;
         T* allocate(size_t n);
         void deallocate(T* p, size_t n) noexcept;
     };
     ```
   - Use `AlignedAllocator` with `std::vector<float, AlignedAllocator<float, 64>>` and verify memory is always 64-byte aligned.

#### 🛠️ Secan Deliberate Task
- Use `FixedVector` or `SmallVector` for graph neighbor exploration queues in `secan`, ensuring zero heap allocation during single-query search traversal.

---

### Day 5: Friday, Oct 23, 2026 — False Sharing, Memory Alignment & Cache Coherence

#### 📖 Exact Reading (30–45 min)
- **Book**: **[ArtOfProg]**
- **Section**: **Chapter 3 ("Memory Architecture and Performance")**, pages 55–80 (Focus on "False Sharing and Data Alignment").
- **Core Focus**: The MESI cache coherence protocol, bus snooping, invalidation traffic, `std::hardware_destructive_interference_size`.

#### 💻 Standalone Daily Drills (You write all 3 from scratch)
1. **Drill 05-A (`drill_05a_false_sharing.cpp`)**: **Reproducing False Sharing**
   - Create an array of 4 counters placed contiguously in a single 64-byte cache line:
     `struct Counter { uint64_t val{0}; }; Counter counters[4];`
   - Spawn 4 threads, each incrementing its counter $10^8$ times. Measure total runtime.
2. **Drill 05-B (`drill_05b_false_sharing_fixed.cpp`)**: **Eliminating False Sharing with `alignas(64)`**
   - Pad each counter to its own 64-byte cache line:
     `struct alignas(64) PaddedCounter { uint64_t val{0}; }; PaddedCounter counters[4];`
   - Re-run the exact same benchmark. Witness the massive 3x–8x speedup.
3. **Drill 05-C (`drill_05c_struct_reordering.cpp`)**: **Struct Padding & Memory Footprint Optimization**
   - Create a poorly ordered struct:
     `struct Bad { bool a; double b; int c; char d; };`
   - Compute its `sizeof()` (24 bytes due to padding).
   - Reorder fields by descending alignment:
     `struct Good { double b; int c; bool a; char d; };`
   - Measure `sizeof()` (16 bytes, a 33% memory saving).
   - Verify array iteration speedup over 10,000,000 elements.

#### 🛠️ Secan Deliberate Task
- Inspect `secan/include/secan/utils/stats.hpp`: Ensure all multi-threaded query statistics and thread-local state are aligned to 64 bytes to eliminate false sharing across search threads.

---

### Day 6: Saturday, Oct 24, 2026 — Freelist, Memory Pools & Fast Deallocation

#### 📖 Exact Reading (30–45 min)
- **Book**: **[CS:APP]**
- **Section**: **§9.9.6 – §9.9.12 Explicit Free Lists & Segregated Free Lists** (Pages 882–892).
- **Core Focus**: Explicit free lists, lifo vs address-ordered insertion, boundary tags, coalescing.

#### 💻 Standalone Daily Drills (You write all 3 from scratch)
1. **Drill 06-A (`drill_06a_freelist_pool.cpp`)**: **Fixed-Size Slab / Object Pool**
   - Implement an intrusive freelist for a fixed object size (e.g., 64 bytes).
   - Maintain a union/intrusive pointer inside unused blocks (`struct FreeNode { FreeNode* next; };`).
   - `allocate()` pops the head in $O(1)$; `deallocate()` pushes to the head in $O(1)$ without calling the system heap.
2. **Drill 06-B (`drill_06b_pool_benchmark.cpp`)**: **Object Pool vs Standard `new`/`delete`**
   - Allocate and deallocate 500,000 graph nodes repeatedly.
   - Benchmark the intrusive object pool against standard `new`/`delete`.
3. **Drill 06-C (`drill_06c_valgrind_asan.cpp`)**: **Sanitizer Defense**
   - Intentionally create three memory bugs in a dummy test: a double-free, a 4-byte buffer overflow, and a use-after-free.
   - Run with AddressSanitizer (`-fsanitize=address -g`) and UndefinedBehaviorSanitizer (`-fsanitize=undefined`).
   - Read the exact sanitizer stack traces and fix all three bugs cleanly.

---

### Day 7: Sunday, Oct 25, 2026 — Comprehensive Timed Systems Exam (No Notes)

- **The Real Test**:
  - Open a blank directory. Set a **45-minute countdown timer**.
  - Without opening any browser, notes, previous files, or asking an AI:
    1. Write `ArenaAllocator` with 64-byte alignment and `reset()`.
    2. Write `UniquePtr<T>` with move constructor and move assignment.
    3. Write `PaddedCounter` demonstrating false sharing prevention.
  - Compile with:
    ```bash
    g++ -std=c++20 -O3 -Wall -Wextra -Werror exam.cpp -o exam && ./exam
    ```
  - If you finish in under 45 minutes with 0 compiler warnings and all tests passing, you have genuinely mastered Week 1.
