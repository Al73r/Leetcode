/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        int length=0;
        for(ListNode* p=head; p!=nullptr; p=p->next)
            length++;
        return solve(head, length);
    }
private:
    TreeNode* solve(ListNode* head, int length){
        if(length<=0)
            return nullptr;
        int mid = length/2;
        auto p_mid=head;
        for(int i=0; i<mid; i++)
            p_mid = p_mid->next;
        auto node = new TreeNode(p_mid->val);
        node->left = solve(head, mid);
        node->right = solve(p_mid->next, length-mid-1);
        return node;
    }
};