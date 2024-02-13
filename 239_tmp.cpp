#include "LeetCode.h"
class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& n, int k) {
        vector<int> res;
        set<int> tree;
        k--;
        for (int i = 0; i < k; i++) {
            tree.insert(n[i]);
        }

        for (int i = 0; i < n.size() - k; i++) {
            tree.insert(n[i + k]);
            res.push_back(*tree.rbegin());
            tree.erase(n[i]);
        }

        return res;
    }
};

int main() {
    Solution q;
    vector<int> data{1, 3, -1, -3, 5, 3, 6, 7};
    auto v = q.maxSlidingWindow(data, 3);
    for (auto d : v) cout << d;
    return 0;
}