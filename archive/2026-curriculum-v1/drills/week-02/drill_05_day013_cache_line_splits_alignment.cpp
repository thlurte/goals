// ==============================================================================
// 🥋 Drill 05 (Week 02 / Day 013): Agner Fog Ch 13 — Memory Alignment & Cache Line Splits
//
// 📖 READING SOURCES:
// - Agner Fog: Optimizing Software in C++ (Ch 13: Alignment & Memory Access)
//
// 🎯 CORE LESSON:
// 1. 64-Byte Cache Line Crossing:
//    When a 32-byte SIMD load (`_mm256_loadu_ps`) crosses a 64-byte cache line boundary,
//    the CPU must issue 2 separate cache access micro-ops, incurring a split-load penalty.
// 2. 64-Byte Alignment in Modern C++:
//    Using `alignas(64)` aligns memory buffers to L1 cache line boundaries, guaranteeing
//    every SIMD load fits within a single cache line.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra drill_05_day013_cache_line_splits_alignment.cpp -o drill05 && ./drill05
// ==============================================================================

#include <iostream>
#include <cstdint>
#include <cassert>

// Check if a pointer is aligned to N bytes (e.g. 64 bytes)
inline bool is_aligned(const void* ptr, size_t alignment) {
    return (reinterpret_cast<uintptr_t>(ptr) % alignment) == 0;
}

struct alignas(64) AlignedVectorBlock {
    float data[16]; // 16 floats * 4 bytes = 64 bytes (exact 1 cache line)
};

int main() {
    std::cout << "--- Week 02 Drill 05: Cache Line Alignment (alignas(64)) ---\n\n";

    AlignedVectorBlock block;
    std::cout << "AlignedVectorBlock Address: " << static_cast<void*>(&block) << "\n";

    assert(is_aligned(&block, 64) == true);
    assert(sizeof(AlignedVectorBlock) == 64);

    std::cout << "✓ Address is strictly 64-byte cache-line aligned!\n";
    std::cout << "\n✓ Week 02 Drill 05 Passed Successfully!\n";
    return 0;
}
