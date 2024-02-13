#include "LeetCode.h"
class Solution {
   public:
    vector<int> findAnagrams(string s, string p) {
        int pLenMinus1 = p.length() - 1;
        unordered_map<char, int> um;
        for (char c : p)
            um[c]++;
        for (int i = 0; i < pLenMinus1; i++)
            um[s[i]]--;

        vector<int> res;
        for (int i = pLenMinus1; i < s.length(); i++) {
            const int first = i - pLenMinus1;
            um[s[i]]--;
            bool isAna = true;
            for (auto p : um)
                if (p.second) {
                    isAna = false;
                    break;
                }
            if (isAna) res.push_back(first);
            um[s[first]]++;
        }

        return res;
    }
};

int main() {
    Solution q;
    auto v = q.findAnagrams("anagramana", "nagaram");
    for (auto i : v) cout << i;
    return 0;
}
