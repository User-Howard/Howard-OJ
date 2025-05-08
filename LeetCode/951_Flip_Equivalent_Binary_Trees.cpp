/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int cnt = 0;
bool flipEquiv(struct TreeNode* root1, struct TreeNode* root2) {
    ++cnt;
    if(root1==NULL && root2==NULL)
        return true;
    if(root1==NULL && root2!=NULL)
        return false;
    if(root1!=NULL && root2==NULL)
        return false;
    
    if(root1->val != root2->val)
        return false;
    printf("%d", cnt);
    bool q = false;
    q |= flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
    if(q) return true;
    q |= flipEquiv(root1->right, root2->left) && flipEquiv(root1->left, root2->right);
    
    return q;
}
