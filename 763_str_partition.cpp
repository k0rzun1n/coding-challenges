#include "LeetCode.h"
class Solution {
   public:
    vector<int> partitionLabels(string str) {
        vector<int> res;
        unordered_map<char, int> rmpos;  // rightmost pos
        
        for (int i = 0; i < str.length(); i++)
            rmpos[str[i]] = i;
        
        for (int i = 0; i < str.length();) {
            int mx = rmpos[str[i]];
            for (int j = i + 1; j <= mx; j++) {
                int& d = rmpos[str[j]];
                i = mx = max(mx, d);
            }
            res.push_back(mx);
            i++;
        }
        
        for (int i = res.size() - 1; i > 0; i--)
            res[i] -= res[i - 1];
        res[0]++;

        return res;
    };
};

int main() {
    Solution q;
    auto v = q.partitionLabels("ababcbacadefegdehijhklij");
    // auto v = q.partitionLabels("eaaaabaaec");
    !cc;
    for (auto i : v) cout << " " << i;
    return 0;
}

// Output: [9,7,8]
// 8 5 8 5 7 |5 8 7 8 14 |15 11 15 13 14 |15 19 22 23 19 |20 21 22 23
// 0 1 2 3 4  5 6 7 8 9   0  1  2  3  4   5  6  7  8  9   0  1  2  3
//  012345678 9012345 67890123
// "ababcbaca defegde hijhklij");
// "ababcbaca", "defegde", "hijhklij".
