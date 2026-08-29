# Vector Search Engine & AI Systems Specialization

> **A 24-Week (6-Month) Deep Curriculum in Mathematical Foundations, High-Dimensional Analytics, Database Storage Engines, C++20/CUDA Systems Engineering, and Modern Transformers.**

---

## 📂 Curriculum Documents

1. [**24-Week Master Daily Curriculum**](vector_search_24_week_daily_plan.md)
   * The complete day-by-day reading and coding schedule (Mon–Fri).
   * Synchronized across **Linear Algebra (Strang)**, **C++20/CUDA Engine (`secan`)**, and **PyTorch Models (Transformers, ViT, BERT, ColBERT, ColPali)**.
   * 24 long-form technical essay assignments.
   * Integrates **High-D Analytics (Hubness/Measure Concentration)**, **ScaNN Anisotropic Loss**, **IR Metrics (NDCG/MRR/SLA)**, **LSM-Tree Storage Engine (Arrow/WAL)**, and **FlashAttention CUDA Kernel**.

2. [**Specialization Architecture & Macro Roadmap**](vector_search_specialization_roadmap.md)
   * High-level architectural phases, evaluation benchmarks, and systems design principles.

---

## 🏛️ The Three Pillars

```
 ┌──────────────────────────────────────────────────────────────────────────────────────────────────┐
 │                               PILLAR 1: MATHEMATICS & HIGH-D ANALYTICS                           │
 │ • Gilbert Strang's Linear Algebra (Vector Spaces, Orthogonality, QR, SVD, Eigenvalues, Graphs)   │
 │ • High-D Geometry: Measure Concentration, Curse of Dimensionality, Hubness & Anisotropic Cones   │
 │ • ScaNN Theory: Anisotropic Vector Quantization Loss (Directional Error Weighting for MIPS)      │
 │ • IR Analytics: NDCG@K, MRR, MAP, and Poisson Process p95/p99 Tail Latency Queueing Theory       │
 └────────────────────────┬─────────────────────────────────────────┬───────────────────────────────┘
                          │                                         │
                          ▼                                         ▼
 ┌────────────────────────────────────────┐     ┌───────────────────────────────────────────────────┐
 │      PILLAR 2: DEEP LEARNING (Py)      │     │      PILLAR 3: DATABASE & C++/GPU ENGINE (secan)  │
 │ • Transformers from Scratch            │     │ • Storage Engine: LSM-Tree, WAL, MemTable, Segs   │
 │ • Online Softmax & FlashAttention-1/2  │────►│ • Columnar Formats: Zero-Copy Apache Arrow Layout │
 │ • Vision Transformer (ViT)             │     │ • Handcrafted SIMD: AVX2, AVX-512, ARM NEON       │
 │ • BERT & Matryoshka Embeddings (MRL)   │     │ • Quantization: SQ8 (Outliers), Anisotropic PQ, BQ│
 │ • ColBERT Late Interaction & MaxSim    │     │ • Graph ANN: HNSW & DiskANN (io_uring Async SSD)  │
 │ • ColPali Multimodal Retrieval         │     │ • CUDA: FlashAttention, CUTLASS GEMM, CAGRA Graph │
 │ • PagedAttention & KV Cache Paging     │     │ • Zero-Copy nanobind Python Engine Architecture   │
 └────────────────────────────────────────┘     └───────────────────────────────────────────────────┘
```
