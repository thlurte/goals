// ==============================================================================
// 🥋 Drill: 1-Bit Binary Quantization: Sign Packing into uint64_t
//
// 📖 READING SOURCES:
// - Jegou et al.: Binary Quantization for Vector Search
// - Hennessy & Patterson: Appendix B
//
// 🎯 CORE LESSON:
// 1. 1-bit BQ converts each dimension to 1 bit: 1 if $x_d > 0.0$, 0 otherwise.
// 2. 64 dimensions pack into a single 64-bit integer (`uint64_t`).
// 3. Hamming distance between two packed vectors is computed with XOR and
// `__builtin_popcountll`.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra
// drill_71_day038_align_binary_quant_bit_packing.cpp -o drill && ./drill
// ==============================================================================

#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

uint64_t pack_bq_64(const float *vec) {
  uint64_t word = 0;
  for (int i = 0; i < 64; ++i) {
    if (vec[i] > 0.0f) {
      word |= (1ULL << i);
    }
  }
  return word;
}

int main() {
  std::cout << "--- Drill 71: 1-Bit Binary Quantization Packing ---\n\n";

  float vec1[64] = {0};
  float vec2[64] = {0};

  // vec1: All positive
  for (int i = 0; i < 64; ++i)
    vec1[i] = 1.0f;
  // vec2: Even positive, odd negative
  for (int i = 0; i < 64; ++i)
    vec2[i] = (i % 2 == 0) ? 1.0f : -1.0f;

  uint64_t code1 = pack_bq_64(vec1);
  uint64_t code2 = pack_bq_64(vec2);

  assert(code1 == 0xFFFFFFFFFFFFFFFFULL);
  assert(code2 == 0x5555555555555555ULL);

  int hamming = __builtin_popcountll(code1 ^ code2);
  assert(hamming == 32);

  std::cout
      << "\n✓ Drill 71 Passed: 1-Bit sign packing into uint64_t verified!\n";
  return 0;
}
