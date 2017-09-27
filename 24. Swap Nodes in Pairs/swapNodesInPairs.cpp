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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode dummy(-1);
        ListNode *p=&dummy, *tmp;
        dummy.next = head;
        while(p!=NULL && p->next!=NULL && p->next->next!=NULL){
            tmp = p->next->next;
            p->next->next = tmp->next;
            tmp->next = p->next;
            p->next = tmp;
            p = p->next->next;
        }
        return dummy.next;
    }
};