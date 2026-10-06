// ==============================================================================
// 🥋 Cennan Drill 36.1: Linear Layer Forward & Analytical Backpropagation in C++
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra day036_drill_01_cennan_linear_backward.cpp -o drill36 && ./drill36
//
// CONTEXT:
// In `cennan`, a fully-connected layer computes:
//   Forward:  Y = X W^T + b  (X: [B, In], W: [Out, In], b: [Out], Y: [B, Out])
//   Backward:
//     dX = dY W       (Shape: [B, In])
//     dW = dY^T X     (Shape: [Out, In])
//     db = sum_{b=0}^{B-1} dY_b (Shape: [Out])
//
// C++ CONCEPTS TO PRACTICE:
// 1. Flat matrix multiplication indexing: `A[i * K + k] * B[j * K + k]`.
// 2. Accumulating gradients into zeroed buffers without memory reallocation.
// 3. Cache-friendly loop order (outer batch, middle out_features, inner in_features).
// ==============================================================================

#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include <numeric>

struct LinearLayer {
    size_t in_features;
    size_t out_features;
    std::vector<float> weight; // [out_features, in_features]
    std::vector<float> bias;   // [out_features]

    std::vector<float> d_weight; // [out_features, in_features]
    std::vector<float> d_bias;   // [out_features]

    LinearLayer(size_t in_f, size_t out_f)
        : in_features(in_f), out_features(out_f),
          weight(out_f * in_f, 0.5f), bias(out_f, 0.1f),
          d_weight(out_f * in_f, 0.0f), d_bias(out_f, 0.0f) {}

    // TODO 1: Implement Forward Pass Y = X W^T + b
    // Args:
    //   X: pointer to input [B, in_features]
    //   B: batch size
    //   Y: pointer to output buffer [B, out_features]
    void forward(const float* X, size_t B, float* Y) const {
        // [YOUR CODE HERE]
    }

    // TODO 2: Implement Backward Pass
    // Args:
    //   X: pointer to input [B, in_features]
    //   dY: pointer to incoming gradient [B, out_features]
    //   B: batch size
    //   dX: pointer to outgoing gradient buffer [B, in_features]
    // Steps:
    // 1. Reset d_weight and d_bias to 0.0f.
    // 2. Compute dX = dY @ W
    // 3. Compute dW = dY^T @ X
    // 4. Compute db = sum(dY, axis=0)
    void backward(const float* X, const float* dY, size_t B, float* dX) {
        // [YOUR CODE HERE]
    }
};

int main() {
    std::cout << "--- Drill 36.1: Cennan Linear Layer Forward & Backward ---\n\n";

    const size_t B = 2;
    const size_t In = 3;
    const size_t Out = 2;

    LinearLayer layer(In, Out);
    // Initialize deterministic weights
    layer.weight = {
        1.0f, 2.0f, 3.0f, // neuron 0
        4.0f, 5.0f, 6.0f  // neuron 1
    };
    layer.bias = {0.5f, -0.5f};

    std::vector<float> X = {
        1.0f, 1.0f, 1.0f, // batch item 0
        2.0f, 0.0f, 1.0f  // batch item 1
    };

    std::vector<float> Y(B * Out, 0.0f);
    layer.forward(X.data(), B, Y.data());

    // Expected Y[0] = [1*1 + 1*2 + 1*3 + 0.5, 1*4 + 1*5 + 1*6 - 0.5] = [6.5, 14.5]
    // Expected Y[1] = [2*1 + 0*2 + 1*3 + 0.5, 2*4 + 0*5 + 1*6 - 0.5] = [5.5, 13.5]
    std::cout << "Y[0]: [" << Y[0] << ", " << Y[1] << "]\n";
    std::cout << "Y[1]: [" << Y[2] << ", " << Y[3] << "]\n";

    assert(std::abs(Y[0] - 6.5f) < 1e-4 && std::abs(Y[1] - 14.5f) < 1e-4);
    assert(std::abs(Y[2] - 5.5f) < 1e-4 && std::abs(Y[3] - 13.5f) < 1e-4);

    std::vector<float> dY = {1.0f, 1.0f, 1.0f, 1.0f}; // all ones gradient
    std::vector<float> dX(B * In, 0.0f);
    layer.backward(X.data(), dY.data(), B, dX.data());

    // Expected db = [2.0, 2.0]
    std::cout << "db: [" << layer.d_bias[0] << ", " << layer.d_bias[1] << "]\n";
    assert(std::abs(layer.d_bias[0] - 2.0f) < 1e-4 && std::abs(layer.d_bias[1] - 2.0f) < 1e-4);

    std::cout << "\n✓ Drill Passed: Linear layer forward and analytical backprop verified!\n";
    return 0;
}
