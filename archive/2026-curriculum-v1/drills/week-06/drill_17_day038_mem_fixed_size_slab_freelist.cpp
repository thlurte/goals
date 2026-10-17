// ==============================================================================
// 🥋 Drill: Fixed-Size Slab Allocator with Embedded Free List
//
// 📖 READING SOURCES:
// - Bonwick: The Slab Allocator: An Object-Caching Kernel Memory Allocator
// - Agner Fog: Optimizing Software in C++ (Ch 8: Memory Allocation)
//
// 🎯 CORE LESSON:
// 1. Slab allocators serve fixed-size blocks in $O(1)$ time with zero heap fragmentation.
// 2. Free blocks store pointers to the next free block inside their own unused memory (embedded free-list).
// 3. Drastically outperforms generic `malloc` for high-frequency node allocations.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_17_day038_mem_fixed_size_slab_freelist.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <cstddef>
#include <cstdint>
#include <vector>
#include <cassert>

template <size_t BlockSize, size_t NumBlocks>
class SlabAllocator {
    union Node {
        Node* next;
        alignas(8) std::byte storage[BlockSize];
    };

public:
    SlabAllocator() : pool_(NumBlocks), free_head_(nullptr) {
        for (size_t i = 0; i < NumBlocks - 1; ++i) {
            pool_[i].next = &pool_[i + 1];
        }
        pool_[NumBlocks - 1].next = nullptr;
        free_head_ = &pool_[0];
    }

    void* allocate() {
        if (!free_head_) return nullptr;
        Node* block = free_head_;
        free_head_ = free_head_->next;
        return block;
    }

    void deallocate(void* ptr) noexcept {
        if (!ptr) return;
        Node* block = static_cast<Node*>(ptr);
        block->next = free_head_;
        free_head_ = block;
    }

private:
    std::vector<Node> pool_;
    Node* free_head_;
};

int main() {
    std::cout << "--- Drill 17: Fixed-Size Slab Allocator ---\n\n";

    SlabAllocator<32, 4> slab;
    void* p1 = slab.allocate();
    void* p2 = slab.allocate();
    assert(p1 != nullptr && p2 != nullptr && p1 != p2);

    slab.deallocate(p1);
    void* p3 = slab.allocate();
    assert(p3 == p1 && "Recycled block must match recently deallocated slab address!");

    std::cout << "\n✓ Drill 17 Passed: O(1) Slab allocator free-list verified!\n";
    return 0;
}
