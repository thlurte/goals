# Vector Search Engine & AI Systems Specialization
> **28 weeks / 7 months** (Sep 2026 – Mar 2027).
> **Dual Engine Architecture**:
> - **[`secan`](https://github.com/thlurte/secan)**: Vector Search, Indexing, Quantization & Retrieval Engine in C++20 / SIMD / GPU.
> - **[`cennan`](https://github.com/thlurte/cennan)**: C++ Embedding, Multimodal Latent Representation & Inference Runtime.
> **Deep Learning Track**: Tuesday & Wednesday mornings (06:30–08:30 builder track).
> **Zero-Noise Doctrine**: No web/REST boilerplate (nanobind + CLI). Pure microarchitectural focus.

## Start here

| Doc | Use when |
|:---|:---|
| [**Hard landings**](curriculum/landings.md) | What must ship which week across `secan`, `cennan`, and DL track |
| [**Architecture roadmap**](curriculum/roadmap.md) | Macro systems blueprint & dual-engine architecture |
| [**Weekly execution playbooks**](curriculum/weeks/week-05.md) | Week-by-week daily runbooks, actions, and deliverables |
| [**Drills & Practice Suites**](drills/README.md) | 62+ standalone C++20 and Python microarchitectural drills |
| [**Systems Canon & Bibliography**](resources/systems_canon.md) | Primary sources, microarchitecture manuals, textbooks & seminal papers |

## Entry prerequisites (before Sep 1)

| Gate | Requirement |
|:---|:---|
| **CPU** | x86_64 with AVX2 (AVX-512 nice-to-have). ARM64 host or CI by Week 23. |
| **GPU** | NVIDIA + CUDA by Week 13. Multi-GPU / NVLink = Week 20 stretch. |
| **Storage** | ≥50 GB free; **NVMe by Week 16** (DiskANN / `io_uring`). |
| **Datasets** | SIFT1M Week 1; **768-D text `.fvecs` by Week 8 Fri**; BEIR/MS MARCO slice Month 3. |
| **VRAM** | BERT/ColBERT/ViT expect a GPU; CPU-only = tiny synthetic runs. |
| **Tooling** | CMake 3.20+, C++20, `perf`, `uv`, Python 3.11+, Git. |

## Layout

```
goals/
├── README.md                 ← you are here
├── curriculum/
│   ├── README.md             ← cadence + master index
│   ├── landings.md           ← VS / DL / deferred ledgers
│   ├── roadmap.md            ← architecture blueprint
│   ├── weeks/
│   │   ├── month-0N-*.md     ← day tables & actions by month
│   │   └── week-01.md ...    ← 28 weekly execution playbooks
│   └── days/
│       └── month-0N/day-*.md ← 196 individual daily runbooks
├── drills/
│   ├── README.md             ← systems & DL hands-on micro-drills
│   ├── week-01/ ... week-06/ ← organized weekly C++ & Python drill suites
│   └── solutions/            ← reference implementations
└── resources/
    └── systems_canon.md      ← primary sources, vendor manuals & canonical textbooks
```
