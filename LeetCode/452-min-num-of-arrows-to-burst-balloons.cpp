#include "LeetCode.h"
class Solution {
   public:
    int findMinArrowShots(vector<vector<int>>& points) {
        vector<pair<int, int>> pp;
        pp.reserve(points.size() * 2);
        for (int i = 0; i < points.size(); ++i)
            pp.emplace_back(make_pair(points[i][0], points[i][1]));

        sort(pp.begin(), pp.end(), [](auto a, auto b) { return a.first < b.first; });
        int r = pp[0].second;
        int res = 1;
        for (auto&& p : pp) {
            if (p.first <= r) {
                r = min(r, p.second);
                continue;
            }
            r = p.second;
            res++;
        }
        return res;
    }
};
int main() {
    Solution q;
    vector<vector<int>> data;

    data = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    cc, q.findMinArrowShots(data);  // 2
    data = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    cc, q.findMinArrowShots(data);  // 4
    data = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    cc, q.findMinArrowShots(data);  // 2
    data = {{-2147483647 - 1, 2147483647}};
    cc, q.findMinArrowShots(data);  // 1
    data = {{1, 2}, {4, 5}, {1, 5}};
    cc, q.findMinArrowShots(data);  // 2
    data = {{9, 12}, {1, 10}, {4, 11}, {8, 12}, {3, 9}, {6, 9}, {6, 7}};
    cc, q.findMinArrowShots(data);  // 2
    return 0;
}

