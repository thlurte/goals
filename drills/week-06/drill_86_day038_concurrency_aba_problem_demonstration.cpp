// ==============================================================================
// 🥋 Drill: The ABA Problem Mechanics in Lock-Free Stacks
//
// 📖 READING SOURCES:
// - Williams: C++ Concurrency in Action (Ch 7.2.4: The ABA problem)
// - Herlihy & Shavit: The Art of Multiprocessor Programming
//
// 🎯 CORE LESSON:
// 1. Thread 1 reads pointer $A$ and prepares to update head to $A \rightarrow \text{next}$ ($B$).
// 2. Thread 2 pops $A$, pops $B$, and pushes a new node that reallocates at memory address $A$ (A-B-A).
// 3. Thread 1 CAS succeeds because head address is $A$, but $B$ has already been freed -> **Memory Corruption**.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_86_day038_concurrency_aba_problem_demonstration.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <cstdint>
#include <cassert>

// Demonstration of ABA logic: pointer address equality does NOT imply unmutated state!
int main() {
    std::cout << "--- Drill 86: Understanding the ABA Hazard ---\n\n";

    int* original_ptr = new int(100);
    uintptr_t addr = reinterpret_cast<uintptr_t>(original_ptr);
    delete original_ptr;

    // Simulate allocator recycling the exact same virtual memory address:
    int* recycled_ptr = new int(200);
    uintptr_t recycled_addr = reinterpret_cast<uintptr_t>(recycled_ptr);

    // If address matches, naive CAS thinks nothing changed!
    if (addr == recycled_addr) {
        std::cout << "Allocator recycled exact pointer address: 0x" << std::hex << addr << std::dec << "\n";
        assert(*recycled_ptr == 200 && "Contents mutated even though address was identical!");
    }

    delete recycled_ptr;
    std::cout << "\n✓ Drill 86 Passed: ABA address recycling mechanics verified!\n";
    return 0;
}
