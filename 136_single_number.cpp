#include "LeetCode.h"
class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        int x =0;
        for (int n : nums){
            x ^= n;
            cc,x;
        }
        return x;
    }
};

int main() {
    Solution q;
    vector<int> v{2,2,1};
    q.singleNumber(v);
    return 0;
}