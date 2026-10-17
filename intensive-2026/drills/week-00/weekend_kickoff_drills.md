# Weekend Intensive Kickoff: Oct 17 – Oct 18, 2026
> **Day 0 (Sat, Oct 17) & Day 0.5 (Sun, Oct 18)**  
> **Cadence**: Double Workload (6 Rigorous Drills Across Weekend)  
> **Core Focus**: C++ Memory Primitives, Pointer Arithmetic, Dynamic Arenas, and Cache Line Alignment.

---

## 📖 Required Reading (Morning)
- **Book**: **[CS:APP]** (Computer Systems: A Programmer's Perspective, 3rd ed)
- **Section**: **§9.9 Dynamic Memory Allocation** (Pages 864–892).
- **Book**: **[ArtOfProg]** (Fedor Pikus)
- **Section**: **Chapter 3 ("Memory Architecture and Performance")**, pages 55–80 (Cache Lines, False Sharing & Alignment).

---

## 🎯 Saturday (Oct 17): Memory Allocation & Allocator Internals (3 Drills)

### Drill W0-1: Raw Bump Arena with Power-of-Two Alignment (`drill_w0_1_bump_arena.cpp`)
- **Specification**:
  - Implement class `BumpArena`:
    - Constructor: Pre-allocate raw byte buffer of specified capacity using `::operator new(capacity)`.
    - Destructor: `::operator delete(buffer_)`.
    - Deleted copy constructor and copy assignment operator.
    - Implement `noexcept` move constructor and move assignment.
    - `void* allocate(size_t bytes, size_t alignment = 8)`:
      - Alignment math: `uintptr_t curr = reinterpret_cast<uintptr_t>(buffer_ + offset_);`
      - `uintptr_t aligned = (curr + alignment - 1) & ~(alignment - 1);`
      - Calculate new offset, bounds check against capacity.
    - `template <typename T, typename... Args> T* create(Args&&... args)`:
      - Construct object in-place using placement `new (mem) T(std::forward<Args>(args)...)`.
    - `void reset()`: Sets offset to 0.
- **Verification**:
  - Allocate `char`, `double`, and a 64-byte aligned SIMD vector. Verify pointers are aligned properly.
- **Compile**:
  ```bash
  g++ -std=c++20 -O3 -Wall -Wextra -Werror drill_w0_1_bump_arena.cpp -o drill_w0_1_bump_arena && ./drill_w0_1_bump_arena
  ```

### Drill W0-2: Arena vs `malloc` Latency & Throughput Benchmark (`drill_w0_2_arena_bench.cpp`)
- **Specification**:
  - Benchmark $N = 2,000,000$ allocations of 32 bytes each.
  - Phase 1: `malloc` + `free` (record elapsed time using `std::chrono::high_resolution_clock`).
  - Phase 2: `BumpArena` allocation (record elapsed time, prevent dead-code elimination with `asm volatile("" : "+r"(ptr) : : "memory")`).
  - Measure and print the speedup factor (expect 8x–20x).
- **Compile**:
  ```bash
  g++ -std=c++20 -O3 -Wall -Wextra -Werror drill_w0_2_arena_bench.cpp -o drill_w0_2_arena_bench && ./drill_w0_2_arena_bench
  ```

### Drill W0-3: Chained / Growable Arena with Dynamic Chunk List (`drill_w0_3_chained_arena.cpp`)
- **Specification**:
  - Implement `ChainedArena`:
    - Node: `struct Chunk { std::byte* data; size_t capacity; size_t offset; Chunk* next; };`
    - Start with initial chunk (e.g. 1 KB for testing).
    - If allocation exceeds current chunk capacity, allocate a new chunk of size `std::max(default_size, bytes + align)` and link it.
    - In `reset()`, reset offsets of all chunks to 0 without deleting the chunk memory blocks.
    - In destructor, free every linked chunk.
- **Verification**:
  - Allocate 200 objects of 256 bytes (forcing ~50 dynamic chunk allocations).
  - Verify zero memory leaks under AddressSanitizer:
  ```bash
  g++ -std=c++20 -fsanitize=address -g -Wall -Wextra -Werror drill_w0_3_chained_arena.cpp -o drill_w0_3_chained_arena && ./drill_w0_3_chained_arena
  ```

---

## 🎯 Sunday (Oct 18): Smart Pointers, Cache Strides & False Sharing (3 Drills)

### Drill W0-4: Custom `UniquePtr<T>` from Scratch (`drill_w0_4_unique_ptr.cpp`)
- **Specification**:
  - Implement `UniquePtr<T>`:
    - Explicit constructor from raw pointer `T*`.
    - Deleted copy constructor and copy assignment operator.
    - Move constructor (`noexcept`): transfers pointer, zeros source.
    - Move assignment operator (`noexcept`): handles self-move, deletes existing owned pointer, steals new pointer.
    - Destructor: `delete ptr_`.
    - `T& operator*()`, `T* operator->()`, `T* get()`, `T* release()`, `void reset(T* p = nullptr)`.
    - Helper `make_unique<T, Args...>(Args&&... args)`.
- **Compile**:
  ```bash
  g++ -std=c++20 -O3 -Wall -Wextra -Werror drill_w0_4_unique_ptr.cpp -o drill_w0_4_unique_ptr && ./drill_w0_4_unique_ptr
  ```

### Drill W0-5: Row-Major vs Column-Major Cache Stride Benchmark (`drill_w0_5_cache_stride.cpp`)
- **Specification**:
  - Allocate a 2D matrix of floats of size $4096 \times 4096$ (~67 MB, exceeds L3 cache).
  - Benchmark `row_major_sum` (stride-1 access, prefetcher friendly) vs `col_major_sum` (stride-4096 access, cache-thrashing).
  - Profile cache misses using Linux `perf`:
    ```bash
    perf stat -e L1-dcache-loads,L1-dcache-load-misses,LLC-loads,LLC-load-misses ./drill_w0_5_cache_stride
    ```
  - Document the miss ratio difference in a comment at the top of the file.

### Drill W0-6: False Sharing Reproduction & `alignas(64)` Elimination (`drill_w0_6_false_sharing.cpp`)
- **Specification**:
  - Benchmark 4 threads incrementing independent counters $10^8$ times.
  - Phase 1: `struct Counter { uint64_t val{0}; }; Counter counters[4];` (all counters fit in one 64-byte cache line).
  - Phase 2: `struct alignas(64) PaddedCounter { uint64_t val{0}; }; PaddedCounter counters[4];` (each on its own 64-byte line).
  - Measure elapsed time. Witness the 3x–8x performance gain from cache line isolation!
- **Compile**:
  ```bash
  g++ -std=c++20 -O3 -pthread -Wall -Wextra -Werror drill_w0_6_false_sharing.cpp -o drill_w0_6_false_sharing && ./drill_w0_6_false_sharing
  ```

---

## 🛠️ Weekend `secan` Contribution
- Create `secan/include/secan/memory/arena.hpp`.
- Place your verified `ChainedArena` into `namespace secan::memory`.
- Add unit tests in `secan/tests/test_arena.cpp` testing 64-byte SIMD vector allocations.
