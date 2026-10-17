# 🚀 Systems & Vector Search Engineering Intensive
> **Dates**: October 19, 2026 – November 30, 2026 (6 Weeks)  
> **Mission**: Build independent, production-grade mastery of C++ Systems Programming, Memory Hierarchies, Concurrency, SIMD, and Vector Search Engines.  
> **Target**: Solo readiness for Systems Engineer / HPC / High-Performance Database interviews without AI assistance.

---

## 🧭 The Core Doctrine

1. **No Vibe Coding**: Never have an AI write your code. You write every line, understand every assembly instruction, and debug every segfault.
2. **First-Principles First**: Every abstraction (smart pointers, arenas, thread pools, SIMD kernels, graph search) is built from scratch before using library versions.
3. **Daily Rhythm**:
   - 📖 **Exact Reading** (30–45 min): Read pinpointed pages from canonical texts.
   - 💻 **Standalone Drills** (60–90 min): 1–2 focused C++ drills written by you from memory/scratch.
   - 🛠️ **Secan Deliberate Progression** (45–60 min): Slow, methodical engineering in [`secan`](https://github.com/thlurte/secan).

---

## 📚 Canonical Book Stack

| Book Code | Title & Edition | Authors | Focus Area |
| :--- | :--- | :--- | :--- |
| **[CS:APP]** | *Computer Systems: A Programmer's Perspective (3rd ed)* | Bryant & O'Hallaron | Memory hierarchy, cache lines, linking, dynamic allocation. |
| **[ArtOfProg]** | *The Art of Writing Efficient Programs* | Fedor Pikus | Modern C++ performance, RAII, memory layout, false sharing. |
| **[C++Concurrency]** | *C++ Concurrency in Action (2nd ed)* | Anthony Williams | Threads, atomics, memory order, lock-free queues, thread pools. |
| **[AgnerFog]** | *Optimizing Software in C++* (`goals/agner_cpp.pdf`) | Agner Fog | SIMD vectorization, instruction tables, port execution. |
| **[Paper: PQ]** | *Product Quantization for Nearest Neighbor Search* | Jégou, Douze, Schmid | Subspace decomposition, codebooks, ADC lookup tables. |
| **[Paper: HNSW]** | *Efficient and Robust Approx Nearest Neighbor Search (HNSW)* | Malkov & Yashunin | Multi-layer navigable small-world graphs, greedy routing, heuristics. |

---

## 🗓️ 6-Week Roadmap

- **[Week 1: C++ Memory Mastery, RAII & Custom Allocators](weeks/week-01.md)** (Oct 19 – Oct 25)
- **Week 2: Multi-threading, Synchronization & Concurrency** (Oct 26 – Nov 1)
- **Week 3: SIMD Intrinsics, AVX2/AVX-512 & Vectorization** (Nov 2 – Nov 8)
- **Week 4: Vector Quantization (SQ8, PQ, Asymmetric Distance)** (Nov 9 – Nov 15)
- **Week 5: Graph Search Algorithms & Cache-Friendly Layouts (HNSW)** (Nov 16 – Nov 22)
- **Week 6: Profiling (`perf`), Zero-Copy I/O (`mmap`), Sanitizers & Interview Defense** (Nov 23 – Nov 30)

---

## 📂 Structure

```text
intensive-2026/
├── README.md           ← Master Syllabus & Doctrine
├── weeks/              ← Detailed daily playbooks for each week
│   ├── week-01.md
│   └── ...
├── drills/             ← Daily C++ drill source files (coded by you)
└── notes/              ← Key conceptual summaries & interview flashcards
```
