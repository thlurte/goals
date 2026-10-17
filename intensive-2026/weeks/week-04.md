# Week 4: Vector Quantization (SQ8, PQ, Asymmetric Distance)
> **Dates**: November 9 – November 15, 2026  
> **Core Focus**: Vector compression (4x–16x reduction), scalar quantization (SQ8), product quantization (PQ), k-means codebook training, and Asymmetric Distance Computation (ADC).

---

### Day 22 (Mon, Nov 9): Scalar Quantization (SQ8) Encoding
- 📖 **Reading**: Linear Affine Scalar Quantization: Mapping FP32 to `uint8_t`: $x_q = \text{round}\left(\frac{x - \min}{\max - \min} \times 255\right)$.
- 💻 **Drills (`day_22_drills.md`)**:
  1. `drill_22a_scalar_quantizer_encode.cpp`: Implement `SQ8Quantizer`: computes global min/max across dataset, serializes FP32 vectors to `uint8_t` buffers.
  2. `drill_22b_quantization_error_mse.cpp`: Implement dequantizer and calculate Mean Squared Error (MSE) loss per vector.
  3. `drill_22c_outlier_clipping.cpp`: Implement percentile clipping (e.g. 99.9% clipping) to prevent extreme outliers from crushing the 8-bit dynamic range.
- 🛠️ **`secan`**: Implement `secan/include/secan/quantization/scalar_quantizer.hpp`.

---

### Day 23 (Tue, Nov 10): Fast Integer Distance on SQ8 Codes
- 📖 **Reading**: Symmetric vs Asymmetric SQ8 Distance Math.
- 💻 **Drills (`day_23_drills.md`)**:
  1. `drill_23a_sq8_symmetric_distance.cpp`: Compute L2 distance directly on `uint8_t` codes by accumulating $(u_i - v_i)^2$ in 16-bit integers and scaling back at the end.
  2. `drill_23b_sq8_asymmetric_distance.cpp`: FP32 Query against SQ8 Vector: $dist(Q, V_q) \approx \sum (Q_i - (V_{q,i} \cdot scale + min))^2$.
  3. `drill_23c_sq8_throughput_benchmark.cpp`: Benchmark SQ8 vs FP32 throughput and memory footprint on 1,000,000 vectors.
- 🛠️ **`secan`**: Wire SQ8 distance kernels into `secan` index storage.

---

### Day 24 (Wed, Nov 11): Product Quantization (PQ) Space Decomposition
- 📖 **Reading**: **[Jégou et al. (2011)]** — **Sections 1–3** ("Product Quantization for Nearest Neighbor Search"). Subspace decomposition and codebook geometry.
- 💻 **Drills (`day_24_drills.md`)**:
  1. `drill_24a_subvector_slicing.cpp`: Decompose a $D=128$ float vector into $M=8$ subvectors of dimension $D^*=16$. Verify slice memory layouts.
  2. `drill_24b_codebook_storage.cpp`: Implement `CodebookStorage`: array of shape $(M, K, D^*)$ where $K=256$ centroids. Align centroids to 64 bytes for fast SIMD evaluation.
  3. `drill_24c_pq_code_packing.cpp`: Store compressed vectors as an array of $M$ bytes (`uint8_t codes[M]`). For $M=8$, compress a 512-byte vector down to 8 bytes (**64x compression**).
- 🛠️ **`secan`**: Scaffold `secan/include/secan/quantization/product_quantizer.hpp`.

---

### Day 25 (Thu, Nov 12): Subspace k-Means Codebook Training
- 📖 **Reading**: Lloyd's Algorithm for vector quantization: Centroid initialization, assignment step, update step.
- 💻 **Drills (`day_25_drills.md`)**:
  1. `drill_25a_mini_kmeans.cpp`: Implement single-threaded k-means in C++ to train $K=256$ centroids on $N=10,000$ subvectors ($D^*=16$).
  2. `drill_25b_parallel_kmeans.cpp`: Parallelize the centroid assignment step using your `ThreadPool`.
  3. `drill_25c_centroid_reassignment.cpp`: Handle empty clusters by re-seeding centroids to furthest outliers.
- 🛠️ **`secan`**: Implement codebook training loop in `secan`.

---

### Day 26 (Fri, Nov 13): Asymmetric Distance Computation (ADC) & Lookup Tables
- 📖 **Reading**: **[Jégou et al. (2011)]** — **Section 4** ("Asymmetric Distance Computation - ADC").
- 💻 **Drills (`day_26_drills.md`)**:
  1. `drill_26a_adc_lut_generation.cpp`: Given an uncompressed FP32 query vector, precalculate distances to all $K=256$ centroids across all $M=8$ subvectors into a table of size $M \times K$ ($8 \times 256$ floats).
  2. `drill_26b_adc_distance_scoring.cpp`: Compute distance between query and a PQ-compressed vector via $M$ byte lookups and additions: $\sum_{m=0}^{M-1} LUT[m][codes[m]]$.
  3. `drill_26c_adc_benchmark.cpp`: Benchmark ADC distance calculation. Show it takes $< 5$ nanoseconds per vector pair.
- 🛠️ **`secan`**: Implement fast ADC evaluation in `secan`.

---

### Day 27 (Sat, Nov 14): Accuracy & Recall Evaluation
- 💻 **Drills (`day_27_drills.md`)**:
  1. `drill_27a_recall_at_k.cpp`: Implement ground-truth evaluation: compute Recall@10 and Recall@100 of Flat, SQ8, and PQ on synthetic 10,000 vectors.
  2. `drill_27b_quantization_memory_profiling.cpp`: Print a clean memory table comparing RAM usage for 1M vectors across FP32 (512 MB), SQ8 (128 MB), and PQ8 (8 MB).
  3. `drill_27c_sq8_vs_pq_tradeoff.cpp`: Plot / print the Pareto frontier of Recall vs QPS vs Memory.
- 🛠️ **`secan`**: Add accuracy benchmark harness to `secan/benchmarks/`.

---

### Day 28 (Sun, Nov 15): Timed Quantization Exam (No Notes)
- ⏱️ **45-minute timed coding exam**: Write the ADC Lookup Table generator and scoring loop from a blank file with zero compiler warnings.
