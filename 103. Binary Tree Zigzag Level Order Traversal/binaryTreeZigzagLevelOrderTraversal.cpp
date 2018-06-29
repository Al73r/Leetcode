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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        stack<TreeNode*> cur, next;
        if(root!=nullptr) cur.push(root);
        while(!cur.empty() || !next.empty()){
            vector<int> rlt;
            while(!cur.empty()){
                auto tmp = cur.top();
                cur.pop();
                rlt.push_back(tmp->val);
                if(tmp->left!=nullptr) next.push(tmp->left);
                if(tmp->right!=nullptr) next.push(tmp->right);
            }
            if(!rlt.empty()) ans.push_back(rlt);
            rlt.clear();
            while(!next.empty()){
                auto tmp = next.top();
                next.pop();
                rlt.push_back(tmp->val);
                if(tmp->right!=nullptr) cur.push(tmp->right);
                if(tmp->left!=nullptr) cur.push(tmp->left);
            }
            if(!rlt.empty()) ans.push_back(rlt);
        }
        return ans;
    }
};