#include "LeetCode.h"
class Solution {
   public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> um;
        for (char c : s) um[c]++;
        for (char c : t) um[c]--;
        for (auto p : um)
            if (p.second) return false;
        return true;
    }
};

int main() {
    Solution q;
    auto v = q.isAnagram("anzagram", "nagaram");
    cout << v << " ";
    return 0;
}