/**
 * Drill 01-B: Arena Allocator vs malloc Throughput Benchmark
 * Goal: Quantify the latency and throughput difference between OS malloc and an arena bump allocator.
 * 
 * TODO: Implement the benchmark measuring 1,000,000 allocations of 32-byte chunks.
 * Compile: g++ -std=c++20 -O3 -Wall -Wextra -Werror drill_01b_arena_benchmark.cpp -o drill_01b_arena_benchmark
 * Run: ./drill_01b_arena_benchmark
 */

#include <iostream>
#include <chrono>
#include <vector>
#include <cstdlib>
#include <cstdint>

// Paste or include your ArenaAllocator from Drill 01-A here
class ArenaAllocator {
private:
    std::byte* buffer_{nullptr};
    size_t capacity_{0};
    size_t offset_{0};
public:
    explicit ArenaAllocator(size_t capacity) : capacity_(capacity) {
        buffer_ = new std::byte[capacity];
    }
    ~ArenaAllocator() { delete[] buffer_; }
    void* allocate(size_t bytes, size_t alignment = 8) {
        uintptr_t current = reinterpret_cast<uintptr_t>(buffer_ + offset_);
        uintptr_t aligned = (current + alignment - 1) & ~(alignment - 1);
        size_t new_offset = (aligned - reinterpret_cast<uintptr_t>(buffer_)) + bytes;
        if (new_offset > capacity_) return nullptr;
        offset_ = new_offset;
        return reinterpret_cast<void*>(aligned);
    }
    void reset() { offset_ = 0; }
};

int main() {
    const size_t NUM_ALLOCS = 1'000'000;
    const size_t ALLOC_SIZE = 32;

    std::cout << "Benchmarking " << NUM_ALLOCS << " allocations of " << ALLOC_SIZE << " bytes...\n\n";

    // 1. Benchmark standard malloc + free
    auto start_malloc = std::chrono::high_resolution_clock::now();
    std::vector<void*> ptrs;
    ptrs.reserve(NUM_ALLOCS);
    for (size_t i = 0; i < NUM_ALLOCS; ++i) {
        ptrs.push_back(std::malloc(ALLOC_SIZE));
    }
    for (void* p : ptrs) {
        std::free(p);
    }
    auto end_malloc = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> diff_malloc = end_malloc - start_malloc;
    std::cout << "1. malloc + free:       " << diff_malloc.count() << " ms\n";

    // 2. Benchmark ArenaAllocator
    ArenaAllocator arena(NUM_ALLOCS * 48); // plenty of room for padding
    auto start_arena = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < NUM_ALLOCS; ++i) {
        void* p = arena.allocate(ALLOC_SIZE);
        // Prevent compiler dead-code elimination
        asm volatile("" : "+r"(p) : : "memory");
    }
    arena.reset();
    auto end_arena = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> diff_arena = end_arena - start_arena;
    std::cout << "2. ArenaAllocator bump: " << diff_arena.count() << " ms\n";

    double speedup = diff_malloc.count() / diff_arena.count();
    std::cout << "\n>>> Arena is " << speedup << "x FASTER than malloc/free! <<<\n";

    return 0;
}
