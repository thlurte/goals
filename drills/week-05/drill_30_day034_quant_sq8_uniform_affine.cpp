// ==============================================================================
// 🥋 Drill 30 (Day 34.21): Quantization Mastery — SQ8 Uniform Affine vs Symmetric Quantization
//
// 📖 READING SOURCES:
// - Jacob et al.: "Quantization and Training of Neural Networks for Efficient Integer-Arithmetic-Only Inference" (CVPR 2018)
// - Nagel et al.: "A White Paper on Neural Network Quantization" (Qualcomm AI Research)
//
// 🎯 CORE LESSON:
// 1. Uniform Asymmetric / Affine Quantization:
//    - Real range $[x_{\min}, x_{\max}] \to$ Integer range $[0, 255]$:
//      $$S = \frac{x_{\max} - x_{\min}}{255}, \quad Z = \text{round}\left(-\frac{x_{\min}}{S}\right)$$
//      $$q = \text{clamp}\left(\text{round}\left(\frac{x}{S}\right) + Z, 0, 255\right)$$
// 2. Dequantization:
//      $$\hat{x} = S \cdot (q - Z)$$
// 3. Symmetric Quantization ($Z = 0$):
//    - For zero-centered activations (e.g. after LayerNorm/Cosine):
//      $$S = \frac{\max(|x_{\min}|, |x_{\max}|)}{127}, \quad q = \text{clamp}\left(\text{round}\left(\frac{x}{S}\right), -128, 127\right)$$
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra drill_30_day034_quant_sq8_uniform_affine.cpp -o drill30 && ./drill30
// ==============================================================================

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>
#include <algorithm>
#include <cassert>

struct AffineQuantizer8 {
    float scale{1.0f};
    int32_t zero_point{0};

    // TODO 1: Implement calibration / parameter calculation
    // 1. S = (max_val - min_val) / 255.0f
    // 2. Z = round(-min_val / S)
    // 3. Clamp Z to [0, 255]
    void calibrate(float min_val, float max_val) {
        // [YOUR CODE HERE]
        (void)min_val;
        (void)max_val;
    }

    // TODO 2: Implement affine quantization: q = clamp(round(x / scale) + zero_point, 0, 255)
    uint8_t quantize(float x) const {
        // [YOUR CODE HERE]
        (void)x;
        return 0;
    }

    // TODO 3: Implement dequantization: x_hat = scale * (static_cast<int32_t>(q) - zero_point)
    float dequantize(uint8_t q) const {
        // [YOUR CODE HERE]
        (void)q;
        return 0.0f;
    }
};

int main() {
    std::cout << "--- Drill 30: SQ8 Uniform Affine Quantization & Zero-Point Calibration ---\n\n";

    AffineQuantizer8 quant;
    float min_val = -10.0f;
    float max_val = 41.0f; // Range: 51.0 -> Scale = 51.0 / 255 = 0.2, Zero-Point = -(-10)/0.2 = 50

    quant.calibrate(min_val, max_val);

    std::cout << "Calibrated Scale:      " << quant.scale << " (Expected: 0.2)\n";
    std::cout << "Calibrated Zero-Point: " << quant.zero_point << " (Expected: 50)\n";

    assert(std::abs(quant.scale - 0.2f) < 1e-5f);
    assert(quant.zero_point == 50);

    // Test exact mapping
    uint8_t q_min = quant.quantize(-10.0f);
    uint8_t q_zero = quant.quantize(0.0f);
    uint8_t q_max = quant.quantize(41.0f);

    assert(q_min == 0 && "Min value must map to 0");
    assert(q_zero == 50 && "Real 0.0 must map to zero_point (50)");
    assert(q_max == 255 && "Max value must map to 255");

    std::cout << "✓ Quantized -10.0 -> " << (int)q_min << " (0)\n";
    std::cout << "✓ Quantized   0.0 -> " << (int)q_zero << " (50)\n";
    std::cout << "✓ Quantized  41.0 -> " << (int)q_max << " (255)\n";

    // Test dequantization precision
    float x_test = 15.6f;
    uint8_t q_test = quant.quantize(x_test);
    float x_hat = quant.dequantize(q_test);

    std::cout << "Original: " << x_test << " -> Quantized: " << (int)q_test << " -> Reconstructed: " << x_hat << "\n";
    assert(std::abs(x_test - x_hat) <= quant.scale / 2.0f);

    std::cout << "\n✓ Drill 30 Passed: SQ8 Uniform Affine Quantization verified!\n";
    return 0;
}
