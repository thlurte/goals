// ==============================================================================
// 🥋 Drill: 2-Bit Scalar Quantization: Packing 4 Values per Byte
//
// 📖 READING SOURCES:
// - ScaNN / Faiss: Multi-Bit Quantization Layouts
// - CS:APP (Ch 2: Representing and Manipulating Information)
//
// 🎯 CORE LESSON:
// 1. 2-bit quantization represents values in range $[0..3]$.
// 2. 4 values pack into a single 8-bit `uint8_t` byte.
// 3. Value at index $i$ occupies bits $[2k+1 : 2k]$ where $k = i \% 4$.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_72_day038_align_2bit_quant_packing.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <cstdint>
#include <cassert>

inline void pack_2bit(const uint8_t* in4, uint8_t& out_byte) {
    out_byte = (in4[0] & 0x03) |
               ((in4[1] & 0x03) << 2) |
               ((in4[2] & 0x03) << 4) |
               ((in4[3] & 0x03) << 6);
}

inline void unpack_2bit(uint8_t in_byte, uint8_t* out4) {
    out4[0] = in_byte & 0x03;
    out4[1] = (in_byte >> 2) & 0x03;
    out4[2] = (in_byte >> 4) & 0x03;
    out4[3] = (in_byte >> 6) & 0x03;
}

int main() {
    std::cout << "--- Drill 72: 2-Bit Quantization Bit-Packing ---\n\n";

    uint8_t values[4] = {0, 1, 2, 3};
    uint8_t packed = 0;
    pack_2bit(values, packed);

    uint8_t recovered[4] = {0};
    unpack_2bit(packed, recovered);

    for (int i = 0; i < 4; ++i) {
        assert(recovered[i] == values[i]);
    }

    std::cout << "\n✓ Drill 72 Passed: 2-Bit scalar quantization packing verified!\n";
    return 0;
}
