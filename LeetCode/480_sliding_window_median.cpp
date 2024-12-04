#include "LeetCode.h"
class Solution {
   public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        
        vector<int> initV(nums.begin(), nums.begin() + k);
        sort(initV.begin(), initV.end());  // set? radix?

        list<int>qq(initV.begin(),initV.end());
        // qq.push_back(nums[0]);
        // for (int i = 1; i < k; i++) {
        //     int& n = nums[i];
        //     if(n>qq.front())
        //         qq.push_back(n);
        //     else
        //         qq.push_front(n);
        // }
        cc, qq;
        return res;
    }
};

int main() {
    Solution q;
    vector<int> data{1, 3, -10, -3, 5, 3, 6, 7};
    auto v = q.medianSlidingWindow(data, 4);
    // vector<int> data{1, -1};
    // auto v = q.medianSlidingWindow(data, 1);
    for (auto d : v) cout << d;

    return 0;
}