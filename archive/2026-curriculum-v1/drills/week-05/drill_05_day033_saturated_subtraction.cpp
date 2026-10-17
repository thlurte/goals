// ==============================================================================
// 🥋 Drill 05 (Day 33.2): Agner Fog Ch 12 — Saturated Arithmetic & L1 Distance
// SAD
//
// 📖 READING SOURCES:
// - Agner Fog: Optimizing Software in C++ (Ch 12: Vector Operations & Integer
// SIMD)
//
// 🎯 CORE LESSON:
// 1. Standard unsigned subtraction wraps around 256: (0 - 5 = 251).
// 2. Saturated unsigned subtraction (_mm256_subs_epu8) clamps underflow to 0.
// 3. Absolute byte difference without branches: |a - b| = (a -_sat b) | (b
// -_sat a).
// 4. Sum of Absolute Differences: `_mm256_sad_epu8` horizontally sums 8 byte
// diffs in 1 cycle.
//
// 🚀 RUN COMMAND:
// g++ -O3 -march=native -mavx2 -std=c++20 -Wall -Wextra
// drill_05_day033_saturated_subtraction.cpp -o drill05 && ./drill05
// ==============================================================================

#include <cassert>
#include <cmath>
#include <cstdint>
#include <immintrin.h>
#include <iostream>
#include <vector>

// TODO 1: Implement scalar L1 distance
uint32_t l1_distance_scalar(const uint8_t *a, const uint8_t *b, size_t dim) {
  uint32_t total{0};
  for (size_t i = 0; i < dim; ++i) {
    total += static_cast<uint32_t>(
        std::abs(static_cast<int>(a[i]) - static_cast<int>(b[i])));
  }
  return total;
}

#if defined(__AVX2__)
uint32_t l1_distance_avx2(const uint8_t *a, const uint8_t *b, size_t dim) {
  __m256i total_acc = _mm256_setzero_si256();
  __m256i zero = _mm256_setzero_si256();

  size_t i{0};
  for (; i + 32 <= dim; i += 32) {
    __m256i va = _mm256_loadu_si256(reinterpret_cast<const __m256i *>(a + i));
    __m256i vb = _mm256_loadu_si256(reinterpret_cast<const __m256i *>(b + i));

    __m256i diff_ab = _mm256_subs_epu8(va, vb);
    __m256i diff_ba = _mm256_subs_epu8(vb, va);

    __m256i abs_diff = _mm256_or_si256(diff_ab, diff_ba);

    __m256i sad = _mm256_sad_epu8(abs_diff, zero);
    total_acc = _mm256_add_epi64(total_acc, sad);
  }

  uint64_t buf[4];
  _mm256_storeu_si256(reinterpret_cast<__m256i *>(buf), total_acc);
  uint32_t total = static_cast<uint32_t>(buf[0] + buf[1] + buf[2] + buf[3]);
  // 6. Scalar cleanup tail loop for any remaining dimensions
  for (; i < dim; ++i) {
    total += static_cast<uint32_t>(
        std::abs(static_cast<int>(a[i]) - static_cast<int>(b[i])));
  }
  return total;
}
#endif

int main() {
  std::cout
      << "--- Drill 05: Agner Fog Ch 12 Saturated Subtraction & SAD ---\n\n";

  constexpr size_t D = 128;
  std::vector<uint8_t> x(D), y(D);
  for (size_t i = 0; i < D; ++i) {
    x[i] = static_cast<uint8_t>(i * 3 % 256);
    y[i] = static_cast<uint8_t>((i * 7 + 13) % 256);
  }

  uint32_t ground_truth = l1_distance_scalar(x.data(), y.data(), D);
  uint32_t avx2_result = l1_distance_avx2(x.data(), y.data(), D);

  std::cout << "Scalar L1 Distance: " << ground_truth << "\n";
  std::cout << "AVX2   L1 Distance: " << avx2_result << "\n";

  assert(ground_truth == avx2_result &&
         "AVX2 saturated subtraction result mismatch!");
  std::cout << "✓ Drill 05 Passed: Saturated subtraction and SAD verified!\n";
  return 0;
}
