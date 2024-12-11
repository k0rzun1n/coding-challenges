#include "LeetCode.h"
class Solution {
   public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res;
        vector<pair<int, int>> bs;
        bs.reserve(buildings.size() * 2);
        for (int i = 0; i < buildings.size(); i++) {
            bs.emplace_back(make_pair(buildings[i][1], buildings[i][2]));
            bs.emplace_back(make_pair(buildings[i][0], -buildings[i][2]));
        }
        sort(bs.begin(), bs.end(),
             [](auto a, auto b) { return a.first < b.first || a.first == b.first && a.second < b.second; });
        multiset<int> s{0};
        int prev = 0;
        for (auto b : bs) {
            if (b.second < 0)
                s.insert(-b.second);
            else
                s.extract(b.second);
            int cur = *s.rbegin();
            if (prev != cur) {
                res.emplace_back(std::initializer_list<int>{b.first, cur});
                prev = cur;
            }
        }
        return res;
    }
};

int main() {
    Solution q;

    // LRH -> XH
    //[[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
    //[[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
    // vector<vector<int>> data{{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
    vector<vector<int>> data{{2, 9, 10}, {3, 7, 15}, {3, 7, 25}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
    // for (size_t i = 0; i < 2 && q.getSkyline({{1,2,3}}).size() > 2; i++) {}
    // cc, data;
    // !cc;
    auto res = q.getSkyline(data);
    !cc;
    cc, res;

    return 0;
}
