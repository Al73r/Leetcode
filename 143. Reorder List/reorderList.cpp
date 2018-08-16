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
    void reorderList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return;
        auto p1=head, p2=head, p0=head;
        while(p1!=nullptr && p1->next!=nullptr) {
            p0 = p2;
            p2 = p2->next;
            p1 = p1->next->next;
        }
        p0->next = nullptr;
        auto ph=p2;
        auto ps=p2->next;
        p2->next = nullptr;
        while(ph!=nullptr && ps!=nullptr) {
            auto tmp=ps->next;
            ps->next = ph;
            ph = ps;
            ps = tmp;
        }
        auto pl=head->next, pr=ph, pw=head;
        while(pl!=nullptr && pr!=nullptr) {
            pw->next = pr;
            pw = pw->next;
            pr = pr->next;
            pw->next = pl;
            pw = pw->next;
            pl = pl->next;
        }
        if(pr!=nullptr)
            pw->next = pr;
    }
};