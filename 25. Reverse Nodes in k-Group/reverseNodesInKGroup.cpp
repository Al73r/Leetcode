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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *prev=&dummy, *cur, *next, *end=head;
        bool stop = false;
        while(!stop){
            for(int i=0; i<k; i++){
                if(end==NULL){
                    stop = true;
                    break;
                }
                end = end->next;
            }
            if(stop) break;
            for(prev=start, cur=prev->next, next=cur->next;
                    next!=end;
                    prev=prev->next, cur=cur->next, next=next->next){
                prev->next = next;
                cur->next = next->next;
                next->next = cur;
            }
        }
        return dummy.next;
    }
};