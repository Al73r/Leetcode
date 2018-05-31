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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode h(0);
        h.next = head;
        ListNode *h1, *h2, *p, *q, *i=&h;
        int j=0;
        while(j<=n){
            if(j==m-1)
                h1 = i;
            if(j==m){
                h2 = i;
                q = i;
            }
            if(j>m & j<=n){
                p = i->next;
                i->next = h2;
                h2 = i;
                i = p;
            }
            else
                i = i->next;  
            j++;
        }
        q->next = i;
        h1->next = h2;
        return h.next;
    }
};