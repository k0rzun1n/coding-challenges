#include "LeetCode.h"
class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& n, int k) {
        vector<int> res;
        map<int, int> tree;  // n count

        k--;
        for (int i = 0; i < k; i++) {
            tree[n[i]]++;
        }

        for (int i = 0; i < n.size() - k; i++) {
            tree[n[i + k]]++;
            int mx = (*tree.rbegin()).first;
            res.push_back(mx);
            tree[n[i]]--;
            if (!tree[n[i]])
                tree.erase(n[i]);
        }

        return res;
    }
};

int main() {
    Solution q;
    vector<int> data{1, 3, -1, -3, 5, 3, 6, 7};
    auto v = q.maxSlidingWindow(data, 3);
    // vector<int> data{1,-1};
    // auto v = q.maxSlidingWindow(data, 1);
    for (auto d : v) cout << d;

    return 0;
}