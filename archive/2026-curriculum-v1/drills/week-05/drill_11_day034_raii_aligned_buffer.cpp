// ==============================================================================
// 🥋 Drill 11 (Day 34.3): Modern C++ RAII — 64-Byte Cache-Aligned Buffer (Rule
// of 5)
//
// 📖 READING SOURCES:
// - Meyers: Effective Modern C++ (Items 11-17: Move Semantics & Special Member
// Functions)
// - Agner Fog: Optimizing Software in C++ (Ch 8: Memory Management & Dynamic
// Allocation)
//
// 🎯 CORE LESSON:
// 1. `posix_memalign` / `std::aligned_alloc` allocates memory aligned to 64
// bytes (L1/L2 cache lines & AVX-512).
// 2. Full Rule of 5:
//    - Destructor: `free(ptr_)`
//    - Move Constructor: Steals pointer & capacity, zeros source.
//    - Move Assignment: Releases existing resource, steals new, handles
//    self-assignment.
//    - Copy Constructor & Copy Assignment: Disabled (or deep copy) to prevent
//    double-free hazards.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra drill_11_day034_raii_aligned_buffer.cpp -o
// drill11 && ./drill11
// ==============================================================================

#include <cassert>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <span>
#include <utility>

template <typename T, size_t Alignment = 64> class AlignedBuffer {
public:
  AlignedBuffer() noexcept : ptr_(nullptr), size_(0) {}

  explicit AlignedBuffer(size_t size) : size_(size) {
    if (size_ > 0) {
      size_t bytes = size_ * sizeof(T);
      // Ensure byte allocation is a multiple of alignment
      size_t remainder = bytes % Alignment;
      if (remainder != 0) {
        bytes += (Alignment - remainder);
      }
      void *raw_ptr = nullptr;
      int ret = posix_memalign(&raw_ptr, Alignment, bytes);
      if (ret != 0 || raw_ptr == nullptr) {
        throw std::bad_alloc();
      }
      ptr_ = static_cast<T *>(raw_ptr);
    } else {
      ptr_ = nullptr;
    }
  }

  // Destructor
  ~AlignedBuffer() noexcept { reset(); }

  // Non-copyable (Unique ownership)
  AlignedBuffer(const AlignedBuffer &) = delete;
  AlignedBuffer &operator=(const AlignedBuffer &) = delete;

  // TODO 1: Implement Move Constructor
  // - Steal pointer and size from other using std::exchange
  // - Leave other in a valid empty state
  AlignedBuffer(AlignedBuffer &&other) noexcept
      // [YOUR CODE HERE]
      : ptr_(std::exchange(other.ptr_, nullptr)),
        size_(std::exchange(other.size_, 0)) {}

  // TODO 2: Implement Move Assignment Operator
  // - Check for self-assignment (this != &other)
  // - Free existing resource (reset())
  // - Steal pointer and size from other using std::exchange
  AlignedBuffer &operator=(AlignedBuffer &&other) noexcept {
    // [YOUR CODE HERE]
    if (this != &other) {
      reset();
      this->ptr_ = other.ptr_;
      this->size_ = other.size_;

      other.ptr_ = nullptr;
      other.size_ = 0;
    }
    return *this;
  }

  void reset() noexcept {
    if (ptr_ != nullptr) {
      std::free(ptr_);
      ptr_ = nullptr;
      size_ = 0;
    }
  }

  [[nodiscard]] T *data() noexcept { return ptr_; }
  [[nodiscard]] const T *data() const noexcept { return ptr_; }
  [[nodiscard]] size_t size() const noexcept { return size_; }

  T &operator[](size_t idx) noexcept { return ptr_[idx]; }
  const T &operator[](size_t idx) const noexcept { return ptr_[idx]; }

  [[nodiscard]] std::span<T> span() noexcept { return {ptr_, size_}; }
  [[nodiscard]] std::span<const T> span() const noexcept {
    return {ptr_, size_};
  }

private:
  T *ptr_{nullptr};
  size_t size_{0};
};

int main() {
  std::cout << "--- Drill 11: RAII 64-Byte Aligned Buffer & Rule of 5 ---\n\n";

  constexpr size_t N = 1024;
  AlignedBuffer<float, 64> buf(N);

  // Verify 64-byte alignment
  uintptr_t addr = reinterpret_cast<uintptr_t>(buf.data());
  std::cout << "Allocated address: 0x" << std::hex << addr << std::dec << "\n";
  assert(addr % 64 == 0 && "Buffer is not 64-byte aligned!");

  // Populate data
  for (size_t i = 0; i < N; ++i)
    buf[i] = static_cast<float>(i);

  // Test Move Constructor
  AlignedBuffer<float, 64> moved_buf = std::move(buf);
  assert(buf.data() == nullptr);
  assert(buf.size() == 0);
  assert(moved_buf.size() == N);
  assert(moved_buf[10] == 10.0f);
  std::cout << "✓ Move construction verified!\n";

  // Test Move Assignment
  AlignedBuffer<float, 64> assigned_buf;
  assigned_buf = std::move(moved_buf);
  assert(moved_buf.data() == nullptr);
  assert(assigned_buf.size() == N);
  assert(assigned_buf[42] == 42.0f);
  std::cout << "✓ Move assignment verified!\n";

  std::cout << "\n✓ Drill 11 Passed: RAII aligned buffer fully operational!\n";
  return 0;
}
