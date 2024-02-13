#include "LeetCode.h"
class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> um;
        for (auto s : strs) {
            string tmp(s);
            sort(tmp.begin(), tmp.end());
            um[tmp].emplace_back(s);
        }
        for (auto& p : um)
            res.emplace_back(p.second);
        return res;
    }
};

int main() {
    Solution q;
    std::clock_t start = std::clock();
    vector<string> data{"eat", "tea", "tan", "ate", "nat", "bat"};
    auto v = q.groupAnagrams(data);
    cc, v;
    std::cout << "Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
    return 0;
}
