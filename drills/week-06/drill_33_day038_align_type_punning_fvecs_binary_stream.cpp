// ==============================================================================
// 🥋 Drill: Safe Type-Punning on Binary .fvecs Streams with std::span
//
// 📖 READING SOURCES:
// - C++20 std::span specification
// - Jegou et al.: SIFT1M & .fvecs format specification
//
// 🎯 CORE LESSON:
// 1. `.fvecs` formats store vectors as 4-byte `uint32_t dim` followed by $D$ 4-byte `float` elements.
// 2. `std::span<const uint8_t>` allows slicing byte buffers without copying.
// 3. `std::memcpy` safely reads the dimension and floats without breaking strict aliasing.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_33_day038_align_type_punning_fvecs_binary_stream.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <span>
#include <vector>
#include <cstdint>
#include <cstring>
#include <cassert>

int main() {
    std::cout << "--- Drill 33: Binary .fvecs Safe Type Punning ---\n\n";

    constexpr uint32_t D = 4;
    // Buffer layout: [uint32_t D] + [float * 4]
    std::vector<uint8_t> raw_bytes(sizeof(uint32_t) + D * sizeof(float));

    uint32_t dim_out = D;
    float floats_out[4] = {1.0f, 2.0f, 3.0f, 4.0f};
    std::memcpy(raw_bytes.data(), &dim_out, sizeof(uint32_t));
    std::memcpy(raw_bytes.data() + sizeof(uint32_t), floats_out, D * sizeof(float));

    // Zero-copy parse using span
    std::span<const uint8_t> stream(raw_bytes);
    uint32_t dim_in = 0;
    std::memcpy(&dim_in, stream.data(), sizeof(uint32_t));
    assert(dim_in == 4);

    float floats_in[4];
    std::memcpy(floats_in, stream.data() + sizeof(uint32_t), dim_in * sizeof(float));
    assert(floats_in[0] == 1.0f);
    assert(floats_in[3] == 4.0f);

    std::cout << "\n✓ Drill 33 Passed: Binary stream unpacked safely via span & memcpy!\n";
    return 0;
}
