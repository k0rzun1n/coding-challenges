#include "LeetCode.h"
class Solution {
   public:
    int search(vector<int>& n, int t) {
        int res = -1;
        int left = 0;
        int right = n.size() - 1;
        int z = findMinId(n);
        while (left <= right) {
            int mid = left + (right - left) / 2;
            // int mid = (right + left) / 2;
            int rmid = (mid + z) % n.size();
            if (n[rmid] == t) {
                return rmid;
            } else if (n[rmid] < t) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return res;
    }

    int findMinId(vector<int>& n) {
        const int z = n.size();
        if (n.size() == 1) return n[0];
        int l = 0;
        int lp = 0;
        int r = z - 1;
        int b = 0;
        while (true) {
            if (n[l] > n[r]) {
                lp = l;
                l = (l + r + 1) / 2;
            } else if (n[l] < n[r]) {
                r = l;
                l = (lp + l) / 2;
            } else
                return l;
        }
        return 101;
    }
};
int main() {
    Solution q;
    vector<int> data{4, 5, 6, 7, 0, 1, 2};
    // vector<int> data{1};
    ~cc, q.search(data, 1);
    // cc, q.search(data,3);
    return 0;
}

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
// Input: nums = [1], target = 0
// -1
