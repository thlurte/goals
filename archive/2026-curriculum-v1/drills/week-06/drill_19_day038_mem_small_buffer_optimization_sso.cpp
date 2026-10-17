// ==============================================================================
// 🥋 Drill: Small Buffer Optimization (SBO / SSO) Mechanics
//
// 📖 READING SOURCES:
// - Meyers: Effective Modern C++ (Ch 4: Smart Pointers)
// - Folly: FBString implementation notes
//
// 🎯 CORE LESSON:
// 1. SSO keeps small payloads in an inline stack buffer, avoiding expensive heap allocation.
// 2. When the payload exceeds the small buffer capacity, it dynamically transitions to the heap.
// 3. Modern `std::string` and vector engines rely heavily on SSO for short strings/lists.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_19_day038_mem_small_buffer_optimization_sso.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <cstring>
#include <cassert>

class SmallString {
    static constexpr size_t SBO_CAPACITY = 16;
public:
    SmallString() : size_(0), is_small_(true) { sbo_[0] = '\0'; }

    explicit SmallString(const char* str) {
        size_ = std::strlen(str);
        if (size_ < SBO_CAPACITY) {
            is_small_ = true;
            std::memcpy(sbo_, str, size_ + 1);
        } else {
            is_small_ = false;
            heap_ = new char[size_ + 1];
            std::memcpy(heap_, str, size_ + 1);
        }
    }

    ~SmallString() noexcept {
        if (!is_small_) delete[] heap_;
    }

    bool is_small() const noexcept { return is_small_; }
    const char* c_str() const noexcept { return is_small_ ? sbo_ : heap_; }

private:
    size_t size_;
    bool is_small_;
    union {
        char sbo_[SBO_CAPACITY];
        char* heap_;
    };
};

int main() {
    std::cout << "--- Drill 19: Small Buffer Optimization (SSO) ---\n\n";

    SmallString short_str("hello_world");
    assert(short_str.is_small() == true && "Short string must reside inline!");
    assert(std::strcmp(short_str.c_str(), "hello_world") == 0);

    SmallString long_str("this_is_a_very_long_string_exceeding_capacity");
    assert(long_str.is_small() == false && "Long string must allocate on heap!");
    assert(std::strcmp(long_str.c_str(), "this_is_a_very_long_string_exceeding_capacity") == 0);

    std::cout << "\n✓ Drill 19 Passed: SSO inline-vs-heap transition operational!\n";
    return 0;
}
