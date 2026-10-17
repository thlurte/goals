// ==============================================================================
// 🥋 Drill: std::unique_ptr<T[]> Array Specialization vs Scalar Mismatch
//
// 📖 READING SOURCES:
// - Meyers: Effective Modern C++ (Item 18: std::unique_ptr array form)
// - C++ Core Guidelines: R.11 (Avoid calling new and delete explicitly)
//
// 🎯 CORE LESSON:
// 1. `std::unique_ptr<T[]>` automatically calls `delete[]` instead of scalar `delete`.
// 2. Using scalar `std::unique_ptr<T>` with `new T[]` is undefined behavior (heap corruption).
// 3. `std::unique_ptr<T[]>` provides `operator[]` and forbids pointer arithmetic and indirection (`*`).
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_03_day038_mem_unique_ptr_array_specialization.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <memory>
#include <cassert>

int main() {
    std::cout << "--- Drill 03: std::unique_ptr<T[]> Array Specialization ---\n\n";

    constexpr size_t N = 64;
    // std::make_unique<float[]>(N) allocates with new float[N]() and deletes with delete[]
    std::unique_ptr<float[]> buffer = std::make_unique<float[]>(N);

    for (size_t i = 0; i < N; ++i) {
        buffer[i] = static_cast<float>(i * 2);
    }

    assert(buffer[0] == 0.0f);
    assert(buffer[10] == 20.0f);
    assert(buffer[63] == 126.0f);

    std::cout << "✓ Buffer correctly allocated and accessed via operator[]\n";
    std::cout << "\n✓ Drill 03 Passed: std::unique_ptr<T[]> safely prevents delete[] mismatch!\n";
    return 0;
}
