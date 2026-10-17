/**
 * Drill 01: Custom Arena (Bump) Allocator
 * Goal: Master memory alignment, raw buffer management, and O(1) allocation without malloc overhead.
 * 
 * TODO: Implement ArenaAllocator below from scratch according to the specification.
 * Compile: g++ -std=c++20 -O3 -Wall -Wextra -Werror drill_01_arena.cpp -o drill_01_arena
 * Run: ./drill_01_arena
 */

#include <iostream>
#include <cstddef>
#include <cstdint>
#include <new>
#include <cassert>
#include <utility>
#include <chrono>

class ArenaAllocator {
private:
    std::byte* buffer_{nullptr};
    size_t capacity_{0};
    size_t offset_{0};

public:
    explicit ArenaAllocator(size_t capacity_bytes) 
        : capacity_(capacity_bytes) {
        // TODO: Allocate capacity_bytes using ::operator new(capacity_bytes) or std::aligned_alloc
    }

    ~ArenaAllocator() {
        // TODO: Free the buffer using ::operator delete(buffer_)
    }

    // Non-copyable
    ArenaAllocator(const ArenaAllocator&) = delete;
    ArenaAllocator& operator=(const ArenaAllocator&) = delete;

    // Movable
    ArenaAllocator(ArenaAllocator&& other) noexcept {
        // TODO: Steal resources from other, set other to empty state
    }

    ArenaAllocator& operator=(ArenaAllocator&& other) noexcept {
        // TODO: Handle self-assignment, clean up existing buffer, steal other
        return *this;
    }

    /**
     * Allocate aligned memory
     * @param bytes Number of bytes to allocate
     * @param alignment Alignment boundary (must be power of 2)
     * @return Aligned pointer to allocated memory, or nullptr / throws if out of memory
     */
    void* allocate(size_t bytes, size_t alignment = alignof(std::max_align_t)) {
        // TODO: Calculate aligned offset:
        // uintptr_t current = reinterpret_cast<uintptr_t>(buffer_ + offset_);
        // uintptr_t aligned = (current + alignment - 1) & ~(alignment - 1);
        // uintptr_t new_offset = (aligned - reinterpret_cast<uintptr_t>(buffer_)) + bytes;
        // Check capacity, update offset_, return pointer
        return nullptr;
    }

    /**
     * Helper to construct an object in-place using placement new
     */
    template <typename T, typename... Args>
    T* create(Args&&... args) {
        void* mem = allocate(sizeof(T), alignof(T));
        if (!mem) return nullptr;
        return new (mem) T(std::forward<Args>(args)...);
    }

    /**
     * Reset bump pointer to 0, reusing the entire buffer
     */
    void reset() {
        offset_ = 0;
    }

    size_t bytes_allocated() const { return offset_; }
    size_t capacity() const { return capacity_; }
};

// ==========================================
// Test Suite (Do not modify - your code must pass these)
// ==========================================
struct alignas(64) SimdVector {
    float data[16];
    SimdVector(float val) {
        for (int i = 0; i < 16; ++i) data[i] = val;
    }
};

int main() {
    std::cout << "Running Drill 01: Arena Allocator Verification...\n";

    // Test 1: Basic allocation & alignment
    ArenaAllocator arena(1024 * 1024); // 1 MB
    assert(arena.capacity() == 1024 * 1024);
    assert(arena.bytes_allocated() == 0);

    int* a = arena.create<int>(42);
    assert(a != nullptr);
    assert(*a == 42);
    assert(reinterpret_cast<uintptr_t>(a) % alignof(int) == 0);

    double* b = arena.create<double>(3.14159);
    assert(b != nullptr);
    assert(*b == 3.14159);
    assert(reinterpret_cast<uintptr_t>(b) % alignof(double) == 0);

    // Test 2: 64-byte SIMD alignment
    SimdVector* vec = arena.create<SimdVector>(1.0f);
    assert(vec != nullptr);
    assert(reinterpret_cast<uintptr_t>(vec) % 64 == 0);
    assert(vec->data[0] == 1.0f && vec->data[15] == 1.0f);

    // Test 3: Reset
    size_t allocated_before = arena.bytes_allocated();
    assert(allocated_before > 0);
    arena.reset();
    assert(arena.bytes_allocated() == 0);

    // Re-allocate after reset
    int* c = arena.create<int>(100);
    assert(c != nullptr && *c == 100);

    std::cout << "All assertions PASSED! ArenaAllocator is functional and aligned.\n";
    return 0;
}
