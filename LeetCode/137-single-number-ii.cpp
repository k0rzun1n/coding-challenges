#include "LeetCode.h"
class Solution {
   public:
    int singleNumber(vector<int> &nums) {
        int b0 = 0, b1 = 0; // "orthogonal" bits 0 1
        int c = 0; // carry bit
        for (int &n : nums) {
            c = b0 & n;
            b0 ^= n;
            b1 ^= c;

            c = b0 & b1; //3
            b0 ^= c;
            b1 ^= c;
        }
        return b0;
    }
};

int main() {
    Solution q;
    vector<int> data;
    data = {7, 7, 7, 16};
    cc, q.singleNumber(data);
    return 0;
}
