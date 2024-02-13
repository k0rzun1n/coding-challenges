#include "LeetCode.h"
class Solution {
   public:
    int maxProfit(vector<int>& prices, int fee) {
        int t_ik0 = 0;
        int t_ik1 = INT32_MIN; 

        for (int& p : prices) {
            int t_ik0_im1 = t_ik0;  // i-1
            // t_ik0 = max(t_ik0_im1, t_ik1 + p - fee); //int32 overflow
            // t_ik1 = max(t_ik1, t_ik0_im1 - p);
            t_ik0 = max(t_ik0_im1, t_ik1 + p );
            t_ik1 = max(t_ik1, t_ik0_im1 - p - fee);
        }

        return t_ik0;
    }
};

int main() {
    Solution q;
    vector<int> data;
    data = {1, 3, 2, 8, 4, 9};  // 2 8
    cc, q.maxProfit(data, 2);
    data = {1, 3, 7, 5, 10, 3};  // 3 6
    cc, q.maxProfit(data, 3);

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