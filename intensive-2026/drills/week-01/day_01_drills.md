# Week 1, Day 1: Dynamic Memory & Custom Arena Allocators
> **Date**: Monday, October 19, 2026  
> **Rule**: You create and code each `.cpp` file from a completely blank file. No boilerplate is provided.

---

## 📖 Required Reading Before Coding
- **Book**: **[CS:APP]** (Computer Systems: A Programmer's Perspective, 3rd Edition)
- **Section**: **§9.9 Dynamic Memory Allocation** (Pages 864–882).
- **Key Concepts to Internalize**:
  - Why standard `malloc()` incurs overhead (chunk headers, boundary tags, thread-synchronization locks).
  - How memory alignment works at the bit level: `(ptr + align - 1) & ~(align - 1)`.
  - Why bump/arena allocators achieve $O(1)$ allocation time and zero per-object deallocation cost.

---

## 🎯 Drill 01-A: The Classic Bump Arena (`drill_01a_arena.cpp`)

### Problem Statement
Build an `ArenaAllocator` class that pre-allocates a single contiguous memory block and hands out slices via a bump pointer.

### Requirements & Public Interface
Your class must implement:
1. `explicit ArenaAllocator(size_t capacity_bytes)`: Allocates the raw underlying buffer using `::operator new` or `std::aligned_alloc`.
2. `~ArenaAllocator()`: Deallocates the buffer using `::operator delete` or `std::free`.
3. **Move Semantics**:
   - Explicitly delete copy constructor and copy assignment operator.
   - Implement `noexcept` move constructor and move assignment operator (steals buffer, sets source to empty).
4. `void* allocate(size_t bytes, size_t alignment = alignof(std::max_align_t))`:
   - Calculates the next aligned address from the current offset.
   - Returns pointer to aligned memory.
   - Returns `nullptr` (or throws `std::bad_alloc`) if remaining capacity is insufficient.
5. `template <typename T, typename... Args> T* create(Args&&... args)`:
   - Allocates `sizeof(T)` with alignment `alignof(T)`.
   - Constructs the object in-place using placement `new (mem) T(std::forward<Args>(args)...)`.
6. `void reset()`:
   - Resets the bump offset back to 0, allowing the entire memory pool to be reused without OS deallocations.
7. `size_t bytes_allocated() const` and `size_t capacity() const`.

### Verification Test in `main()`
- Allocate an `int` (verify address is 4-byte aligned).
- Allocate a `double` (verify address is 8-byte aligned).
- Define a 64-byte aligned struct:
  ```cpp
  struct alignas(64) SimdVector { float v[16]; };
  ```
  Allocate it and `assert(reinterpret_cast<uintptr_t>(ptr) % 64 == 0)`.
- Call `reset()` and verify you can re-allocate from the beginning of the buffer.

### Compilation Command
```bash
g++ -std=c++20 -O3 -Wall -Wextra -Werror drill_01a_arena.cpp -o drill_01a_arena && ./drill_01a_arena
```

---

## 🎯 Drill 01-B: Arena vs `malloc` Throughput Benchmark (`drill_01b_arena_benchmark.cpp`)

### Problem Statement
Quantify the physical performance gap between standard OS heap allocation (`malloc`/`free`) and your custom bump `ArenaAllocator`.

### Requirements
1. Set iterations: $N = 1,000,000$ allocations of 32 bytes each.
2. **Phase 1 (`malloc` + `free`)**:
   - Allocate $N$ pointers into a `std::vector<void*>`.
   - Free all $N$ pointers.
   - Measure elapsed time in milliseconds using `std::chrono::high_resolution_clock`.
3. **Phase 2 (Arena)**:
   - Create an `ArenaAllocator` with sufficient capacity ($N \times 48$ bytes to account for alignment).
   - In a loop of $N$ iterations, call `arena.allocate(32)`. Use `asm volatile("" : "+r"(p) : : "memory");` to prevent compiler dead-code elimination.
   - Reset the arena.
   - Measure elapsed time in milliseconds.
4. Calculate and print the speedup factor ($\text{Time}_{\text{malloc}} / \text{Time}_{\text{arena}}$).
5. **Expected Outcome**: Arena allocation should be **5x to 20x faster** than `malloc/free`.

### Compilation Command
```bash
g++ -std=c++20 -O3 -Wall -Wextra -Werror drill_01b_arena_benchmark.cpp -o drill_01b_arena_benchmark && ./drill_01b_arena_benchmark
```

---

## 🎯 Drill 01-C: Growable / Chained Arena Allocator (`drill_01c_growable_arena.cpp`)

### Problem Statement
A fixed-capacity arena has a fatal flaw: if allocation exceeds capacity, it fails. Implement a production-grade **Chained Arena** that dynamically grows by allocating linked chunks when the current chunk is exhausted.

### Requirements & Architecture
1. Define internal node:
   ```cpp
   struct Chunk {
       std::byte* data{nullptr};
       size_t capacity{0};
       size_t offset{0};
       Chunk* next{nullptr};
   };
   ```
2. Class `ChainedArenaAllocator`:
   - Takes a `default_chunk_size` (e.g. 64 KB).
   - Manages a linked list of chunks starting at `head_` and tracked by `current_`.
3. `void* allocate(size_t bytes, size_t alignment)`:
   - Attempts allocation in `current_`.
   - If not enough space remains, allocates a new `Chunk` with size `std::max(default_chunk_size, bytes + alignment)`, appends it to `current_->next`, sets `current_ = current_->next`, and allocates from the new chunk.
4. `void reset()`:
   - Iterates through all chunks from `head_` and resets each chunk's `offset` to 0.
   - Sets `current_ = head_` (does NOT free the chunks, keeping memory ready for future allocations).
5. Destructor:
   - Frees every linked chunk cleanly with zero memory leaks.

### Verification Test in `main()`
- Construct `ChainedArenaAllocator arena(1024);` (tiny 1 KB initial chunks).
- Allocate 100 objects of 256 bytes (total 25 KB, forcing ~25 dynamic chunk allocations).
- Verify every returned pointer satisfies the requested alignment.
- Call `reset()` and allocate another 512-byte object with 64-byte alignment.
- Verify with Valgrind or AddressSanitizer:
  ```bash
  g++ -std=c++20 -fsanitize=address -g -Wall -Wextra -Werror drill_01c_growable_arena.cpp -o drill_01c_growable_arena && ./drill_01c_growable_arena
  ```

---

## 🛠️ Deliberate `secan` Task (After Completing All 3 Drills)
- Create `secan/include/secan/memory/arena.hpp`.
- Place your clean `ChainedArenaAllocator` inside namespace `secan::memory`.
- Add a unit test in `secan/tests/` asserting 64-byte alignment for SIMD vector allocations.
