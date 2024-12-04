#include "LeetCode.h"
unordered_map<char, char> cb{
    {'(', ')'},
    {'[', ']'},
    {'{', '}'}};
class Solution {
   public:
    int findMin(vector<int>& n) {
        cc, n;
        const int z = n.size();
        if (n.size() == 1) return n[0];
        int l = 0;
        int lp = 0;
        int r = z - 1;
        int b = 0;
        while (true) {
            ~cc;
            if (n[l] > n[r]) {
                cc, "1.", l, r;
                lp = l;
                l = (l + r + 1) / 2;
            } else if (n[l] < n[r]) {
                cc, "2.", l, r,lp;
                r = l;
                l = (lp + l) / 2;
                ~cc, "22.", l, r,lp;
            } else
                return n[l];
        }
        return 101;
    }
};
int main() {
    Solution q;
    
    vector<int> data{8,1,2,3,4,5,6,7};
    // vector<int> data{4,5,6,7,0,1,2};
    // vector<int> data{4, 5, 6, 7,8,8,8,8,8,8,8,8,8,8,8,8,9, 0, 1, 2};
    // vector<int> data{2,1};
    // vector<int> data{3, 4, 5, 1, 2};
    // vector<int> data{3,1,3};
    cc, q.findMin(data);
    return 0;
}