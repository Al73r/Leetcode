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
    int sumNumbers(TreeNode* root) {
        int ans=0, path=0;
        dfs(root, path, ans);
        return ans;
    }
private:
    void dfs(TreeNode* root, int& path, int& ans) {
        if(root==nullptr) return;
        if(root->left==nullptr && root->right==nullptr) {
            ans += path*10 + root->val;
        }
        path = path*10 + root->val;
        if(root->left!=nullptr)
            dfs(root->left, path, ans);
        if(root->right!=nullptr)
            dfs(root->right, path, ans);
        path = (path-root->val)/10;
    }
};