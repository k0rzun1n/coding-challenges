#include "LeetCode.h"
class Solution {
   public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> row;
        vector<int> res;
        row.emplace(root);
        while (!row.empty()) {
            auto row_sz = row.size();
            int right;
            while (row_sz--) {
                auto el = row.front();
                if (!el) continue;
                right = el->val;
                row.pop();
                if (el->left) row.emplace(move(el->left));
                if (el->right) row.emplace(move(el->right));
                el->left = nullptr;
                el->right = nullptr;
            }
            res.push_back(right);
        }
        return res;
    }
};

int main() {
    Solution q;

    cc, q.rightSideView(makeTree({3, 9, 20, -1001, -1001, 15, 7}));
    cc, q.rightSideView(makeTree({1, 2, 3, 4, -1001, -1001, -1001, 5}));
    return 0;
}

// Input: root = [1,2,3,4,null,null,null,5]
// Output: [1,3,4,5]
