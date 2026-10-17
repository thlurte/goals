/**
 * Drill 01-C: Growable / Chained Arena Allocator
 * Goal: Build a production-grade arena that does not fail when a fixed capacity is exceeded,
 *       allocating chained blocks dynamically while maintaining O(1) allocation and fast reset.
 * 
 * TODO: Implement ChainedArenaAllocator below.
 * Compile: g++ -std=c++20 -O3 -Wall -Wextra -Werror drill_01c_growable_arena.cpp -o drill_01c_growable_arena
 * Run: ./drill_01c_growable_arena
 */

#include <iostream>
#include <cstddef>
#include <cstdint>
#include <new>
#include <cassert>
#include <algorithm>

class ChainedArenaAllocator {
private:
    struct Chunk {
        std::byte* data{nullptr};
        size_t capacity{0};
        size_t offset{0};
        Chunk* next{nullptr};

        explicit Chunk(size_t cap) : capacity(cap) {
            data = new std::byte[cap];
        }
        ~Chunk() {
            delete[] data;
        }
    };

    Chunk* head_{nullptr};
    Chunk* current_{nullptr};
    size_t default_chunk_size_{0};

public:
    explicit ChainedArenaAllocator(size_t default_chunk_size = 64 * 1024) // 64 KB default
        : default_chunk_size_(default_chunk_size) {
        head_ = new Chunk(default_chunk_size_);
        current_ = head_;
    }

    ~ChainedArenaAllocator() {
        Chunk* it = head_;
        while (it) {
            Chunk* next = it->next;
            delete it;
            it = next;
        }
    }

    // Non-copyable
    ChainedArenaAllocator(const ChainedArenaAllocator&) = delete;
    ChainedArenaAllocator& operator=(const ChainedArenaAllocator&) = delete;

    /**
     * Allocate aligned memory, automatically creating a new chunk if current is exhausted
     */
    void* allocate(size_t bytes, size_t alignment = alignof(std::max_align_t)) {
        // TODO: Try allocating in current_
        // If not enough room:
        //   size_t new_cap = std::max(default_chunk_size_, bytes + alignment);
        //   Chunk* new_chunk = new Chunk(new_cap);
        //   current_->next = new_chunk;
        //   current_ = new_chunk;
        //   allocate from current_
        return nullptr;
    }

    /**
     * Reset all chunks for reuse without freeing the memory blocks
     */
    void reset() {
        // TODO: Reset offset = 0 for all chunks from head_ onwards
        // Set current_ = head_
    }
};

int main() {
    std::cout << "Running Drill 01-C: Chained Arena Allocator Verification...\n";

    // Initialize with tiny 1 KB chunks to force multiple dynamic chunk allocations
    ChainedArenaAllocator arena(1024);

    // Allocate 100 objects of 256 bytes (total ~25 KB, forcing ~25 chunks)
    for (int i = 0; i < 100; ++i) {
        void* p = arena.allocate(256, 16);
        assert(p != nullptr);
        assert(reinterpret_cast<uintptr_t>(p) % 16 == 0);
    }

    // Reset and reuse
    arena.reset();
    void* p_after = arena.allocate(512, 64);
    assert(p_after != nullptr);
    assert(reinterpret_cast<uintptr_t>(p_after) % 64 == 0);

    std::cout << "All assertions PASSED! ChainedArenaAllocator dynamically grew and reset cleanly.\n";
    return 0;
}
