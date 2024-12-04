#include "LeetCode.h"
class Solution {
   public:
    // int maxProfit(vector<int>& prices) {
    //     int b = INT32_MAX;
    //     int s = 0;

    //     for (int& p : prices) {
    //         b = min(b, p);
    //         s = max(s, p - b);
    //     }

    //     return s;
    // }
    
    int maxProfit(vector<int>& prices) {
        int t_i10 = 0;
        int t_i11 = INT32_MIN;

        for (int& p : prices) {
            t_i10 = max(t_i10, t_i11 + p);
            t_i11 = max(t_i11, -p);
        }

        return t_i10;
    }
};

// Base cases:
// T[-1][k][0] = 0, T[-1][k][1] = -Infinity
// T[i][0][0] = 0, T[i][0][1] = -Infinity

// Recurrence relation:
// T[i][k][0] = max(T[i-1][k][0], T[i-1][k][1] + prices[i])
// T[i][k][1] = max(T[i-1][k][1], T[i-1][k-1][0] - prices[i])