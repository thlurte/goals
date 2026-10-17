// ==============================================================================
// 🥋 Drill 02 (Day 31.2): Two's Complement Internals, Overflow Detection &
// Shifts
//
// 📖 READING SOURCES:
// - Agner Fog: Optimizing Software in C++ (Ch 7.2: Integer Operations)
// - CS:APP 3rd Ed: §2.2–2.3 (Integer Arithmetic, Two's Complement, Overflow)
//
// 🎯 CORE LESSON:
// 1. In C++, signed integer overflow (INT32_MAX + 1) is UNDEFINED BEHAVIOR
// (UB).
//    The compiler will optimize away sanity checks like `if (a + b < a)`!
// 2. Pre-condition checking: test limits before adding.
// 3. Shifting signed integers (`int32_t >> 31`) performs ARITHMETIC shift
// (copies MSB sign bit).
// 4. Shifting unsigned integers (`uint32_t >> 31`) performs LOGICAL shift
// (zero-fill).
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra -Wconversion
// drill_02_day031_twos_complement_overflow.cpp -o drill02 && ./drill02
// ==============================================================================

#include <cassert>
#include <cstdint>
#include <iostream>
#include <limits>

// TODO 1: Implement safe signed 32-bit addition overflow check.
// Return true if (a + b) would overflow or underflow int32_t.
// DO NOT perform `a + b` directly on signed ints if it might overflow (UB).
constexpr bool check_signed_add_overflow(int32_t a, int32_t b) {
  // [YOUR CODE HERE]
  // Hint:
  if (b > 0 and a > INT32_MAX - b) {
    return true;
  } else if (b < 0 and a < INT32_MIN - b) {
    return true;
  }
  // If b > 0 and a > INT32_MAX - b -> overflow!
  // If b < 0 and a < INT32_MIN - b -> underflow!
  return false;
}

// TODO 2: Extract the sign bit of an int32_t branchlessly (no if/else).
// Return 1 if negative, 0 if non-negative.
constexpr uint32_t extract_sign_bit_branchless(int32_t x) {
  // [YOUR CODE HERE]
  // Hint: Cast x to uint32_t and shift right by 31.
  return static_cast<uint32_t>(x) >> 31;
}

int main() {
  std::cout
      << "--- Drill 02: Two's Complement & UB-Safe Overflow Detection ---\n\n";

  int32_t max_val = std::numeric_limits<int32_t>::max();
  int32_t min_val = std::numeric_limits<int32_t>::min();

  assert(check_signed_add_overflow(max_val, 1) == true);
  assert(check_signed_add_overflow(max_val, -1) == false);
  assert(check_signed_add_overflow(min_val, -1) == true);
  assert(check_signed_add_overflow(min_val, 1) == false);
  assert(check_signed_add_overflow(100, 200) == false);
  std::cout << "✓ Part 1 Passed: UB-safe signed overflow detection verified!\n";

  assert(extract_sign_bit_branchless(-1) == 1);
  assert(extract_sign_bit_branchless(-5000) == 1);
  assert(extract_sign_bit_branchless(0) == 0);
  assert(extract_sign_bit_branchless(42) == 0);
  assert(extract_sign_bit_branchless(max_val) == 0);
  assert(extract_sign_bit_branchless(min_val) == 1);
  std::cout << "✓ Part 2 Passed: Branchless sign bit extraction verified!\n";

  std::cout << "\n✓ Drill 02 Passed Successfully!\n";
  return 0;
}
