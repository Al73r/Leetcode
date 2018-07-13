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
    int maxPathSum(TreeNode* root) {
        pair<int, int> ans=dfs(root);
        return ans.first;
    }
private:
    pair<int, int> dfs(TreeNode* root){
        if(root->left==nullptr && root->right==nullptr)
            return make_pair(root->val, root->val);
        pair<int, int> L, R;
        L.first=L.second=R.first=R.second=INT_MIN;
        if(root->left!=nullptr)
            L = dfs(root->left);
        if(root->right!=nullptr)
            R = dfs(root->right);
        int length=max(L.second,0)+max(R.second,0)+root->val;
        return make_pair(max(max(L.first, R.first), length),
                         max(max(L.second, R.second),0)+root->val);
    }
};