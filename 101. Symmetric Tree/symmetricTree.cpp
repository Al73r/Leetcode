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
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) return true;
        if(root->left==nullptr || root->right==nullptr){
            if(root->left==nullptr && root->right==nullptr)
                return true;
            else
                return false;
        }
        stack<TreeNode*> s;
        s.push(root->left);//p
        s.push(root->right);//q
        while(!s.empty()){
            auto q = s.top();
            s.pop();
            auto p = s.top();
            s.pop();
            if(p->val!=q->val) return false;
            if(p->left!=nullptr){
                if(q->right==nullptr) return false;
                s.push(p->left);
                s.push(q->right);
            }
            else if(q->right!=nullptr) return false;
            if(p->right!=nullptr){
                if(q->left==nullptr) return false;
                s.push(p->right);
                s.push(q->left);
            }
            else if(q->left!=nullptr) return false;
        }
    }
};