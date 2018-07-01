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
    bool isBalanced(TreeNode* root) {
        return solve(root)!=-1;
    }
private:
    int solve(TreeNode* root){
        if(root==nullptr) return 0;
        int ll=solve(root->left);
        int lr=solve(root->right);
        if(ll==-1 || lr==-1 || abs(ll-lr)>1) return -1;
        return max(ll, lr)+1;
    }
};