#include "LeetCode.h"
class Solution {
   public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;

        vector<int> initV(nums.begin(), nums.begin() + k);
        sort(initV.begin(), initV.end());  // set? radix?

        vector<unordered_multiset<int>> v(2);  // LR

        int lMax = INT32_MIN;
        int rMin = INT32_MAX;
        vector<int> mn{INT32_MAX, INT32_MAX};  // min LR
        vector<int> mx{INT32_MIN, INT32_MIN};  // max LR
        for (int i = 0; i < k / 2; i++) {
            cc, i;
            int& n = initV[i];
            v[0].insert(n);
            mn[0] = min(mn[0], n);
            mx[0] = max(mx[0], n);
        }
        for (int i = k / 2; i < k; i++) {
            cc, i;
            int& n = initV[i];
            v[1].insert(n);
            mn[1] = min(mn[1], n);
            mx[1] = max(mx[1], n);
        }
        !cc;
        cc, mn[0];
        cc, mx[0];
        cc, mn[1];
        cc, mx[1];
        if (k % 2 == 0) {
            cc, (mx[0] + mn[1]) / 2.0;
            cc, (mx[0] + mn[1]) / 2.0;
        }
        return res;
    }
};

int main() {
    Solution q;
    vector<int> data{1, 3, -10, -33, 5, 3, 6, 7};
    auto v = q.medianSlidingWindow(data, 4);
    // vector<int> data{1, -1};
    // auto v = q.medianSlidingWindow(data, 1);
    for (auto d : v) cout << d;

    return 0;
}