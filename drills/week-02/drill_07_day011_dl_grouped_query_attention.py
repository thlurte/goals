# ==============================================================================
# 🥋 Drill 07 (Week 02 / Day 011): DL Builder Track — Grouped-Query Attention (GQA)
#
# 📖 READING / CONTEXT:
# - Ainslie et al.: "GQA: Training Generalized Multi-Query Transformer Models"
#
# 🎯 CORE LESSON:
# 1. Multi-Head (MHA: H_q = H_kv), Multi-Query (MQA: H_kv = 1), Grouped-Query (GQA: H_kv < H_q).
# 2. KV Head Repeat / Broadcasting:
#    If H_q = 8 and H_kv = 2, each KV head is shared across (8 / 2 = 4) Query heads.
#    `k = k.repeat_interleave(num_queries_per_kv, dim=1)`
#
# 🚀 RUN COMMAND:
# python3 drill_07_day011_dl_grouped_query_attention.py
# ==============================================================================

import torch
import torch.nn.functional as F
import math

def grouped_query_attention(
    q: torch.Tensor, # (B, H_q, S, d_k)
    k: torch.Tensor, # (B, H_kv, S, d_k)
    v: torch.Tensor, # (B, H_kv, S, d_k)
) -> torch.Tensor:
    B, H_q, S, d_k = q.shape
    H_kv = k.shape[1]
    assert H_q % H_kv == 0, "H_q must be divisible by H_kv"
    
    rep = H_q // H_kv
    # Repeat KV heads to match Q heads
    if rep > 1:
        k = k.repeat_interleave(rep, dim=1) # (B, H_q, S, d_k)
        v = v.repeat_interleave(rep, dim=1) # (B, H_q, S, d_k)

    scores = torch.matmul(q, k.transpose(-2, -1)) / math.sqrt(d_k)
    weights = F.softmax(scores, dim=-1)
    out = torch.matmul(weights, v)
    return out

if __name__ == "__main__":
    print("--- Week 02 Drill 07: Grouped-Query Attention (GQA) ---\n")

    B, S, d_k = 2, 16, 64
    H_q, H_kv = 8, 2 # 4 query heads per KV group

    q = torch.randn(B, H_q, S, d_k)
    k = torch.randn(B, H_kv, S, d_k)
    v = torch.randn(B, H_kv, S, d_k)

    out = grouped_query_attention(q, k, v)
    print(f"Q Shape:  {q.shape} (8 heads)")
    print(f"KV Shape: {k.shape} (2 heads)")
    print(f"Output:   {out.shape} (8 heads)")

    assert out.shape == (B, H_q, S, d_k)
    print("\n✓ Week 02 Drill 07 Passed: GQA broadcasting verified!")
