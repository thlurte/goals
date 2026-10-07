# 🥋 Daily Systems, Engines & Deep Learning Drills

Targeted, hands-on micro-drills designed to build instinctual engineering reflexes across:
1. **🌙 `secan` Vector Search Engine (C++20/SIMD)**: Quantization (SQ8/SQ4/PQ/BQ), AVX2 integer dot products, cache alignment (`alignas(64)`), zero-allocation `std::span` views, inverted indexing (IVF), and POPCNT Hamming distance.
2. **🌙 `cennan` Neural Engine (C++20)**: N-D contiguous tensor strides, manual analytical backward passes (Linear/ReLU/Loss), and C++ Directed Acyclic Graph (DAG) reverse-mode automatic differentiation.
3. **☀️ Morning Builder Track (Python/PyTorch from scratch)**: Scalar computational graph engine (Micrograd), Rotary Position Embeddings (RoPE), Vision Transformer (ViT) patch projections, custom AdamW optimizer with decoupled weight decay, and InfoNCE in-batch contrastive loss.

---

## 📁 Weekly Drill Suites

All drills are organized into self-contained weekly directories matching the master curriculum:

* **[`week-01/`](week-01/)** (17 Drills): Information Theory, Amdahl's Law, Numerical Differentiation, Benchmarking DCE (`asm volatile`), Pointer Aliasing (`__restrict__`), Binary `.fvecs` I/O, IR Metrics (MRR/Recall), Fast `rsqrt`, PMU IPC profiling, SDPA, Stable Softmax, and MHA.
* **[`week-02/`](week-02/)** (9 Drills): Agner Fog FTZ/DAZ Denormal Traps, AVX2 8-Lane L2 Distance, CS:APP 4-Way Parallel Accumulators, Fused 1-Pass Cosine Distance, `alignas(64)` Alignment, AVX-512 vs AVX2 Registers, Grouped-Query Attention (GQA), Pre-LN vs Post-LN, and Mask-Aware Mean Pooling.
* **[`week-03/`](week-03/)** (8 Drills): CS:APP Memory Mountain, 256KB L2 Cache Tiling, Software Prefetching (`_mm_prefetch`), Offline Unit-Sphere Pre-Normalization, FLANN Randomized KD-Trees, Linux `madvise(MADV_HUGEPAGE)`, Micrograd Autograd, and Manual Linear Backprop.
* **[`week-04/`](week-04/)** (12 Drills): Cache Coherence & False Sharing (`alignas(64)`), Batch Linear Scan (GEMM), Spherical $k$-Means, Multi-Probe IVF Routing, Pinned `std::jthread` Workers, IVF List Skew Rebalancing, Bounded Max-Heap Top-K, Zero-Copy `mmap` Tensors, `cennan` RMSNorm, RoPE, Custom SGD Momentum, and KV-Cache.
* **[`week-05/`](week-05/)** (16 Drills): N-D Tensor Strides & Offsets, Two's Complement UB-Safe Overflow, H&P AMAT Calculator, AVX2 Integer Dot (`_mm256_madd_epi16`), Saturated Subtraction (`_mm256_subs_epu8`), CS:APP Dual Accumulators, Jégou PQ Asymmetric Distance (ADC), In-Place Activations (GELU/SiLU/SwiGLU), IEEE 754 `std::bit_cast`, SQ4 4-Bit Packing, Two-Stage Re-ranker, `std::span` Register ABI, Kahan Summation, SQ8 Percentile Clipping, and ViT Transformer Blocks.
* **[`week-06/`](week-06/)** (8 Drills): Analytical Linear Backward, Custom AdamW from Scratch, Subspace $k$-Means, InfoNCE Contrastive Loss, C++ DAG Autograd Engine, Product Quantization ADC Unrolling, 1-Bit Binary Quantization (POPCNT), and Composed IVF-PQ Scans.

---

## 💡 How to Practice & Verify

### 1. Compile and Run C++ Drills
All C++ drills are self-contained and run under strict modern compiler flags:
```bash
cd week-05
g++ -O3 -march=native -mavx2 -mfma -std=c++20 -Wall -Wextra -Wconversion drill_04_day032_avx2_integer_dot.cpp -o drill04 && ./drill04
```

### 2. Run Python Deep Learning Drills
```bash
cd week-01
python3 drill_13_day004_sdpa_attention_from_scratch.py
```

### 3. Reference Solutions
Working reference implementations are stored in [`solutions/`](solutions/).
