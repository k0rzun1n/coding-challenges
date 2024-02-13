#include "LeetCode.h"
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int t_ik0 = 0;
        int t_ik1 = INT32_MIN;
        int t_ik0_im1 = 0;  // i-1
        int t_ik0_im2 = 0;  // i-2

        for (int& p : prices) {
            t_ik0_im1 = t_ik0;
            t_ik0 = max(t_ik0_im1, t_ik1 + p);
            t_ik1 = max(t_ik1, t_ik0_im2 - p);
            t_ik0_im2 = t_ik0_im1; 
        }

        return t_ik0;
    }
};

int main() {
    Solution q;
    vector<int> data;
    data = {1,2,3,0,2};// 3
    cc, q.maxProfit(data);

    return 0;
}

// Base cases:
// T[-1][k][0] = 0, T[-1][k][1] = -Infinity
// T[i][0][0] = 0, T[i][0][1] = -Infinity

// Recurrence relation:
// T[i][k][0] = max(T[i-1][k][0], T[i-1][k][1] + prices[i])
// T[i][k][1] = max(T[i-1][k][1], T[i-1][k-1][0] - prices[i])

// Input: prices = [1,3,2,8,4,9], fee = 2
// Output: 8

// Input: prices = [1,3,7,5,10,3], fee = 3
// Output: 6