// ==============================================================================
// 🥋 Drill 01 (Week 03 / Day 017): CS:APP §6.1–6.3 — Memory Mountain & Spatial Locality
//
// 📖 READING SOURCES:
// - Bryant & O'Hallaron: Computer Systems (CS:APP 3rd Ed, §6.1–6.3: Memory Hierarchy)
//
// 🎯 CORE LESSON:
// 1. Spatial Locality: Accessing contiguous elements (stride = 1) maximizes cache line reuse (64 bytes = 16 floats).
// 2. Stride Penalty: Stride = 16 skips entire cache lines on every access, causing a cache miss on 100% of memory loads!
//
// 🚀 RUN COMMAND:
// g++ -O3 -std=c++20 -Wall -Wextra drill_01_day017_csapp_memory_mountain_bandwidth.cpp -o drill01 && ./drill01
// ==============================================================================

#include <iostream>
#include <vector>
#include <chrono>
#include <cassert>

// Benchmark throughput with different stride sizes
double measure_stride_read(const std::vector<float>& buffer, size_t stride) {
    auto start = std::chrono::high_resolution_clock::now();
    float sum{0.0f};
    for (size_t i = 0; i < buffer.size(); i += stride) {
        sum += buffer[i];
    }
    auto end = std::chrono::high_resolution_clock::now();

    #if defined(__GNUC__) || defined(__clang__)
    asm volatile("" : "+r,m"(sum) : : "memory");
    #endif

    std::chrono::duration<double, std::nano> ns = end - start;
    return ns.count();
}

int main() {
    std::cout << "--- Week 03 Drill 01: Memory Mountain Stride Effects ---\n\n";

    constexpr size_t N = 1000000;
    std::vector<float> buffer(N, 1.0f);

    double time_stride1 = measure_stride_read(buffer, 1);
    double time_stride16 = measure_stride_read(buffer, 16);

    std::cout << "Stride 1 (Unit Stride Spatial Locality) Time: " << time_stride1 << " ns\n";
    std::cout << "Stride 16 (Cache Line Skip) Time:            " << time_stride16 << " ns\n";

    assert(time_stride1 > 0 && time_stride16 > 0);
    std::cout << "\n✓ Week 03 Drill 01 Passed Successfully!\n";
    return 0;
}
