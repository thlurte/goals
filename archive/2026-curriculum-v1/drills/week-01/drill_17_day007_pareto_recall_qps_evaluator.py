# ==============================================================================
# 🥋 Drill 17 (Week 01 / Day 007): Python — Pareto Frontier & Recall@K vs QPS Evaluator
#
# 📖 READING / CONTEXT:
# - Systems Benchmarking Standard for Vector Search Engines (ann-benchmarks / secan)
#
# 🎯 CORE LESSON:
# 1. Recall@K Metric:
#    Recall@K = (retrieved_top_k INTERSECT ground_truth_top_k) / K
# 2. Queries Per Second (QPS):
#    QPS = num_queries / total_search_time_seconds
# 3. Pareto Frontier:
#    A configuration is Pareto-optimal if no other configuration has BOTH higher Recall AND higher QPS.
#
# 🚀 RUN COMMAND:
# python3 drill_17_day007_pareto_recall_qps_evaluator.py
# ==============================================================================

import numpy as np
from typing import List, Dict, Tuple

def compute_recall_at_k(retrieved_ids: np.ndarray, ground_truth_ids: np.ndarray, k: int) -> float:
    """
    retrieved_ids: (NumQueries, K)
    ground_truth_ids: (NumQueries, K)
    """
    num_queries = retrieved_ids.shape[0]
    total_matches = 0
    for q in range(num_queries):
        ret_set = set(retrieved_ids[q, :k])
        gt_set = set(ground_truth_ids[q, :k])
        total_matches += len(ret_set.intersection(gt_set))
    return total_matches / (num_queries * k)

def extract_pareto_frontier(runs: List[Dict[str, float]]) -> List[Dict[str, float]]:
    """
    Extracts Pareto optimal (Recall, QPS) points where higher is better for both.
    """
    # Sort runs primarily by Recall descending, secondarily by QPS descending
    sorted_runs = sorted(runs, key=lambda x: (x["recall"], x["qps"]), reverse=True)
    pareto_points = []
    max_qps_seen = -1.0
    
    for run in sorted_runs:
        if run["qps"] > max_qps_seen:
            pareto_points.append(run)
            max_qps_seen = run["qps"]
            
    return pareto_points

if __name__ == "__main__":
    print("--- Week 01 Drill 17: Pareto Frontier & Recall vs QPS Evaluation ---\n")

    # 1. Test Recall@10
    num_q, k = 100, 10
    # Simulate ground truth
    gt = np.arange(num_q * k).reshape(num_q, k)
    # Simulate retrieved (8 out of 10 match per query)
    ret = gt.copy()
    ret[:, -2:] = 999999 # Corrupt last 2 items
    
    recall_10 = compute_recall_at_k(ret, gt, k=10)
    print(f"Computed Recall@10: {recall_10:.4f} (Expected: 0.8000)")
    assert np.isclose(recall_10, 0.80)

    # 2. Test Pareto Frontier Extraction
    test_runs = [
        {"name": "config_A", "recall": 0.95, "qps": 1000.0},
        {"name": "config_B", "recall": 0.90, "qps": 2500.0},
        {"name": "config_C", "recall": 0.85, "qps": 2000.0}, # Dominated by config_B (lower recall AND lower QPS)
        {"name": "config_D", "recall": 0.70, "qps": 5000.0},
    ]
    pareto = extract_pareto_frontier(test_runs)
    print("\nPareto Optimal Configurations:")
    for p in pareto:
        print(f"  {p['name']}: Recall = {p['recall']:.2f}, QPS = {p['qps']:.0f}")

    assert len(pareto) == 3
    assert all(p["name"] != "config_C" for p in pareto), "config_C is dominated and should not be in Pareto set!"
    
    print("\n✓ Week 01 Drill 17 Passed: Recall & Pareto evaluation verified!")
