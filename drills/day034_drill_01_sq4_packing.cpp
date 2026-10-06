/**
 * @file day034_drill_01_sq4_packing.cpp
 * @brief Drill 34.1: 4-Bit Scalar Quantization (SQ4) Nibble Packing & Bitwise Logic
 *
 * 🎓 C++ CONCEPTS TAUGHT IN THIS DRILL:
 * 1. Bitwise operators in C++: Bitwise AND (`&`), Bitwise OR (`|`), Bitwise Shift Left/Right (`<<`, `>>`).
 * 2. Nibbles: Packing two 4-bit values [0, 15] into a single 8-bit `uint8_t` byte.
 * 3. Static class methods vs free functions: Organizing stateless byte utility libraries.
 * 4. Cache-line alignment: Why 128 dimensions in SQ4 equals 64 bytes = exactly one hardware cache line.
 *
 * Compile: g++ -O3 -std=c++20 -Wall -Wextra day034_drill_01_sq4_packing.cpp -o drill34 && ./drill34
 */

#include <iostream>
#include <vector>
#include <cstdint>
#include <cassert>
#include <span>

class SQ4BitPacker {
public:
    static void pack_nibbles(std::span<const uint8_t> src, std::span<uint8_t> dst) {
        assert(src.size() == dst.size() * 2 && "Source span size must be exactly 2x destination span size!");

        for (size_t i = 0; i < dst.size(); ++i) {
            uint8_t low_nibble  = src[2 * i + 0] & 0x0F;
            uint8_t high_nibble = (src[2 * i + 1] & 0x0F) << 4;
            dst[i] = low_nibble | high_nibble;
        }
    }

    static void unpack_nibbles(std::span<const uint8_t> src, std::span<uint8_t> dst) {
        assert(dst.size() == src.size() * 2 && "Destination span size must be exactly 2x source span size!");

        for (size_t i = 0; i < src.size(); ++i) {
            uint8_t packed_byte = src[i];
            dst[2 * i + 0] = packed_byte & 0x0F;
            dst[2 * i + 1] = (packed_byte >> 4) & 0x0F;
        }
    }
};

int main() {
    std::cout << "===================================================================\n";
    std::cout << "🥋 Drill 34.1: SQ4 Nibble Packing & Bitwise Operator Mastery\n";
    std::cout << "===================================================================\n";

    constexpr size_t D = 128;
    constexpr size_t PACKED_BYTES = D / 2; // 64 bytes = 1 CPU Cache Line!

    std::vector<uint8_t> original_4bit(D);
    for (size_t i = 0; i < D; ++i) {
        original_4bit[i] = static_cast<uint8_t>((i * 7) % 16);
    }

    std::vector<uint8_t> packed_buffer(PACKED_BYTES);
    SQ4BitPacker::pack_nibbles(original_4bit, packed_buffer);

    std::cout << "[C++ Bitwise Info]\n";
    std::cout << "  - Original Elements: " << original_4bit.size() << " (each in [0, 15])\n";
    std::cout << "  - Packed Footprint:  " << packed_buffer.size() << " bytes (Fits in 1x 64B L1 Cache Line)\n";

    std::vector<uint8_t> recovered_4bit(D);
    SQ4BitPacker::unpack_nibbles(packed_buffer, recovered_4bit);

    for (size_t i = 0; i < D; ++i) {
        assert(original_4bit[i] == recovered_4bit[i] && "Unpacked nibble does not match original!");
    }

    std::cout << "  - Verification:      128/128 nibbles matched exactly.\n";
    std::cout << "\n✅ DRILL 34.1 PASSED: 4-bit nibble bit-packing verified.\n";
    return 0;
}
