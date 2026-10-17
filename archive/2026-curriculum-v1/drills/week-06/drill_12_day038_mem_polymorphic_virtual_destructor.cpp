// ==============================================================================
// 🥋 Drill: Polymorphic Virtual Destructors in Base Classes
//
// 📖 READING SOURCES:
// - Meyers: Effective C++ (Item 7: Declare destructors virtual in polymorphic base classes)
// - C++ Core Guidelines: C.127 (A class with a virtual function should have a virtual or protected destructor)
//
// 🎯 CORE LESSON:
// 1. Deleting a derived object through a `Base*` without a virtual destructor is undefined behavior.
// 2. A non-virtual destructor skips the derived class destructor, causing memory and resource leaks.
// 3. Always declare `virtual ~Base() = default;` when polymorphic inheritance is used.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -mavx2 -pthread -Wall -Wextra drill_12_day038_mem_polymorphic_virtual_destructor.cpp -o drill && ./drill
// ==============================================================================

#include <iostream>
#include <memory>
#include <cstdint>
#include <cassert>

static int s_derived_destructed_count = 0;

class BaseQuantizer {
public:
    virtual ~BaseQuantizer() = default; // Essential virtual destructor!
    virtual int bits() const = 0;
};

class SQ8Quantizer : public BaseQuantizer {
public:
    SQ8Quantizer() : buffer_(new uint8_t[256]) {}
    ~SQ8Quantizer() override {
        delete[] buffer_;
        s_derived_destructed_count++;
    }

    int bits() const override { return 8; }

private:
    uint8_t* buffer_;
};

int main() {
    std::cout << "--- Drill 12: Polymorphic Virtual Destructor ---\n\n";

    {
        std::unique_ptr<BaseQuantizer> q = std::make_unique<SQ8Quantizer>();
        assert(q->bits() == 8);
    } // Virtual destructor guarantees ~SQ8Quantizer() is called

    assert(s_derived_destructed_count == 1 && "Derived destructor must have executed!");
    std::cout << "\n✓ Drill 12 Passed: Virtual destructor ensured derived cleanup!\n";
    return 0;
}
