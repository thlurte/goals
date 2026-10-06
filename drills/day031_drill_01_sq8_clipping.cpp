// ==============================================================================
// 🥋 Drill 31.1: Outlier-Robust Scalar Quantization (SQ8) & C++ Memory Views
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra day031_drill_01_sq8_clipping.cpp -o drill31 && ./drill31
//
// CONTEXT:
// In vector embeddings, extreme outliers ruin naive min/max quantization.
// In this drill, you will implement an outlier-clipped 8-bit scalar quantizer.
//
// C++ CONCEPTS TO PRACTICE:
// 1. `std::span<const float>`: Zero-copy non-owning view of a continuous buffer.
// 2. `std::clamp(val, min_val, max_val)`: Constraining values to a bounding box.
// 3. `std::round`: Converting floating-point scaled values to nearest integer.
// ==============================================================================

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <random>
#include <cassert>
#include <span>
#include <iomanip>

struct SQ8Quantizer {
    float min_val{0.0f};
    float max_val{1.0f};
    float scale{1.0f};
    float inv_scale{1.0f};

    // TODO 1: Train quantizer bounds on sample data using percentile clipping
    // Steps:
    // 1. Copy `samples` into a local std::vector<float> and sort it using std::sort.
    // 2. Set min_val = sorted_vals[lower_pct * n] and max_val = sorted_vals[upper_pct * n].
    // 3. Compute scale = 255.0f / (max_val - min_val) and inv_scale = (max_val - min_val) / 255.0f.
    void train(std::span<const float> samples, float lower_pct = 0.0005f, float upper_pct = 0.9995f) {
        // [YOUR CODE HERE]
    }

    // TODO 2: Quantize a single float into an 8-bit unsigned integer (uint8_t)
    // Steps:
    // 1. Clamp `val` between min_val and max_val using std::clamp.
    // 2. Scale: (clamped - min_val) * scale.
    // 3. Round to nearest integer using std::round and cast to uint8_t.
    inline uint8_t quantize_scalar(float val) const noexcept {
        // [YOUR CODE HERE]
        return 0; // Replace with your implementation
    }

    // TODO 3: Dequantize an 8-bit code back to an approximate FP32 float
    // Steps:
    // 1. Compute min_val + static_cast<float>(code) * inv_scale.
    inline float dequantize_scalar(uint8_t code) const noexcept {
        // [YOUR CODE HERE]
        return 0.0f; // Replace with your implementation
    }
};

int main() {
    std::cout << "--- Drill 31.1: SQ8 Percentile Clipping & C++ Span Views ---\n\n";

    constexpr size_t N_SAMPLES = 5000;
    constexpr size_t D = 128;
    std::vector<float> dataset(N_SAMPLES * D);

    std::mt19937 rng(42);
    std::normal_distribution<float> dist(0.0f, 1.0f);
    for (float& x : dataset) x = dist(rng);

    // Inject outliers (±25.0) simulating LLM embedding anomalies
    std::uniform_int_distribution<size_t> idx_dist(0, dataset.size() - 1);
    for (size_t i = 0; i < 50; ++i) {
        dataset[idx_dist(rng)] = (i % 2 == 0) ? 25.0f : -25.0f;
    }

    SQ8Quantizer robust_sq8;
    robust_sq8.train(dataset, 0.0005f, 0.9995f);

    std::cout << "[Trained Bounds] Min: " << robust_sq8.min_val << " | Max: " << robust_sq8.max_val << "\n";

    // Verification
    assert(robust_sq8.min_val < -2.0f && robust_sq8.min_val > -5.0f && "min_val should exclude -25.0 outlier!");
    assert(robust_sq8.max_val > 2.0f && robust_sq8.max_val < 5.0f && "max_val should exclude +25.0 outlier!");

    float test_val = 1.25f;
    uint8_t code = robust_sq8.quantize_scalar(test_val);
    float rec = robust_sq8.dequantize_scalar(code);
    std::cout << "Original: " << test_val << " -> Code: " << static_cast<int>(code) << " -> Reconstructed: " << rec << "\n";
    assert(std::abs(test_val - rec) < 0.05f);

    std::cout << "\n✓ Drill Passed: Robust SQ8 quantizer with outlier clipping verified!\n";
    return 0;
}
