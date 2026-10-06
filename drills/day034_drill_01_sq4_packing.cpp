// ==============================================================================
// 🥋 Drill 34.1: 4-Bit Scalar Quantization (SQ4) Nibble Bit-Packing
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra day034_drill_01_sq4_packing.cpp -o drill34 && ./drill34
//
// CONTEXT:
// 4-bit scalar quantization stores two coordinates per byte, allowing a 128-D
// vector to fit in 64 bytes (exactly 1 hardware CPU cache line!).
//
// C++ CONCEPTS TO PRACTICE:
// 1. Bitwise masking: `val & 0x0F` isolates the lowest 4 bits.
// 2. Bitwise shifts: `val << 4` shifts bits to the upper nibble.
// 3. Bitwise OR: `low | high` combines two 4-bit nibbles into one byte.
// ==============================================================================

#include <iostream>
#include <vector>
#include <cstdint>
#include <cassert>
#include <span>

class SQ4BitPacker {
public:
    // TODO 1: Pack two 4-bit numbers (stored in uint8_t with values 0..15) into 1 byte
    // For each output index i:
    // - low_nibble  = src[2 * i + 0] & 0x0F
    // - high_nibble = (src[2 * i + 1] & 0x0F) << 4
    // - dst[i]      = low_nibble | high_nibble
    static void pack_nibbles(std::span<const uint8_t> src, std::span<uint8_t> dst) {
        assert(src.size() == dst.size() * 2);
        // [YOUR CODE HERE]
    }

    // TODO 2: Unpack 1 byte into two 4-bit numbers
    // For each input index i:
    // - dst[2 * i + 0] = src[i] & 0x0F
    // - dst[2 * i + 1] = (src[i] >> 4) & 0x0F
    static void unpack_nibbles(std::span<const uint8_t> src, std::span<uint8_t> dst) {
        assert(dst.size() == src.size() * 2);
        // [YOUR CODE HERE]
    }
};

int main() {
    std::cout << "--- Drill 34.1: 4-Bit SQ4 Nibble Packing ---\n\n";

    constexpr size_t D = 128;
    constexpr size_t PACKED_BYTES = D / 2; // 64 bytes

    std::vector<uint8_t> original_4bit(D);
    for (size_t i = 0; i < D; ++i) {
        original_4bit[i] = static_cast<uint8_t>((i * 7) % 16); // Values in [0, 15]
    }

    std::vector<uint8_t> packed_buffer(PACKED_BYTES);
    SQ4BitPacker::pack_nibbles(original_4bit, packed_buffer);

    std::cout << "Original elements: " << original_4bit.size() << "\n";
    std::cout << "Packed byte count: " << packed_buffer.size() << " bytes (1x 64B Cache Line!)\n";

    std::vector<uint8_t> recovered_4bit(D);
    SQ4BitPacker::unpack_nibbles(packed_buffer, recovered_4bit);

    for (size_t i = 0; i < D; ++i) {
        assert(original_4bit[i] == recovered_4bit[i] && "Unpacked value does not match original!");
    }

    std::cout << "\n✓ Drill Passed: 4-bit nibble packing and unpacking verified!\n";
    return 0;
}
