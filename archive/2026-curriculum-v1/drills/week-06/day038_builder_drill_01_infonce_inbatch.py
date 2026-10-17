#!/usr/bin/env python3
"""
🥋 Morning Builder Drill 38.1: InfoNCE Loss with In-Batch Negatives & Temperature

🚀 RUN COMMAND:
python3 day038_builder_drill_01_infonce_inbatch.py

CONTEXT:
Contrastive embedding models (e.g. CLIP, DPR, Contriever) use in-batch negatives:
For batch of pairs (q_i, d_i), similarity matrix S = (Q @ D^T) / tau has positive pairs on the diagonal (S[i, i])
and all other elements in row i (S[i, j], j != i) act as negatives.

CONCEPTS TO PRACTICE:
1. L2 normalization of query and document embeddings.
2. Pairwise cosine similarity matrix: (B, D) @ (D, B) -> (B, B).
3. Temperature scaling (tau = 0.05).
4. Cross-entropy loss with ground truth labels = torch.arange(B).
"""

import torch
import torch.nn as nn
import torch.nn.functional as F

# TODO 1: Implement InfoNCE loss function with in-batch negatives
# Args:
#   query_embeds: Tensor of shape (B, D)
#   doc_embeds: Tensor of shape (B, D)
#   temperature: Scaling factor tau (default 0.05)
# Returns:
#   scalar loss tensor
def infonce_loss(query_embeds: torch.Tensor, doc_embeds: torch.Tensor, temperature: float = 0.05) -> torch.Tensor:
    # [YOUR CODE HERE]
    # 1. Normalize query_embeds and doc_embeds across embedding dimension using F.normalize(..., p=2, dim=-1).
    # 2. Compute similarity logits matrix: logits = (q_norm @ d_norm.T) / temperature (shape: B, B).
    # 3. Create target labels: labels = torch.arange(B, device=query_embeds.device).
    # 4. Compute cross entropy loss: F.cross_entropy(logits, labels).
    pass

def test_infonce():
    print("--- Testing InfoNCE Contrastive Loss with In-Batch Negatives ---")
    torch.manual_seed(42)
    B, D = 16, 128
    queries = torch.randn(B, D, requires_grad=True)
    # Docs are slightly perturbed versions of queries
    docs = queries.clone().detach() + torch.randn(B, D) * 0.1
    docs.requires_grad_(True)

    loss = infonce_loss(queries, docs, temperature=0.05)
    print(f"InfoNCE Loss: {loss.item():.4f}")
    loss.backward()

    assert loss.item() > 0.0, "Loss must be positive"
    assert queries.grad is not None and docs.grad is not None, "Gradients must propagate to inputs"
    print("\n✓ Drill Passed: InfoNCE in-batch contrastive loss and gradient flow verified!\n")

if __name__ == "__main__":
    test_infonce()
