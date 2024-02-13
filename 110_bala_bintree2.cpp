#include "LeetCode.h"
class Solution {
   public:
    bool ans = true;
    int dfsHeight(TreeNode* root) {
        if (!ans || root == NULL) {
            return 0;
        }
        int lh = dfsHeight(root->left);
        int rh = dfsHeight(root->right);
        int d = lh - rh;
        uint32_t m = d >> 31;
        d = (d ^ m) - m;
        if (d > 1) {
            ans = false;
            return 0;
        }
        return max(lh, rh) + 1;
    }
    bool isBalanced(TreeNode* root) {
        dfsHeight(root);
        return ans;
    }
};

int main() {
    Solution q;
    auto t1 = makeTree({3, 9, 20, -1001, -1001, 15, 7});
    auto t2 = makeTree({1, 2, 2, 3, 3, -1001, -1001, 4, 4});

    auto v = q.isSameTree(t1, t2);
    cc, v;
    return 0;
}
