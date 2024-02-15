#include "LeetCode.h"
class Solution {
   public:
    void gameOfLife(vector<vector<int>>& v) {
        // v[y][x] bits: 0 state; 1-4 neighbour count;
        const int h = v.size();
        const int w = v[0].size();
        if ((w < 2 && h < 2) || (w == 1 && h < 3) || (h == 1 && w < 3)) {
            for (int y = 0; y < h; y++) {
                for (int x = 0; x < w; x++) {
                    v[y][x] = 0;
                }
            }
            return;
        }
        if (v[0][0] & 1) {
            if (w > 1 && h > 1) v[1][1] += 2;
            if (w > 1) v[0][1] += 2;
            if (h > 1) v[1][0] += 2;
        }
        if (v[0][w - 1] & 1 && w>1) {
            if (w > 1 && h > 1) v[1][w - 2] += 2;
            if (w > 1) v[0][w - 2] += 2;
            if (h > 1) v[1][w - 1] += 2;
        }
        if (v[h - 1][0] & 1 && h>1) {
            if (w > 1 && h > 1) v[h - 2][1] += 2;
            if (w > 1) v[h - 1][1] += 2;
            if (h > 1) v[h - 2][0] += 2;
        }
        if (v[h - 1][w - 1] & 1 && h>1 && w>1) {
            if (w > 1 && h > 1) v[h - 2][w - 2] += 2;
            if (w > 1) v[h - 1][w - 2] += 2;
            if (h > 1) v[h - 2][w - 1] += 2;
        }

        if (h == 1) {
            for (int x = 1; x < w - 1; x++) {
                if (v[0][x] & 1) {
                    v[0][x - 1] += 2;
                    v[0][x + 1] += 2;
                }
            }
        } else
            for (int x = 1; x < w - 1; x++) {
                if (v[0][x] & 1) {
                    v[0][x - 1] += 2;
                    v[1][x - 1] += 2;
                    v[1][x - 0] += 2;
                    v[1][x + 1] += 2;
                    v[0][x + 1] += 2;
                }
                if (v[h - 1][x] & 1) {
                    v[h - 1][x - 1] += 2;
                    v[h - 2][x - 1] += 2;
                    v[h - 2][x - 0] += 2;
                    v[h - 2][x + 1] += 2;
                    v[h - 1][x + 1] += 2;
                }
            }

        if (w == 1) {
            for (int y = 1; y < h - 1; y++) {
                if (v[y][0] & 1) {
                    v[y - 1][0] += 2;
                    v[y + 1][0] += 2;
                }
            }
        } else
            for (int y = 1; y < h - 1; y++) {
                if (v[y][0] & 1) {
                    v[y - 1][0] += 2;
                    v[y - 1][1] += 2;
                    v[y - 0][1] += 2;
                    v[y + 1][1] += 2;
                    v[y + 1][0] += 2;
                }
                if (v[y][w - 1] & 1) {
                    v[y - 1][w - 1] += 2;
                    v[y - 1][w - 2] += 2;
                    v[y - 0][w - 2] += 2;
                    v[y + 1][w - 2] += 2;
                    v[y + 1][w - 1] += 2;
                }
            }

        for (int y = 1; y < h - 1; y++) {
            for (int x = 1; x < w - 1; x++) {
                if (!(v[y][x] & 1)) continue;
                v[y - 1][x - 1] += 2;
                v[y - 1][x - 0] += 2;
                v[y - 1][x + 1] += 2;
                v[y + 1][x - 1] += 2;
                v[y + 1][x - 0] += 2;
                v[y + 1][x + 1] += 2;
                v[y + 0][x - 1] += 2;
                v[y + 0][x + 1] += 2;
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
    v = {{1, 0, 0, 1}};
    v = {{1, 0, 0, 1}};
    v = {{1}, {0}, {1}, {1}, {1}, {0}};
    // v = {{1, 0, 1, 1, 1, 0}};

    cc, q.gameOfLife(v);

    return 0;
}