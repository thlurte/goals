# Week 5: HNSW Filtered Search, Selectivity Bypass & Cache-Friendly Graph
> **Dates**: November 16 – November 22, 2026  
> **Core Focus**: HNSW graph traversal, `ConcurrentBitset` integration, **Single-Stage Filtered Search**, and **<2% Low-Selectivity SIMD Flat Bypass**.

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

### Day 31 (Wed, Nov 18): Single-Stage Filtered Search with `ConcurrentBitset`
- 📖 **Reading**: **Filtered Vector Search Architecture** (Single-stage vs post-filtering; why post-filtering fails when selectivity is low).
- 💻 **Drills (`day_31_drills.md`)**:
  1. `drill_31a_filter_bitset_integration.cpp`: Integrate `ConcurrentBitset` into HNSW `SEARCH-LAYER`:
     - When exploring neighbor $v$, check `filter_bitset.test(v)`.
     - If it passes the filter, add it to `results` (top-$k$ candidate heap).
     - **Crucial Systems Detail**: Even if $v$ fails the filter, it MUST still be added to the `candidates` exploration heap to maintain graph navigation through invalid nodes!
  2. `drill_31b_filtered_recall_bench.cpp`: Measure recall of single-stage graph filtering across selectivities ($50\%, 20\%, 5\%, 1\%$).
  3. `drill_31c_graph_disconnection_trap.cpp`: Demonstrate the classic graph disconnection phenomenon: when filter selectivity drops below $2\%$, graph paths become dead ends and recall plummets.
- 🛠️ **`secan`**: Add `FilteredSearch` API to `secan::index::HnswIndex`.

---

### Day 32 (Thu, Nov 19): The <2% Low-Selectivity SIMD Flat Bypass
- 📖 **Reading**: **Adaptive Filtered Search Strategy** (The industry standard technique used in Milvus / Qdrant to defend against low-selectivity filter collapse).
- 💻 **Drills (`day_32_drills.md`)**:
  1. `drill_32a_selectivity_estimator.cpp`: Compute filter selectivity: $\text{selectivity} = \text{popcount}(\text{filter\_bitset}) / N$.
  2. `drill_32b_simd_flat_bypass.cpp`: When $\text{selectivity} < 0.02$ ($< 2\%$):
     - **Bypass HNSW graph traversal entirely!**
     - Iterate through surviving bitset indices using `_tzcnt_u64` (trailing zero count bit-hopping).
     - Score surviving candidates directly with unrolled AVX2 distance kernel.
  3. `drill_32c_adaptive_switch_benchmark.cpp`: Benchmark adaptive search: show that for $0.5\%$ selectivity, the SIMD Flat Bypass achieves **100% recall and 10x higher QPS** than struggling through the disconnected HNSW graph!
- 🛠️ **`secan`**: Implement adaptive low-selectivity bypass in `secan/src/search/filtered_search.cpp`.

---

### Day 33 (Fri, Nov 20): Contiguous Flattened Graph Memory Layout
- 📖 **Reading**: Cache-friendly graph serialization: eliminating `std::vector` pointer indirection.
- 💻 **Drills (`day_33_drills.md`)**:
  1. `drill_33a_scattered_vs_flat_graph.cpp`: Compare pointer-based node representations (`std::vector<std::vector<uint32_t>>`) vs a single flat buffer `uint32_t* edges` with fixed capacity $M$.
  2. `drill_33b_flat_graph_search.cpp`: Implement `SEARCH-LAYER` directly on flat buffer with offset math: `node_offset = node_id * (M + 1)`.
  3. `drill_33c_traversal_speedup_bench.cpp`: Measure cache misses (`perf stat -e L1-dcache-load-misses`) of flat graph vs pointer graph during 10,000 queries. Witness a 2x–3x speedup.
- 🛠️ **`secan`**: Refactor `secan` HNSW storage to a single contiguous flattened buffer.

---

### Day 34 (Sat, Nov 21): Hierarchical Entry Point Navigation & Diversity Heuristic
- 💻 **Drills (`day_34_drills.md`)**:
  1. `drill_34a_random_level_generator.cpp`: Geometric random level assignment $l = \lfloor -\ln(\text{uniform}(0,1)) \cdot m_L \rfloor$.
  2. `drill_34b_heuristic_neighbor_pruning.cpp`: Heuristic neighbor selection (triangle inequality diversity pruning).
  3. `drill_34c_end_to_end_hnsw_bench.cpp`: Full multi-layer HNSW build and search on 50,000 vectors ($D=128$).
- 🛠️ **`secan`**: End-to-end HNSW verification with filtered search in `secan`.

---

### Day 35 (Sun, Nov 22): Timed Filtered HNSW Exam (No Notes)
- ⏱️ **45-minute timed coding exam**: Write `SEARCH-LAYER` with `ConcurrentBitset` attribute filtering AND the $<2\%$ selectivity SIMD flat bypass from a blank file with zero compiler warnings.
