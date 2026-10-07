// ==============================================================================
// 🥋 Drill 40.1: Asymmetric Distance Computation (ADC) & Loop Unrolling
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra day040_drill_01_adc_unroll.cpp -o drill40 && ./drill40
//
// CONTEXT:
// In Product Quantization Asymmetric Distance Computation (ADC), we precompute
// a query-to-centroid lookup table `float lut[M][256]`.
// Distance computation becomes M table lookups per database vector!
// Unrolling 4 vectors at once breaks CPU dependency chains and saturates memory ports.
//
// C++ CONCEPTS TO PRACTICE:
// 1. 2D array lookups: `lut[m][code[m]]`.
// 2. 4-way loop unrolling across vectors.
// 3. Remainder tail loops.
// ==============================================================================

#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <cassert>

constexpr size_t M = 8;
constexpr size_t K_CENTROIDS = 256;
constexpr size_t N_VECTORS = 200000;

int main() {
    std::cout << "--- Drill 40.1: 4-Way Unrolled Asymmetric Distance (ADC) ---\n\n";

    float lut[M][K_CENTROIDS];
    std::mt19937 rng(42);
    std::uniform_real_distribution<float> dist(0.0f, 10.0f);
    for (size_t m = 0; m < M; ++m) {
        for (size_t k = 0; k < K_CENTROIDS; ++k) {
            lut[m][k] = dist(rng);
        }
    }

    std::vector<uint8_t> db_codes(N_VECTORS * M);
    for (uint8_t& b : db_codes) b = static_cast<uint8_t>(rng() % 256);

    std::vector<float> distances(N_VECTORS);

    auto t0 = std::chrono::high_resolution_clock::now();

    // TODO 1: Implement 4-way unrolled ADC distance calculation
    // Loop `i + 4 <= N_VECTORS` in steps of 4:
    // - Extract 4 vector code pointers: c0, c1, c2, c3
    // - Accumulate distances across m in [0, M): d0 += lut[m][c0[m]], etc.
    // - Store d0..d3 into distances[i..i+3]
    size_t i = 0;
    for (; i + 4 <= N_VECTORS; i += 4) {
        // [YOUR CODE HERE]
    }

    // TODO 2: Implement remainder tail loop for any remaining vectors
    for (; i < N_VECTORS; ++i) {
        // [YOUR CODE HERE]
    }

    auto t1 = std::chrono::high_resolution_clock::now();
    double ms = std::chrono::duration<double, std::milli>(t1 - t0).count();
    double qps = (static_cast<double>(N_VECTORS) / (ms / 1000.0));

    std::cout << "🚀 ADC Throughput: " << (qps / 1e6) << " Million Vectors/sec (" << ms << " ms for 200K vectors)\n";
    assert(distances[0] > 0.0f && "Distances should be computed!");
    std::cout << "\n✓ Drill Passed: 4-way unrolled ADC scan verified!\n";
    return 0;
}
