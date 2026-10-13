// ==============================================================================
// 🥋 Drill: Struct Padding & Field Ordering for Cache Efficiency
//
// 📖 READING SOURCES:
// - CS:APP (Ch 3.9.3: Data Alignment)
// - Agner Fog: Optimizing Software in C++ (Ch 7: Data Structures)
//
// 🎯 CORE LESSON:
// 1. Compilers insert padding bytes to satisfy alignment requirements of structure members.
// 2. Ordering fields from largest to smallest eliminates internal padding holes.
// 3. Cache-conscious layout reduces memory footprints by 30-50% in large vector arrays.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_21_day038_align_struct_padding_and_ordering.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <cstddef>
#include <cassert>

// Suboptimal: Interleaved types create padding holes
struct BadLayout {
    char a;     // 1 byte + 7 bytes padding
    double b;   // 8 bytes
    char c;     // 1 byte + 7 bytes padding
};              // Total: 24 bytes

// Optimal: Ordered from largest to smallest alignment
struct GoodLayout {
    double b;   // 8 bytes
    char a;     // 1 byte
    char c;     // 1 byte + 6 bytes tail padding
};              // Total: 16 bytes

int main() {
    std::cout << "--- Drill 21: Struct Padding & Field Ordering ---\n\n";

    std::cout << "sizeof(BadLayout):  " << sizeof(BadLayout) << " bytes\n";
    std::cout << "sizeof(GoodLayout): " << sizeof(GoodLayout) << " bytes\n";

    assert(sizeof(BadLayout) == 24);
    assert(sizeof(GoodLayout) == 16);
    assert(sizeof(GoodLayout) < sizeof(BadLayout));

    std::cout << "\n✓ Drill 21 Passed: Field reordering successfully saved padding memory!\n";
    return 0;
}
