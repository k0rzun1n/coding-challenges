#include "LeetCode.h"
class Solution {
   public:
    int maxArea(vector<int>& h) {
        int left = 0;
        int right = h.size() - 1;
        int maxA = 0;

        while (left < right) {
            const int b = (right - left);
            maxA = max(maxA, b * min(h[left], h[right]));

            if (h[left] < h[right])
                left++;
            else
                right--;
        }

        return maxA;
    }
};
int main() {
    Solution q;
    //               0  1  2  3  4  5  6  7  8
    vector<int> data{1, 8, 6, 2, 5, 4, 8, 3, 7};
    // vector<int> data{1,1};
    auto v = q.maxArea(data);
    !cc;
    cc, v;
    return 0;
}
