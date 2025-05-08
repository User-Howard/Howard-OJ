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
        vector<string> solve(TreeNode* root) {
            vector<string> ans;
            string s = to_string(root->val);
            if(root->right) {
                auto result = solve(root->right);
                for(string &i: result) {
                    ans.push_back(s+i);
                }
            }
            if(root->left) {
                auto result = solve(root->left);
                for(string &i: result) {
                    ans.push_back(s+i);
                }
            }
    
            if(not root->left and not root->right) {
                return vector<string>({s});
            }
            return ans;
        }
        int sumNumbers(TreeNode* root) {
            auto result = solve(root);
            int ans = 0;
            for(auto i: result) ans += stoi(i);
            return ans;
        }
    };