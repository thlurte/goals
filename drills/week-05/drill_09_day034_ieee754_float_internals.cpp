// ==============================================================================
// 🥋 Drill 09 (Day 34.1): CS:APP §2.4 — IEEE 754 Float Internals & `std::bit_cast`
//
// 📖 READING SOURCES:
// - Bryant & O'Hallaron: Computer Systems (CS:APP 3rd Ed, §2.4)
//
// 🎯 CORE LESSON:
// 1. IEEE 754 Single-Precision Float:
//    - Bit 31: Sign bit (1 bit).
//    - Bits 30-23: Biased Exponent (8 bits, Bias = 127). Unbiased = raw - 127.
//    - Bits 22-0: Fraction / Mantissa (23 bits, normalized 1.f).
// 2. Modern C++ Type Punning:
//    - `std::bit_cast<uint32_t>(float_val)` (#include <bit>) eliminates undefined behavior.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra drill_09_day034_ieee754_float_internals.cpp -o drill09 && ./drill09
// ==============================================================================

#include <iostream>
#include <cstdint>
#include <bit>
#include <cassert>

struct FloatDecoder {
    uint32_t sign{0};
    int32_t unbiased_exp{0};
    uint32_t mantissa{0};

    // TODO 1: Decode a float into sign, unbiased exponent, and mantissa
    static FloatDecoder decode(float val) {
        // [YOUR CODE HERE]
        // 1. Bit cast to uint32_t
        // 2. Extract sign bit (bit 31)
        // 3. Extract exponent bits (bits 30..23) and subtract 127
        // 4. Extract mantissa bits (bits 22..0) using mask 0x7FFFFF
        return {};
    }
};

int main() {
    std::cout << "--- Drill 09: IEEE 754 Bitfield Decoding & std::bit_cast ---\n\n";

    float val = -6.5f; // -1 * (1.625) * 2^2
    auto d = FloatDecoder::decode(val);

    std::cout << "Value: " << val << "\n"
              << "  Sign:             " << d.sign << " (Expected: 1)\n"
              << "  Unbiased Exponent:" << d.unbiased_exp << " (Expected: 2)\n";

    assert(d.sign == 1);
    assert(d.unbiased_exp == 2);
    std::cout << "\n✓ Drill 09 Passed: IEEE 754 decoding verified!\n";
    return 0;
}
