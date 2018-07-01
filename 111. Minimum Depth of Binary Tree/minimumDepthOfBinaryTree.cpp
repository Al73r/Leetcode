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
    int minDepth(TreeNode* root) {
        queue<TreeNode*> cur, next;
        int depth = 0;
        if(root!=nullptr) cur.push(root);
        bool finish = false;
        while(!cur.empty()){
            while(!cur.empty()){
                auto tmp = cur.front();
                cur.pop();
                if(tmp->left!=nullptr) next.push(tmp->left);
                if(tmp->right!=nullptr) next.push(tmp->right);
                if(tmp->left==nullptr && tmp->right==nullptr){
                    finish = true;
                    break;
                }
            }
            depth++;
            if(finish) break;
            swap(cur, next);
        }
        return depth;
    }
};