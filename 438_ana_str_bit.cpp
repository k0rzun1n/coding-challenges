#include "LeetCode.h"
class Solution {
   public:
    vector<int> findAnagrams(string s, string p) {
        int pLenMinus1 = p.length() - 1;
        int bm = 0;
        for (int i = 0; i < pLenMinus1; i++)
            bm ^= s[i];
        for (char c : p)
            bm ^= c;

        vector<int> res;
        for (int i = pLenMinus1; i < s.length(); i++) {
            const int first = i - pLenMinus1;
            bm ^= s[i];
            if (!bm) res.push_back(first);
            bm ^= s[first];
        }
        return res;
    }
};

int main() {
    Solution q;
    auto v = q.findAnagrams("aa", "bb");
    // auto v = q.findAnagrams("anagramana", "nagaram");
    for (auto i : v) cout << i;
    return 0;
}
