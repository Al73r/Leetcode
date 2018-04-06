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
        if(head==NULL || head->next==NULL) return head;
        while(head!=NULL && head->val==head->next->val){
            ListNode* p = head->next;
            int change = 0;
            while(p!=NULL && head->val==p->val){
                p = p->next;
                change = 1;
            }
            if(change) head = p;
            if(head==NULL || head->next==NULL)
                return head;
        }
        
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* h = head;
        ListNode* p = h->next;
        int change = 0;
        while(p!=NULL){
            while(p->next!=NULL && p->val==p->next->val){
                p = p->next;
                change = 1;
            }
            if(change){
                h->next = p->next;
                if(h==NULL || h->next==NULL)
                    return head;
                p = h->next;
                change = 0;
            }
            else{
                h=h->next;
                p=p->next;
            }
        }
        return head;
        
    }
};