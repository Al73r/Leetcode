/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return head;
        ListNode H(0);
        ListNode *h, *p, *q;
        h = &H;
        h->next = head;
        p = head;
        q = head->next;
        head = h;
        while(q!=NULL){
            if(p->val==q->val) 
                h->next = q;
            else
                h = p;
            p = q;
            q = q->next;
        }
        return head->next;
    }
};