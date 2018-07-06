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
        auto prev=root;
        while(prev!=nullptr){
            TreeLinkNode *cur=nullptr;
            TreeLinkNode *next=nullptr;
            TreeLinkNode *prev2=nullptr;        
            for(auto tmp=prev; tmp!=nullptr; tmp=tmp->next){
                if(tmp->left!=nullptr){
                    if(prev2==nullptr) prev2=tmp->left;
                    cur = next;
                    next = tmp->left;
                    if(cur!=nullptr) cur->next = next;
                }
                if(tmp->right!=nullptr){
                    if(prev2==nullptr) prev2=tmp->right;
                    cur = next;
                    next = tmp->right;
                    if(cur!=nullptr) cur->next = next;
                }
            }
            prev = prev2;
        }
    }
};