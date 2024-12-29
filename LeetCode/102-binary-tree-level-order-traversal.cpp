#include "LeetCode.h"
class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> row;
        vector<vector<int>> res;
        row.emplace(root);
        while (!row.empty()) {
            auto row_sz = row.size();
            auto row_elems = vector<int>();
            while (row_sz--) {
                auto el = row.front();
                if (!el) continue;
                row_elems.emplace_back(move(el->val));
                row.pop();
                if (el->left) row.emplace(move(el->left));
                if (el->right) row.emplace(move(el->right));
                el->left = nullptr;
                el->right = nullptr;
            }
            res.emplace_back(move(row_elems));
        }
        return res;
    }
};

int main() {
    Solution q;

    cc, q.levelOrder(makeTree({3, 9, 20, -1001, -1001, 15, 7}));
    return 0;
}

// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[9,20],[15,7]]