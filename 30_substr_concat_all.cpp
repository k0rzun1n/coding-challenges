#include "LeetCode.h"
class Solution {
   public:
    vector<int> findSubstring(string s, vector<string> &words) {
        cc, s, words;
        vector<int> res;
        const int wl = words[0].length();
        unordered_map<string, int> ww;
        for (auto w : words) ww[w]++;
        auto dd = ww;
        // cc, dd;
        for (int k = 0; k < wl; k++) {
            int ws = k;  // window start
            for (int i = k; i <= s.length() - wl; i += wl) {
                string ss = s.substr(i, wl);
                cc, ss;
                if (ww.find(ss) == ww.end()) {
                    dd = ww;
                    ws = i + wl;
                    continue;
                }
                if (--dd[ss] == 0) {
                    dd.erase(ss);
                    if (dd.size() == 0) {
                        res.push_back(ws);
                        ++dd[s.substr(ws, wl)];
                        ws += wl;
                    }
                } else {
                    dd = ww;
                    if (--dd[ss] == 0) {
                        dd.erase(ss);
                    }
                    ws = i;
                }
                ~cc;
                cc, dd;
                cc, dd.size();
                !cc;
            }
        }
        return res;
    }
};

int main() {
    Solution q;

    vector<string> v;

    v = {"foo", "bar"};
    cc, q.findSubstring("barfoothefoobarman", v);
    cc, q.findSubstring("zbarfoobarfoobarthefoobarman", v);
    // cc, q.findSubstring("barfoofoobarthefoobarman", v);

    // v = {"xbc", "pcxbcf", "xb", "cxbc", "pcxbc"};
    // cc, q.longestStrChain(v);

    // cc, q.longestStrChain(v);

    return 0;
}