// ==============================================================================
// 🥋 Drill 21 (Day 34.12): Quantization Mastery — AVX2 FastScan 4-bit LUT (`_mm256_shuffle_epi8`)
//
// 📖 READING SOURCES:
// - Andre, Kermarrec, Le Scouarnec: "Accelerating Product Quantization with AVX" (SIMD-PQ)
// - Faiss / FastScan Architecture: `pshufb` register-resident 16-entry Look-Up Tables
//
// 🎯 CORE LESSON:
// 1. Look-Up Table (LUT) in registers: Store 16 precomputed centroid distance floats/bytes in a 128-bit register.
// 2. `_mm256_shuffle_epi8` (`VPSHUFB`): Evaluates 32 4-bit quantized lookups simultaneously in 1 CPU cycle!
// 3. Low and High Nibble masking: `_mm256_and_si256` with mask `0x0F` and bit-shift `_mm256_srli_epi16(codes, 4)`.
//
// 🚀 RUN COMMAND:
// g++ -O3 -march=native -mavx2 -std=c++20 -Wall -Wextra drill_21_day034_quant_fastscan_pshufb_lut.cpp -o drill21 && ./drill21
// ==============================================================================

#include <iostream>
#include <vector>
#include <immintrin.h>
#include <cstdint>
#include <cassert>

// TODO 1: Implement AVX2 4-Bit FastScan LUT lookup using _mm256_shuffle_epi8
// 1. Load 32 packed bytes (each byte contains two 4-bit codes: low nibble & high nibble)
// 2. Extract low nibbles using mask 0x0F: low_codes = _mm256_and_si256(packed_bytes, mask_0f)
// 3. Extract high nibbles: high_codes = _mm256_and_si256(_mm256_srli_epi16(packed_bytes, 4), mask_0f)
// 4. Perform parallel register lookups:
//    dist_low = _mm256_shuffle_epi8(lut_table, low_codes)
//    dist_high = _mm256_shuffle_epi8(lut_table, high_codes)
// 5. Accumulate distances horizontally using saturated addition or SAD
void fastscan_4bit_lookup_avx2(
    const uint8_t* packed_codes_32bytes,
    __m256i lut_table,
    uint8_t* out_distances_64bytes
) {
    // [YOUR CODE HERE]
    (void)packed_codes_32bytes;
    (void)lut_table;
    (void)out_distances_64bytes;
}

int main() {
    std::cout << "--- Drill 21: AVX2 FastScan 4-Bit LUT via _mm256_shuffle_epi8 ---\n\n";

    // 1. Build a 16-entry lookup table (e.g. entry i = i * 10)
    alignas(32) uint8_t lut[32];
    for (int i = 0; i < 16; ++i) {
        lut[i] = static_cast<uint8_t>(i * 10);
        lut[i + 16] = static_cast<uint8_t>(i * 10); // Duplicate across both 128-bit lanes
    }
    __m256i v_lut = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(lut));

    // 2. Create 32 packed bytes where each byte has low nibble = 3 (dist 30), high nibble = 7 (dist 70)
    // Hex: 0x73
    alignas(32) uint8_t packed_input[32];
    for (int i = 0; i < 32; ++i) {
        packed_input[i] = 0x73;
    }

    alignas(32) uint8_t output_dists[64];
    fastscan_4bit_lookup_avx2(packed_input, v_lut, output_dists);

    // Verify
    for (int i = 0; i < 32; ++i) {
        assert(output_dists[i] == 30 && "Low nibble LUT mismatch!");
        assert(output_dists[i + 32] == 70 && "High nibble LUT mismatch!");
    }

    std::cout << "✓ 64 4-bit vector distances evaluated in single-cycle SIMD shuffles!\n";
    std::cout << "\n✓ Drill 21 Passed: FastScan pshufb LUT verified!\n";
    return 0;
}
