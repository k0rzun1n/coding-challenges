#include "LeetCode.h"
class Solution {
   public:
    int trap(vector<int>& h) {
        if (h.size() <= 1) return 0;
        auto w = h;  // copy heights to water level
        for (int i = 1; i < h.size() - 1; i++)
            w[i] = max(h[i], w[i - 1]);
        for (int i = h.size() - 2; i >= 0 && w[i] > h[i + 1]; i--)
            w[i] = max(h[i], w[i + 1]);

        auto res = 0;
        for (int i = 0; i < h.size(); i++)
            res += w[i] - h[i];

        return res;
    }
};

int main() {
    Solution q;
    vector<int> data;
    data = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cc, q.trap(data);
    data = {4, 2, 0, 3, 2, 5};
    cc, q.trap(data);
    data = {4, 2, 3};
    cc, q.trap(data);
    return 0;
}