// ==============================================================================
// 🥋 Drill 08 (Day 33.5): `cennan` Core — Vectorized In-Place Neural Activations
//
// 📖 READING SOURCES:
// - `cennan` Neural Engine Activations Architecture
//
// 🎯 CORE LESSON:
// 1. `std::span<float>` provides zero-overhead in-place buffer mutation.
// 2. GELU (tanh approximation):
//    GELU(x) = 0.5 * x * (1 + tanh(sqrt(2/pi) * (x + 0.044715 * x^3)))
// 3. SwiGLU Gated Multi-Modal Projection:
//    SwiGLU(x, g) = x * SiLU(g) = x * (g / (1 + exp(-g)))
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra drill_08_day033_neural_activations.cpp -o drill08 && ./drill08
// ==============================================================================

#include <iostream>
#include <vector>
#include <span>
#include <cmath>
#include <cassert>

constexpr float SQRT_2_OVER_PI = 0.7978845608f;
constexpr float GELU_COEFF = 0.044715f;

inline float sigmoid(float x) {
    return 1.0f / (1.0f + std::exp(-x));
}

// TODO 1: Implement in-place GELU tanh approximation
void gelu_inplace(std::span<float> data) {
    // [YOUR CODE HERE]
}

// TODO 2: Implement SwiGLU forward pass
// out[i] = x[i] * (gate[i] * sigmoid(gate[i]))
void swiglu_forward(std::span<const float> x, std::span<const float> gate, std::span<float> out) {
    // [YOUR CODE HERE]
}

int main() {
    std::cout << "--- Drill 08: Cennan Vectorized In-Place Activations ---\n\n";

    std::vector<float> vec = {-2.0f, -1.0f, 0.0f, 1.0f, 2.0f};
    std::vector<float> expected_gelu = {-0.0454f, -0.1588f, 0.0f, 0.8412f, 1.9545f};

    gelu_inplace(vec);
    for (size_t i = 0; i < vec.size(); ++i) {
        assert(std::abs(vec[i] - expected_gelu[i]) < 1e-3f);
    }
    std::cout << "✓ In-place GELU verified!\n";

    std::vector<float> x = {1.0f, 2.0f};
    std::vector<float> gate = {0.0f, 1.0f};
    std::vector<float> out(2);

    swiglu_forward(x, gate, out);
    assert(out[0] == 0.0f);
    assert(std::abs(out[1] - 1.462117f) < 1e-4f);
    std::cout << "✓ SwiGLU forward verified!\n";

    std::cout << "\n✓ Drill 08 Passed Successfully!\n";
    return 0;
}
