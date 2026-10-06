# 🛠️ Open-Source Systems Contribution Pipeline

> **Rule**: Resolve & submit **1 open-source issue per day** alongside core curriculum work.
> **Target Domains**: Vector Search Engines, Low-Level SIMD Kernels, Numerical Precision, Memory Alignment, and Quantization.

---

## 🏆 Resolved / Active PRs

| Date | Repo | PR / Issue | Title | Status | Impact |
|:---|:---|:---|:---|:---|:---|
| **2026-09-18** | `facebookresearch/faiss` | [PR #5654](https://github.com/facebookresearch/faiss/pull/5654) (Fixes [#5576](https://github.com/facebookresearch/faiss/issues/5576)) | `fix(IndexFlat1D): keep sorted permutation valid across remove_ids and merge_from` | **CLA Signed / In Review** ✅ | Prevents crash in `IndexFlat1D.search()` after deletions/merges; added C++ GTests + Python tests. |
| **2026-09-18** | `ashvardanian/NumKong` | [PR #385](https://github.com/ashvardanian/NumKong/pull/385) (Fixes [#384](https://github.com/ashvardanian/NumKong/issues/384)) | `fix(scalar): propagate NaN on Euclidean overflow instead of zero` | **In Review** 🚀 | Fixes Euclidean distance returning 0.0 on overflow across f64/bf16; aligns serial fallback with hardware SIMD. |

---

## 🎯 Daily Resolution Queue (Prioritized)

### Day 1: USearch — Cosine Norm Caching
* **Target Repo**: [`unum-cloud/USearch`](https://github.com/unum-cloud/USearch)
* **Issue**: [USearch#786: Feature: Cache member norms for built-in cosine search](https://github.com/unum-cloud/USearch/issues/786)
* **Domain**: Mathematical optimization & Memory layout
* **Core Problem**: On every candidate comparison during graph traversal, USearch computes the $L_2$ norm of the candidate vector on the fly. Because index vectors are immutable, pre-calculating and caching vector norms turns 3 memory passes into 1 dot product + 1 scalar multiply:
  $$\text{Cosine}(q, v) = 1.0 - \frac{q \cdot v}{\|q\| \cdot \text{CachedNorm}(v)}$$
* **Action**: Add cached norm storage to the index layout and update the cosine search loop.

---

### Day 2: SimSIMD / NumKong — Euclidean Overflow Return
* **Target Repo**: [`ashvardanian/simsimd`](https://github.com/ashvardanian/simsimd) (NumKong)
* **Issue**: [SimSIMD#384: Bug: Serial Euclidean distance returns zero after floating-point overflow](https://github.com/ashvardanian/NumKong/issues/384)
* **Domain**: IEEE 754 Floating-Point & Numerical Stability
* **Core Problem**: When coordinates are large ($10^{154}$ in double, $10^{19}$ in BF16), intermediate squaring overflows to $+\infty$, but subsequent operations collapse to `0.0`. This causes very distant vectors to report distance 0 (identical match), corrupting nearest-neighbor rankings.
* **Action**: Ensure overflowed intermediates saturate to `+inf` instead of collapsing to zero.

---

### Day 3: Qdrant — Cosine Bound Clamping (1.0 Upper Bound)
* **Target Repo**: [`qdrant/qdrant`](https://github.com/qdrant/qdrant)
* **Issue**: [Qdrant#8688: Cosine similarity score strictly exceeds upper bound of 1.0](https://github.com/qdrant/qdrant/issues/8688)
* **Domain**: Numerical precision & Contract invariants
* **Core Problem**: After normalizing vectors and computing the dot product via AVX/NEON FMA, rounding error causes identical vectors to yield `1.00000012`. Strict downstream client assertions (`assert score <= 1.0`) fail.
* **Action**: Enforce numerical clamp `score.min(1.0).max(-1.0)` in score conversion before serialization.

---

### Day 4: Alibaba ZVec — ARM64 NEON INT8 Distance Kernel
* **Target Repo**: [`alibaba/zvec`](https://github.com/alibaba/zvec)
* **Issue**: [zvec#719: [Performance][ARM64] ZVec Flat INT8 search is ~2-4x slower than FP32](https://github.com/alibaba/zvec/issues/719)
* **Domain**: ARM NEON SIMD (`sdot`/`udot`)
* **Core Problem**: On Apple Silicon / ARM64, Flat FP32 search is accelerated by NEON, but Flat INT8 lacks a NEON kernel, falling back to a slow scalar loop and causing a 2–4× search throughput regression.
* **Action**: Implement ARM64 NEON dot product kernel for INT8 distance using `vdotq_s32`.

---

### Day 5: Qdrant — FP16 Accumulator Widening on NEON
* **Target Repo**: [`qdrant/qdrant`](https://github.com/qdrant/qdrant)
* **Issue**: [Qdrant#10350: f16 vectors: NEON Euclid/Dot/Manhattan accumulate in float16](https://github.com/qdrant/qdrant/issues/10350)
* **Domain**: SIMD Register Dynamic Range
* **Core Problem**: FP16 accumulators cap at 65,504. For 1536-D embeddings, the sum of squares overflows to `inf`/`null`.
* **Action**: Widen accumulation to `float32x4_t` using `vfmlalq_low_f16` / `vfmlalq_high_f16` under ARMv8.2-A `+fp16fml`.

---

### Day 6: Alibaba ZVec — Turbo AVX2/AVX-512 Distance Dispatch
* **Target Repo**: [`alibaba/zvec`](https://github.com/alibaba/zvec)
* **Issue**: [zvec#706: Add AVX2/AVX512 SIMD Kernels for Distance in Turbo](https://github.com/alibaba/zvec/issues/706)
* **Domain**: Multi-ISA SIMD kernels & CPUID dispatch
* **Core Problem**: ZVec's `Turbo` index lacks AVX2 and AVX-512 kernels for `SquaredEuclidean`, `InnerProduct`, and `Cosine`.
* **Action**: Register unrolled AVX2/AVX-512 kernels into Turbo's `KernelSet kKernelTable[]` dispatch table.
