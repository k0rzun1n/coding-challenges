#include "LeetCode.h"

class Solution {
   public:
    int characterReplacement(string s, int k) {
        vector<int> cnt(26);
        int cnt_max = 0;
        int res = 0;
        int l = 0;
        int r = 0;
        for (; r < s.size(); r++) {
            cnt_max = max(cnt_max, ++cnt[s[r] - 'A']);
            while (r - l + 1 - cnt_max > k) {
                cnt[s[l] - 'A']--;
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};

int main() {
    Solution q;
    cc, q.characterReplacement("BAAAB", 2);
    cc, q.characterReplacement("AAAAABBB", 2);
    cc, q.characterReplacement("AABBB", 2);
    cc, q.characterReplacement("ABBB", 2);
    cc, q.characterReplacement("ABAB", 2);
    cc, q.characterReplacement("AABABBA", 1);
    // cc, q.characterReplacement("AAAA", 2);
    cc, q.characterReplacement("AABABBACCCCCA",0);
    return 0;
}