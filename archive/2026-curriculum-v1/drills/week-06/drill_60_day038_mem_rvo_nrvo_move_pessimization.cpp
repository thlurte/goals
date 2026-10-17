// ==============================================================================
// 🥋 Drill: Return Value Optimization (RVO / NRVO) vs Move Pessimization
//
// 📖 READING SOURCES:
// - Meyers: Effective Modern C++ (Item 25: Apply std::move to rvalue references, std::forward to universal references)
// - C++ Standard: Guaranteed Copy Elision (C++17)
//
// 🎯 CORE LESSON:
// 1. C++17 guarantees RVO (copy elision): returning a prvalue constructs the object directly in caller space.
// 2. Writing `return std::move(local);` prevents NRVO (Named Return Value Optimization).
// 3. `return std::move(local);` forces an unnecessary move constructor call instead of zero-overhead elision.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_60_day038_mem_rvo_nrvo_move_pessimization.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <cassert>

static int s_moves = 0;
static int s_copies = 0;

struct HeavyIndex {
    HeavyIndex() = default;
    HeavyIndex(const HeavyIndex&) { s_copies++; }
    HeavyIndex(HeavyIndex&&) noexcept { s_moves++; }
};

// Guaranteed RVO: Zero copies, zero moves!
HeavyIndex create_index_rvo() {
    return HeavyIndex(); // Constructed directly in caller's stack frame!
}

int main() {
    std::cout << "--- Drill 60: RVO / Guaranteed Copy Elision ---\n\n";

    s_moves = 0;
    s_copies = 0;

    HeavyIndex idx = create_index_rvo();
    (void)idx;

    // In C++17/20, RVO is guaranteed: exactly 0 copies and 0 moves!
    assert(s_copies == 0 && "RVO must completely elide copy constructors!");
    assert(s_moves == 0 && "RVO must completely elide move constructors!");

    std::cout << "Copies: " << s_copies << ", Moves: " << s_moves << " (Zero overhead!)\n";
    std::cout << "\n✓ Drill 60 Passed: RVO copy elision confirmed!\n";
    return 0;
}
