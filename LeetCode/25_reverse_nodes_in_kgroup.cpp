#include "LeetCode.h"

class Solution {
   public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;
        ListNode *a, *b, *c, *d;
        a = b = head;
        c = d = nullptr;
        int len = 0;
        while (head) head = head->next, len++;
        for (int i = 0; i < len / k; i++) {
            for (int j = 0; j < k - 1; j++) b = b->next;
            if (d) d->next = b;
            b = b->next;
            d = a;
            for (int j = 0; j < k; j++) {
                c = a->next;
                a->next = b;
                b = a;
                a = c;
            }
            if (!i) head = b;
            b = c;
        }
        return head;
    }
};

int main() {
    Solution q;
    vector<int> data{0, 1, 2, 3, 4, 5, 6, 7};
    auto d = makeList(data);
    // cc, d;
    cc, q.reverseKGroup(makeList(data), 3);

    return 0;
}