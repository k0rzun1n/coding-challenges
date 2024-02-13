#include "LeetCode.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
   public:
    vector<vector<int>> rt;
    int t;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        t = targetSum;
        vector<int> branch(0);
        rec(root, branch, 0);
        return rt;
    }
    void rec(TreeNode* root, vector<int>& branch, int sum) {
        if (root == nullptr) return;
        branch.push_back(root->val);
        sum += root->val;
        if (sum == t && !root->left && !root->right)
            rt.push_back(branch);
        if (root->left) rec(root->left, branch, sum);
        if (root->right) rec(root->right, branch, sum);
        branch.pop_back();
        sum -= root->val;
        return;
    }
};

// Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
// Output: [[5,4,11,2],[5,8,4,5]]
// Explanation: There are two paths whose sum equals targetSum:
// 5 + 4 + 11 + 2 = 22
// 5 + 8 + 4 + 5 = 22

int main() {
    Solution q;
    auto root = makeTree({5, 4, 8, 11, -1001, 13, 4, 7, 2, -1001, -1001, 5, 1});
    // auto root = makeTree({1,2});
    // auto root = makeTree({1, -2, -3, 1, 3, -2, -1001, -1});

    auto v = q.pathSum(root, 22);
    // auto v = q.pathSum(root, 2);
    // auto v = q.pathSum(root, 0);
    // auto v = q.pathSum(root, 1);
    // auto v = q.pathSum(root, 2);
    cc, v;
    return 0;
}