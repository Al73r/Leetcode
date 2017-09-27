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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ans, *pa;
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        if(l1->val < l2->val){
            ans = l1;
            l1 = l1->next;
        }
        else{
            ans = l2;
            l2 = l2->next;
        }
        pa=ans;
        while(l1!=NULL && l2!=NULL){
            if(l1->val < l2->val){
                pa->next = l1;
                l1=l1->next;
                pa=pa->next;
            }
            else{
                pa->next = l2;
                l2=l2->next;
                pa=pa->next;
            }
        }
        while(l1!=NULL){
            pa->next = l1;
            l1=l1->next;
            pa=pa->next;
        }
        while(l2!=NULL){
            pa->next = l2;
            l2=l2->next;
            pa=pa->next;
        }
        return ans;
    }
};