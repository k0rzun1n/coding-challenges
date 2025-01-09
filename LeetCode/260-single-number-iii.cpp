#include "LeetCode.h"
class Solution {
   public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res(2);
        for (int& n : nums) res[0] ^= n;

        int r1 = 1; //rightmost 1 in res[0]
        while (!(res[0] & r1)) r1 <<= 1; //assumed res[0]>0

        for (int& n : nums)
            if (r1 & n) res[1] ^= n;
        res[0] ^= res[1];
        return res;
    }
};

int main() {
    Solution q;
    vector<int> data;
    data = {1, 2, 1, 2, 5, 6, 8, 8};
    cc, q.singleNumber(data);
    return 0;
}
