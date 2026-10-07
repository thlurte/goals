// ==============================================================================
// 🥋 Drill 12 (Week 04 / Day 028): `cennan` Core — Zero-Copy `mmap` Tensor Loader
//
// 📖 READING SOURCES:
// - `cennan/include/cennan/core/io.h`
//
// 🎯 CORE LESSON:
// 1. Zero-Copy Tensor Slicing:
//    Using POSIX `mmap()` maps binary weight files directly into process address space.
// 2. Non-owning `std::span<const float>` avoids copying megabytes/gigabytes of weights into RAM heap.
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra drill_12_day028_zero_copy_mmap_tensor.cpp -o drill12 && ./drill12
// ==============================================================================

#include <iostream>
#include <span>
#include <vector>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <cassert>

struct MmapTensorView {
    const float* data{nullptr};
    size_t num_elements{0};

    std::span<const float> span() const {
        return {data, num_elements};
    }
};

int main() {
    std::cout << "--- Week 04 Drill 12: Zero-Copy mmap Tensor Mapping ---\n\n";

    // Allocate anonymous memory mapping simulating memory-mapped tensor
    size_t num_floats = 1024;
    size_t size_bytes = num_floats * sizeof(float);

    void* mapped = mmap(
        nullptr, size_bytes,
        PROT_READ | PROT_WRITE,
        MAP_PRIVATE | MAP_ANONYMOUS,
        -1, 0
    );
    assert(mapped != MAP_FAILED);

    float* floats = static_cast<float*>(mapped);
    for (size_t i = 0; i < num_floats; ++i) floats[i] = static_cast<float>(i);

    MmapTensorView view{floats, num_floats};
    auto tensor_span = view.span();

    std::cout << "Mapped Tensor Size: " << tensor_span.size() << " elements\n";
    std::cout << "Element at index 42: " << tensor_span[42] << " (Expected: 42.0)\n";

    assert(tensor_span.size() == num_floats);
    assert(tensor_span[42] == 42.0f);

    munmap(mapped, size_bytes);
    std::cout << "\n✓ Week 04 Drill 12 Passed Successfully!\n";
    return 0;
}
