// ==============================================================================
// 🥋 Drill: Vector Dimension Stride/Pitch Padding for Aligned Matrix Rows
//
// 📖 READING SOURCES:
// - Agner Fog: Optimizing Software in C++ (Ch 8.1: Padded Arrays)
// - CUDA / SIMD Best Practices: Row Pitch Alignment
//
// 🎯 CORE LESSON:
// 1. If vector dimension $D$ is not a multiple of SIMD width, row boundaries become unaligned.
// 2. Adding pitch padding rounds row stride up to a multiple of 8 (AVX2) or 16 (AVX-512) floats.
// 3. Eliminates boundary peeling loops and ensures every row starts on an aligned address.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_30_day038_align_vector_dimension_pitch_padding.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <cstddef>
#include <cassert>

inline size_t compute_pitch(size_t dim, size_t align_elements) {
    size_t rem = dim % align_elements;
    return (rem == 0) ? dim : (dim + (align_elements - rem));
}

int main() {
    std::cout << "--- Drill 30: Vector Stride/Pitch Padding ---\n\n";

    // AVX2 requires multiples of 8 floats (32 bytes)
    assert(compute_pitch(128, 8) == 128); // Already aligned
    assert(compute_pitch(130, 8) == 136); // Padded with 6 floats
    assert(compute_pitch(135, 8) == 136); // Padded with 1 float

    // AVX-512 / 64-byte cache line requires multiples of 16 floats
    assert(compute_pitch(130, 16) == 144);

    std::cout << "Pitch calculated: dim 130 padded to " << compute_pitch(130, 8) << " floats for AVX2.\n";
    std::cout << "\n✓ Drill 30 Passed: Pitch padding calculation verified!\n";
    return 0;
}
