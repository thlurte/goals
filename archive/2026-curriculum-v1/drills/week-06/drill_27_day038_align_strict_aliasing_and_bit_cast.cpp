// ==============================================================================
// 🥋 Drill: Strict Aliasing Rules & Safe Type Punning via std::bit_cast
//
// 📖 READING SOURCES:
// - C++20 Standard: [bit.cast]
// - Agner Fog: Optimizing Subroutines in Assembly Language (Strict Aliasing UB)
//
// 🎯 CORE LESSON:
// 1. Casting `float*` to `int*` and dereferencing violates Strict Aliasing, causing silent compiler optimization bugs.
// 2. `std::bit_cast` (C++20) provides UB-free bit-level type punning with zero runtime overhead.
// 3. `std::memcpy` is the pre-C++20 safe alternative that compilers optimize to a single register move.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_27_day038_align_strict_aliasing_and_bit_cast.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <bit>
#include <cstdint>
#include <cassert>

int main() {
    std::cout << "--- Drill 27: Safe Type Punning with std::bit_cast ---\n\n";

    float f = 1.0f; // IEEE-754: 0x3f800000
    uint32_t bits = std::bit_cast<uint32_t>(f);

    std::cout << "1.0f represented in IEEE-754 hex: 0x" << std::hex << bits << std::dec << "\n";
    assert(bits == 0x3f800000 && "IEEE-754 1.0f must bitcast to 0x3f800000!");

    // Round-trip bit_cast
    float recovered = std::bit_cast<float>(bits);
    assert(recovered == 1.0f);

    std::cout << "\n✓ Drill 27 Passed: std::bit_cast bypassed strict aliasing UB legally!\n";
    return 0;
}
