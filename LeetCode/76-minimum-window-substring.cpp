#include "LeetCode.h"
class Solution {
   public:
    string minWindow(string s, string t) {
        vector<int> freq(128, 0);
        for (auto c : t)
            freq[c]++;

        int cnt = 0;
        // left, right, lastvalid, bestL, bestR
        int l = 0, r = 0, lv = 0, bl = 0, br = INT_MAX;
        for (auto i = 0; i < s.size(); i++) {
            if (--freq[s[i]] >= 0) {  // s[i] in t
                r = i;
                cnt++;
                while (cnt == t.size())
                    if (++freq[s[lv = l++]] > 0) {
                        if (br - bl > r - l) br = r, bl = lv;
                        cnt--;
                    }
            }
        }
        return br == INT_MAX ? "" : s.substr(bl, br - bl + 1);
    }
};

int main() {
    Solution q;
    cc, q.minWindow("ADOBECODEBANC", "ABC");
    cc, q.minWindow("a", "a");
    cc, q.minWindow("a", "aa");
    cc, q.minWindow("aa", "aa");
    return 0;
}
