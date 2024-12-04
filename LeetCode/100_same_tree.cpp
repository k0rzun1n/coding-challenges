#include "LeetCode.h"

class Solution {
   public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        bool res = p->val == q->val 
                && isSameTree(p->left, q->left) 
                && isSameTree(p->right, q->right);
        if(p != nullptr)p->left = p->right = nullptr;
        if(q != nullptr)q->left = q->right = nullptr;
        return res;
    }
};

int main() {
    Solution q;
    auto t1 = makeTree({1, 2, 3});
    auto t2 = makeTree({1, 2, 3});

    auto v = q.isSameTree(t1, t2);
    cc, v;
    return 0;
}