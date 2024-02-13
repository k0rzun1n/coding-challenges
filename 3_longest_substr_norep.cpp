#include "LeetCode.h"
class Solution {
   public:
    int lengthOfLongestSubstring(string z) {
        int res = 0;
        vector<int> pp(256, -1);  // prev pos
        int left = -1;
        for (int i = 0; i < z.length(); i++) {
            if (left < pp[z[i]]) left = pp[z[i]];
            pp[z[i]] = i;
            res = max(res, i - left);
        }

        return res;
    };
};

int main() {
    Solution q;
    // auto v = q.lengthOfLongestSubstring("pwwkew");
    // auto v = q.lengthOfLongestSubstring("aaaaaa");
    // auto v = q.lengthOfLongestSubstring("abba");
    // auto v = q.lengthOfLongestSubstring("vbxpvwkkteaiob");
    auto v = q.lengthOfLongestSubstring("abcabcbb");
    // auto v = q.lengthOfLongestSubstring(" ");
    // auto v = q.lengthOfLongestSubstring("abccc");
    // auto v = q.lengthOfLongestSubstring("a");
    !cc;
    cc, v;
    return 0;
}
