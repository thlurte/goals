# Week 1, Day 2: RAII, Smart Pointers & Move Semantics
> **Date**: Tuesday, October 20, 2026  
> **Rule**: You create and code each `.cpp` file from a completely blank file. No boilerplate is provided.

---

## 📖 Required Reading Before Coding
- **Book**: **[ArtOfProg]** (Fedor Pikus)
- **Section**: **Chapter 2 ("Resource Management and RAII")**, pages 25–45.
- **Key Concepts to Internalize**:
  - The Rule of 5 vs Rule of 0: When custom destructors necessitate custom move/copy operators.
  - The Copy-and-Swap idiom: Exception-safe assignment without duplicate deallocation code.
  - Atomic control blocks in `std::shared_ptr`: Why shared ownership has synchronization overhead.

---

## 🎯 Drill 02-A: Custom `UniquePtr<T>` with Custom Deleter (`drill_02a_unique_ptr.cpp`)

### Problem Statement
Implement a custom move-only `UniquePtr<T, Deleter = std::default_delete<T>>` that models strict, zero-overhead single ownership.

### Requirements & Public Interface
1. Default constructor: `UniquePtr()` initializes pointer to `nullptr`.
2. Explicit constructor: `explicit UniquePtr(T* ptr)`.
3. Constructor with custom deleter: `UniquePtr(T* ptr, Deleter deleter)`.
4. **Copy Semantics**:
   - `UniquePtr(const UniquePtr&) = delete;`
   - `UniquePtr& operator=(const UniquePtr&) = delete;`
5. **Move Semantics**:
   - `UniquePtr(UniquePtr&& other) noexcept`: Transfers pointer, sets `other` to `nullptr`.
   - `UniquePtr& operator=(UniquePtr&& other) noexcept`: Handles self-assignment, deletes owned pointer, steals from `other`.
6. **Destructor**:
   - Calls `deleter_(ptr_)` if `ptr_ != nullptr`.
7. **Observers & Modifiers**:
   - `T& operator*() const`, `T* operator->() const`, `T* get() const`.
   - `explicit operator bool() const noexcept`: Checks if pointer is non-null.
   - `T* release() noexcept`: Relinquishes ownership and returns raw pointer.
   - `void reset(T* ptr = nullptr) noexcept`: Deletes current pointer, adopts new pointer.
8. Helper function `make_unique<T, Args...>(Args&&... args)`.

### Verification Test in `main()`
- Construct `UniquePtr<int>` and verify value via `*` and `->`.
- Demonstrate move construction and move assignment, asserting source becomes `nullptr`.
- Test with a custom lambda/struct deleter (e.g. tracking deallocation calls).
- Verify zero memory leaks under AddressSanitizer:
  ```bash
  g++ -std=c++20 -fsanitize=address -g -Wall -Wextra -Werror drill_02a_unique_ptr.cpp -o drill_02a_unique_ptr && ./drill_02a_unique_ptr
  ```

---

## 🎯 Drill 02-B: Custom `SharedPtr<T>` with Atomic Ref-Counting (`drill_02b_shared_ptr.cpp`)

### Problem Statement
Implement a thread-safe `SharedPtr<T>` that manages a shared object using an atomic control block.

### Requirements & Public Interface
1. Control Block:
   ```cpp
   struct ControlBlock {
       std::atomic<long> ref_count{1};
   };
   ```
2. Class `SharedPtr<T>`:
   - Stores `T* ptr_{nullptr};` and `ControlBlock* ctrl_{nullptr};`.
3. Constructors:
   - `explicit SharedPtr(T* ptr = nullptr)`: Allocates control block on heap if `ptr != nullptr`.
4. Copy Semantics (Shared Ownership):
   - Copy Constructor: Increments `ctrl_->ref_count.fetch_add(1)`.
   - Copy Assignment: Decrements own ref count (frees if 0), steals pointer and control block, increments ref count.
5. Move Semantics:
   - Move Constructor: Steals pointer and control block without modifying ref count; zeros source.
   - Move Assignment: Decrements own ref count (frees if 0), steals from source, zeros source.
6. Destructor:
   - Decrements `ctrl_->ref_count.fetch_sub(1)`. If new count is 0: calls `delete ptr_` and `delete ctrl_`.
7. Methods:
   - `long use_count() const noexcept`: Returns current ref count.
   - `T& operator*() const`, `T* operator->() const`, `T* get() const`.
   - `void reset() noexcept`.

### Verification Test in `main()`
- Create `SharedPtr<int>` and assert `use_count() == 1`.
- Make 3 copies into a `std::vector<SharedPtr<int>>`, asserting `use_count() == 4`.
- Pop elements from vector and verify `use_count()` decrements appropriately.
- Verify memory is cleanly freed when last instance leaves scope (under AddressSanitizer).

---

## 🎯 Drill 02-C: Rule of Five & Copy-and-Swap Aligned Buffer (`drill_02c_rule_of_five.cpp`)

### Problem Statement
Implement a 64-byte aligned vector buffer `AlignedBuffer` demonstrating the **Copy-and-Swap** idiom to eliminate redundant allocation/free logic between copy assignment and move assignment.

### Requirements
1. Class `AlignedBuffer`:
   - Members: `float* data_{nullptr};`, `size_t size_{0};`.
   - Constructor `explicit AlignedBuffer(size_t size)`: Allocates 64-byte aligned memory using `posix_memalign` or `std::aligned_alloc`.
   - Destructor: Frees memory with `free`.
   - Copy Constructor: Deep copies elements.
   - Move Constructor: Swaps pointers.
   - Friend `void swap(AlignedBuffer& first, AlignedBuffer& second) noexcept`.
   - **Unified Assignment Operator (Copy-and-Swap)**:
     ```cpp
     AlignedBuffer& operator=(AlignedBuffer other) noexcept {
         swap(*this, other);
         return *this;
     }
     ```
     *(Notice: `other` is passed by value! If caller passes lvalue, copy ctor runs. If rvalue, move ctor runs. Exception safety is 100% guaranteed!)*

### Verification Test in `main()`
- Verify self-assignment, copy assignment, and move assignment.
- Verify 64-byte alignment: `assert(reinterpret_cast<uintptr_t>(buf.data()) % 64 == 0)`.
- Compile and verify with AddressSanitizer.
