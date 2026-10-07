// ==============================================================================
// 🥋 Drill 03 (Week 01 / Day 002): Strang Calculus — Numerical Differentiation & Gradient Checking
//
// 📖 READING SOURCES:
// - Gilbert Strang: Calculus (3rd Ed, §2.1–2.5: Derivatives from First Principles)
//
// 🎯 CORE LESSON:
// 1. Numerical Derivative (Central Difference Approximation):
//    f'(x) approx (f(x + h) - f(x - h)) / (2h)   [Error is O(h^2)]
// 2. Numerical Gradient Checking:
//    Used in neural engines (`cennan`) to verify analytical backpropagation passes.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra drill_03_day002_numerical_differentiation.cpp -o drill03 && ./drill03
// ==============================================================================

#include <iostream>
#include <functional>
#include <cmath>
#include <cassert>

// TODO 1: Implement Central Difference numerical derivative
// (f(x + h) - f(x - h)) / (2 * h)
double numerical_derivative(const std::function<double(double)>& f, double x, double h = 1e-5) {
    // [YOUR CODE HERE]
    return 0.0;
}

int main() {
    std::cout << "--- Week 01 Drill 03: Strang Calculus & Numerical Differentiation ---\n\n";

    // Test 1: f(x) = x^3 - 2x + 5 -> f'(x) = 3x^2 - 2
    // At x = 2.0: f'(2.0) = 3*(4) - 2 = 10.0
    auto f1 = [](double x) { return x * x * x - 2.0 * x + 5.0; };
    double d1 = numerical_derivative(f1, 2.0);
    std::cout << "f(x) = x^3 - 2x + 5 at x=2.0 -> Numerical: " << d1 << " (Expected: 10.0)\n";
    assert(std::abs(d1 - 10.0) < 1e-4);

    // Test 2: f(x) = sin(x) -> f'(x) = cos(x)
    // At x = 0.0: f'(0.0) = cos(0.0) = 1.0
    auto f2 = [](double x) { return std::sin(x); };
    double d2 = numerical_derivative(f2, 0.0);
    std::cout << "f(x) = sin(x) at x=0.0 -> Numerical: " << d2 << " (Expected: 1.0)\n";
    assert(std::abs(d2 - 1.0) < 1e-4);

    std::cout << "\n✓ Week 01 Drill 03 Passed Successfully!\n";
    return 0;
}
