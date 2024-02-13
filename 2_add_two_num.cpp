#include "LeetCode.h"

class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto res = l1;
        auto tmp = l2;
        auto prev = l1;
        int c = 0;
        for (;;) {
            if (l1 && l2) {
                l1->val += l2->val + c;
                c = l1->val / 10;
                l1->val = l1->val % 10;
                prev = l1;
                l1 = l1->next;
                l2 = l2->next;
            } else if (l1) {
                if (c) l1->val++; 
                c = l1->val / 10;
                l1->val %= 10;
            } else if (l2) { 
                l1 = l2;
                prev->next = l1;
            } else {
                if (c) {
                    tmp->val = 1;
                    prev->next = tmp;
                    tmp->next = nullptr;
                }
                return res;
            }
        }
    }
};