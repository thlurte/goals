// ==============================================================================
// 🥋 Drill: SIMD Loop Alignment Peeling: Head, Aligned Body, and Tail
//
// 📖 READING SOURCES:
// - Fog: Optimizing Subroutines in Assembly Language (Loop Alignment Peeling)
// - Intel Optimization Manual: Vector Alignment
//
// 🎯 CORE LESSON:
// 1. When an array pointer is not 32-byte aligned, peel initial scalar elements until aligned.
// 2. Execute fast aligned SIMD instructions (`_mm256_load_ps`) across the aligned main body.
// 3. Peel remaining tail elements with scalar operations.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_70_day038_align_simd_unaligned_loop_peeling.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <immintrin.h>
#include <cstdint>
#include <cassert>

float compute_sum_peeled(const float* ptr, size_t n) {
    float sum = 0.0f;
    size_t i = 0;

    // 1. Head Peeling: Advance until ptr + i is 32-byte aligned
    while (i < n && (reinterpret_cast<uintptr_t>(ptr + i) % 32 != 0)) {
        sum += ptr[i];
        i++;
    }

    // 2. Aligned SIMD Body
    __m256 v_acc = _mm256_setzero_ps();
    while (i + 8 <= n) {
        __m256 v = _mm256_load_ps(ptr + i); // Aligned load!
        v_acc = _mm256_add_ps(v_acc, v);
        i += 8;
    }

    alignas(32) float acc_buf[8];
    _mm256_store_ps(acc_buf, v_acc);
    for (int k = 0; k < 8; ++k) sum += acc_buf[k];

    // 3. Tail Peeling: Process remaining elements
    while (i < n) {
        sum += ptr[i];
        i++;
    }

    return sum;
}

int main() {
    std::cout << "--- Drill 70: SIMD Alignment Loop Peeling ---\n\n";

    alignas(32) float buffer[33];
    for (size_t i = 0; i < 33; ++i) buffer[i] = 1.0f;

    // Start at unaligned offset + 1
    float result = compute_sum_peeled(&buffer[1], 32);
    assert(result == 32.0f);

    std::cout << "\n✓ Drill 70 Passed: Loop peeling with aligned SIMD load verified!\n";
    return 0;
}
