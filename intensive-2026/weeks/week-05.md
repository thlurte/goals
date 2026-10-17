# Week 5: Graph Search Algorithms & Cache-Friendly Layouts (HNSW)
> **Dates**: November 16 – November 22, 2026  
> **Core Focus**: Navigable Small World (NSW) graphs, greedy routing, multi-layer hierarchical navigation, heuristic neighbor selection, and contiguous flattened graph storage.

---

### Day 29 (Mon, Nov 16): 1-Layer Navigable Small World (NSW) & Greedy Routing
- 📖 **Reading**: **[Malkov & Yashunin (2018)]** — **Sections 1 & 2** (NSW topology, greedy routing, probability decay).
- 💻 **Drills (`day_29_drills.md`)**:
  1. `drill_29a_nsw_graph_struct.cpp`: Build a basic adjacency graph: `struct Node { uint32_t id; std::vector<uint32_t> neighbors; };`.
  2. `drill_29b_greedy_routing.cpp`: Implement `greedy_search(query, entry_point)`: evaluate distance to all neighbors of current node, hop to neighbor closest to query, stop when no neighbor is closer (local minimum).
  3. `drill_29c_greedy_failure_analysis.cpp`: Demonstrate why naive greedy search gets trapped in local minima if graph connectivity is poor.
- 🛠️ **`secan`**: Design graph index representation in `secan/include/secan/index/hnsw/`.

---

### Day 30 (Tue, Nov 17): Beam Search & `SEARCH-LAYER`
- 📖 **Reading**: **[Malkov & Yashunin (2018)]** — **Section 3** (Algorithm 1: `SEARCH-LAYER(q, ep, ef, lc)`).
- 💻 **Drills (`day_30_drills.md`)**:
  1. `drill_30a_candidate_queues.cpp`: Implement the two-priority-queue structure:
     - `candidates`: Min-heap storing vectors to be explored.
     - `results`: Max-heap storing the $ef$ closest vectors found so far.
  2. `drill_30b_search_layer_impl.cpp`: Implement full `SEARCH-LAYER`: pop closest candidate, evaluate all unvisited neighbors, update $results$ bounded by $ef$.
  3. `drill_30c_search_layer_bench.cpp`: Benchmark Recall vs $ef$ setting on a 10,000-vector graph. Show how higher $ef$ increases recall at the cost of QPS.
- 🛠️ **`secan`**: Implement `search_layer` in `secan`.

---

### Day 31 (Wed, Nov 18): Hierarchical Multi-Layer Entry Point Navigation
- 📖 **Reading**: **[Malkov & Yashunin (2018)]** — Algorithm 2 & 3 (Level assignment $l = \lfloor -\ln(\text{uniform}(0,1)) \cdot m_L \rfloor$).
- 💻 **Drills (`day_31_drills.md`)**:
  1. `drill_31a_random_level_generator.cpp`: Implement geometric random level generator with parameter $m_L = 1 / \ln(M)$. Verify distribution matches expected exponential decay.
  2. `drill_31b_hierarchical_traversal.cpp`: Implement top-down entry-point navigation: from layer $L_{max}$ down to layer 1, perform greedy routing with $ef=1$ to find entry point for layer 0.
  3. `drill_31c_hnsw_multi_layer_struct.cpp`: Multi-layer node storage: `Node { std::vector<std::vector<uint32_t>> layer_neighbors; }`.
- 🛠️ **`secan`**: Implement multi-layer navigation in `secan`.

---

### Day 32 (Thu, Nov 19): Heuristic Neighbor Selection (Diversity Pruning)
- 📖 **Reading**: **[Malkov & Yashunin (2018)]** — **Section 3.4** (Algorithm 4: `SELECT-NEIGHBORS-HEURISTIC`).
- 💻 **Drills (`day_32_drills.md`)**:
  1. `drill_32a_simple_neighbors_selection.cpp`: Naive top-$M$ closest neighbors selection.
  2. `drill_32b_heuristic_neighbor_pruning.cpp`: Heuristic neighbor selection: keep neighbor $e$ only if distance from candidate to $e$ is strictly less than distance between $e$ and any previously selected neighbor (triangle inequality diversity pruning).
  3. `drill_32c_clustering_effect_bench.cpp`: Compare graph navigation efficiency using simple vs heuristic neighbor selection. Show how heuristic eliminates clustering traps.
- 🛠️ **`secan`**: Implement neighbor pruning heuristic in `secan`.

---

### Day 33 (Fri, Nov 20): Contiguous Flattened Graph Memory Layout
- 📖 **Reading**: Cache-friendly graph serialization: eliminating `std::vector` pointer indirection.
- 💻 **Drills (`day_33_drills.md`)**:
  1. `drill_33a_scattered_vs_flat_graph.cpp`: Compare pointer-based node representations (`std::vector<std::vector<uint32_t>>`) vs a single flat buffer `uint32_t* edges` with fixed capacity $M$.
  2. `drill_33b_flat_graph_search.cpp`: Implement `SEARCH-LAYER` directly on flat buffer with offset math: `node_offset = node_id * (M + 1)`.
  3. `drill_33c_traversal_speedup_bench.cpp`: Measure cache misses (`perf stat -e L1-dcache-load-misses`) of flat graph vs pointer graph during 10,000 queries. Witness a 2x–3x speedup.
- 🛠️ **`secan`**: Refactor `secan` HNSW storage to a single contiguous flattened buffer.

---

### Day 34 (Sat, Nov 21): End-to-End HNSW Index Build & Query
- 💻 **Drills (`day_34_drills.md`)**:
  1. `drill_34a_end_to_end_hnsw.cpp`: Full single-threaded HNSW index build and search on 10,000 vectors ($D=128$).
  2. `drill_34b_recall_qps_curve.cpp`: Measure Recall@10 vs QPS across $efSearch \in \{16, 32, 64, 128, 256\}$.
  3. `drill_34c_parallel_hnsw_build.cpp`: Multi-threaded index insertion using fine-grained locks or your `ThreadPool`.
- 🛠️ **`secan`**: Benchmark `secan` HNSW on SIFT1M subset. Verify Recall@10 $> 0.95$.

---

### Day 35 (Sun, Nov 22): Timed Graph Search Exam (No Notes)
- ⏱️ **45-minute timed coding exam**: Write `greedy_search` and `SEARCH-LAYER` with two priority queues from a blank file with zero compiler warnings.
