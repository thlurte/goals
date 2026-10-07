// ==============================================================================
// 🥋 Drill 07 (Day 33.4): Jégou PQ §3.1–3.3 — Asymmetric SQ8 Distance Kernel
// (ADC)
//
// 📖 READING SOURCES:
// - Jégou, Douze, Schmid: "Product Quantization for Nearest Neighbor Search"
// (IEEE TPAMI)
//
// 🎯 CORE LESSON:
// 1. Asymmetric Distance Computation (ADC):
//    Keep query unquantized in FP32; pre-scale query q'[i] = (q[i] - x_min) /
//    step.
// 2. Direct distance computation:
//    ||q - x_hat||^2 = sum (q'[i] - code[i])^2 * step^2.
// 3. Widening unsigned uint8 codes to FP32 registers in AVX2:
//    `_mm256_cvtepu8_epi32` + `_mm256_cvtepi32_ps`.
//
// 🚀 RUN COMMAND:
// g++ -O3 -march=native -mavx2 -mfma -std=c++20 -Wall -Wextra
// drill_07_day033_asymmetric_sq8_l2.cpp -o drill07 && ./drill07
// ==============================================================================

#include <cassert>
#include <cmath>
#include <cstdint>
#include <emmintrin.h>
#include <immintrin.h>
#include <iostream>
#include <vector>

// TODO 1: Implement AVX2 Asymmetric L2 SQ8 Distance Kernel
// 1. Initialize __m256 accumulator to zero.
// 2. Step in chunks of 8 (i + 8 <= dim):
//    - Load 8 floats from query_scaled: _mm256_loadu_ps
//    - Load 8 bytes from base_sq8: _mm_loadu_si64
//    - Widen 8 bytes to 8 x int32: _mm256_cvtepu8_epi32
//    - Convert 8 x int32 to 8 x float: _mm256_cvtepi32_ps
//    - Subtract (vq - vb) and accumulate diff^2 via _mm256_fmadd_ps
// 3. Perform horizontal reduction across 8 floats.
// 4. Scalar tail cleanup for remaining dims.
// 5. Return total * step_sq.
float asymmetric_l2_sq8_avx2(const float *query_scaled, const uint8_t *base_sq8,
                             size_t dim, float step_sq) {
  // [YOUR CODE HERE]
  __m256 acc = _mm256_setzero_ps();

  size_t i{0};
  for (; i + 8 <= dim; i += 8) {
    __m256 vq = _mm256_loadu_ps(query_scaled + i);
    __m128i vb8 = _mm_loadu_si64(base_sq8 + i);

    __m256i vi32 = _mm256_cvtepu8_epi32(vb8);
    __m256 vb = _mm256_cvtepi32_ps(vi32);

    __m256 diff = _mm256_sub_ps(vq, vb);
    acc = _mm256_fmadd_ps(diff, diff, acc);
  }

  alignas(32) float buf[8];
  _mm256_store_ps(buf, acc);
  float total =
      buf[0] + buf[1] + buf[2] + buf[3] + buf[4] + buf[5] + buf[6] + buf[7];

  for (; i < dim; ++i) {
    float diff = query_scaled[i] - static_cast<float>(base_sq8[i]);
    total += diff * diff;
  }
  return total * step_sq;
}

int main() {
  std::cout
      << "--- Drill 07: Jégou PQ Asymmetric SQ8 Distance Kernel (ADC) ---\n\n";

  constexpr size_t D = 128;
  float step = 0.05f;
  std::vector<float> q_scaled(D, 10.0f);
  std::vector<uint8_t> base(D, 8);

  float dist =
      asymmetric_l2_sq8_avx2(q_scaled.data(), base.data(), D, step * step);
  std::cout << "Computed ADC Distance: " << dist << " (Expected: 1.28)\n";

  assert(std::abs(dist - 1.28f) < 1e-4f);
  std::cout << "✓ Drill 07 Passed: Asymmetric distance kernel verified!\n";
  return 0;
}
