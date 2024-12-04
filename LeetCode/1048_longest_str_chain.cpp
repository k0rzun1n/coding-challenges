#include "LeetCode.h"
class Solution {
   public:
    int longestStrChain(vector<string> &words) {
        sort(words.begin(), words.end(),
             [](const string &a,
                const string &b) { return a.size() > b.size(); });

        unordered_map<string, int> um;
        for (auto w : words) {
            um[w] = 1;
        }

        int res = 1;
        for (auto w : words) {
            int len = um[w];
            for (int i = 0; i < w.length(); i++) {
                string ss = w.substr(0, i) + w.substr(i + 1);
                if (um.find(ss) != um.end()) {
                    um[ss] = len + 1;
                    res = max(res, um[ss]);
                }
            }
        }
        return res;
    }
    // int longestStrChain(vector<string>& words) {
    //     sort(words.begin(), words.end(),
    //          [](const string &a,
    //             const string &b) { return a.size() < b.size(); });

    //     unordered_map<string, int> dp;

    //     int res = 0;
    //     for (string w : words) {
    //         for (int i = 0; i < w.length(); i++) {
    //             string pre = w.substr(0, i) + w.substr(i + 1);
    //             dp[w] = max(dp[w], dp.find(pre) == dp.end() ? 1 : dp[pre] + 1);
    //         }
    //         res = max(res, dp[w]);
    //     }
    //     return res;
    // }
};

int main() {
    Solution q;
    // 4  ["a","b","ba","bca","bda","bdca"]
    // 5  ["xbc","pcxbcf","xb","cxbc","pcxbc"]
    // 1  ["abcd","dbqca"]

    vector<string> v;

    // v = {"abcd", "dbqca"};
    // v = {"xbc","pcxbcf","xb","cxbc","pcxbc"};
    v = {"a", "b", "ba", "bca", "bda", "bdca"};
    cc, q.longestStrChain(v);

    // v = {"xbc", "pcxbcf", "xb", "cxbc", "pcxbc"};
    // cc, q.longestStrChain(v);

    // cc, q.longestStrChain(v);

    return 0;
}