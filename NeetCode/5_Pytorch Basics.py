import torch
import torch.nn
from torchtyping import TensorType

# Helpful functions:
# https://pytorch.org/docs/stable/generated/torch.reshape.html
# https://pytorch.org/docs/stable/generated/torch.mean.html
# https://pytorch.org/docs/stable/generated/torch.cat.html
# https://pytorch.org/docs/stable/generated/torch.nn.functional.mse_loss.html


# Round your answers to 4 decimal places using torch.round(input_tensor, decimals = 4)
class Solution:
    def reshape(self, inp: TensorType[float]) -> TensorType[float]:
        M, N = inp.shape
        reshaped = torch.reshape(inp, (M * N // 2, 2))
        return torch.round(reshaped, decimals=4)

    def average(self, to_avg: TensorType[float]) -> TensorType[float]:
        return torch.mean(to_avg,0)

    def concatenate(
        self, cat_one: TensorType[float], cat_two: TensorType[float]
    ) -> TensorType[float]:
        return torch.cat((cat_one, cat_two), 1)

    def get_loss(
        self, prediction: TensorType[float], target: TensorType[float]
    ) -> TensorType[float]:
        return torch.nn.functional.mse_loss(prediction, target)
