// ==============================================================================
// 🥋 Drill 07 (Week 04 / Day 028): `cennan` Core — Root Mean Square Normalization (RMSNorm)
//
// 📖 READING SOURCES:
// - Zhang & Sennrich: "Root Mean Square Layer Normalization" (NeurIPS 2019)
//
// 🎯 CORE LESSON:
// 1. RMSNorm Formula:
//    y_i = (x_i / RMS(x)) * gamma_i,  where RMS(x) = sqrt((1 / D) * sum(x_i^2) + eps)
// 2. Eliminates mean-centering, cutting compute time by 30% compared to standard LayerNorm.
//
// 🚀 RUN COMMAND:
// g++ -O3 -march=native -mavx2 -mfma -std=c++20 -Wall -Wextra drill_07_day028_cennan_avx2_rmsnorm.cpp -o drill07 && ./drill07
// ==============================================================================

#include <iostream>
#include <vector>
#include <span>
#include <cmath>
#include <cassert>

void rms_norm(
    std::span<const float> x,
    std::span<const float> gamma,
    std::span<float> out,
    float eps = 1e-5f
) {
    size_t dim = x.size();
    float sum_sq{0.0f};
    for (size_t i = 0; i < dim; ++i) {
        sum_sq += x[i] * x[i];
    }

    float rms = std::sqrt(sum_sq / static_cast<float>(dim) + eps);
    float inv_rms = 1.0f / rms;

    for (size_t i = 0; i < dim; ++i) {
        out[i] = (x[i] * inv_rms) * gamma[i];
    }
}

int main() {
    std::cout << "--- Week 04 Drill 07: Cennan RMSNorm Layer ---\n\n";

    constexpr size_t D = 4;
    std::vector<float> x = {2.0f, 2.0f, 2.0f, 2.0f}; // RMS = sqrt(16 / 4) = 2.0
    std::vector<float> gamma = {1.0f, 1.0f, 1.0f, 1.0f};
    std::vector<float> out(D);

    rms_norm(x, gamma, out);
    // out[i] approx (2.0 / 2.0) * 1.0 = 1.0

    for (size_t i = 0; i < D; ++i) {
        assert(std::abs(out[i] - 1.0f) < 1e-4f);
    }

    std::cout << "✓ RMSNorm output matches expected normalized values!\n";
    std::cout << "\n✓ Week 04 Drill 07 Passed Successfully!\n";
    return 0;
}
