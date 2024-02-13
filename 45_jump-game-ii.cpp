#include "LeetCode.h"
class Solution {
   public:
    int jump(vector<int>& n) {
        if (n.size() == 1)
            return 0;
        if (n[0] >= n.size() - 1)
            return 1;
        int jj = 1;  // jumps
        int maxD = n[0];
        int jmax = 0;
        for (int i = 1; i < n.size() - 1; i++) {
            jmax = max(jmax, i + n[i]);
            if (jmax >= n.size() - 1)
                return jj + 1;
            if (i == maxD) {
                jj++;
                maxD = jmax;
            }
        }
        return jj;
    }
};

int main() {
    Solution q;
    vector<int> data;
    data = {2, 3, 1, 1, 4};
    cc, q.jump(data);
    data = {2, 3, 0, 1, 4};
    cc, q.jump(data);
    data = {1, 2};
    cc, q.jump(data);
    data = {3, 2, 1};
    cc, q.jump(data);
    data = {3, 2, 1, 3, 3, 3, 3, 3, 3, 3};
    cc, q.jump(data);
    return 0;
}
