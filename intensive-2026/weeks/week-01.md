# Week 1: C++ Memory Mastery, RAII & Custom Allocators
> **Dates**: October 19 – October 25, 2026  
> **Core Focus**: Object lifecycles, memory ownership, stack vs heap, cache line alignment, custom arena allocators, avoiding false sharing.

---

### Day 1: Monday, Oct 19, 2026 — Dynamic Memory Allocation & Custom Arena Allocator

#### 📖 Exact Reading (30–45 min)
- **Book**: **[CS:APP]** (Computer Systems: A Programmer's Perspective, 3rd ed)
- **Section**: **§9.9 Dynamic Memory Allocation** (Pages 864–882).
- **Key Concepts to Absorb**:
  - The heap layout and `brk` / `sbrk` / `mmap`.
  - Internal vs external fragmentation.
  - Alignment requirements (8-byte, 16-byte, 64-byte for SIMD/cache lines).
  - Why standard `malloc()` has overhead (chunk headers, metadata, thread synchronization).
  - Why bump/arena allocators have $O(1)$ allocation and zero per-object deallocation cost.

#### 💻 Standalone Drill 01 (You code from scratch)
- **File**: `drills/drill_01_arena.cpp`
- **Specification**:
  - Implement a class `ArenaAllocator`:
    ```cpp
    class ArenaAllocator {
    public:
        explicit ArenaAllocator(size_t capacity_bytes);
        ~ArenaAllocator();
        
        // Non-copyable, movable
        ArenaAllocator(const ArenaAllocator&) = delete;
        ArenaAllocator& operator=(const ArenaAllocator&) = delete;
        ArenaAllocator(ArenaAllocator&&) noexcept;
        ArenaAllocator& operator=(ArenaAllocator&&) noexcept;

        // Allocate aligned memory
        void* allocate(size_t bytes, size_t alignment = alignof(std::max_align_t));
        
        // Templated helper with constructor forwarding
        template <typename T, typename... Args>
        T* create(Args&&... args);

        // Reset the bump pointer to reuse memory without freeing the block
        void reset();

        size_t bytes_allocated() const;
        size_t capacity() const;
    };
    ```
  - **Edge cases to handle**:
    - Pointer alignment calculation: `uintptr_t current = ...; uintptr_t aligned = (current + alignment - 1) & ~(alignment - 1);`
    - Out-of-memory check (throw `std::bad_alloc` or return `nullptr`).
    - Test allocating mixed types (`char`, `int`, a 64-byte aligned SIMD struct). Verify addresses are properly aligned.
- **Compilation**:
  ```bash
  g++ -std=c++20 -O3 -Wall -Wextra -Werror drills/drill_01_arena.cpp -o drills/drill_01_arena && ./drills/drill_01_arena
  ```

#### 🛠️ Secan Deliberate Task
- Create `secan/include/secan/memory/arena.hpp`.
- Add a unit test verifying allocation and reset performance vs `new`/`delete` over 100,000 small nodes.

---

### Day 2: Tuesday, Oct 20, 2026 — RAII, Value Types & Move Semantics

#### 📖 Exact Reading (30–45 min)
- **Book**: **[ArtOfProg]** (The Art of Writing Efficient Programs by Fedor Pikus)
- **Section**: **Chapter 2 ("Performance and Concurrency")**, pages 25–45 (Focus on "Resource Acquisition Is Initialization (RAII)" and "Move semantics and temporary objects").
- **Key Concepts to Absorb**:
  - Why RAII is not just about exception safety, but about deterministic resource reclamation and cache efficiency.
  - The difference between lvalues and rvalues, `std::move` (which does not move anything, it's just a cast to rvalue reference).
  - The Rule of Five (Destructor, Copy Constructor, Copy Assignment, Move Constructor, Move Assignment) and Rule of Zero.
  - Why a moved-from object must be left in a valid, destructible state.

#### 💻 Standalone Drill 02 (You code from scratch)
- **File**: `drills/drill_02_unique_ptr.cpp`
- **Specification**:
  - Implement your own `UniquePtr<T>` class from scratch:
    - Explicit single-argument constructor from raw pointer.
    - Deleted copy constructor and copy assignment operator.
    - Move constructor and move assignment operator (steal the pointer, set the source to `nullptr`).
    - Destructor calls `delete ptr_`.
    - `T& operator*() const`, `T* operator->() const`, `T* get() const`, `T* release()`, `void reset(T* ptr = nullptr)`.
    - Helper template `make_unique<T, ...Args>(Args&&... args)`.
  - **Edge case**: Self-assignment in move assignment (`ptr = std::move(ptr);`).

#### 🛠️ Secan Deliberate Task
- Audit all index structures in `secan/include/secan/` to ensure no raw pointers represent ownership. Every resource must be managed by RAII.

---

### Day 3: Wednesday, Oct 21, 2026 — Cache Lines, Strides & Memory Layout

#### 📖 Exact Reading (30–45 min)
- **Book**: **[CS:APP]**
- **Section**: **§6.1 – §6.4 The Memory Hierarchy, Locality & Cache Memories** (Pages 605–645).
- **Key Concepts to Absorb**:
  - Temporal vs Spatial locality.
  - Cache line mechanics (64-byte blocks, cache tags, set-associative mapping).
  - Cold, conflict, and capacity misses.
  - Row-major vs column-major traversal penalty on 2D matrices.

#### 💻 Standalone Drill 03 (You code from scratch)
- **File**: `drills/drill_03_cache_strides.cpp`
- **Specification**:
  - Allocate a 2D matrix of `float` of size $8192 \times 8192$ (~268 MB, exceeds L3 cache).
  - Implement two traversal functions:
    1. `row_major_sum`: Iterates `[i][j]` (stride-1 access, hardware prefetcher friendly).
    2. `col_major_sum`: Iterates `[j][i]` (stride-8192 access, cache-thrashing).
  - Use `std::chrono::high_resolution_clock` to benchmark both.
  - Inspect cache misses using `perf stat`:
    ```bash
    perf stat -e L1-dcache-loads,L1-dcache-load-misses,LLC-loads,LLC-load-misses ./drills/drill_03_cache_strides
    ```
  - Document the speedup and cache miss ratio in a comment.

#### 🛠️ Secan Deliberate Task
- Verify `secan`'s `Dataset` representation: Vectors must be stored contiguously in a flat 1D array (`data[vector_id * dim + d]`) rather than `std::vector<std::vector<float>>` (pointer indirection penalty).

---

### Day 4: Thursday, Oct 22, 2026 — Stack Allocation, Placement New & Custom Vector

#### 📖 Exact Reading (30–45 min)
- **Book**: **[AgnerFog]** (`goals/agner_cpp.pdf`)
- **Section**: **§7 "Memory access"** and **§8 "Data structures"** (Pages 35–55).
- **Key Concepts to Absorb**:
  - Why heap allocations (`malloc`/`operator new`) cause syscall/allocator lock contention.
  - Stack allocation speed ($O(1)$ stack pointer decrement).
  - Placement `new` (`new (buffer) T(...)`) and explicit destructor invocation (`ptr->~T()`).
  - Cache line alignment using `alignas(64)`.

#### 💻 Standalone Drill 04 (You code from scratch)
- **File**: `drills/drill_04_fixed_vector.cpp`
- **Specification**:
  - Implement `FixedVector<T, Capacity>`: A vector stored completely inline on the stack with capacity fixed at compile-time.
  - Zero heap allocations (`sizeof(FixedVector<T, N>) == N * sizeof(T) + sizeof(size_t)`).
  - Store storage in `alignas(alignof(T)) std::byte buffer_[Capacity * sizeof(T)]`.
  - Implement `push_back(const T&)`, `push_back(T&&)`, `pop_back()`, `operator[]`, `size()`, `clear()`.
  - In `clear()` and destructor, explicitly call destructors of active objects.

#### 🛠️ Secan Deliberate Task
- Ensure all intermediate distance calculation accumulators and query candidate queues in `secan` do not trigger heap allocations in the hot path.

---

### Day 5: Friday, Oct 23, 2026 — False Sharing & Cache Line Alignment

#### 📖 Exact Reading (30–45 min)
- **Book**: **[ArtOfProg]**
- **Section**: **Chapter 3 ("Memory Architecture and Performance")**, pages 55–80 (Focus on "False Sharing and Data Alignment").
- **Key Concepts to Absorb**:
  - The MESI cache coherence protocol (Modified, Exclusive, Shared, Invalid).
  - Why two threads modifying independent variables on the same 64-byte cache line cause the line to bounce between CPU L1 caches (false sharing).
  - Using `alignas(std::hardware_destructive_interference_size)` (or 64 bytes) to isolate thread-local state.

#### 💻 Standalone Drill 05 (You code from scratch)
- **File**: `drills/drill_05_false_sharing.cpp`
- **Specification**:
  - Create two structs:
    ```cpp
    struct UnpaddedCounter {
        uint64_t counter{0};
    };

    struct alignas(64) PaddedCounter {
        uint64_t counter{0};
    };
    ```
  - Spawn 4 threads. Each thread increments its own counter $10^8$ times.
  - Run with an array of `UnpaddedCounter counters[4]` (all in the same 64-byte cache line).
  - Run with an array of `PaddedCounter counters[4]` (each on its own 64-byte line).
  - Benchmark both runs. Measure the 3x–10x slowdown caused by false sharing!

#### 🛠️ Secan Deliberate Task
- In `secan`, inspect query worker metrics / query stats structs. Ensure thread-local counters are padded to 64 bytes to eliminate false sharing during parallel searches.

---

### Day 6: Saturday, Oct 24, 2026 — Small Buffer Optimization (SBO) & Consolidation

#### 💻 Standalone Drill 06 (You code from scratch)
- **File**: `drills/drill_06_sbo_vector.cpp`
- **Specification**:
  - Implement a `SmallVector<T, SmallCapacity>`:
    - If `size() <= SmallCapacity`, elements live in an inline stack buffer.
    - If `size() > SmallCapacity`, it dynamically allocates on the heap like `std::vector`.
  - Test transitions from small buffer to heap buffer when elements exceed `SmallCapacity`.

---

### Day 7: Sunday, Oct 25, 2026 — Timed Self-Audit & Review

- **The Test**:
  - Open a blank file. Set a 25-minute timer.
  - Code `ArenaAllocator` and `UniquePtr` completely from memory without opening any references or looking at previous solutions.
  - Compile with `-Wall -Wextra -Werror`.
  - If it compiles and passes cleanly, Week 1 is mastered.
