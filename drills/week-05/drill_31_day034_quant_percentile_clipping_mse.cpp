// ==============================================================================
// 🥋 Drill 31 (Day 34.22): Quantization Mastery — Outlier Percentile Clipping & MSE Optimization
//
// 📖 READING SOURCES:
// - Dettmers et al.: "LLM.int8(): 8-bit Matrix Multiplication for Transformers at Scale" (NeurIPS 2022)
// - Banner et al.: "Post-Training 4-bit Quantization of Convolutional Networks for Rapid-Deployment" (NeurIPS 2019)
//
// 🎯 CORE LESSON:
// 1. The Outlier Hazard: Real neural embeddings have heavy-tailed coordinate distributions.
//    A single outlier (e.g. +50.0 when 99.9% of values are in [-2, +2]) ruins 8-bit resolution for the entire vector.
// 2. Percentile Clipping Calibration:
//    - Sort sample values.
//    - Set $x_{\min} = \text{percentile}(0.05\%)$, $x_{\max} = \text{percentile}(99.95\%)$.
// 3. Clamping:
//    - `std::clamp(val, min_val, max_val)` before quantizing eliminates outlier damage and drops reconstruction MSE.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra drill_31_day034_quant_percentile_clipping_mse.cpp -o drill31 && ./drill31
// ==============================================================================

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>
#include <algorithm>
#include <cassert>
#include <random>

struct PercentileClippedQuantizer {
    float min_val{-1.0f};
    float max_val{1.0f};
    float step{0.0f};
    float inv_step{0.0f};

    // TODO 1: Implement Percentile Calibration
    // 1. Copy sample data into a local vector and sort in ascending order
    // 2. lower_idx = floor((sample.size() - 1) * lower_pct)
    // 3. upper_idx = floor((sample.size() - 1) * upper_pct)
    // 4. Set min_val = sample[lower_idx], max_val = sample[upper_idx]
    // 5. step = (max_val - min_val) / 255.0f, inv_step = 1.0f / step
    void train_percentiles(
        const float* data,
        size_t n,
        float lower_pct = 0.0005f, // 0.05th percentile
        float upper_pct = 0.9995f  // 99.95th percentile
    ) {
        // [YOUR CODE HERE]
        (void)data;
        (void)n;
        (void)lower_pct;
        (void)upper_pct;
    }

    // TODO 2: Encode with std::clamp
    uint8_t encode(float x) const {
        // [YOUR CODE HERE]
        (void)x;
        return 0;
    }

    // TODO 3: Decode to float
    float decode(uint8_t q) const {
        // [YOUR CODE HERE]
        (void)q;
        return 0.0f;
    }
};

int main() {
    std::cout << "--- Drill 31: Outlier Percentile Clipping & Reconstruction MSE ---\n\n";

    constexpr size_t N = 10000;
    std::vector<float> data(N);

    // Generate standard normal distribution N(0, 1) with 5 extreme outliers (+50.0f)
    std::mt19937 gen(42);
    std::normal_distribution<float> dist(0.0f, 1.0f);
    for (size_t i = 0; i < N; ++i) {
        data[i] = dist(gen);
    }
    // Inject extreme outliers
    data[10] = 50.0f;
    data[100] = -50.0f;
    data[500] = 45.0f;

    // 1. Train with Percentile Clipping (0.05th / 99.95th)
    PercentileClippedQuantizer quant;
    quant.train_percentiles(data.data(), N);

    std::cout << "Calibrated Min: " << quant.min_val << " (Near -3.5)\n";
    std::cout << "Calibrated Max: " << quant.max_val << " (Near +3.5)\n";
    std::cout << "Quantization Step: " << quant.step << "\n";

    // Min and max should ignore the -50.0 and +50.0 outliers!
    assert(quant.min_val > -10.0f && "Percentile clipping must ignore extreme negative outliers!");
    assert(quant.max_val < 10.0f && "Percentile clipping must ignore extreme positive outliers!");

    // 2. Measure Reconstruction MSE on inlier data
    float total_sq_err = 0.0f;
    size_t inlier_count = 0;

    for (size_t i = 0; i < N; ++i) {
        if (std::abs(data[i]) < 10.0f) { // Evaluate inliers
            uint8_t q = quant.encode(data[i]);
            float recon = quant.decode(q);
            float err = data[i] - recon;
            total_sq_err += err * err;
            inlier_count++;
        }
    }

    float mse = total_sq_err / inlier_count;
    std::cout << "Inlier Reconstruction MSE: " << mse << " (Expected: < 0.001)\n";
    assert(mse < 0.001f && "Percentile clipping must yield high inlier precision!");

    std::cout << "\n✓ Drill 31 Passed: Percentile Clipping & MSE Optimization verified!\n";
    return 0;
}
