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
    int ans = 0;

    pair<int, int> solve(TreeNode* node) {
        if (!node) return {0, 0};

        auto [ls, lc] = solve(node->left);
        auto [rs, rc] = solve(node->right);

        int sum = ls + rs + node->val;
        int cnt = lc + rc + 1;

        if (node->val == sum / cnt) ++ans;
        return {sum, cnt};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        ans = 0;
        solve(root);
        return ans;
    }
};
