#include "LeetCode.h"
class Solution {
   public:
    bool isSymmetric(TreeNode* root) {
        return rec(root->left, root->right);
    }
    bool rec(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        bool res = p->val == q->val && rec(p->right, q->left) && rec(p->left, q->right);
        // if (p != nullptr) p->left = p->right = nullptr;
        // if (q != nullptr) q->left = q->right = nullptr;
        return res;
    }
};

int main() {
    Solution q;
    auto t1 = makeTree({1, 2, 2, 3, 4, 4, 3});
    auto t2 = makeTree({1, 2, 2, -1001, 3, -1001, 3});

    auto v = q.isSymmetric(t1);
    cc, v;
    return 0;
}