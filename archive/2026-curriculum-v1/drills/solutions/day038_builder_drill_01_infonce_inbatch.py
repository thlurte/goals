#!/usr/bin/env python3
import torch
import torch.nn.functional as F

def infonce_loss(query_embeds: torch.Tensor, doc_embeds: torch.Tensor, temperature: float = 0.05) -> torch.Tensor:
    q_norm = F.normalize(query_embeds, p=2, dim=-1)
    d_norm = F.normalize(doc_embeds, p=2, dim=-1)
    logits = torch.matmul(q_norm, d_norm.T) / temperature
    labels = torch.arange(logits.shape[0], device=query_embeds.device)
    return F.cross_entropy(logits, labels)

def test_infonce():
    print("--- Testing InfoNCE Contrastive Loss (Solution) ---")
    torch.manual_seed(42)
    B, D = 16, 128
    queries = torch.randn(B, D, requires_grad=True)
    docs = queries.clone().detach() + torch.randn(B, D) * 0.1
    docs.requires_grad_(True)

    loss = infonce_loss(queries, docs, temperature=0.05)
    print(f"InfoNCE Loss: {loss.item():.4f}")
    loss.backward()

    assert loss.item() > 0.0, "Loss must be positive"
    assert queries.grad is not None and docs.grad is not None, "Gradients must propagate to inputs"
    print("\n✓ Drill Passed: InfoNCE in-batch contrastive loss verified!\n")

if __name__ == "__main__":
    test_infonce()
