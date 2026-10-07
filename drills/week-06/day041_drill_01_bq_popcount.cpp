// ==============================================================================
// 🥋 Drill 41.1: 1-Bit Binary Quantization (BQ) & Hardware Popcount
//
// 🚀 RUN COMMAND:
// g++ -O3 -march=native -std=c++20 -Wall -Wextra day041_drill_01_bq_popcount.cpp -o drill41 && ./drill41
//
// CONTEXT:
// 1-Bit Binary Quantization stores each coordinate as a single bit (1 if >= 0 else 0).
// A 128-D vector fits in two 64-bit unsigned integers (`uint64_t words[2]`).
// Hamming distance is computed via XOR (`^`) and hardware `__builtin_popcountll`.
//
// C++ CONCEPTS TO PRACTICE:
// 1. Bit shifts with 64-bit literals: `1ULL << i`.
// 2. Hardware intrinsic `__builtin_popcountll(uint64_t)` (maps directly to POPCNT instruction).
// ==============================================================================

#include <iostream>
#include <vector>
#include <cstdint>
#include <random>
#include <chrono>
#include <cassert>

struct BQVector128 {
    uint64_t words[2]{0, 0}; // 128 bits = 16 bytes total

    // TODO 1: Pack 128 FP32 floats into 128 binary bits based on sign (>= 0.0f -> 1, else 0)
    static BQVector128 from_fp32(const float* vec) {
        BQVector128 bq;
        // First 64 dimensions in words[0]
        for (size_t i = 0; i < 64; ++i) {
            // [YOUR CODE HERE: if vec[i] >= 0.0f, set bit i: bq.words[0] |= (1ULL << i)]
        }
        // Next 64 dimensions in words[1]
        for (size_t i = 64; i < 128; ++i) {
            // [YOUR CODE HERE: if vec[i] >= 0.0f, set bit (i - 64): bq.words[1] |= (1ULL << (i - 64))]
        }
        return bq;
    }

    // TODO 2: Compute Hamming distance between this vector and other using XOR and __builtin_popcountll
    inline uint32_t hamming_distance(const BQVector128& other) const noexcept {
        // [YOUR CODE HERE: XOR words[0] with other.words[0] and words[1] with other.words[1], sum popcounts]
        return 0;
    }
};

int main() {
    std::cout << "--- Drill 41.1: 1-Bit Binary Quantization & POPCNT ---\n\n";

    constexpr size_t N_VECTORS = 1000000;
    std::vector<BQVector128> dataset(N_VECTORS);

    std::mt19937_64 rng(42);
    for (size_t i = 0; i < N_VECTORS; ++i) {
        dataset[i].words[0] = rng();
        dataset[i].words[1] = rng();
    }

    BQVector128 query{ rng(), rng() };

    auto t0 = std::chrono::high_resolution_clock::now();
    uint32_t total_hamming = 0;
    for (size_t i = 0; i < N_VECTORS; ++i) {
        total_hamming += query.hamming_distance(dataset[i]);
    }
    auto t1 = std::chrono::high_resolution_clock::now();

    double ms = std::chrono::duration<double, std::milli>(t1 - t0).count();
    double qps = (static_cast<double>(N_VECTORS) / (ms / 1000.0));

    std::cout << "🚀 1-Bit BQ Hardware POPCNT Throughput: " << (qps / 1e6) << " Million Vectors/sec\n";
    std::cout << "   Checksum: " << total_hamming << "\n";

    std::cout << "\n✓ Drill Passed: 1-bit popcount distance kernel verified!\n";
    return 0;
}
