// ==============================================================================
// 🥋 Drill 13 (Day 34.5): Modern C++ RAII — Custom Deleters & Arena Bump Allocator
//
// 📖 READING SOURCES:
// - Meyers: Effective Modern C++ (Item 18: Use std::unique_ptr for exclusive-ownership)
// - Alexandrescu: Modern C++ Design (Ch 4: Small-Object Allocation)
//
// 🎯 CORE LESSON:
// 1. `std::unique_ptr<T, Deleter>` with stateful and stateless custom deleters.
// 2. Arena / Bump Allocator: Pre-allocates a massive contiguous block (e.g. 64 MiB),
//    sub-allocating objects in $O(1)$ by bumping an offset pointer.
// 3. Fast bulk reset: Releasing an entire arena frees thousands of allocations in $O(1)$.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra drill_13_day034_raii_custom_deleter_arena.cpp -o drill13 && ./drill13
// ==============================================================================

#include <iostream>
#include <memory>
#include <vector>
#include <cstdint>
#include <cassert>
#include <utility>
#include <new>

class ArenaAllocator {
public:
    explicit ArenaAllocator(size_t capacity_bytes)
        : capacity_(capacity_bytes), offset_(0) {
        buffer_ = static_cast<uint8_t*>(std::aligned_alloc(64, capacity_));
        if (!buffer_) throw std::bad_alloc();
    }

    ~ArenaAllocator() noexcept {
        if (buffer_) {
            std::free(buffer_);
            buffer_ = nullptr;
        }
    }

    ArenaAllocator(const ArenaAllocator&) = delete;
    ArenaAllocator& operator=(const ArenaAllocator&) = delete;

    ArenaAllocator(ArenaAllocator&& other) noexcept
        : buffer_(std::exchange(other.buffer_, nullptr)),
          capacity_(std::exchange(other.capacity_, 0)),
          offset_(std::exchange(other.offset_, 0)) {}

    ArenaAllocator& operator=(ArenaAllocator&& other) noexcept {
        if (this != &other) {
            if (buffer_) std::free(buffer_);
            buffer_ = std::exchange(other.buffer_, nullptr);
            capacity_ = std::exchange(other.capacity_, 0);
            offset_ = std::exchange(other.offset_, 0);
        }
        return *this;
    }

    // TODO 1: Implement template-based in-place bump allocation
    // 1. Calculate alignment padding: padding = (alignof(T) - (current_addr % alignof(T))) % alignof(T)
    // 2. Check if offset_ + padding + sizeof(T) > capacity_ (throw std::bad_alloc if exceeded)
    // 3. Update offset_ and construct object in-place using placement-new: new (target_ptr) T(args...)
    template <typename T, typename... Args>
    T* allocate(Args&&... args) {
        // [YOUR CODE HERE]
        return nullptr;
    }

    // O(1) bulk reset of entire arena
    void reset() noexcept {
        offset_ = 0;
    }

    [[nodiscard]] size_t used_bytes() const noexcept { return offset_; }
    [[nodiscard]] size_t capacity() const noexcept { return capacity_; }

private:
    uint8_t* buffer_{nullptr};
    size_t capacity_{0};
    size_t offset_{0};
};

// Struct to track destructor calls
struct TrackedResource {
    int id{0};
    static inline int active_count{0};

    explicit TrackedResource(int val) : id(val) {
        ++active_count;
    }

    ~TrackedResource() {
        --active_count;
    }
};

int main() {
    std::cout << "--- Drill 13: RAII Custom Deleters & Arena Bump Allocator ---\n\n";

    constexpr size_t ARENA_SIZE = 1024 * 1024; // 1 MiB
    ArenaAllocator arena(ARENA_SIZE);

    assert(TrackedResource::active_count == 0);

    // 1. Allocate 100 tracked resources in the arena
    std::vector<TrackedResource*> items;
    for (int i = 0; i < 100; ++i) {
        items.push_back(arena.allocate<TrackedResource>(i));
    }

    assert(TrackedResource::active_count == 100);
    std::cout << "Allocated 100 items. Arena used: " << arena.used_bytes() << " bytes\n";
    assert(items[50]->id == 50);

    // 2. Custom Deleter for single arena object (invokes destructor without free)
    auto arena_deleter = [](TrackedResource* p) {
        if (p) p->~TrackedResource();
    };

    {
        std::unique_ptr<TrackedResource, decltype(arena_deleter)> managed_item(
            arena.allocate<TrackedResource>(999), arena_deleter
        );
        assert(TrackedResource::active_count == 101);
        assert(managed_item->id == 999);
    } // managed_item destroyed here, active_count decreases!

    assert(TrackedResource::active_count == 100);
    std::cout << "✓ Custom unique_ptr deleter verified!\n";

    // 3. Explicitly destroy elements and reset arena
    for (auto* item : items) {
        item->~TrackedResource();
    }
    arena.reset();

    assert(TrackedResource::active_count == 0);
    assert(arena.used_bytes() == 0);
    std::cout << "✓ O(1) Arena bulk reset verified!\n";

    std::cout << "\n✓ Drill 13 Passed: RAII custom deleters & Arena allocator verified!\n";
    return 0;
}
