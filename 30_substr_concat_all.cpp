#include "LeetCode.h"
class Solution {
   public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        const char* str = s.c_str();
        unordered_map<string_view, int> um_full;
        for (string_view w : words) um_full[w]++;
        const int wlen = words[0].length();
        const int tl = words.size() * wlen;  // target len
        for (int k = 0; k < wlen; k++) {
            int ws = k;               // window start
            int zc = um_full.size();  // zero count
            auto um_window = um_full;
            for (int i = k; i < s.length(); i += wlen) {
                // string_view ss = s.substr(i, wlen);
                string_view ss (str + i, wlen);
                if (um_full.find(ss) == um_full.end()) {
                    um_window = um_full;  // bad word, reset window
                    ws = i + wlen;
                    zc = um_full.size();
                    continue;
                }
                int cur = um_window[ss];
                int next = --um_window[ss];
                if (next == 0) zc--;
                if (cur == 0) zc++;
                if (i + wlen - ws == tl) {
                    if (!zc) {
                        res.push_back(ws);
                    }
                    // ss = s.substr(ws, wlen);
                    ss = string_view (str + ws, wlen);
                    cur = um_window[ss];
                    next = ++um_window[ss];
                    if (next == 0) zc--;
                    if (cur == 0) zc++;
                    ws += wlen;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution q;

    vector<string> v;

    v = {"foo", "bar"};
    // v = {"bar"};
    cc, q.findSubstring("barfoothefoobarman", v);
    // v = {"word", "good", "best", "good"};
    // cc, q.findSubstring("wordgoodgoodgoodbestword", v);
    v = {"fooo", "barr", "wing", "ding", "wing"};
    cc, q.findSubstring("lingmindraboofooowingdingbarrwingmonkeypoundcake", v);
    v = {"aa", "aa"};
    cc, q.findSubstring("aaaaaaaaaaaaaa", v);
    // Output
    // [0,2,4,6,8,10]
    // Expected
    // [0,1,2,3,4,5,6,7,8,9,10]

    return 0;
}