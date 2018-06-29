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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        stack<vector<int>> s;
        queue<TreeNode*> cur, next;
        if(root!=nullptr) cur.push(root);
        while(!cur.empty()){
            vector<int> rlt;
            while(!cur.empty()){
                auto tmp = cur.front();
                cur.pop();
                rlt.push_back(tmp->val);
                if(tmp->left!=nullptr) next.push(tmp->left);
                if(tmp->right!=nullptr) next.push(tmp->right);
            }
            s.push(rlt);
            swap(cur, next);
        }
        vector<vector<int>> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};