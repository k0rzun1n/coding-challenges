#include "LeetCode.h"
class Solution {
   public:
    int numIslands(vector<vector<char>>& g) {
        int cnt = 0;
        for (int y = 0; y < g.size(); y++) {
            for (int x = 0; x < g[0].size(); x++) {
                auto& c = g[y][x];
                if (c & 2) continue;  // visited
                if (c & 1) {
                    rc(g, y, x);
                    cnt++;
                }
            }
        }
        return cnt;
    }
    void rc(vector<vector<char>>& g, const int& y, const int& x) {
        if (x < 0 || y < 0 || x >= g[0].size() || y >= g.size()) return;
        if (g[y][x] & 2) return;
        if (!(g[y][x] & 1)) return;

        g[y][x] |= 2;
        rc(g, y, x - 1);
        rc(g, y - 1, x);
        rc(g, y, x + 1);
        rc(g, y + 1, x);
    }
};

int main() {
    Solution q;
    vector<vector<char>> data{
        {1, 1, 1, 1, 0},
        {1, 1, 0, 1, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0}};
    vector<vector<char>> data2{
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1}};
    auto v = q.numIslands(data2);
    !cc;
    cc, v;

    return 0;
}
