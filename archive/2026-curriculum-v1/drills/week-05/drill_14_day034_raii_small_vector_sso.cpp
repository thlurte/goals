// ==============================================================================
// 🥋 Drill 14 (Day 34.6): Modern C++ RAII — Small-Vector Optimization (SSO)
//
// 📖 READING SOURCES:
// - Meyers: Effective Modern C++ (Item 23: Understand std::move and
// std::forward)
// - LLVM / Abseil: `llvm::SmallVector` / `absl::InlinedVector` Design
// Architecture
//
// 🎯 CORE LESSON:
// 1. Small-Size Optimization (SSO): Avoid heap allocations for small vector
// dimensions (e.g. N <= 16).
// 2. Inline stack array vs Heap pointer union.
// 3. Move semantics with SSO: When moving an SSO vector, elements are moved
// from stack to stack;
//    when moving a heap vector, only the pointer is stolen.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra drill_14_day034_raii_small_vector_sso.cpp -o
// drill14 && ./drill14
// ==============================================================================

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <utility>

template <typename T, size_t InlineCapacity = 8> class SmallVector {
public:
  SmallVector() noexcept
      : size_(0), capacity_(InlineCapacity), is_heap_(false) {}

  explicit SmallVector(size_t n, const T &val = T())
      : size_(0), capacity_(InlineCapacity), is_heap_(false) {
    reserve(n);
    for (size_t i = 0; i < n; ++i) {
      push_back(val);
    }
  }

  ~SmallVector() noexcept {
    clear();
    if (is_heap_) {
      std::free(heap_ptr_);
    }
  }

  // Move constructor
  SmallVector(SmallVector &&other) noexcept
      : size_(0), capacity_(InlineCapacity), is_heap_(false) {
    if (other.is_heap_) {
      // Steal heap pointer
      heap_ptr_ = other.heap_ptr_;
      size_ = other.size_;
      capacity_ = other.capacity_;
      is_heap_ = true;

      other.heap_ptr_ = nullptr;
      other.size_ = 0;
      other.capacity_ = InlineCapacity;
      other.is_heap_ = false;
    } else {
      // Move stack elements
      for (size_t i = 0; i < other.size_; ++i) {
        new (&inline_storage_[i]) T(std::move(other.inline_storage_[i]));
      }
      size_ = other.size_;
      other.clear();
    }
  }

  // TODO 1: Implement capacity reservation (spill from inline storage to heap)
  // 1. Allocate new heap memory: malloc(new_cap * sizeof(T))
  // 2. Move existing elements from old storage (inline or heap) into new heap
  // buffer
  // 3. Destroy old elements and free old heap storage if is_heap_ was true
  // 4. Update heap_ptr_, capacity_, and set is_heap_ = true
  void reserve(size_t new_cap) {
    // [YOUR CODE HERE]
    if (new_cap <= capacity_) {
      return;
    }

    T *new_ptr = static_cast<T *>(std::malloc(new_cap * sizeof(T)));
    if (!new_ptr) {
      throw std::bad_alloc();
    }

    T *old_ptr = is_heap_ ? heap_ptr_ : inline_storage_;

    for (size_t i = 0; i < size_; ++i) {
      new (&new_ptr[i]) T(std::move(old_ptr[i]));

      old_ptr[i].~T();
    }

    if (is_heap_) {
      std::free(heap_ptr_);
    }

    heap_ptr_ = new_ptr;
    capacity_ = new_cap;
    is_heap_ = true;
  }

  // TODO 2: Implement push_back with automatic SSO-to-heap growth
  // 1. If size_ == capacity_, double capacity via reserve(capacity_ * 2)
  // 2. Construct element in-place at index size_ using placement-new
  // 3. Increment size_
  void push_back(const T &val) {
    // [YOUR CODE HERE]
    if (size_ == capacity_) {
      reserve(capacity_ * 2);
    }

    T *data_ptr = is_heap_ ? heap_ptr_ : inline_storage_;

    new (&data_ptr[size_]) T(val);
    size_++;
  }

  void clear() noexcept {
    T *dst = is_heap_ ? heap_ptr_ : inline_storage_;
    for (size_t i = 0; i < size_; ++i) {
      dst[i].~T();
    }
    size_ = 0;
  }

  [[nodiscard]] size_t size() const noexcept { return size_; }
  [[nodiscard]] size_t capacity() const noexcept { return capacity_; }
  [[nodiscard]] bool is_heap() const noexcept { return is_heap_; }

  T &operator[](size_t i) noexcept {
    return is_heap_ ? heap_ptr_[i] : inline_storage_[i];
  }
  const T &operator[](size_t i) const noexcept {
    return is_heap_ ? heap_ptr_[i] : inline_storage_[i];
  }

private:
  union {
    T inline_storage_[InlineCapacity];
    T *heap_ptr_;
  };
  size_t size_{0};
  size_t capacity_{InlineCapacity};
  bool is_heap_{false};
};

int main() {
  std::cout << "--- Drill 14: Small Vector Optimization (SSO) & Memory Layout "
               "---\n\n";

  // 1. Small size: fits in inline storage (0 heap allocations!)
  SmallVector<int, 8> sv_small;
  for (int i = 0; i < 8; ++i)
    sv_small.push_back(i * 10);
  assert(!sv_small.is_heap());
  assert(sv_small.size() == 8);
  assert(sv_small[3] == 30);
  std::cout
      << "✓ Stack-allocated SSO vector verified (8 elements, 0 heap calls)!\n";

  // 2. Growth beyond inline capacity triggers smooth heap spillover
  sv_small.push_back(80);
  assert(sv_small.is_heap());
  assert(sv_small.size() == 9);
  assert(sv_small[8] == 80);
  std::cout << "✓ Seamless heap spillover verified (now on heap with cap "
            << sv_small.capacity() << ")!\n";

  // 3. Move semantics test
  SmallVector<int, 8> sv_moved = std::move(sv_small);
  assert(sv_moved.is_heap());
  assert(sv_moved.size() == 9);
  assert(sv_moved[8] == 80);
  assert(sv_small.size() == 0);
  std::cout << "✓ SSO move semantics verified!\n";

  std::cout << "\n✓ Drill 14 Passed: SmallVector SSO fully operational!\n";
  return 0;
}
