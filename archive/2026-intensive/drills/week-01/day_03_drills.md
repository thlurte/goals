# Week 1, Day 3: Cache Lines, Strides & Memory Hierarchy
> **Date**: Wednesday, October 21, 2026  
> **Rule**: You create and code each `.cpp` file from a completely blank file. No boilerplate is provided.

---

## 📖 Required Reading Before Coding
- **Book**: **[CS:APP]** (Computer Systems: A Programmer's Perspective, 3rd Edition)
- **Section**: **§6.1–§6.4 (pp. 605–645)**. Memory hierarchy, cache memories, spatial & temporal locality, cache-friendly code.
- **Key Concepts to Internalize**:
  - The 64-byte Cache Line: Why modern CPUs fetch 64 contiguous bytes on every load.
  - Spatial locality: Sequential (stride-1) access enables hardware prefetchers.
  - Cache blocking (tiling): Partitioning working data into sub-matrices that fit within L1/L2 cache.

---

## 🎯 Drill 03-A: Row-Major vs Column-Major Cache Stride (`drill_03a_cache_strides.cpp`)

### Problem Statement
Benchmark matrix summation to physically demonstrate the performance impact of spatial locality and CPU cache misses.

### Requirements
1. Allocate a flat 2D matrix of $N \times N$ floats on the heap (e.g. $N = 4096$, size $\approx 67\text{ MB}$, exceeding typical L3 cache sizes).
2. **Phase 1: Row-Major Sum (Stride-1)**:
   - Nested loop: outer `i` (rows 0 to $N-1$), inner `j` (columns 0 to $N-1$).
   - Sum `matrix[i * N + j]`.
   - Measure time using `std::chrono::high_resolution_clock`.
3. **Phase 2: Column-Major Sum (Stride-$N$)**:
   - Inverted nested loop: outer `j` (columns 0 to $N-1$), inner `i` (rows 0 to $N-1$).
   - Sum `matrix[i * N + j]`.
   - Measure time.
4. Calculate speedup factor ($\text{Time}_{\text{col}} / \text{Time}_{\text{row}}$).
5. **Profile with Linux `perf`**:
   ```bash
   perf stat -e L1-dcache-loads,L1-dcache-load-misses,LLC-loads,LLC-load-misses ./drill_03a_cache_strides
   ```
   Document the cache miss percentage difference in a comment at the top of the file.

---

## 🎯 Drill 03-B: Cache-Blocked (Tiled) Matrix Transpose (`drill_03b_cache_blocking.cpp`)

### Problem Statement
Matrix transpose $B[j][i] = A[i][j]$ is inherently cache-hostile because writing/reading columns destroys spatial locality. Implement **cache blocking (tiling)** to keep sub-matrices inside the L1/L2 cache.

### Requirements
1. Allocate square matrix $A$ and transpose output $B$ of dimension $N = 4096$.
2. **Baseline: Naive Transpose**:
   - `for i in 0..N: for j in 0..N: B[j*N + i] = A[i*N + j];`
   - Measure execution time.
3. **Optimized: Blocked Transpose**:
   - Choose tile size $B_{size} = 64$ (fits neatly in L1 data cache).
   - Use 4 nested loops: iterate over blocks of size $B_{size} \times B_{size}$, then transpose elements locally within the block.
   - Measure execution time and calculate speedup (expect 2x to 5x improvement).

---

## 🎯 Drill 03-C: Contiguous Dataset Buffer vs AoS (`drill_03c_contiguous_dataset.cpp`)

### Problem Statement
Vector search engines cannot use `std::vector<std::vector<float>>` or pointer arrays because pointer chasing causes massive cache misses. Benchmark memory layout performance for 100,000 vectors of dimension 128.

### Requirements
1. **Layout A (Array of Pointers / AoS)**:
   - `std::vector<std::vector<float>> dataset_aos;`
   - Compute inner product of a query vector against all 100,000 vectors.
2. **Layout B (Flat 64-byte Aligned Contiguous Buffer)**:
   - Single contiguous buffer: `float* flat_data` of size $100000 \times 128$.
   - Aligned to 64 bytes (`alignas(64)` / `posix_memalign`).
   - Compute inner product using flat index arithmetic `flat_data + i * dim`.
3. Compare throughput (queries/sec or total scan latency).

---

## 🛠️ Deliberate `secan` Task
- Implement `secan/include/secan/common/dataset.hpp`.
- Define `Dataset` class managing flat, 64-byte aligned contiguous memory for vectors, supporting `dim()`, `num_vectors()`, and `get_vector(size_t i)`.
