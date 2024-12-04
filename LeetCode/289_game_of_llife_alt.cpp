#include "LeetCode.h"
class Solution {
   public:
    void gameOfLife(vector<vector<int>>& v) {
        // v[y][x] bits: 0 state; 1-4 neighbour count;
        const int h = v.size();
        const int w = v[0].size();
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                for (int j = -1; j <= 1; j++) {
                    for (int i = -1; i <= 1; i++) {
                        if (!(i == 0 && j == 0) && x + i >= 0 && y + j >= 0 && x + i < w && y + j < h)
                            v[y][x] += (v[y + j][x + i] & 1) * 2;
                    }
                }
            }
        }
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                int nc = v[y][x] >> 1;  // neighbour count
                if (nc < 2 || nc > 3) v[y][x] = 0;
                if (nc == 2) v[y][x] &= 1;
                if (nc == 3) v[y][x] = 1;
            }
        }
    }
};

int main() {
    Solution q;

    vector<vector<int>> v;
    v = {{0, 1, 0},  //
         {0, 0, 1},
         {1, 1, 1},
         {0, 0, 0}};
    // v = {{1, 0, 0, 1}};
    // v = {{1, 0, 0, 1}};
    // v = {{1}, {0}, {1}, {1}, {1}, {0}};
    // v = {{1, 0, 1, 1, 1, 0}};

    cc, q.gameOfLife(v);

    return 0;
}