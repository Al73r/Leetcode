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
    void flatten(TreeNode* root) {
        if(root!=nullptr)
            solve(root);
    }
private:
    TreeNode* solve(TreeNode* root){
        if(root->left==nullptr && root->right==nullptr)
            return root;
        TreeNode *r_end=nullptr, *l_end;
        if(root->right!=nullptr)
            r_end = solve(root->right);
        if(root->left!=nullptr){
            l_end = solve(root->left);
            l_end->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        return r_end==nullptr ? l_end : r_end;
    }
};