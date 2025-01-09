#include "leetcode.h"
class Solution {
   public:
    int rangeBitwiseAnd(int left, int right) {
        while (right > left)
            right &= right - 1;
        return right & left;
    }
};

int main() {
    Solution q;
    cc, q.rangeBitwiseAnd(5, 7);
    return 0;
}
