import torch
import torch.nn as nn
from torchtyping import TensorType
from functools import reduce
from typing import List


class Solution:
    def get_dataset(
        self, positive: List[str], negative: List[str]
    ) -> TensorType[float]:
        words = reduce(lambda acc, nx: acc + nx.split(), positive + negative, [])
        # words = [w for s in positive + negative for w in s.split()]
        words = sorted(set(words))
        word2score = {}
        for i, w in enumerate(words):
            word2score[w] = i + 1
        res = []
        for s in positive + negative:
            res += torch.tensor([[word2score[w] for w in s.split()]])
        res = nn.utils.rnn.pad_sequence(res, batch_first=1 == 1)
        return res


positive = [
    "Good case, Excellent value.",
    "Great for the jawbone.",
    "The mic is great.",
    "If you are Razr owner...you must have this!",
    "Highly recommend for any one who has a blue tooth phone",
]
negative = [
    "So there is no way for me to plug it in here in the US unless I go buy a converter.",
    "Tied to charger for conversations lasting more than 45 minutes.MAJOR PROBLEMS!!",
    "I have to jiggle the plug to get it to line up right to get decent volume.",
    "Needless to say I wasted my money.",
    "What a waste of money and time!",
]
res = Solution().get_dataset(positive, negative)
print(res)

# [
# [3.0,22.0,2.0,67.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0]
# [4.0,27.0,59.0,37.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0]
# [12.0,42.0,35.0,30.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0]
# [7.0,73.0,19.0,10.0,52.0,47.0,32.0,61.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0]
# [5.0,55.0,27.0,18.0,51.0,72.0,31.0,16.0,20.0,64.0,53.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0]

# [11.0,60.0,35.0,49.0,71.0,27.0,41.0,63.0,54.0,36.0,34.0,33.0,34.0,59.0,14.0,65.0,6.0,29.0,21.0,16.0,25.0]
# [13.0,63.0,23.0,27.0,24.0,39.0,46.0,58.0,1.0,43.0,9.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0]
# [6.0,32.0,63.0,38.0,59.0,54.0,63.0,28.0,36.0,63.0,40.0,66.0,56.0,63.0,28.0,26.0,68.0,0.0,0.0,0.0,0.0]
# [8.0,63.0,57.0,6.0,70.0,48.0,45.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0]
# [15.0,16.0,69.0,50.0,44.0,17.0,62.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0]
# ]
