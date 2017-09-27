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
        ListNode *prev=&dummy, *cur, *tmp, *next, *end=head;
        bool stop = false;
        while(end!=NULL){
            for(int i=0; i<k; i++){
                if(end==NULL){
                    stop = true;
                    break;
                }
                end = end->next;
            }
            if(stop) break;
            for(cur=prev->next, next=end;
                    cur->next!=end;
                    next = cur, cur = tmp, i++){
                tmp = cur->next;
                cur->next = next;
            }
            cur->next = next;
            tmp = prev->next;
            prev->next = cur;
            prev = tmp;
            end = prev->next;
        }
        return dummy.next;
    }
};