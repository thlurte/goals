// ==============================================================================
// 🥋 Cennan Drill 36.1: Solution
// ==============================================================================

#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include <numeric>
#include <algorithm>

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

    void forward(const float* X, size_t B, float* Y) const {
        for (size_t b = 0; b < B; ++b) {
            for (size_t o = 0; o < out_features; ++o) {
                float sum = bias[o];
                for (size_t i = 0; i < in_features; ++i) {
                    sum += X[b * in_features + i] * weight[o * in_features + i];
                }
                Y[b * out_features + o] = sum;
            }
        }
    }

    void backward(const float* X, const float* dY, size_t B, float* dX) {
        std::fill(d_weight.begin(), d_weight.end(), 0.0f);
        std::fill(d_bias.begin(), d_bias.end(), 0.0f);
        std::fill(dX, dX + B * in_features, 0.0f);

        for (size_t b = 0; b < B; ++b) {
            for (size_t o = 0; o < out_features; ++o) {
                float dy = dY[b * out_features + o];
                d_bias[o] += dy;
                for (size_t i = 0; i < in_features; ++i) {
                    dX[b * in_features + i] += dy * weight[o * in_features + i];
                    d_weight[o * in_features + i] += dy * X[b * in_features + i];
                }
            }
        }
    }
};

int main() {
    std::cout << "--- Drill 36.1: Cennan Linear Layer Forward & Backward (Solution) ---\n\n";

    const size_t B = 2;
    const size_t In = 3;
    const size_t Out = 2;

    LinearLayer layer(In, Out);
    layer.weight = {
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f
    };
    layer.bias = {0.5f, -0.5f};

    std::vector<float> X = {
        1.0f, 1.0f, 1.0f,
        2.0f, 0.0f, 1.0f
    };

    std::vector<float> Y(B * Out, 0.0f);
    layer.forward(X.data(), B, Y.data());

    std::cout << "Y[0]: [" << Y[0] << ", " << Y[1] << "]\n";
    std::cout << "Y[1]: [" << Y[2] << ", " << Y[3] << "]\n";

    assert(std::abs(Y[0] - 6.5f) < 1e-4 && std::abs(Y[1] - 14.5f) < 1e-4);
    assert(std::abs(Y[2] - 5.5f) < 1e-4 && std::abs(Y[3] - 13.5f) < 1e-4);

    std::vector<float> dY = {1.0f, 1.0f, 1.0f, 1.0f};
    std::vector<float> dX(B * In, 0.0f);
    layer.backward(X.data(), dY.data(), B, dX.data());

    std::cout << "db: [" << layer.d_bias[0] << ", " << layer.d_bias[1] << "]\n";
    assert(std::abs(layer.d_bias[0] - 2.0f) < 1e-4 && std::abs(layer.d_bias[1] - 2.0f) < 1e-4);

    std::cout << "\n✓ Drill Passed: Linear layer forward and analytical backprop verified!\n";
    return 0;
}
