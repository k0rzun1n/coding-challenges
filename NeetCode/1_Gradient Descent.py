class Solution:
    def get_minimizer(self, iterations: int, learning_rate: float, init: int) -> float:
        minimizer = init

        for _ in range(iterations):
            print(round(minimizer, 5))
            derivative = 2 * minimizer
            minimizer = minimizer - learning_rate * derivative

        return round(minimizer, 5)

# res = Solution().get_minimizer(iterations = 0, learning_rate = 0.01, init = 5)
# print(res)
# res = Solution().get_minimizer(iterations = 10, learning_rate = 0.01, init = 5)
# print(res)
res = Solution().get_minimizer(iterations = 10, learning_rate = 0.01, init = -50)
print(res)


# Input: 
# iterations = 0, learning_rate = 0.01, init = 5
# Output:
# 5

# Input: 
# iterations = 10, learning_rate = 0.01, init = 5
# Output:
# 4.08536
