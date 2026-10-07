// ==============================================================================
// 🥋 Drill 05 (Week 01 / Day 003): `secan` — Baseline Scalar L2 Squared Distance
//
// 📖 READING SOURCES:
// - `secan` Vector Search Baseline Architecture
//
// 🎯 CORE LESSON:
// 1. Squared Euclidean Distance (L2):
//    ||u - v||_2^2 = sum_{i=0}^{D-1} (u[i] - v[i])^2
// 2. Establishing the unoptimized baseline before applying SIMD/AVX2.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra drill_05_day003_scalar_l2_squared.cpp -o drill05 && ./drill05
// ==============================================================================

#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

// TODO 1: Implement baseline scalar L2 squared distance
float l2_squared_scalar(const float* a, const float* b, size_t dim) {
    // [YOUR CODE HERE]
    return 0.0f;
}

int main() {
    std::cout << "--- Week 01 Drill 05: Secan Baseline Scalar L2 Squared Distance ---\n\n";

    constexpr size_t D = 128;
    std::vector<float> u(D, 1.0f);
    std::vector<float> v(D, 4.0f);

    // Each dim diff = (1 - 4)^2 = 9. Total = 128 * 9 = 1152.0
    float dist = l2_squared_scalar(u.data(), v.data(), D);
    std::cout << "Calculated L2 Squared: " << dist << " (Expected: 1152.0)\n";

    assert(dist == 1152.0f);
    std::cout << "\n✓ Week 01 Drill 05 Passed Successfully!\n";
    return 0;
}
