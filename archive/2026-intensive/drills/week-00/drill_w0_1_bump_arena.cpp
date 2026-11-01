#include <cassert>
#include <chrono>
#include <cstdint>
#include <iostream>
#include <new>
#include <string>
class BumpArena {
public:
  explicit BumpArena(size_t capacity) : offset_(0), capacity_(capacity) {
    buffer_ = static_cast<std::byte *>(::operator new(capacity_));
  }

  ~BumpArena() {
    if (buffer_) {
      ::operator delete(buffer_);
    }
  }

  BumpArena(const BumpArena &other) = delete;

  BumpArena &operator=(const BumpArena &other) = delete;

  BumpArena(BumpArena &&other) noexcept
      : buffer_(other.buffer_), offset_(other.offset_),
        capacity_(other.capacity_) {
    other.buffer_ = nullptr;
    other.capacity_ = 0;
    other.offset_ = 0;
  }

  BumpArena &operator=(BumpArena &&other) noexcept {
    if (this == &other) {
      return *this;
    }

    ::operator delete(buffer_);

    buffer_ = other.buffer_;
    offset_ = other.offset_;
    capacity_ = other.capacity_;

    other.buffer_ = nullptr;
    other.offset_ = 0;
    other.capacity_ = 0;

    return *this;
  }

  void *allocate(size_t bytes, size_t alignment = 8) {
    uintptr_t curr = reinterpret_cast<uintptr_t>(buffer_ + offset_);
    uintptr_t aligned = (curr + alignment - 1) & ~(alignment - 1);
    size_t padding = aligned - curr;

    if (offset_ + padding + bytes > capacity_) {
      throw std::bad_alloc();
    }
    offset_ += padding + bytes;
    return reinterpret_cast<void *>(aligned);
  }

  void reset() noexcept { offset_ = 0; }

  size_t bytes_allocated() const noexcept { return offset_; }

  size_t capacity() const noexcept { return capacity_; }

  template <typename T, typename... Args> T *create(Args &&...args) {
    void *mem = allocate(sizeof(T), alignof(T));

    return new (mem) T(static_cast<Args &&>(args)...);
  }

private:
  std::byte *buffer_{};
  size_t offset_{0};
  size_t capacity_{0};
};

int main() {
  BumpArena a = BumpArena(1024 * 1024);
  char *chr = a.create<char>('Z');

  std::cout << *chr;
  assert(a.bytes_allocated() == 1);
  assert(a.capacity() == 1024 * 1024);

  float *flt = a.create<float>(15.0f);
  assert(reinterpret_cast<uintptr_t>(flt) % alignof(float) == 0);

  BumpArena moved = std::move(a);
  assert(moved.capacity() == 1024 * 1024);
  assert(a.capacity() == 0);
  assert(a.bytes_allocated() == 0);

  auto start = std::chrono::high_resolution_clock::now();

  for (size_t i = 0; i < 2000000; ++i) {
    size_t capacity{32};
    void *ptr = std::malloc(capacity);
    asm volatile("" : "+r"(ptr) : : "memory");
    float *plt_ptr = static_cast<float *>(ptr);
    std::free(plt_ptr);
  }

  auto end = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double, std::milli> elapsed_ms = end - start;
  std::cout << "Elapsed time: " << elapsed_ms.count() << " ms\n";

  BumpArena a_ = BumpArena(2000000 * 32);

  auto start_ = std::chrono::high_resolution_clock::now();

  for (size_t i = 0; i < 2000000; ++i) {
    void *vptr = a_.allocate(32);
    asm volatile("" : "+r"(vptr) : : "memory");
  }

  auto end_ = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double, std::milli> elapsed_ms_ = end_ - start_;
  std::cout << "Elapsed time: " << elapsed_ms_.count() << " ms\n";
}
