#include "LeetCode.h"
class Solution {
   public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> row;
        vector<double> res;
        row.push(root);
        double row_sum;
        while (!row.empty()) {
            row_sum = 0;
            auto row_sz = row.size();
            for (int i = 0; i < row_sz; i++) {
                auto el = row.front();
                row_sum += el->val;
                row.pop();
                if (el->left) row.push(el->left);
                if (el->right) row.push(el->right);
            }
            res.push_back(row_sum / row_sz);
        }
        return res;
    }
};

int main() {
    Solution q;

    cc, q.averageOfLevels(makeTree({3,9,20,-1001,-1001,15,7}));  
    return 0;
}

// Input: root = [3,9,20,null,null,15,7]
// Output: [3.00000,14.50000,11.00000]
// Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
// Hence return [3, 14.5, 11].