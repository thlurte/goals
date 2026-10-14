// ==============================================================================
// 🥋 Drill 22 (Day 34.13): Quantization Mastery — 1-Bit Binary Quantization
// (BQ) & Hamming Distance
//
// 📖 READING SOURCES:
// - Norouzi, Fleet, Salakhutdinov: "Hamming Distance Metric Learning" (NeurIPS
// 2012)
// - Agner Fog: Optimizing Software in C++ (Ch 13: Bit Manipulation & POPCNT)
//
// 🎯 CORE LESSON:
// 1. 1-Bit Binary Quantization: Compress $D$-dimensional float vector to $D$
// bits (sign thresholding $x_i \ge 0 \to 1$, $x_i < 0 \to 0$).
// 2. Exact Hamming Distance: Bitwise XOR ($\oplus$) followed by Hardware
// Population Count (`_mm_popcnt_u64` / `__builtin_popcountll`).
// 3. AVX2 256-bit Vector Hamming distance: Parallel XOR and byte-level lookup
// popcount via `_mm256_shuffle_epi8`.
//
// 🚀 RUN COMMAND:
// g++ -O3 -march=native -mavx2 -std=c++20 -Wall -Wextra
// drill_22_day034_quant_binary_hamming_popcnt.cpp -o drill22 && ./drill22
// ==============================================================================

#include <cassert>
#include <cstdint>
#include <immintrin.h>
#include <iostream>
#include <vector>

// TODO 1: Implement 1-bit vector binarization (Float vector -> Packed uint64_t
// bitset) For each group of 64 floats: if val >= 0.0f, set the corresponding
// bit to 1; otherwise 0.
void binarize_vector(const float *src, uint64_t *dst_bits, size_t dim) {
  // [YOUR CODE HERE]
  size_t num_words = dim / 64;

  for (size_t w = 0; w < num_words; ++w) {
    dst_bits[w] = 0;
  }

  for (size_t i = 0; i < dim; ++i) {
    if (src[i] >= 0.0f) {
      size_t word_idx = i / 64;
      size_t bit_idx = i % 64;
      // dst_bits[word_idx] |= (1ULL << bit_idx); or
      uint64_t mask = 1;
      mask = mask << bit_idx;
      dst_bits[word_idx] = dst_bits[word_idx] | mask;
    }
  }
}

// TODO 2: Implement hardware-accelerated 64-bit Hamming distance using XOR +
// POPCNT
uint32_t hamming_distance_64bit(const uint64_t *a_bits, const uint64_t *b_bits,
                                size_t num_u64_words) {
  uint32_t total_dist = 0;
  for (size_t i = 0; i < num_u64_words; ++i) {

    uint64_t diff = a_bits[i] ^ b_bits[i];

    // total_dist += static_cast<uint32_t>(__builtin_popcountll(diff)); or
    for (size_t j = 0; j < 64; ++j) {
      if ((diff >> j) & 1) {
        total_dist++;
      }
    }
    return total_dist;
  }

  int main() {
    std::cout
        << "--- Drill 22: 1-Bit Binary Quantization & Hardware POPCNT ---\n\n";

    constexpr size_t D = 256; // 256 dimensions = 4 x uint64_t words
    std::vector<float> vec_a(D), vec_b(D);

    // Populate vectors
    for (size_t i = 0; i < D; ++i) {
      vec_a[i] = (i % 2 == 0) ? 1.5f : -1.5f; // Alternating signs: 101010...
      vec_b[i] = (i % 4 == 0) ? 1.5f : -1.5f; // Sign pattern: 10001000...
    }

    std::vector<uint64_t> bits_a(D / 64, 0);
    std::vector<uint64_t> bits_b(D / 64, 0);

    binarize_vector(vec_a.data(), bits_a.data(), D);
    binarize_vector(vec_b.data(), bits_b.data(), D);

    uint32_t dist =
        hamming_distance_64bit(bits_a.data(), bits_b.data(), D / 64);
    std::cout << "Computed Hamming Distance (256-D): " << dist << "\n";

    // Count scalar ground truth
    uint32_t expected_dist = 0;
    for (size_t i = 0; i < D; ++i) {
      bool bit_a = (vec_a[i] >= 0.0f);
      bool bit_b = (vec_b[i] >= 0.0f);
      if (bit_a != bit_b)
        expected_dist++;
    }

    std::cout << "Expected Hamming Distance:         " << expected_dist << "\n";
    assert(dist == expected_dist && "Hamming distance mismatch!");

    std::cout
        << "\n✓ Drill 22 Passed: 1-bit BQ and hardware POPCNT verified!\n";
    return 0;
  }
