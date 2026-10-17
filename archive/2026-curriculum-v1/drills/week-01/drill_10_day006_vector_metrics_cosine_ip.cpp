// ==============================================================================
// 🥋 Drill 10 (Week 01 / Day 006): `secan` — MetricType Enum, Inner Product & Cosine Distance
//
// 📖 READING SOURCES:
// - `secan/src/distance.cpp`
//
// 🎯 CORE LESSON:
// 1. Strongly-typed enums (`enum class MetricType { L2, IP, Cosine }`) in Modern C++.
// 2. Inner Product (MIPS): <u, v> = sum(u[i] * v[i]).
// 3. Cosine Distance: 1.0 - (<u, v> / (||u|| * ||v||)).
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra drill_10_day006_vector_metrics_cosine_ip.cpp -o drill10 && ./drill10
// ==============================================================================

#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

enum class MetricType {
    L2,
    InnerProduct,
    Cosine
};

// TODO 1: Implement inner product
float inner_product_scalar(const float* a, const float* b, size_t dim) {
    // [YOUR CODE HERE]
    return 0.0f;
}

// TODO 2: Implement cosine distance: 1.0f - (dot / (norm_a * norm_b))
float cosine_distance_scalar(const float* a, const float* b, size_t dim) {
    // [YOUR CODE HERE]
    return 0.0f;
}

int main() {
    std::cout << "--- Week 01 Drill 10: MetricType Enum, Inner Product & Cosine ---\n\n";

    constexpr size_t D = 4;
    std::vector<float> u = {1.0f, 0.0f, 0.0f, 0.0f};
    std::vector<float> v = {0.0f, 1.0f, 0.0f, 0.0f};

    // Orthogonal vectors -> Dot = 0.0, Cosine Distance = 1.0 - 0.0 = 1.0
    float ip = inner_product_scalar(u.data(), v.data(), D);
    float cos_dist = cosine_distance_scalar(u.data(), v.data(), D);

    std::cout << "Inner Product of Orthogonal Vectors: " << ip << " (Expected: 0.0)\n";
    std::cout << "Cosine Distance of Orthogonal Vectors: " << cos_dist << " (Expected: 1.0)\n";

    assert(ip == 0.0f);
    assert(cos_dist == 1.0f);

    std::cout << "\n✓ Week 01 Drill 10 Passed Successfully!\n";
    return 0;
}
