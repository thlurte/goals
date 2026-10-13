// ==============================================================================
// 🥋 Drill: Custom Deleter for C APIs (FILE* RAII Management)
//
// 📖 READING SOURCES:
// - Meyers: Effective Modern C++ (Item 18: Custom deleters in std::unique_ptr)
// - Stroustrup: A Tour of C++ (Ch 5: Essential Operations)
//
// 🎯 CORE LESSON:
// 1. `std::unique_ptr<T, Deleter>` accepts a custom functor or function pointer to release resources.
// 2. C APIs like `FILE*` require `fclose` rather than `delete`.
// 3. A stateless functor deleter introduces zero memory overhead compared to a raw pointer.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_06_day038_mem_unique_ptr_custom_deleter_c_file.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <memory>
#include <cstdio>
#include <cassert>

struct FileCloser {
    void operator()(FILE* fp) const noexcept {
        if (fp) {
            std::cout << "[FileCloser] Automatically closing file\n";
            std::fclose(fp);
        }
    }
};

using UniqueFile = std::unique_ptr<FILE, FileCloser>;

UniqueFile open_temp_file() {
    FILE* fp = std::tmpfile();
    return UniqueFile(fp);
}

int main() {
    std::cout << "--- Drill 06: std::unique_ptr Custom Deleter ---\n\n";

    {
        UniqueFile file = open_temp_file();
        assert(file != nullptr);
        std::fputs("Testing RAII File Wrapper\n", file.get());
        std::rewind(file.get());

        char buffer[64] = {0};
        char* res = std::fgets(buffer, sizeof(buffer), file.get());
        assert(res != nullptr);
        std::cout << "Read from temp file: " << buffer;
    } // File automatically closed here by FileCloser

    std::cout << "\n✓ Drill 06 Passed: Custom deleter safely closed C file handle!\n";
    return 0;
}
