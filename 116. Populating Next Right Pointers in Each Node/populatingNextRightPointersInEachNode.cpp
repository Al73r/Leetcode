/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root==nullptr) return;
        for(auto prev=root; prev->left!=nullptr; prev=prev->left){
            for(auto tmp=prev; tmp!=nullptr; tmp=tmp->next){
                auto cur = tmp->left;
                cur->next = tmp->right;
                if(tmp->next!=nullptr){
                    cur = tmp->right;
                    cur->next = tmp->next->left;
                }
            }
        } 
    }
};