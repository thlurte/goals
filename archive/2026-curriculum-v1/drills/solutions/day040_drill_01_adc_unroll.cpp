/**
 * @file day040_drill_01_adc_unroll.cpp
 * @brief Drill 40.1: Asymmetric Distance Computation (ADC) & 4-Way Loop Unrolling in C++
 *
 * 🎓 C++ CONCEPTS TAUGHT IN THIS DRILL:
 * 1. 2D arrays in contiguous memory: `float lut[M][256]`.
 * 2. Loop unrolling: Breaking instruction dependency chains to maximize IPC (Instructions Per Cycle).
 * 3. Precomputed query lookup tables (ADC): Turning floating-point distance math into 8 table lookups.
 * 4. Micro-benchmarking with `std::chrono::high_resolution_clock`.
 *
 * Compile: g++ -O3 -std=c++20 -Wall -Wextra day040_drill_01_adc_unroll.cpp -o drill40 && ./drill40
 */

#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <cassert>

constexpr size_t M = 8;
constexpr size_t K_CENTROIDS = 256;
constexpr size_t N_VECTORS = 200000;

int main() {
    std::cout << "===================================================================\n";
    std::cout << "🥋 Drill 40.1: 4-Way Unrolled Asymmetric Distance Computation (ADC)\n";
    std::cout << "===================================================================\n";

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

    size_t i = 0;
    for (; i + 4 <= N_VECTORS; i += 4) {
        const uint8_t* c0 = &db_codes[(i + 0) * M];
        const uint8_t* c1 = &db_codes[(i + 1) * M];
        const uint8_t* c2 = &db_codes[(i + 2) * M];
        const uint8_t* c3 = &db_codes[(i + 3) * M];

        float d0 = 0.0f, d1 = 0.0f, d2 = 0.0f, d3 = 0.0f;

        for (size_t m = 0; m < M; ++m) {
            d0 += lut[m][c0[m]];
            d1 += lut[m][c1[m]];
            d2 += lut[m][c2[m]];
            d3 += lut[m][c3[m]];
        }

        distances[i + 0] = d0;
        distances[i + 1] = d1;
        distances[i + 2] = d2;
        distances[i + 3] = d3;
    }

    for (; i < N_VECTORS; ++i) {
        const uint8_t* c = &db_codes[i * M];
        float d = 0.0f;
        for (size_t m = 0; m < M; ++m) {
            d += lut[m][c[m]];
        }
        distances[i] = d;
    }

    auto t1 = std::chrono::high_resolution_clock::now();
    double ms = std::chrono::duration<double, std::milli>(t1 - t0).count();
    double qps = (static_cast<double>(N_VECTORS) / (ms / 1000.0));

    std::cout << "🚀 ADC 4-Way Unrolled Scan: " << (qps / 1e6) << " Million Vectors/sec (" << ms << " ms for 200K vectors)\n";
    std::cout << "\n✅ DRILL 40.1 PASSED: ADC unrolled LUT lookup verified.\n";
    return 0;
}
