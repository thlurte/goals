#include <algorithm> // for std::max
#include <cstdint>   // for uintptr_t
#include <iostream>
#include <new>
struct Chunk {
  std::byte *data;
  size_t capacity;
  size_t offset;
  Chunk *next{nullptr};
};

class ChainedArena {
public:
  explicit ChainedArena(size_t default_capacity = 1024)
      : default_chunk_size_(default_capacity) {
    Chunk *chunk_ = new Chunk();
    chunk_->capacity = default_chunk_size_;
    chunk_->data =
        static_cast<std::byte *>(::operator new(default_chunk_size_));
    chunk_->offset = 0;
    head_ = chunk_;
  }

  ~ChainedArena() {

    Chunk *curr = head_;
    while (curr != nullptr) {
      Chunk *next = curr->next;
      ::operator delete(curr->data);
      delete curr;

      curr = next;
    }
  }

  ChainedArena(const ChainedArena &) = delete;
  ChainedArena &operator=(const ChainedArena &) = delete;

  ChainedArena(ChainedArena &&other) noexcept
      : head_(other.head_), default_chunk_size_(other.default_chunk_size_) {
    other.head_ = nullptr;
    other.default_chunk_size_ = 0;
  }

  ChainedArena &operator=(ChainedArena &&other) noexcept {
    if (this == &other) {
      return *this;
    }

    Chunk *curr = head_;
    while (curr != nullptr) {
      Chunk *next = curr->next;
      ::operator delete(curr->data);
      delete curr;

      curr = next;
    }

    head_ = other.head_;
    default_chunk_size_ = other.default_chunk_size_;

    other.head_ = nullptr;
    other.default_chunk_size_ = 0;

    return *this;
  }

  void *allocate(size_t bytes, size_t alignment = 8) {
    uintptr_t curr = reinterpret_cast<uintptr_t>(head_->data + head_->offset);
    uintptr_t aligned = (curr + alignment - 1) & ~(alignment - 1);
    size_t padding = aligned - curr;

    if (head_->offset + padding + bytes <= head_->capacity) {
      head_->offset += padding + bytes;
      return reinterpret_cast<void *>(aligned);
    } else {
      size_t new_cap = std::max(default_chunk_size_, bytes + alignment);
      Chunk *new_chunk = new Chunk();
      new_chunk->data = static_cast<std::byte *>(::operator new(new_cap));
      new_chunk->capacity = new_cap;
      new_chunk->offset = 0;

      new_chunk->next = head_;
      head_ = new_chunk;

      uintptr_t n_curr =
          reinterpret_cast<uintptr_t>(head_->data + head_->offset);
      uintptr_t n_aligned = (n_curr + alignment - 1) & ~(alignment - 1);
      size_t n_padding = n_aligned - n_curr;
      head_->offset += n_padding + bytes;

      return reinterpret_cast<void *>(n_aligned);
    }
  }

  void reset() {
    Chunk *curr = head_;
    while (curr != nullptr) {
      curr->offset = 0;
      curr = curr->next;
    }
  }

  template <typename T, typename... Args> T *create(Args &&...args) {
    void *mem = allocate(sizeof(T), alignof(T));
    return new (mem) T(static_cast<Args &&>(args)...);
  }

private:
  Chunk *head_{nullptr};
  size_t default_chunk_size_{1024};
};

#include <cassert>

int main() {
  // Start with a small default chunk of 1024 bytes
  ChainedArena arena(1024);

  // 1. Allocate 200 blocks of 256 bytes each (~50 KB total)
  // This will force the arena to dynamically allocate ~50 chunks!
  void *first_ptr = nullptr;
  for (int i = 0; i < 200; ++i) {
    void *ptr = arena.allocate(256, 8);
    assert(ptr != nullptr);
    assert(reinterpret_cast<uintptr_t>(ptr) % 8 == 0); // 8-byte aligned

    // Write to the memory to ensure it's valid RAM
    *static_cast<char *>(ptr) = static_cast<char>(i % 128);

    if (i == 0)
      first_ptr = ptr;
  }

  std::cout << "Successfully allocated 200 blocks across dynamic chunks!\n";

  // 2. Test reset
  arena.reset();
  void *after_reset_ptr = arena.allocate(256, 8);
  assert(after_reset_ptr != nullptr);
  std::cout << "Reset succeeded!\n";

  // 3. Test Move
  ChainedArena moved_arena = std::move(arena);
  void *moved_ptr = moved_arena.allocate(128, 8);
  assert(moved_ptr != nullptr);
  std::cout << "Move semantics succeeded!\n";

  std::cout << ">>> ALL DRILL W0-3 CHECKS PASSED! <<<\n";
  return 0;
}
