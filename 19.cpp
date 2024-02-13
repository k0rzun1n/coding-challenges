struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head->next) return nullptr;

        ListNode** cbuf = new ListNode*[n + 1];
        int id = 0;
        auto cur = head;
        do {
            cbuf[id] = cur;
            id = (id + 1) % (n + 1);
        } while (cur = cur->next);

        if (!cbuf[id]) {
            id = (id + 1) % (n + 1);
            // delete cbuf[id];//?
            head = cbuf[id]->next;
        } else {
            cbuf[id]->next = cbuf[id]->next->next;
        }

        delete[] cbuf;
        return head;
    }
};

int main(){
    ListNode h = new ListNode
    return 0;
}