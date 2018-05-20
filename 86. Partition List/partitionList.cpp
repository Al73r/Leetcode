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
    ListNode* partition(ListNode* head, int x) {
        ListNode *pls=NULL, *p1=NULL, *pgr=NULL, *p2=NULL;
        for(ListNode* p=head; p!=NULL; p=p->next){
            if(p->val<x){
                if(pls==NULL){
                    pls = p;
                    p1 = p;
                }
                else{
                    p1->next = p;
                    p1 = p;
                }
            }
            else{
                if(pgr==NULL){
                    pgr = p;
                    p2 = p;
                }
                else{
                    p2->next = p;
                    p2 = p;
                }
            }
        }
        if(p1!=NULL) p1->next = pgr;
        else pls = pgr;
        if(p2!=NULL) p2->next = NULL;
        return pls;
    }
};