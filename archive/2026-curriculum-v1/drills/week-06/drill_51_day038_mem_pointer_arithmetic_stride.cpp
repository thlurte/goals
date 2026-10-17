// ==============================================================================
// 🥋 Drill: Pointer Arithmetic & Stride Calculation: char* vs T*
//
// 📖 READING SOURCES:
// - CS:APP (Ch 3.8: Array Allocation and Access)
// - Stroustrup: The C++ Programming Language (Ch 7: Pointers and Arrays)
//
// 🎯 CORE LESSON:
// 1. Pointer arithmetic `ptr + 1` advances by `sizeof(T)` bytes, NOT 1 byte.
// 2. Casting to `char*` or `uint8_t*` enables single-byte offset stepping for serialization.
// 3. Pointer difference `ptr2 - ptr1` yields the number of elements of type `T`, not byte difference.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_51_day038_mem_pointer_arithmetic_stride.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <cstdint>
#include <cassert>

struct Embedding {
    float vec[8]; // 32 bytes
    int64_t id;   // 8 bytes (8-byte alignment)
};                // Total: 40 bytes

int main() {
    std::cout << "--- Drill 51: Pointer Arithmetic & Stride Calculation ---\n\n";

    Embedding arr[3];
    Embedding* p_emb = arr;
    uint8_t* p_byte = reinterpret_cast<uint8_t*>(arr);

    // Advancing Embedding* by 1 advances by sizeof(Embedding)
    assert(sizeof(Embedding) == 40);
    assert(reinterpret_cast<uintptr_t>(p_emb + 1) - reinterpret_cast<uintptr_t>(p_emb) == 40);

    // Advancing uint8_t* by 40 matches p_emb + 1
    assert(reinterpret_cast<uintptr_t>(p_byte + 40) == reinterpret_cast<uintptr_t>(p_emb + 1));

    // Element distance
    assert((&arr[2] - &arr[0]) == 2);

    std::cout << "Pointer stride verified: sizeof(Embedding)=" << sizeof(Embedding) << " bytes.\n";
    std::cout << "\n✓ Drill 51 Passed: Pointer arithmetic stride verified!\n";
    return 0;
}
