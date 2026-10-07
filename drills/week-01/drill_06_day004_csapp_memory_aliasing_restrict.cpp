// ==============================================================================
// 🥋 Drill 06 (Week 01 / Day 004): CS:APP §5.1–5.6 — Memory Aliasing & `__restrict__`
//
// 📖 READING SOURCES:
// - Bryant & O'Hallaron: Computer Systems (CS:APP 3rd Ed, §5.1–5.6: Compiler Limitations & Memory Aliasing)
//
// 🎯 CORE LESSON:
// 1. The Memory Aliasing Constraint:
//    When two pointers `float* a` and `float* b` are passed into a function, the compiler
//    must assume they might overlap in memory. It is forced to reload from memory on every step!
// 2. The `__restrict__` Contract:
//    Qualifying pointers with `const float* __restrict__ a` promises the compiler that
//    `a` and `b` point to disjoint memory regions, enabling aggressive vectorization and register caching.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra drill_06_day004_csapp_memory_aliasing_restrict.cpp -o drill06 && ./drill06
// ==============================================================================

#include <iostream>
#include <vector>
#include <cassert>

// TODO 1: Implement vector accumulation with __restrict__ pointers
// out[i] += a[i] * scale
void vector_saxpy(
    float* __restrict__ out,
    const float* __restrict__ a,
    float scale,
    size_t dim
) {
    // [YOUR CODE HERE]
}

int main() {
    std::cout << "--- Week 01 Drill 06: CS:APP Memory Aliasing & __restrict__ ---\n\n";

    constexpr size_t D = 128;
    std::vector<float> a(D, 2.0f);
    std::vector<float> out(D, 10.0f);

    vector_saxpy(out.data(), a.data(), 3.0f, D);
    // Each element: 10.0 + (2.0 * 3.0) = 16.0

    std::cout << "out[0]: " << out[0] << " (Expected: 16.0)\n";
    assert(out[0] == 16.0f);
    assert(out[D - 1] == 16.0f);

    std::cout << "\n✓ Week 01 Drill 06 Passed Successfully!\n";
    return 0;
}
