#include "LeetCode.h"
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return -1;
    }
};

int main() {
    Solution q;
    vector<int> m{-2, 0, 3, 5, 9, 12};
    // cout << q.search(m, -3);
    // cout << q.search(m, -2);
    // cout << q.search(m, -1);
    cout << q.search(m, 0);
    cout << q.search(m, 1);
    cout << q.search(m, 3);
    // cout << q.search(m, 4);
    // cout << q.search(m, 5);
    // cout << q.search(m, 6);
    // cout << q.search(m, 9);
    // cout << q.search(m, 10);
    // cout << q.search(m, 12);
    // cout << q.search(m, 14);
    return 0;
}