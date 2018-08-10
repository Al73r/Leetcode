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
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr || head->next==nullptr)
            return nullptr;
        ListNode *p1=head->next, *p2=head->next->next;
        while(p2!=nullptr && p2->next!=nullptr) {
            if(p1==p2){
                auto p3=head;
                while(p1!=p3) {
                    p1 = p1->next;
                    p3 = p3->next;
                }
                return p1;
            }
            p1 = p1->next;
            p2 = p2->next->next;
        }
        return nullptr;
    }
};