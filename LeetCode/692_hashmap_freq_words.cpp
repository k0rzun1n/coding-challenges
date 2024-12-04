#include "LeetCode.h"
class Solution {
   public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> ms;
        multimap<int, string, greater<int>> freq;
        for (auto w : words) {
            ms[w]++;
        }
        for (auto it = ms.begin(); it != ms.end(); it++) {
            freq.insert(make_pair(it->second, it->first));
        }
        vector<string> res(0);
        auto it = freq.begin();
        while (k-- && it != freq.end()) {
            // cout << it->first << " " << it->second << endl;
            res.push_back(it->second);
            it++;
        }
        
        return res;
    }
};

int main() {
    Solution q;
    vector<string> m{"i", "i", "hove", "love", "love", "leetcode", "meetcode", "i", "love", "coding"};
    auto v = q.topKFrequent(m, 2);
    for (auto s : v) {
        cout << s << " ";
    }
    return 0;
}