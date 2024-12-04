#include "LeetCode.h"
class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        auto l = head;
        auto r = head->next;
        head->next = nullptr;
        auto tmp = r;
        while (r) {
            tmp = r->next;
            r->next = l;
            l = r;
            r = tmp;
        }
        return l;
    }
};
// 1 2 3 4 5

int main() {
    Solution q;
    return 0;
}