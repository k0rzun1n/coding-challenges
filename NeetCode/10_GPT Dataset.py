import torch
from typing import List, Tuple

class Solution:
    def batch_loader(self, raw_dataset: str, context_length: int, batch_size: int) -> Tuple[List[List[str]]]:
        torch.manual_seed(0)
        tokenized = raw_dataset.split()
        indices = torch.randint(low=0, high=len(tokenized) - context_length, size=(batch_size,)).tolist()
        X = []
        Y = []
        for idx in indices:
            X.append(tokenized[idx:idx+context_length])
            Y.append(tokenized[idx+1:idx+1+context_length])
        return X, Y



# Input:
# raw_dataset = "Hello darkness my old friend"
# context_length = 3
# batch_size = 2

# Output:
# X = [['darkness', 'my', 'old'], ['hello', 'darkness', 'my']]
# Y = [['my', 'old', 'friend'], ['darkness', 'my', 'old']]