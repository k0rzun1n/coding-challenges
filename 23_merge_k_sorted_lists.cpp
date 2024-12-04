#include "LeetCode.h"

class Solution {
   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        multiset<int> ms;
        for (auto row : lists) {
            for (auto cur = row; cur; cur = cur->next) {
                ms.insert(cur->val);
                cc, cur->val;
            }
        }
        ListNode* res = nullptr;
        ListNode* cur = nullptr;
        for (auto k : ms) {
            cc, k;
            if (!res) {
                cur = res = new ListNode(k);
            } else {
                cur->next = new ListNode(k);
                cur = cur->next;
            }
        }
        return res;
    }
};
int main() {
    Solution q;
    //[[1,4,5],[1,3,4],[2,6]]
    // 1->1->2->3->4->4->5->6

    vector<ListNode*> data;
    vector<vector<int>> init{{1, 4, 5}, {1, 3, 4}, {2, 6}};
    for (auto row : init) {
        ListNode* prev = nullptr;
        for (int d : row) {
            if (!prev) {
                prev = new ListNode(d);
                data.push_back(prev);
            } else {
                prev->next = new ListNode(d);
                prev = prev->next;
            }
        }
        prev->next = nullptr;
    }

    auto v = q.mergeKLists(data);
    !cc;

    for (; v; v = v->next)
        cc, v->val;
    // do
    //     cc, v->val;
    // while (v = v->next);

    for (auto row : data) {
        auto prev = row;
        while (prev) {
            row = row->next;
            // cc,prev->val;
            delete prev;
            prev = row;
        }
    }
    return 0;
}
