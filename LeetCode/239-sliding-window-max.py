from LeetCodeH import *


class Solution:
    def maxSlidingWindow(self, nums, k):
        n = len(nums)
        ans = []
        dq = collections.deque()

        for i in range(n):
            if dq and dq[0] <= i - k:
                dq.popleft()
            while dq and nums[dq[-1]] <= nums[i]:
                dq.pop()
            dq.append(i)
            if i >= k - 1:
                ans.append(nums[dq[0]])

        return ans


def main():
    q = Solution()
    data = [1, 3, -1, -3, 5, 3, 6, 7]
    cc-q.maxSlidingWindow(data, 3)
    data = [1, -1]
    cc-q.maxSlidingWindow(data, 1)
    data = [7, 2, 4]
    cc-q.maxSlidingWindow(data, 2)


main()
