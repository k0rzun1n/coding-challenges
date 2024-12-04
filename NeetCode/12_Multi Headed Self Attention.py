import torch
import torch.nn as nn
from torchtyping import TensorType

class MultiHeadedSelfAttention(nn.Module):
     
    def __init__(self, embedding_dim: int, attention_dim: int, num_heads: int):
        super().__init__()
        torch.manual_seed(0)
        self.att_heads = nn.ModuleList()
        for i in range(num_heads):
            self.att_heads.append(SingleHeadAttention(embedding_dim, attention_dim // num_heads))

    def forward(self, embedded: TensorType[float]) -> TensorType[float]:
        head_outputs = []
        for head in self.att_heads:
            head_outputs.append(head(embedded))
        concatenated = torch.cat(head_outputs, dim = 2)
        return torch.round(concatenated, decimals=4)
    
class SingleHeadAttention(nn.Module):
    def __init__(self, embedding_dim: int, attention_dim: int):
        super().__init__()
        torch.manual_seed(0)
        self.key = nn.Linear(embedding_dim, attention_dim, bias=False)
        self.query = nn.Linear(embedding_dim, attention_dim, bias=False)
        self.value = nn.Linear(embedding_dim, attention_dim, bias=False)
        pass

    def forward(self, embedded: TensorType[float]) -> TensorType[float]:
        k = self.key(embedded)
        q = self.query(embedded)
        v = self.value(embedded)

        # embedded (B T E)
        # Batch(rows count) 
        # T(tokens per row; row len; context len; time?) 
        # Embedding dimensions 
        # Attention dimensions (head size; model_dim) 
        # D model_dim       
        # generally? model_dim == atention_dim == embedding_dim


        B, T, A = k.shape
        scores = q @ k.transpose(1, 2)
        scores /= A**0.5

        mask = torch.tril(torch.ones(T, T)) == 0
        scores = scores.masked_fill(mask, float("-inf"))
        scores = nn.functional.softmax(scores, dim=2)
        transformed = scores @ v
        return transformed.round(decimals=4)

