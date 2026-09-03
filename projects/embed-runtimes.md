# Advanced inspection: `limbed` + `ggmbed`

Read: C++ encode/ORT/MaxSim, Python wrappers, CMake, CI, tests, eval, convert scripts.

Paths: `/home/ahmed/personal/intextus` · `/home/ahmed/personal/intextus-embed-ggml`

**Budget:** 30–60 min/week, Sep 2026 – Feb 2027 (~26 weeks). Does **not** steal `secan` nights or Sat DL. **Dedicated Slot: Sunday 13:00–14:00 (immediately after monthly research block).**

Jump: [§7 Timeline](#7-timeline-sep-2026--feb-2027) · [§6 priorities](#6-add-these-priority-if-you-only-pick-a-few)

---

## 1. Correctness (highest severity)

### `ggmbed`

| Issue | Evidence | Effect |
|:---|:---|:---|
| **One sequence per `llama_encode`** | `embedder.cpp` loop; `seq_id` always `0`; `n_batch=512` unused | API looks batched; compute is serial. Explains flat QPS vs ST. |
| **No KV clear between items** | Encode loop never resets cache | Possible **cross-example contamination** until you prove llama.cpp encoder mode is stateless. |
| **`n_ctx` hardcoded 512** | `ctx_params.n_ctx = 512` | Silent truncate / fail on longer GGUF. |
| **ASCII-only lowercasing** | `std::tolower` on bytes | Uncased multilingual / Unicode ≠ ST. |
| **Dual tokenizer** | HF `tokenizers` if `tokenizer.json` exists, else `llama_tokenize` | Same model, two ID sequences. |
| **Pooling by name heuristics** | `"bge"` / `"denseon"` → CLS else mean | Wrong pool for E5/GTE/Nomic without override. |
| **`logits[s] = true` on every token** | Full seq | Wasteful; some ggml embedding paths expect last-token only. |
| **`llama_encode` then fallback `llama_decode`** | Encoder vs decoder models | Hides architecture mismatch instead of failing. |
| **Tests mostly mock C++** | `tests/test_encoder.py` | CI does not lock cosine vs sentence-transformers. One local e2e exists; not the gate. |
| **Broken scripts** | `evaluate_accuracy.py` imports `GGMBedEncoder`, `DenseEncoder` | `__init__` only exports `Embedder`. Dead / lying tooling. |

### `limbed`

| Issue | Evidence | Effect |
|:---|:---|:---|
| **PAD rows still scored** | Docs pad with `pad_id`; only **punctuation** is zeroed. `compute_maxsim` uses full `(Lq, D)` / `(Ld, D)` | **MaxSim includes PAD (and query MASK) embeddings** unless the caller slices lengths. Rankings can be garbage vs pylate. |
| **MaxSim is naive triple loop** | No SIMD, no GEMM, 1 query × 1 doc | Fine for demo; not a retrieval kernel. Late-chunk MaxSim is Python `for` over chunks. |
| **`session_->Run` holds the GIL** | `gil_scoped_release` only around punct/L2 and MaxSim, **not** ORT `Run` | README “GIL released during encode” is **false for the expensive part**. Threads serialize on encode. |
| **No session mutex** | One `Ort::Session` | Concurrent encode from two threads is data-race territory even if GIL dropped later. |
| **Punct skiplist is naïve** | Single-char `string.punctuation` → vocab id; C++ `Encode("!")` may emit extra specials | Misses `##.`, `Ġ,`, SentencePiece punct; over-skip if Encode adds CLS. |
| **`tokenizers-cpp` on `GIT_TAG main`** | `CMakeLists.txt` | **Non-reproducible** wheels; tokenizer behavior can change under you. |
| **ORT CUDA: no fallback if EP add fails** | `AppendExecutionProvider_CUDA` then construct session | `auto`/CUDA with no device can throw at init instead of CPU. |
| **External ONNX data** | `hf_hub_download("model.onnx.data")` into Hub cache | File is **not** guaranteed next to `model.onnx`. Jina-scale models often **fail to load** or load incomplete graph. |
| **Local dir picks first `**/*.onnx`** | glob `[0]` | Easy to load the wrong export (fp16 vs fp32 vs decoder). |
| **Query always padded to `max_length`** | `seq_len = max_length` for queries | MASK tokens always in the 3D tensor; ColBERT-style but must match pylate MASK + attn (Jina uses all-1s mask). Fragile. |

---

## 2. Systems / performance

### `ggmbed`

- **`GGML_NATIVE ON` always** (`CMakeLists.txt`). cibuildwheel then emits **`-march=native` of the GHA CPU**. Wheels can **SIGILL** on AVX2-only boxes. This fights the README “portable SIMD” story. For wheels: `GGML_NATIVE OFF` + explicit AVX2 (or runtime dispatch).
- **`GGML_OPENMP OFF`** + serial encode: you left both parallelisms on the table.
- **Metal/CUDA ggml off**. Fine for v1; don’t claim “hardware optimized” beyond CPU.
- Bindings: extra `new float[]` copy of every batch.
- llama.cpp pinned `b8500` — good. Bump is a project, not a drive-by.

### `limbed`

- Intra-op threads: Python says `0` = all cores; C++ `SetIntraOpNumThreads(0)` — verify ORT semantics (0 is usually “default”, not “detect physical cores”).
- Graph opt `ORT_ENABLE_ALL` — good; no **IOBound / packed INT8** session option.
- MaxSim: `float` dots, no FMA/AVX, no blocking; PAD rows make it slower **and** wrong.
- Output always dense 3D — memory explosion for long Jina seqs (8192 × 128 × batch).

---

## 3. Product / API

| | `ggmbed` | `limbed` |
|:---|:---|:---|
| Query vs doc | Single `encode` | Split encode — good |
| Prefixes / instruct | Missing (BGE/E5) | Markers `[Q]`/`[D]` — good |
| `encode_tokens` | Yes | **No** |
| Lengths / mask returned | No | No — callers can’t slice PAD |
| MRL `truncate_dim` | No | N/A (token dim) |
| Model spec | 3 if-aliases | Alias map + jina heuristics |
| Logging | `print` on Hub download | same |
| GPU product | None | Local rebuild only; PyPI CPU |

Don’t put HNSW in either package. Do return **lengths** (or ragged lists) so MaxSim can skip PAD.

---

## 4. Supply chain / ops

| Hole | Where |
|:---|:---|
| **Hugging Face token hardcoded** in `ggmbed/scripts/convert_denseon.py` | **Rotate that token now.** Never commit Hub tokens. |
| Version bump **on every `main` push** then publish | Both `publish.yml` — noisy PyPI, easy to ship a tokenizer-main surprise (`limbed`). |
| CI `pytest` after `pip install -e .` | Does not prove wheel SIMD portability (`GGML_NATIVE`). |
| `limbed` tests mock ONNX | Publish job never scores vs pylate. |

---

## 5. What is actually solid (don’t redo)

- ColBERT packing (CLS/marker/SEP, query MASK vs doc PAD) is thought-through, including Jina markers and `query_attn_mask_all_1s`.
- Punct zeroing on **docs** is the right ColBERT idea (incomplete skiplist, not a wrong idea).
- nanobind + FetchContent ORT/llama, manylinux RPATH, aarch64 `-mno-outline-atomics` on ggmbed — real packaging work.
- `limbed` eval harness (BEIR slices, pylate/fastembed backends) is ahead of the **core** API.
- llama.cpp for dense GGUF is the right engine choice.

---

## 6. Add these (priority if you only pick a few)

**Must-fix / must-consider**

1. `limbed`: MaxSim **mask PAD/MASK** (or return `seq_lens` and slice). Until then, scores are not ColBERT.  
2. `ggmbed`: **`GGML_NATIVE OFF` for wheels**; native only for source `CMAKE_ARGS`.  
3. `ggmbed`: **true multi-seq `llama_batch`** (the actual perf hole).  
4. `limbed`: **GIL release around `session_->Run`**.  
5. Rotate HF token; pin `tokenizers-cpp` to a **commit**, not `main`.  
6. Fix or delete `evaluate_accuracy.py` imports.  
7. External ONNX: copy `model.onnx.data` **next to** the loaded `model.onnx`.

**Strong product adds (after the above)**

8. `limbed`: batched MaxSim `(nq, nd)` + SIMD/GEMM.  
9. `limbed`: `encode_tokens` + lengths.  
10. `ggmbed`: `encode_queries` / `encode_documents` + prefix table; last-token pooling.  
11. Golden tests: ST cosine (`ggmbed`) and pylate MaxSim (`limbed`) on 8 texts in CI.

**Leave to `secan` / later**

PLAID index, MUVERA FDE, CUDA wheels, training, recsys, REST.

---

## 7. Timeline (Sep 2026 – Feb 2027)

One theme per month. Each week = **one** landing from that theme. Miss a week → skip, don’t stack onto `secan`.

### Month map

| Month | Primary | Theme | Outcome |
|:---|:---|:---|:---|
| **0 — now** | both | Security / stop the bleeding | Token rotated; no more secrets in git |
| **1 — Sep** | `limbed` | **Correct MaxSim** | PAD/MASK not scored; lengths API |
| **2 — Oct** | `ggmbed` | **Portable wheels** | `GGML_NATIVE` fixed; dead scripts cleaned |
| **3 — Nov** | `ggmbed` | **Real batch encode** | Multi-seq `llama_batch` + KV clear |
| **4 — Dec** | `limbed` | **Encode concurrency** | GIL off on `Run`; tokenizer pin; ONNX `.data` |
| **5 — Jan** | both | **Golden CI** | ST + pylate fixtures; query/doc prefixes |
| **6 — Feb** | both | **Product APIs** | Batched MaxSim *or* `encode_tokens`; small releases |

### Week-by-week

#### Now (before Sep 1)

| | Landing |
|:---|:---|
| **ASAP** | Rotate HF token used in `convert_denseon.py`; purge from git history if it was pushed; use `HF_TOKEN` env only |

#### Month 1 — Sep · `limbed` correctness

| Wk | ~Sun | Landing (≤60 min) |
|:---|:---|:---|
| 1 | Sep 6 | Return `seq_lens` (or mask) from encode; document that MaxSim must use them |
| 2 | Sep 13 | `compute_maxsim`: skip PAD / zero / mask rows (C++) |
| 3 | Sep 20 | Query MASK policy: match pylate on one fixture (8 texts) |
| 4 | Sep 27 | Patch eval harness to use lengths; freeze. **Publish month-1 secan paper separately** |

#### Month 2 — Oct · `ggmbed` packaging

| Wk | ~Sun | Landing |
|:---|:---|:---|
| 5 | Oct 4 | CMake: `GGML_NATIVE OFF` by default; `ON` only via explicit `CMAKE_ARGS` |
| 6 | Oct 11 | cibuildwheel: assert wheel has no `AVX512`-only requirement (or document baseline) |
| 7 | Oct 18 | Fix or delete `evaluate_accuracy.py` / broken imports |
| 8 | Oct 25 | Optional: KV clear between serial encodes until batch lands |

#### Month 3 — Nov · `ggmbed` batching

| Wk | ~Sun | Landing |
|:---|:---|:---|
| 9 | Nov 1 | Design: pack N seqs into one `llama_batch` (read llama embedding examples) |
| 10 | Nov 8 | Implement multi-seq encode path for B≥2 |
| 11 | Nov 15 | Re-bench B=1,8,32 vs fastembed; update README honestly |
| 12 | Nov 22 | Configurable `n_ctx`; fail loud if tokens > ctx |

#### Month 4 — Dec · `limbed` systems

| Wk | ~Sun | Landing |
|:---|:---|:---|
| 13 | Nov 29 | `gil_scoped_release` around `session_->Run` |
| 14 | Dec 6 | Pin `tokenizers-cpp` to a **commit hash** |
| 15 | Dec 13 | Hub load: place `model.onnx.data` beside `model.onnx` |
| 16 | Dec 20 | CUDA init: try EP, fall back to CPU; README: wheels = CPU |

#### Month 5 — Jan · trust / API surface

| Wk | ~Sun | Landing |
|:---|:---|:---|
| 17 | Dec 27 | Skip or token-only hygiene (holiday) |
| 18 | Jan 3 | `ggmbed` CI golden: MiniLM cosine vs ST ≥ 0.99 on fixed 8 sentences |
| 19 | Jan 10 | `limbed` CI golden: MaxSim vs pylate on fixed pair (CPU) |
| 20 | Jan 17 | `ggmbed`: `encode_queries` / `encode_documents` + BGE/E5 prefix table |

#### Month 6 — Feb · ship

| Wk | ~Sun | Landing |
|:---|:---|:---|
| 21 | Jan 24 | Pick **one**: batched MaxSim `(nq, nd)` **or** `limbed.encode_tokens` |
| 22 | Jan 31 | Finish that one feature + tests |
| 23 | Feb 7 | Changelogs; bump both packages |
| 24 | Feb 14 | PyPI tags; stop. Backlog only after Mar `secan` GPU closeout |

Weeks 25–26 (late Feb): bugfixes only. No PLAID, no CUDA wheels, no training.

### Capacity math

| | |
|:---|:---|
| Weeks | ~24 working + 2 buffer |
| Hours | ~12–24 total |
| Success | PAD-correct MaxSim + portable ggmbed wheels + batched ggml + GIL fix + two goldens |
| Stretch if ahead | Batched MaxSim SIMD **or** `encode_tokens` — not both unless a week frees up |

### Do not schedule

Merging repos · `secan` indexes inside these libs · CUDA PyPI matrix · llama.cpp major bumps mid-batch-work · rewriting eval harness (already ahead of core).

