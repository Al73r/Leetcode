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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int ones = 0;
        int tens = 0;
        int rlt = 0;
        ListNode* ans;
        ListNode* last = NULL;
        
        while(l1!=NULL || l2!=NULL){
            if(l1 == NULL){
                rlt = l2->val + tens;
                l2 = l2->next;
            }
            else if(l2 == NULL){
                rlt = l1->val + tens;
                l1 = l1->next;
            }
            else{
                rlt = l1->val + l2->val + tens;
                l1 = l1->next;
                l2 = l2->next;
            }
            ones = rlt % 10;
            tens = rlt / 10;
            ListNode* node = new ListNode(ones);
            if(last == NULL){
                ans = node;
                last = node;
            }
            else{
                last->next = node;
                last = node;
            }
        }
        if(tens>0){
            ListNode* node = new ListNode(tens);
            last->next = node;
        }
        return ans;
    }
};