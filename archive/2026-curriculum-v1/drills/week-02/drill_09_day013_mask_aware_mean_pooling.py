# ==============================================================================
# 🥋 Drill 09 (Week 02 / Day 013): DL Track — Mask-Aware Mean Pooling & L2 Normalization
#
# 📖 READING / CONTEXT:
# - Reimers & Gurevych: "Sentence-BERT: Sentence Embeddings using Siamese BERT-Networks"
#
# 🎯 CORE LESSON:
# 1. Mask-Aware Mean Pooling:
#    Embedding models pad sequences with zeros (attention_mask = 0).
#    Standard .mean(dim=1) erroneously divides by padding tokens!
#    Correct pooling: sum(token_embeddings * mask.unsqueeze(-1)) / sum(mask.unsqueeze(-1)).
# 2. Unit L2 Normalization:
#    embeddings = F.normalize(pooled, p=2, dim=-1)
#
# 🚀 RUN COMMAND:
# python3 drill_09_day013_mask_aware_mean_pooling.py
# ==============================================================================

import torch
import torch.nn.functional as F

def mask_aware_mean_pooling(
    last_hidden_state: torch.Tensor, # (B, S, D)
    attention_mask: torch.Tensor     # (B, S)
) -> torch.Tensor:
    """
    Computes true mean pooling ignoring padded tokens.
    """
    # 1. Expand mask to (B, S, 1)
    mask_expanded = attention_mask.unsqueeze(-1).float() # (B, S, 1)

    # 2. Zero out padding token embeddings
    sum_embeddings = torch.sum(last_hidden_state * mask_expanded, dim=1) # (B, D)

    # 3. Sum valid tokens (clamp to 1e-9 to avoid div-by-zero)
    sum_mask = torch.clamp(mask_expanded.sum(dim=1), min=1e-9) # (B, 1)

    # 4. Compute mean and normalize L2
    mean_pooled = sum_embeddings / sum_mask
    return F.normalize(mean_pooled, p=2, dim=-1)

if __name__ == "__main__":
    print("--- Week 02 Drill 09: Mask-Aware Mean Pooling & L2 Normalization ---\n")

    B, S, D = 2, 4, 32
    token_embeds = torch.randn(B, S, D)
    # Batch item 0 has 4 valid tokens; Batch item 1 has 2 valid tokens (last 2 padded)
    mask = torch.tensor([[1, 1, 1, 1], [1, 1, 0, 0]], dtype=torch.long)

    sentence_embeddings = mask_aware_mean_pooling(token_embeds, mask)
    print(f"Sentence Embeddings Shape: {sentence_embeddings.shape}")

    # Verify L2 Unit Norm: ||e||_2 = 1.0
    norms = torch.norm(sentence_embeddings, p=2, dim=-1)
    print(f"Computed L2 Norms: {norms}")

    assert sentence_embeddings.shape == (B, D)
    assert torch.allclose(norms, torch.ones(B), atol=1e-5), "Norms must be strictly 1.0!"
    print("\n✓ Week 02 Drill 09 Passed: Mask-aware pooling verified!")
