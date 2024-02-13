#include "LeetCode.h"

class Solution {
   public:
    bool splitArraySameAverage(vector<int> &&nums) {
        int n = nums.size();
        if (n <= 1) return false;

        int sum = 0;
        for (auto x : nums) sum += x;

        vector<int> dp(sum + 1);
        dp[0] = 1;
        cout << sum << endl;

        for (int i = 1; i < n; i++) {
            for (int s = sum - nums[i]; s >= 0; s--)
                if (dp[s])
                    dp[s + nums[i]] |= (dp[s] << 1);

            dp[nums[i]] |= 2;
        }

        for (int len = 1; len < n; len++) {
            cout << endl;
            cout << 333 << sum * len;
            cout << endl;
            if ((sum * len) % n == 0 && ((1 << len) & dp[sum * len / n]))
                return true;
        }

        return false;
    }
};
int main() {
    Solution s;

    vector<int> nums {18, 10, 5, 3};
    // vector<int> nums = {11, 2, 3, 4, 5, 6, 7, 8};
    // vector<int> nums = {132, 42, 23, 36, 13, 5, 3, 2};
    // cout << s.splitArraySameAverage(nums);
    cout << s.splitArraySameAverage({18, 10, 5, 3});
    // cout << s.splitArraySameAverage(vector<int>{18, 10, 5, 3});
}