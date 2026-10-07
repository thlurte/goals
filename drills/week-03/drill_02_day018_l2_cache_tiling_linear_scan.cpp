// ==============================================================================
// 🥋 Drill 02 (Week 03 / Day 018): CS:APP §6.4–6.5 — L2-Cache Tiling for Vector Scans
//
// 📖 READING SOURCES:
// - Bryant & O'Hallaron: Computer Systems (CS:APP 3rd Ed, §6.4–6.5: Cache-Friendly Tiling)
//
// 🎯 CORE LESSON:
// 1. Working Set Sizing:
//    When scanning N vectors with a batch of B queries, naive iteration thrashes L2 cache.
// 2. Cache Tiling:
//    Partitioning N vectors into tiles of size T (where T * D * sizeof(float) <= 256KB)
//    keeps the current block resident in L2 cache across all queries.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra drill_02_day018_l2_cache_tiling_linear_scan.cpp -o drill02 && ./drill02
// ==============================================================================

#include <iostream>
#include <vector>
#include <cassert>

// Compute ideal tile size T (number of vectors) fitting in max_bytes (e.g. 256KB L2 cache)
constexpr size_t compute_tile_size(size_t dim, size_t max_cache_bytes = 256 * 1024) {
    size_t vec_bytes = dim * sizeof(float);
    return max_cache_bytes / vec_bytes;
}

int main() {
    std::cout << "--- Week 03 Drill 02: L2 Cache Tiling Calculator ---\n\n";

    constexpr size_t D = 128; // 128 floats = 512 bytes per vector
    constexpr size_t tile_size = compute_tile_size(D); // 262,144 / 512 = 512 vectors

    std::cout << "Vector Dimension: " << D << " (512 bytes)\n";
    std::cout << "Optimal L2 Tile Size: " << tile_size << " vectors (256 KB)\n";

    assert(tile_size == 512);
    std::cout << "\n✓ Week 03 Drill 02 Passed Successfully!\n";
    return 0;
}
