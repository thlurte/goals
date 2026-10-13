// ==============================================================================
// 🥋 Drill: Arena Bump Allocator with Placement new & Explicit Destructors
//
// 📖 READING SOURCES:
// - Agner Fog: Optimizing Software in C++ (Ch 8)
// - Nystrom: Game Programming Patterns (Sub-allocators)
//
// 🎯 CORE LESSON:
// 1. Arena bump allocators allocate sequentially by advancing an offset pointer (near zero cost).
// 2. Placement `new (ptr) T(...)` constructs an object in pre-allocated memory.
// 3. Objects must be manually destructed via `ptr->~T()` before resetting the entire arena in bulk.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_18_day038_mem_arena_bump_placement_new.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <vector>
#include <cstddef>
#include <new>
#include <cassert>

class BumpArena {
public:
    explicit BumpArena(size_t capacity) : buffer_(capacity), offset_(0) {}

    void* allocate(size_t bytes, size_t alignment = 8) {
        size_t current = reinterpret_cast<size_t>(buffer_.data() + offset_);
        size_t padding = (alignment - (current % alignment)) % alignment;
        if (offset_ + padding + bytes > buffer_.size()) {
            return nullptr; // Out of memory
        }
        offset_ += padding;
        void* ptr = buffer_.data() + offset_;
        offset_ += bytes;
        return ptr;
    }

    void reset() noexcept { offset_ = 0; }

private:
    std::vector<std::byte> buffer_;
    size_t offset_;
};

static int s_destructor_count = 0;

struct VectorItem {
    int id;
    float value;
    VectorItem(int i, float v) : id(i), value(v) {}
    ~VectorItem() { s_destructor_count++; }
};

int main() {
    std::cout << "--- Drill 18: Arena Bump Allocator with Placement new ---\n\n";

    BumpArena arena(1024);
    void* mem = arena.allocate(sizeof(VectorItem), alignof(VectorItem));
    assert(mem != nullptr);

    // Placement new
    VectorItem* item = new (mem) VectorItem(99, 1.23f);
    assert(item->id == 99);
    assert(item->value == 1.23f);

    // Explicit destructor call
    item->~VectorItem();
    assert(s_destructor_count == 1);

    arena.reset();
    std::cout << "\n✓ Drill 18 Passed: Placement new and arena bump allocation verified!\n";
    return 0;
}
