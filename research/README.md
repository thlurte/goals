# Monthly Research Program

One research topic per calendar month. **Build every weekend. Publish by month-end.**  
Weekly Saturday essays are *lab notes* that feed the monthly paper — not six separate polished publications.

## Cadence

| When | What |
|:---|:---|
| **Sat 09:00–13:00** | Weekly essay / lab note |
| **Sat 14:00–18:00** | **DL weekly** (the one Python day — not research) |
| **Sun 09:00–13:00** | Monthly research experiments / draft in `research/YYYY-MM-<slug>/` |
| **Last weekend of month** | **Publish**: freeze PDF/Markdown + GitHub tag + public post (blog / LinkedIn / HF) |

## Paper structure (every month)

One file, one format: copy [`_template.md`](_template.md) → `YYYY-MM-<slug>/paper.md`.

| § | Required |
|:---|:---|
| 1 Question | One falsifiable sentence |
| 2 Method | Hardware, commit, flags, dataset, protocol |
| 3 Experiments | Table of runs |
| 4 Results | ≥1 figure in `figures/` + numbers in the paper |
| 5 Baseline | Named (`faiss`, `hnswlib`, scalar, paper method) |
| 6 Limitations | Honest paragraph |
| 7 Reproduce | Commands |

Do **not** put weekend checklists in `paper.md` (cadence is this README). Lab notes go in `notes/`, plots in `figures/`.

Curriculum weeks: [`../curriculum/README.md`](../curriculum/README.md). Lab notes: [`../curriculum/essays.md`](../curriculum/essays.md).

## Seven topics (Sep 2026 – Mar 2027)

| Month | Topic (working title) | Publish by | Primary artifacts |
|:---|:---|:---|:---|
| **1 — Sep 2026** | *Measurement Before Optimization: A Reproducible Protocol for Vector Distance Microbenchmarks* | **Sun Sep 27** | Google Benchmark suite, `perf` tables, scalar L2/cosine on SIFT dims |
| **2 — Oct 2026** | *Anisotropy, Hubness, and Bits: SQ / PQ / FastScan / ScaNN + OPQ / asymmetric distance* | **Sun Oct 25** | Quantization ablations, hubness $S_{N_k}$, OPQ vs PQ, vision vs **768-D text** |
| **3 — Nov 2026** | *Late Interaction Under Writes: PLAID vs MUVERA FDE→MIPS Inside an LSM Vector Engine* | **Sun Nov 29** | Multi-vector + WAL; **BEIR or MS MARCO slice**; candidate counts PLAID vs MUVERA |
| **4 — Dec 2026** | *One Engine, Three Paths: GPU IVF, Vamana + DiskANN `io_uring`, and Hybrid RRF/WAND* | **Sun Dec 27** | Spine closeout Pareto; tag `v1.2-vs-spine-complete` |
| **5 — Jan 2027** | *Paging vs Quantizing Memory: PagedAttention and TurboQuant as Complementary KV Levers* | **Sun Jan 31** | Block table vs bitwidth; naive KV (Week 4) is the baseline |
| **6 — Feb 2027** | *Predicate-Aware Graphs: Pre/Post/Range Filters, ACORN, Tombstones, Portable SIMD* | **Sun Feb 28** | Selectivity vs recall; range predicates; delete/vacuum; x86 vs ARM |
| **7 — Mar 2027** | *IO-Aware GPU Serving: FlashAttention-2, Multi-GPU Search, and KV Paging* | **Fri Mar 12** | FA-2 Nsight tables, multi-GPU scaling, `v2.0` |

## Relationship to weekly essays

Weekly essays = short, sharp, same-week.  
Monthly paper = synthesis + experiments you could show in a hiring loop.  
Do **not** polish all 28 essays for public; polish **7 monthlies**.
