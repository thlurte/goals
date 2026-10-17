// ==============================================================================
// 🥋 Drill: Lifetime Extension of Temporaries: const Ref vs string_view Dangling
//
// 📖 READING SOURCES:
// - C++ Standard: [class.temporary]
// - Meyers: Effective Modern C++ (Item 1: Understand template type deduction)
//
// 🎯 CORE LESSON:
// 1. Binding a temporary to `const T&` extends the temporary's lifetime to the reference's scope.
// 2. Binding a temporary to `std::string_view` or raw pointer does NOT extend lifetime -> **Dangling Pointer**.
// 3. Never initialize a string_view / span from a temporary function return value across expressions.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_59_day038_mem_lifetime_extension_temporaries.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <string>
#include <string_view>
#include <cassert>

std::string get_temporary_index_name() {
    return std::string("ivf_sq8_10m");
}

int main() {
    std::cout << "--- Drill 59: Lifetime Extension Rules ---\n\n";

    // Valid: const std::string& extends the temporary's lifetime to the end of main()!
    const std::string& extended = get_temporary_index_name();
    assert(extended == "ivf_sq8_10m");

    // HAZARD NOTICE:
    // std::string_view dangling = get_temporary_index_name();
    // 'dangling' immediately points to freed memory because string_view is not a reference!

    std::cout << "Lifetime successfully extended for reference: " << extended << "\n";
    std::cout << "\n✓ Drill 59 Passed: Temporary lifetime extension rules verified!\n";
    return 0;
}
