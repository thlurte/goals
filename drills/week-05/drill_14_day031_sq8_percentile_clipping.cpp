// ==============================================================================
// 🥋 Drill 14 (Week 05 / Day 031): `secan` — ScalarQuantizer Percentile Clipping
//
// 📖 READING SOURCES:
// - `secan/src/quantization/scalar_quantizer.cpp`
//
// 🎯 CORE LESSON:
// 1. Extreme Outlier Dimensions:
//    In high-dimensional embeddings, a single outlier value (e.g. +50.0 when 99% are in [-2, 2])
//    drastically increases quantization step size: step = (max - min) / 255.
//    This collapses precision across 99% of normal vector coordinates.
// 2. Percentile Clipping (0.05th / 99.95th):
//    Clamping data to the 0.05th and 99.95th percentiles rejects outlier spikes and preserves resolution.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra drill_14_day031_sq8_percentile_clipping.cpp -o drill14 && ./drill14
// ==============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

struct SQ8Params {
    float x_min{0.0f};
    float x_max{0.0f};
    float step{0.0f};
};

SQ8Params compute_sq8_params_clipped(const std::vector<float>& data, double clip_percentile = 0.05) {
    std::vector<float> sorted = data;
    std::sort(sorted.begin(), sorted.end());

    size_t n = sorted.size();
    size_t low_idx = static_cast<size_t>(std::floor((clip_percentile / 100.0) * static_cast<double>(n)));
    size_t high_idx = static_cast<size_t>(std::ceil(((100.0 - clip_percentile) / 100.0) * static_cast<double>(n))) - 1;

    float x_min = sorted[low_idx];
    float x_max = sorted[high_idx];
    float step = (x_max - x_min) / 255.0f;

    return {x_min, x_max, step};
}

int main() {
    std::cout << "--- Week 05 Drill 14: SQ8 Percentile Outlier Clipping ---\n\n";

    // 1000 normal values in [-2.0, 2.0] + 1 extreme outlier spike at 100.0f
    std::vector<float> data;
    for (int i = -500; i < 500; ++i) {
        data.push_back(static_cast<float>(i) * 0.004f); // [-2.0, +2.0]
    }
    data.push_back(100.0f); // Outlier spike!

    auto params = compute_sq8_params_clipped(data, 0.1); // 0.1th percentile clip

    std::cout << "Clipped x_min: " << params.x_min << "\n";
    std::cout << "Clipped x_max: " << params.x_max << " (Rejected 100.0 outlier!)\n";
    std::cout << "Quantization step: " << params.step << "\n";

    assert(params.x_max < 3.0f && "Outlier 100.0 must be successfully clipped!");
    assert(params.step > 0.015f && params.step < 0.020f);

    std::cout << "\n✓ Week 05 Drill 14 Passed: Outlier percentile clipping verified!\n";
    return 0;
}
