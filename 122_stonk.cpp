#include "LeetCode.h"
class Solution {
   public:
    // int maxProfit(vector<int>& prices) {
    //     int b = INT32_MAX;
    //     int s = 0;
    //     int s_max = 0;
    //     int res = 0;
    //     int s_prev = 0;
    //     for (int &p: prices) {
    //         b = min(b, p);
    //         s = p - b;
    //         s_max = max(s, s_max);
    //         if (s < s_prev) {
    //             b = p;
    //             res += s_max;
    //             s_max = 0;
    //         }
    //         s_prev = s;
    //     }
    //     res += s_max;
    //     return res;
    // }

    int maxProfit(vector<int>& prices) {
        int t_ik0 = 0;
        int t_ik1 = INT32_MIN;

        for (int& p : prices) {
            int t_ik0_im1 = t_ik0; //i-1
            t_ik0 = max(t_ik0_im1, t_ik1 + p);
            t_ik1 = max(t_ik1, t_ik0_im1 - p);
        }

        return t_ik0;
    }
};

int main() {
    Solution q;

    return 0;
}