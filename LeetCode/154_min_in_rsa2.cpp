#include "LeetCode.h"
unordered_map<char, char> cb{
    {'(', ')'},
    {'[', ']'},
    {'{', '}'}};
class Solution {
   public:
    // int findMin(vector<int>& v) {
    //     auto result = min_element(v.begin(), v.end());
    //     return *result;
    // }
    // int findMin(vector<int>& n) {
    //     int l = 0;
    //     int r = n.size() - 1;
    //     int mid = 0;

    //     while (l < r) {
    //         mid = l + (r - l) / 2;

    //         if (n[mid] > n[r])
    //             l = mid + 1;
    //         else if (n[mid] < n[r])
    //             r = mid;
    //         else
    //             r--;
    //     }
    //     l = n[l];
    //     n.clear();
    //     return l;
    // }
    //bad 313
    int findMin(vector<int>& n) {
        cc, n;
        const int z = n.size();
        if (n.size() == 1) return n[0];
        int l = 0;
        int lp = 0;
        int r = z - 1;
        int b = 0;
        while (l<r) {
            if (n[l] > n[r]) {
                lp = l;
                l = (l + r + 1) / 2;
            } else if (n[l] < n[r]) {
                r = l;
                l = (lp + l) / 2;
            } else
                return n[l];
        }
        return 101;
    }
};

int main() {
    Solution q;

    // vector<int> data{8,1,2,3,4,5,6,7};
    // vector<int> data{4,5,6,7,0,1,2};
    // vector<int> data{4, 5, 6, 7,8,8,8,8,8,8,8,8,8,8,8,8,9, 0, 1, 2};
    // vector<int> data{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,9, 0,1,2,3,4,5,6,7,8,8};
    // vector<int> data{2,1};
    // vector<int> data{3, 4, 5, 1, 2};
    vector<int> data{3, 1, 3};
    cc, q.findMin(data);
    return 0;
}