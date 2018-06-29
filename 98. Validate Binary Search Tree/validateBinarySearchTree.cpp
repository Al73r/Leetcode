/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, -1e18, 1e18);
    }
private:
    bool dfs(TreeNode* root, long long lower, long long upper){
        if(root==NULL) return true;
        return lower < root->val && root->val < upper
            && dfs(root->left,lower,root->val) && dfs(root->right,root->val,upper);
    }
};