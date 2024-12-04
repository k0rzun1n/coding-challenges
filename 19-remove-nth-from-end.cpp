#include "LeetCode.h"

class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *left = head, *right = head;
        for (int i = 0; i < n; i++) right = right->next;
        if (!right) return head->next;
        while (right->next) right = right->next, left = left->next;
        left->next = left->next->next;
        return head;
    }
};
