#include "LeetCode.h"
class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& n, int target) {
        unsigned int ut = target;
        set<multiset<int>> sms;
        unordered_multimap<int, pair<int, int>> sumpair;
        map<int, int> counter;  // skip if repeated >4
        for (int i = 0; i < n.size(); i++) {
            counter[n[i]]++;
        }
        int left = 0;
        int right = 0;
        for (auto p : counter) {
            int dt = min(4, p.second);
            right += dt;
            fill(n.begin() + left, n.end(), p.first);
            left += dt;
        }
        n.erase(n.begin() + left, n.end());
        for (int i = 0; i < n.size(); i++)
            for (int j = i + 1; j < n.size(); j++) {
                const auto sum = n[i] + n[j];
                pair<int, int> p{i, j};

                sumpair.insert({sum, {i, j}});
            }
        for (auto it1 = sumpair.begin(); it1 != sumpair.end(); it1++) {
            auto it2 = it1;
            it2++;
            for (; it2 != sumpair.end(); it2++) {
                if((long long)it1->first + (long long)it2->first>INT32_MAX)continue;
                // if ((long long)(it1->first + it2->first) != (long long)ut) continue;
                if (target - it1->first != it2->first) continue;
                auto& x = it1->second.first;
                auto& y = it1->second.second;
                auto& z = it2->second.first;
                auto& w = it2->second.second;
                if (x != z && x != w &&
                    y != z && y != w) {
                    sms.insert({n[x], n[y], n[z], n[w]});
                }
            }
        }
        vector<vector<int>> res;
        for (auto q : sms) {
            vector<int> row;
            row.reserve(4);
            for (auto e : q)
                row.push_back(e);
            res.push_back(row);
        }

        return res;
    }
};

int main() {
    Solution q;
    // [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

    // vector<int> data{
    //     10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
    //     20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
    //     30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
    //     40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40,
    //     50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50,
    //     60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60,
    //     70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
    //     80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80,
    //     90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90};
    // auto v = q.fourSum(data, 200);

    vector<int> data{1000000000, 1000000000, 1000000000, 1000000000};
    auto v = q.fourSum(data, -294967296);
    // vector<int> data{1000000000, 1000000000, 1000000000, 1000000000};
    // auto v = q.fourSum(data, 0);
    // vector<int> data{1, 0, -1, 0, -2, 2};
    // auto v = q.fourSum(data, 0);
    // vector<int> data{2, 2, 2, 2, 2};
    // auto v = q.fourSum(data, 8);

    cc, v;

    return 0;
}