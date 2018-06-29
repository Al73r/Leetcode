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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> rlt;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        while(!q.empty()){
            auto tmp = q.front();
            q.pop();
            if(tmp!=nullptr){
                rlt.push_back(tmp->val);
                if(tmp->left!=nullptr)
                    q.push(tmp->left);
                if(tmp->right!=nullptr)
                    q.push(tmp->right);
            }
            else if(!rlt.empty()){
                ans.push_back(rlt);
                rlt.clear();
                q.push(nullptr);
            }
        }
        return ans;
    }
};