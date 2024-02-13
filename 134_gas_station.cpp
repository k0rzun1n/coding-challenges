#include "LeetCode.h"
class Solution {
   public:
    int canCompleteCircuit(vector<int>& g, vector<int>& c) {
        std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
        int cur = 0;
        int total = 0;
        int st = 0;
        for (int i = 0; i < g.size(); i++) {
            int move = g[i] - c[i];
            total += move;
            cur += move;
            if (cur < 0) {
                cur = 0;
                st = i + 1;
            }
        }
        return total < 0 ? -1 : st % g.size();
    }
};
class Solution {
   public:
    int canCompleteCircuit(vector<int>& g, vector<int>& c) {
        std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
        g[0] -= c[0];
        c[0] = g[0] < 0 ? 1 : 0;  // potential start
        int cur = g[0];
        for (int i = 1; i < g.size(); i++) {
            g[i] -= c[i];
            g[0] += g[i];  // total
            cur += g[i];
            if (cur < 0) {
                cur = 0;
                c[0] = i + 1;
            }
        }
        return g[0] < 0 ? -1 : c[0] % g.size();
    }
};

int main() {
    Solution q;
    vector<int> g, c;
    g = {1, 2, 3, 4, 5};
    c = {3, 4, 5, 1, 2};
    // g = {2, 3, 4}; c = {3, 4, 3};
    // g = {3, 1, 1};
    // c = {1, 2, 2};
    // g = {1, 2}; c = {2, 1};
    cc, q.canCompleteCircuit(g, c);
    return 0;
}