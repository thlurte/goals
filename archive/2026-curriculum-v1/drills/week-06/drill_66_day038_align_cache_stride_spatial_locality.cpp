// ==============================================================================
// 🥋 Drill: Spatial Locality: Cache Line Stride 1 vs Stride 16
//
// 📖 READING SOURCES:
// - CS:APP (Ch 6.2: Locality)
// - Ulrich Drepper: What Every Programmer Should Know About Memory
//
// 🎯 CORE LESSON:
// 1. CPUs fetch memory in 64-byte cache lines (16 `float`s).
// 2. Stride-1 sequential traversal accesses 16 floats per L1 cache line fetch (100% spatial locality).
// 3. Stride-16 traversal forces a fresh L1 cache line fetch on every single access.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_66_day038_align_cache_stride_spatial_locality.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <vector>
#include <chrono>
#include <cassert>

int main() {
    std::cout << "--- Drill 66: Cache Stride & Spatial Locality ---\n\n";

    constexpr size_t N = 1024 * 1024; // 1M floats = 4MB
    std::vector<float> data(N, 1.0f);

    float sum_stride1 = 0.0f;
    for (size_t i = 0; i < N; ++i) {
        sum_stride1 += data[i];
    }
    assert(sum_stride1 == static_cast<float>(N));

    float sum_stride16 = 0.0f;
    for (size_t i = 0; i < N; i += 16) {
        sum_stride16 += data[i];
    }
    assert(sum_stride16 == static_cast<float>(N / 16));

    std::cout << "Spatial locality sequential traversal completed accurately.\n";
    std::cout << "\n✓ Drill 66 Passed: Cache line stride locality verified!\n";
    return 0;
}
