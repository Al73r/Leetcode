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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // if(head==NULL) return NULL;
        int length=1;
        ListNode * p=head;
        while(p->next!=NULL){
            p = p->next;
            length++;
        }
        if(length>n){
            p=head;
            for(int i=0; i<length-n-1; i++){
                p = p->next;
            }
            p->next=p->next->next;
        }
        else{
            head=head->next;
        }

        return head;
    }
};