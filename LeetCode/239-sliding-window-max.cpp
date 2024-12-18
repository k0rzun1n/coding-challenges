#include "LeetCode.h"
class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;
        for (int i = 0; i < n; i++) {
            if (!dq.empty() && dq.front() <= i - k) dq.pop_front();
            while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
            dq.push_back(i);
            if (i >= k - 1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};

int main() {
    Solution q;
    vector<int> data;
    data = {1, 3, -1, -3, 5, 3, 6, 7};
    cc, q.maxSlidingWindow(data, 3);
    data = {1, -1};
    cc, q.maxSlidingWindow(data, 1);
    data = {7, 2, 4};
    cc, q.maxSlidingWindow(data, 2);
    return 0;
}