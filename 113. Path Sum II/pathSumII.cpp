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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        if(root==nullptr) return ans;
        vector<int> path;
        solve(root, sum, path, ans);
        return ans;
    }
private:
    void solve(TreeNode* root, int sum, vector<int> &path, vector<vector<int>> &ans){
        if(root->left==nullptr && root->right==nullptr){
            if(sum==root->val) {
                path.push_back(root->val);
                ans.push_back(path);
                path.pop_back();
            }
        }
        else{
            path.push_back(root->val);
            if(root->left!=nullptr)
                solve(root->left, sum-root->val, path, ans);
            if(root->right!=nullptr)
                solve(root->right, sum-root->val, path, ans);
            path.pop_back();
        }
    }
};