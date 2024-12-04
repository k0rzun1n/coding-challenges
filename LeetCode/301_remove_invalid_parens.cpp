#include "LeetCode.h"
class Solution {
   public:
    vector<string> removeInvalidParentheses(string s) {
        if (s.length() == 0) return {""};
        {
            // trim useless
            int l = 0;
            int r = s.length()-1;
            while (s[l++] == ')');
            while (s[r--] == '(');
        }
        const int len = s.length();  // 1 <= s.length <= 25
        int az_mask = 0;
        int imba_count = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] >= 'a' && s[i] <= 'z')
                az_mask |= 1 << i;
            if (s[i] == '(')
                imba_count++;
            if (s[i] == ')')
                imba_count--;
        }
        imba_count = abs(imba_count);
        vector<bool> cnk_vmask(len);
        bool done = false;
        unordered_set<string> us;
        for (int bit_count = imba_count; !done && bit_count < len; bit_count++) {
            for (int j = 0; j < bit_count; j++)
                cnk_vmask[j] = true;
            for (int j = bit_count; j < len; j++)
                cnk_vmask[j] = false;
            do {
                int count = 0;
                for (int i = 0; i < len; i++) {
                    // isValid
                    // if (cnk_vmask[i] & az_mask) {
                    //     count = -1;
                    //     break;
                    // }
                    if ((1 << i) & az_mask) continue;
                    if (cnk_vmask[i]) continue;
                    char c = s[i];
                    if (c == '(') count++;
                    if (c == ')') count--;
                    if (count < 0) break;
                }
                if (count == 0) {
                    // add
                    string tmp;
                    for (int i = 0; i < len; i++) {
                        if (cnk_vmask[i]) continue;
                        tmp += s[i];
                    }
                    us.emplace(tmp);
                    done = true;
                }
            } while (prev_permutation(begin(cnk_vmask), end(cnk_vmask)));
        }
        vector<string> res;
        for (auto &p : us)
            res.emplace_back(p);
        if (res.size() == 0)
            res.emplace_back("");
        return res;
    }
};

int main() {
    Solution q;
    // auto v = q.removeInvalidParentheses("");
    // auto v = q.removeInvalidParentheses("n");
    // auto v = q.removeInvalidParentheses("x(");
    auto v = q.removeInvalidParentheses("((((((((((((((((((((aaaaa");  // rle? imba count?
    // auto v = q.removeInvalidParentheses("(a)())()");
    // auto v = q.removeInvalidParentheses(")a(");
    // auto v = q.removeInvalidParentheses("(aa))");
    // auto v = q.removeInvalidParentheses("(aa)(()))(");
    cc, v;
    cc, v.size();
    return 0;
}

// "(a)())()"
// ["a)())()"]
// expected
// ["(a())()","(a)()()"]