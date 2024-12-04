import torch
import torch.nn as nn
from torchtyping import TensorType


# 0. Instantiate the linear layers in the following order: Key, Query, Value.
# 1. Biases are not used in Attention, so for all 3 nn.Linear() instances, pass in bias=False.
# 2. torch.transpose(tensor, 1, 2) returns a B x T x A tensor as a B x A x T tensor.
# 3. This function is useful:
#    https://pytorch.org/docs/stable/generated/torch.nn.functional.softmax.html
# 4. Apply the masking to the TxT scores BEFORE calling softmax() so that the future
#    tokens don't get factored in at all.
#    To do this, set the "future" indices to float('-inf') since e^(-infinity) is 0.
# 5. To implement masking, note that in PyTorch, tensor == 0 returns a same-shape tensor
#    of booleans. Also look into utilizing torch.ones(), torch.tril(), and tensor.masked_fill(),
#    in that order.
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

        B, T, A = k.shape
        scores = q @ k.transpose(1, 2)
        scores /= A**0.5

        mask = torch.tril(torch.ones(T, T)) == 0
        scores = scores.masked_fill(mask, float("-inf"))
        scores = nn.functional.softmax(scores, dim=2)
        transformed = scores @ v
        return transformed.round(decimals=4)


s = SingleHeadAttention(2, 3)
cc-type(s)
embedded = [
    [[-1.4381, 0.1232], [-0.1080, 0.3458]],
    [[0.1929, -0.8567], [-0.1160, 1.2547]],
]
embedded = torch.tensor(embedded)
# cc-s.forward(embedded)


# Input:
# embedding_dim = 2
# attention_dim = 3
# /////embedded = [
#   [[-1.4381, 0.1232],
#    [-0.1080, 0.3458]],
#   [[0.1929, -0.8567],
#    [-0.1160, 1.2547]]
# ]

# Output:[
#   [[-0.9737, 0.4302, -0.4216],
#    [-2.4031, 1.4092, 1.3797]],
#   [[ 1.7862, -2.1856, 0.2375],
#    [-0.7592, -0.1953, -0.4658]]
# ]
