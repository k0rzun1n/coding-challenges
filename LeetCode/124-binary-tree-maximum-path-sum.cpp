#include "LeetCode.h"
class Solution {
    int res = INT_MIN;

   public:
    int maxPathSum(TreeNode* root) {
        rec(root);
        return res;
    }
    int rec(TreeNode* root) {
        if (!root) return 0;
        int L = max(0, rec(root->left));
        int R = max(0, rec(root->right));
        res = max(res, root->val + L + R);
        return root->val + max(L, R);
    }
};

int main() {
    Solution q;

    cc, q.maxPathSum(makeTree({-10, 9, 20, -1001, -1001, 15, 7}));  // 42
    return 0;
}

// Input: root = [-10,9,20,null,null,15,7]
// Output: 42
// Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
