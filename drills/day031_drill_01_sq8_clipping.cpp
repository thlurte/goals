/**
 * @file day031_drill_01_sq8_clipping.cpp
 * @brief Drill 31.1: Outlier-Robust Scalar Quantization (SQ8) & C++ Memory Views (std::span)
 *
 * 🎓 C++ CONCEPTS TAUGHT IN THIS DRILL:
 * 1. `std::span<const float>`: Non-owning view of contiguous memory (eliminates expensive std::vector copies).
 * 2. `const` correctness: Distinguishing between `const float*` (data is read-only) and `float* const` (pointer is fixed).
 * 3. `std::clamp(val, min, max)`: Modern C++17 branchless-friendly bounding utility.
 * 4. Inlier vs Outlier Quantization Error: Why clipping yields higher precision (narrower bin width) for 99.9% of data.
 *
 * Compile: g++ -O3 -std=c++20 -Wall -Wextra day031_drill_01_sq8_clipping.cpp -o drill31 && ./drill31
 */

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

    void train(std::span<const float> samples, float lower_pct = 0.0005f, float upper_pct = 0.9995f) {
        std::vector<float> sorted_vals(samples.begin(), samples.end());
        std::sort(sorted_vals.begin(), sorted_vals.end());

        size_t n = sorted_vals.size();
        size_t lower_idx = static_cast<size_t>(lower_pct * n);
        size_t upper_idx = static_cast<size_t>(upper_pct * n);
        upper_idx = std::min(upper_idx, n - 1);

        min_val = sorted_vals[lower_idx];
        max_val = sorted_vals[upper_idx];

        if (max_val <= min_val) {
            max_val = min_val + 1e-5f;
        }

        scale = 255.0f / (max_val - min_val);
        inv_scale = (max_val - min_val) / 255.0f;
    }

    inline uint8_t quantize_scalar(float val) const noexcept {
        float clamped = std::clamp(val, min_val, max_val);
        return static_cast<uint8_t>(std::round((clamped - min_val) * scale));
    }

    inline float dequantize_scalar(uint8_t code) const noexcept {
        return min_val + static_cast<float>(code) * inv_scale;
    }
};

int main() {
    std::cout << "===================================================================\n";
    std::cout << "🥋 Drill 31.1: SQ8 Percentile Clipping & Inlier Resolution Test\n";
    std::cout << "===================================================================\n";

    constexpr size_t N_SAMPLES = 5000;
    constexpr size_t D = 128;
    std::vector<float> dataset(N_SAMPLES * D);

    std::mt19937 rng(42);
    std::normal_distribution<float> dist(0.0f, 1.0f);
    for (float& x : dataset) x = dist(rng);

    // Inject outliers in 0.1% of coordinates (e.g. ±25.0)
    std::uniform_int_distribution<size_t> idx_dist(0, dataset.size() - 1);
    for (size_t i = 0; i < 50; ++i) {
        dataset[idx_dist(rng)] = (i % 2 == 0) ? 25.0f : -25.0f;
    }

    // 1. Train Robust Clipped Quantizer
    SQ8Quantizer robust_sq8;
    robust_sq8.train(dataset, 0.0005f, 0.9995f);

    // 2. Train Naive Min-Max Quantizer
    SQ8Quantizer naive_sq8;
    naive_sq8.train(dataset, 0.0f, 1.0f);

    float robust_bin_width = (robust_sq8.max_val - robust_sq8.min_val) / 255.0f;
    float naive_bin_width  = (naive_sq8.max_val - naive_sq8.min_val) / 255.0f;

    std::cout << "[C++ Quantizer State]\n";
    std::cout << "  - Robust Bounds:    [" << robust_sq8.min_val << ", " << robust_sq8.max_val << "] (Bin Width: " << robust_bin_width << ")\n";
    std::cout << "  - Naive Bounds:     [" << naive_sq8.min_val << ", " << naive_sq8.max_val << "] (Bin Width: " << naive_bin_width << ")\n";
    std::cout << "  - Precision Gain:   " << (naive_bin_width / robust_bin_width) << "x finer bin resolution on normal data!\n";

    // 3. Measure Inlier Reconstruction Error (the 99.9% of actual embedding signal)
    double inlier_robust_mse = 0.0;
    double inlier_naive_mse  = 0.0;
    size_t inlier_count = 0;

    for (float x : dataset) {
        if (x >= robust_sq8.min_val && x <= robust_sq8.max_val) {
            float rec_robust = robust_sq8.dequantize_scalar(robust_sq8.quantize_scalar(x));
            float rec_naive  = naive_sq8.dequantize_scalar(naive_sq8.quantize_scalar(x));

            inlier_robust_mse += (x - rec_robust) * (x - rec_robust);
            inlier_naive_mse  += (x - rec_naive) * (x - rec_naive);
            inlier_count++;
        }
    }
    inlier_robust_mse /= inlier_count;
    inlier_naive_mse  /= inlier_count;

    std::cout << "\n📊 Inlier Signal Reconstruction MSE (" << inlier_count << " / " << dataset.size() << " samples):\n";
    std::cout << "  - Naive Min/Max MSE: " << std::fixed << std::setprecision(6) << inlier_naive_mse << "\n";
    std::cout << "  - Robust SQ8 MSE:    " << inlier_robust_mse << "\n";
    std::cout << "  - Accuracy Boost:    " << (inlier_naive_mse / inlier_robust_mse) << "x higher accuracy for inliers!\n";

    assert(inlier_robust_mse < inlier_naive_mse);
    std::cout << "\n✅ DRILL 31.1 PASSED: Robust quantization & C++20 span views verified.\n";
    return 0;
}
