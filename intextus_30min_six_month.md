# Intextus 30-Minute Track (Sep 2026 – Feb 2027)

**Repos**: [`intextus`](https://github.com/thlurte/limbed) (`limbed-py`, ONNX ColBERT) · [`intextus-embed-ggml`](https://github.com/thlurte/ggmbed) (`ggmbed`, GGUF dense)

**Budget**: **30 minutes per week**, one sitting. Not a second specialization. Does not steal Mon–Fri `secan` or Saturday DL.

**Slot**: Sunday **13:15–13:45** (after the research block). If Sunday is a publish weekend, skip Intextus that week.

**ONNX on the VS timeline (required):** Week **8 Fri** dense encode→HNSW; Week **9 Fri** `limbed` ColBERT ONNX→`MultiVectorIndex`. This 30-min track **maintains** `limbed`/`ggmbed` so those Fridays work. It does **not** replace them. `secan` still does not link ORT.

---

## How many projects besides `secan`

**Three public codebases. Not eight. Do not dump encoders into `secan`.**

| # | Repo | Job | Not its job |
|:---|:---|:---|:---|
| **1** | **`secan`** | Indexes, SIMD/CUDA search, LSM, IVF-PQ, HNSW-SQ, MUVERA FDE, DiskANN | Tokenizers, ONNX Runtime, llama.cpp, training |
| **2** | **`limbed` (`intextus`)** | ColBERT **encode** on ONNX Runtime + MaxSim scores + late chunking | ANN graphs, PQ, WAL |
| **3** | **`ggmbed` (`intextus-embed-ggml`)** | Dense **encode** on GGUF / llama.cpp | Late interaction, search |

`secan` consumes **arrays**. `limbed` / `ggmbed` produce them. Glue is a **script** (`examples/encode_to_fvecs.py` in `secan` or `scripts/` in the encoder repo), not a fourth engine.

### Keep private (not products)

| Thing | Rule |
|:---|:---|
| Weekend PyTorch (`transformers-pytorch`, ViT, BERT, ColBERT, ColPali) | **One folder**, e.g. `~/personal/dl-scratch/`. Learning artifacts. Do not PyPI them. |
| `goals/` research papers | Writing. Not a runtime. |

### Do not create

- `intextus-search` / a REST wrapper
- Merging `limbed` + `ggmbed` into one package (ORT ≠ ggml; 30 min/week cannot pay a merge)
- ColBERT-on-ggml (wrong runtime; ColBERT stays ONNX)
- Putting `llama.cpp` or ORT into `secan` CMake

**Hiring story:** `secan` is the engine. `limbed` / `ggmbed` are already-shipped **zero-PyTorch encode** products (wheels, benches vs fastembed). That split is a feature.

---

## What the repos already are

**`limbed`**: nanobind + ORT 1.20 + tokenizers-cpp. PyPI CPU wheels. Local CUDA ORT optional. Late chunking on `main`. Uncommitted: `src/limbed/eval/` + overnight eval scripts — **first weeks ship or stash**, do not let them rot as a second project.

**`ggmbed`**: nanobind + llama.cpp `b8500`. MiniLM / BGE-small / DenseOn GGUF. README benches show **batch throughput almost flat** (MiniLM ~79 sent/s from batch 1→128). That is the real product gap, not “add more models.”

---

## Six months at 30 min/week (~26 sittings, ~13 hours)

One **theme per month**. Each week: **one** of {merge PR, one test, one script, one README row, one export}. If it needs a weekend, it is out of scope.

### Month 1 — Sep 2026 · Ship what you already built

Curriculum is measurement + SIMD. Do not start features.

| Week | 30 min |
|:---|:---|
| Sep 6 | `limbed`: decide eval tree — **commit** `src/limbed/eval/` + smoke script, or move to a branch and ignore. README still says “CPU only”; fix to match CUDA rebuild. |
| Sep 13 | `limbed`: one CI/eval smoke on default mxbai model (already have `validate_eval_smoke.py`). |
| Sep 20 | `ggmbed`: reproduce batch=1 vs batch=32 throughput on your machine; write the number in an issue. |
| Sep 27 | **Skip** (Month 1 paper). |

### Month 2 — Oct 2026 · Prep export so Week 8–9 Fridays exist

VS timeline owns the handoff. These 30 min only keep `limbed` export/load green.

| Week | 30 min |
|:---|:---|
| Oct 4 | `limbed/scripts/export_colbert_onnx.py` stub (HF ColBERT → `model.onnx` + `tokenizer.json`). |
| Oct 11 | Dense: confirm `ggmbed` encode→`.fvecs` for **Week 8 Fri**. Optional dense ONNX. |
| Oct 18 | `LateEmbedder("./exported/")` smoke — needed for **Week 9 Fri**. |
| Oct 25 | **Skip** (Month 2 paper). Week 8 Fri already ran the dense handoff. |

### Month 3 — Nov 2026 · After Week 9 Fri, widen the slice

| Week | 30 min |
|:---|:---|
| Nov 1 | **Skip or tiny**: Week 9 Fri already did limbed→`secan`. Only fix glue if broken. |
| Nov 8 | Queries for BEIR/MS MARCO **tiny** split if Month 3 paper needs more than Week 9 dump. |
| Nov 15 | `ggmbed` dense side of that slice (hybrid/RRF later). |
| Nov 22 | README “used with `secan`” + file format. |
| Nov 29 | **Skip** (Month 3 paper). |

### Month 4 — Dec 2026 · Freeze

GPU IVF + DiskANN spine. Maintenance only.

| Week | 30 min |
|:---|:---|
| Dec 6 | Dependency bump **or** skip: ORT / llama.cpp tag only if CI is red. |
| Dec 13 | `ggmbed`: first cut at **real batched** decode (even if incomplete; park a branch). |
| Dec 20 | Nothing new. |
| Dec 27 | **Skip** (Month 4 paper). |

### Month 5 — Jan 2027 · `ggmbed` batching

This is the 30-min track’s **one engineering win**.

| Week | 30 min |
|:---|:---|
| Jan 3 | llama.cpp embedding batch API: read current `encode_tokens`; list why throughput is flat. |
| Jan 10 | Implement or land **one** batched path; bench batch 8 vs 1. |
| Jan 17 | Accuracy check vs existing MiniLM test (padding / mean pool — you already fixed this once). |
| Jan 24 | Optional: one extra GGUF alias (e5-small **or** gte-small), not five. |
| Jan 31 | **Skip** (Month 5 paper). |

### Month 6 — Feb 2027 · Release hygiene

| Week | 30 min |
|:---|:---|
| Feb 7 | Version bump + changelog for whichever repo actually moved (likely `ggmbed`). |
| Feb 14 | **Skip** or docs-only (Month 6 paper). |
| Feb 21 | `limbed`: confirm export script still runs on one public ColBERT ONNX. |
| Feb 28 | Stop. March is GPU closeout — no Intextus features. |

---

## Explicit non-goals (6 months)

- Merging the two packages
- Training in C++
- GPU llama.cpp / Metal in `ggmbed` wheels
- Alpine/musl ORT
- ColPali ONNX (weekend DL only; export only if a Sunday is empty)
- Duplicating MaxSim SIMD that `secan` Week 9 already owns — `limbed`’s `compute_maxsim` stays a convenience score, not an ANN engine

---

## Pointers

Curriculum: [`vector_search_24_week_daily_plan.md`](vector_search_24_week_daily_plan.md)  
`secan` does not grow an ONNX **library** target. Week 23 Fri stays ARM CI. The VS **encode→index** days are Week 8–9 in [`vector_search_24_week_daily_plan.md`](vector_search_24_week_daily_plan.md).
