#include "LeetCode.h"
class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& vv) {
        sort(vv.begin(), vv.end());
        int res_vv_id = 0;  // in-place
        vv[res_vv_id] = vv[0];
        for (int i = 0; i < vv.size() - 1; i++) {
            // cc, i, vv[i];
            // cc, res_vv_id, vv[res_vv_id];
            // ~cc;
            if (vv[res_vv_id][1] >= vv[i + 1][0])
                vv[res_vv_id][1] = max(vv[i + 1][1], vv[res_vv_id][1]);
            else {
                res_vv_id++;
                vv[res_vv_id] = vv[i +1];
            }
        }
        vv.resize(res_vv_id + 1);
        return vv;
    }
};
int main() {
    Solution q;
    vector<vector<int>> data{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    // vector<vector<int>> data{{1, 4}, {2, 3}};  // 1,4
    // vector<vector<int>> data{{2, 3}, {4, 5}, {6, 7}, {8, 9}, {1, 10}};  // 1,10

    auto v = q.merge(data);
    cc, v;
    return 0;
}