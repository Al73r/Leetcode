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
    ListNode* rotateRight(ListNode* head, int k) {
        int length=0;
        for(ListNode *p=head; p!=NULL; p=p->next){
            length++;
        }
        if(length==0) return head;
        k = k%length;
        ListNode *p1=head, *p2=head;
        while(k--) p2 = p2->next;
        while(p2->next != NULL){
            p1 = p1->next;
            p2 = p2->next;
        }
        p2->next = head;
        head = p1->next;
        p1->next = NULL;
        return head;
    }
};