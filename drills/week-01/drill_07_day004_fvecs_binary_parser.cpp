// ==============================================================================
// 🥋 Drill 07 (Week 01 / Day 004): `secan` — Binary `.fvecs` Format Parser
//
// 📖 READING SOURCES:
// - Texmex Dataset Format Standard (`.fvecs` / `.ivecs` / `.bvecs`)
// - `secan/include/secan/utils/io.h`
//
// 🎯 CORE LESSON:
// 1. `.fvecs` Binary File Layout:
//    Each vector starts with a 4-byte little-endian integer specifying the dimension $D$,
//    followed immediately by $D$ contiguous 32-bit IEEE 754 floats ($D \times 4$ bytes).
//    Vector size in bytes = 4 + (D * 4).
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra drill_07_day004_fvecs_binary_parser.cpp -o drill07 && ./drill07
// ==============================================================================

#include <iostream>
#include <vector>
#include <cstring>
#include <cstdint>
#include <cassert>

struct FvecsParser {
    // TODO 1: Parse an in-memory .fvecs binary buffer into vector of vectors
    // buffer contains N vectors, each formatted as: [int32_t dim][float x_0][float x_1]...[float x_{dim-1}]
    static std::vector<std::vector<float>> parse_memory(const uint8_t* data, size_t total_bytes) {
        std::vector<std::vector<float>> result;
        size_t offset{0};

        while (offset + sizeof(int32_t) <= total_bytes) {
            int32_t dim{0};
            std::memcpy(&dim, data + offset, sizeof(int32_t));
            offset += sizeof(int32_t);

            if (dim <= 0) break;
            size_t vector_bytes = static_cast<size_t>(dim) * sizeof(float);
            if (offset + vector_bytes > total_bytes) break;

            std::vector<float> vec(static_cast<size_t>(dim));
            std::memcpy(vec.data(), data + offset, vector_bytes);
            offset += vector_bytes;

            result.push_back(std::move(vec));
        }
        return result;
    }
};

int main() {
    std::cout << "--- Week 01 Drill 07: Binary .fvecs Format Parser ---\n\n";

    // Synthetic .fvecs binary stream: 2 vectors of dimension D=3
    // Vector 0: [3, 1.0f, 2.0f, 3.0f]
    // Vector 1: [3, 4.0f, 5.0f, 6.0f]
    std::vector<uint8_t> buffer;
    auto append_vector = [&](int32_t dim, const std::vector<float>& vals) {
        uint8_t dim_bytes[4];
        std::memcpy(dim_bytes, &dim, 4);
        buffer.insert(buffer.end(), dim_bytes, dim_bytes + 4);
        const uint8_t* fbytes = reinterpret_cast<const uint8_t*>(vals.data());
        buffer.insert(buffer.end(), fbytes, fbytes + vals.size() * sizeof(float));
    };

    append_vector(3, {1.0f, 2.0f, 3.0f});
    append_vector(3, {4.0f, 5.0f, 6.0f});

    auto parsed = FvecsParser::parse_memory(buffer.data(), buffer.size());

    std::cout << "Parsed Vectors Count: " << parsed.size() << " (Expected: 2)\n";
    assert(parsed.size() == 2);
    assert(parsed[0].size() == 3);
    assert(parsed[0][0] == 1.0f && parsed[0][2] == 3.0f);
    assert(parsed[1][0] == 4.0f && parsed[1][2] == 6.0f);

    std::cout << "\n✓ Week 01 Drill 07 Passed Successfully!\n";
    return 0;
}
