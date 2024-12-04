#include "LeetCode.h"
unordered_map<char, char> cb{
    {'(', ')'},
    {'[', ']'},
    {'{', '}'}};
class Solution {
   public:
    vector<string> removeInvalidParentheses(string s) {
        if (s.size() == 0) return {""};
        int az_mask = 0;
        unsigned skip_mask = 0;      // skip mask
        const int len = s.length();  // 1 <= s.length <= 25
        for (int i = 0; i < len; i++)
            if (s[i] >= 'a' && s[i] <= 'z')
                az_mask |= 1 << i;
        unordered_map<string, int> um;
        int rm_count_min = INT32_MAX;
        for (int i = 0; i < (1 << len); i++) {
            if (i & az_mask) continue;
            if (isValid(s, i | az_mask)) {
                string s_masked = "";
                for (int j = 0; j < len; j++) {
                    if ((1 << j) & i) continue;
                    s_masked += s[j];
                }
                int rm_count = countSetBits(i);
                if (rm_count > rm_count_min) continue;
                rm_count_min = min(rm_count_min, rm_count);
                um.insert({s_masked, rm_count});
            }
        }
        vector<string> res;
        for (auto p : um)
            if (p.second == rm_count_min)
                res.push_back(p.first);

        return res;
    }
    uint32_t countSetBits(uint32_t n) {
        uint32_t count = 0;
        while (n) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
    uint32_t bitCount(uint32_t n) {
        n = n - ((n >> 1) & 0x55555555);
        n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
        return ((n + (n >> 4) & 0xF0F0F0F) * 0x1010101) >> 24;
    }

    bool isValid(const string& s, const uint32_t& mask) {
        vector<char> stk(26);
        int top = -1;
        for (int i = 0; i < s.length(); i++) {
            if ((1 << i) & mask) continue;
            char c = s[i];
            if (top != -1 && cb[stk[top]] == c)
                top--;
            else
                stk[++top] = c;
        }
        return top == -1;
    };
};

int main() {
    Solution q;
    // auto v = q.removeInvalidParentheses("");
    // auto v = q.removeInvalidParentheses("n");
    auto v = q.removeInvalidParentheses("([]]))(");
    cc, v;
    cc, v.size();
    return 0;
}