#include "LeetCode.h"
class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res{-1, -1};
        if (nums.size() == 0) return res;

        // rightmost
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        while (left < right) {
            mid = (left + 1 + right) / 2;  // ceil
            if (nums[mid] == target) {
                left = mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {  // <
                left = mid + 1;
            }
        }
        if (nums[right] != target) return res;
        res[1] = right;

        // leftmost
        right = left;
        left = 0;
        while (left != right) {
            mid = (left + right) / 2;
            if (nums[mid] == target) {
                right = mid;
            } else {  // <
                left = mid + 1;
            }
        }
        res[0] = left;

        return res;
    }
};

int main() {
    Solution q;
    vector<int> m{-2, 0, 3, 3, 3, 5, 9, 12};
    cc, q.searchRange(m, 0);
    cc, q.searchRange(m, 1);
    cc, q.searchRange(m, 3);
    m = {5, 7, 7, 8, 8, 10};
    cc, q.searchRange(m, 6);
    cc, q.searchRange(m, 7);
    cc, q.searchRange(m, 8);
    m = {2, 2};
    cc, q.searchRange(m, 3);
    return 0;
}