#include "LeetCode.h"

class Solution {
   public:
    bool searchMatrix(vector<vector<int>> &vv, int target) {
        int rsz = vv[0].size();
        int l = 0;
        int r = rsz * vv.size() - 1;
        while (l != r) {
            int mid = (l + r - 1) >> 1;
            if (vv[mid / rsz][mid % rsz] < target)
                l = mid + 1;
            else
                r = mid;
        }
        return vv[r / rsz][r % rsz] == target;
    }
};

int main() {
    Solution q;
    // vector<vector<int>> m{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    // cout << q.searchMatrix(m, 11);
    // cout << q.searchMatrix(m, 13);
    // vector<vector<int>> m{{1, 3}};
    vector<vector<int>> m{{1}, {3}};
    cout << q.searchMatrix(m, 0);
    cout << q.searchMatrix(m, 1);
    cout << q.searchMatrix(m, 2);
    cout << q.searchMatrix(m, 3);
    cout << q.searchMatrix(m, 4);
    return 0;
}