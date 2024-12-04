#include "LeetCode.h"
class Solution {
   public:
    int dfsHeight(TreeNode *root) {
        if (root == NULL) return 0;

        int lh = dfsHeight(root->left);
        if (lh == -1) return -1;
        int rh = dfsHeight(root->right);
        if (rh == -1) return -1;

        if (abs(lh - rh) > 1) return -1;
        return max(lh, rh) + 1;
    }
    bool isBalanced(TreeNode *root) {
        return dfsHeight(root) != -1;
    }
};

int main() {
    Solution q;
    auto t1 = makeTree({3, 9, 20, -1001, -1001, 15, 7});
    auto t2 = makeTree({1, 2, 2, 3, 3, -1001, -1001, 4, 4});

    // auto v = q.isBalanced(t1);
    auto v = q.isBalanced(t2);
    cc, v;
    return 0;
}
