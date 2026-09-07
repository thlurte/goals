# Hard landings & ledgers

> Required VS / DL / deferred landings. Week tables: [`weeks/`](weeks/). Curriculum index: [`README.md`](README.md).

## Deferred-work ledger (slimmed → hard landing)

Nothing slimmed is optional. Every row is **required** on the landing week.

| Slimmed from | What was cut | **Hard landing (required)** | Why there |
|:---|:---|:---|:---|
| **Week 8** | HNSW bounded flat heap + bitset visited | **Week 12 Wed** | Before composed-index Pareto |
| **Week 10** | BM25 + Block-Max WAND + **RRF** | **Week 16 Fri** | Hybrid IR; not only linear $\alpha$ |
| **Week 11** | DiskANN `io_uring` + **Vamana prune** | **Week 16 Thu** | Graph construction, not only SSD fetch |
| **Week 15** | FlashAttention-2 | **Week 25** | GPU block |
| **Week 7→10** | RaBitQ (after QR) | **Week 10 Thu** | Already required |
| **Week 8→12** | Whitening / query-side PCA | **Week 12 Mon** | After SVD |
| *(frontier)* | ACORN + tombstones + NUMA + **pre/post/range** | **Week 22** | On-call filters |

## VS composition landings (the specialty)

REST out of scope. Cluster shard/replica = stretch only.

| Need | Lands (required) |
|:---|:---|
| **IP/MIPS + spherical k-means IVF** + list-size histogram / rebalance | **Week 4 Thu–Fri** |
| **Asymmetric PQ/BQ** (FP32 query vs quantized db) + **OPQ / residual PQ** | **Week 6 Fri + Week 7 Fri** |
| **768-D text Recall@10 vs QPS** (golden pre-staged `.fvecs` + DL model parity) | **Week 8 Fri** |
| **Batch HNSW / graph build** | **Week 9 Mon–Tue** |
| **MUVERA FDE** (asymmetric) → IP MIPS → MaxSim re-rank vs PLAID | **Week 10 Mon–Wed** |
| **TurboQuant 1@k** vs RaBitQ/PQ (GloVe or 768-D) | **Week 10 Fri** |
| **`IVFPQIndex` + `HNSWSQIndex`**; Pareto vs Faiss/hnswlib on **SIFT + 768-D** | **Week 12 Thu–Fri** |
| **ONNX → ORT** dense bi-encoder → `.fvecs` → `secan` (PyTorch parity) | **Week 12 Thu (Builder Integration)** |
| **Vamana prune** + compressed RAM + `io_uring` raw (**Deep10M** core; Deep1B NVMe tier) | **Week 16 Thu** |
| **RRF** + linear $\alpha$ (SPLADE stretch) | **Week 16 Fri** |
| **Pre- vs post-filter vs ACORN**; **range**; selectivity vs recall | **Week 22 Mon + Fri** |
| BEIR / MS MARCO **slice** (dense + ColBERT + **MUVERA**) | **Week 10 Thu (Builder Integration)** |
| REST API | **Skip** |

## Deep Learning Landings (Tue & Wed Mornings 06:30–08:30)

| Week | DL Architecture & Implementation (Tue & Wed Mornings 06:30–08:30) |
|:---|:---|
| **W1 (Tue Sep 8 / Wed Sep 9)** | SDPA + causal mask (`uv init transformers-pytorch`) & unit tests |
| **W2 (Tue Sep 15 / Wed Sep 16)** | MHA + **GQA**; Pre-LN vs Post-LN |
| **W3 (Tue Sep 22 / Wed Sep 23)** | **🔗 Micrograd autograd engine** (~150 lines) + Pre-LN encoder + FFN + manual `backward()` for `Linear` |
| **W4 (Tue Sep 29 / Wed Sep 30)** | **RoPE + SwiGLU + CausalLM + CE + naive KV** + **SGD from scratch** (momentum, verify vs `torch.optim.SGD`) |
| **W5 (Tue Oct 6 / Wed Oct 7)** | ViT patch embed + `[CLS]` |
| **W6 (Tue Oct 13 / Wed Oct 14)** | BERT + **InfoNCE** + **in-batch negatives** + **hard negative mining** (BM25 top-100); **AdamW from scratch**; export 768-D `.fvecs` for Week 8 Fri |
| **W7 (Tue Oct 20 / Wed Oct 21)** | Matryoshka Representation Learning (MRL) loss & dynamic dimension slicing |
| **W8 (Tue Oct 27 / Wed Oct 28)** | MRL / Anisotropic Projection Evaluation & Embedding Geometry Diagnostics |
| **W9 (Tue Nov 3 / Wed Nov 4)** | ColBERT + MaxSim + tiny Margin MSE + **knowledge distillation** (cross-encoder → bi-encoder) |
| **W12 (Tue Nov 24 / Wed Nov 25)** | **ONNX required**: InfoNCE bi-encoder → ONNX → **ORT**; PyTorch parity; emit 768-D `.fvecs` → `secan` |
| **W15 (Tue Dec 15 / Wed Dec 16)** | Online softmax (FA-1 math) & CUDA kernel foundations |
| **W21 (Tue Jan 26 / Wed Jan 27)** | CLIP projector + ColPali head |
| **W23 (Tue Feb 9 / Wed Feb 10)** | Stretch: re-run same ORT graph on ARM host (with NEON week) |
| **Remaining Weeks** | Continuous transformer scaling, multi-modal tokenization, and GPU inference pipelines |

---

---

---
