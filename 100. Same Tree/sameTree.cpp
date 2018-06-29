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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> pstack, qstack;
        if(p!=nullptr){
            if(q==nullptr) return false;
            pstack.push(p);
            qstack.push(q);
        }
        else if(q!=nullptr) return false;
        
        while(!pstack.empty()){
            if(qstack.empty()) return false;
            auto pcur = pstack.top();
            auto qcur = qstack.top();
            pstack.pop();
            qstack.pop();
            if(pcur->val!=qcur->val) return false;
            if(pcur->right!=nullptr){
                if(qcur->right==nullptr) return false;
                pstack.push(pcur->right);
                qstack.push(qcur->right);
            }
            else if(qcur->right!=nullptr) return false;
            if(pcur->left!=nullptr){
                if(qcur->left==nullptr) return false;
                pstack.push(pcur->left);
                qstack.push(qcur->left);
            }
            else if(qcur->left!=nullptr) return false;
        }
        return qstack.empty();
    }
};