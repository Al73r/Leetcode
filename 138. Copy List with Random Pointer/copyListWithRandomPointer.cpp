/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head==nullptr) return nullptr;
        for(auto p=head; p!=nullptr; p=p->next->next) {
            auto newp = new RandomListNode(p->label);
            newp->next = p->next;
            p->next = newp;
        }
        for(auto p=head; p!=nullptr; p=p->next->next) {
            if(p->random==nullptr) p->next->random = nullptr;
            else p->next->random = p->random->next;
        }
        auto ans = head->next;
        for(auto p=head, q=ans; p!=nullptr && q!=nullptr; p=p->next, q=q->next) {
            p->next = q->next;
            if(p->next!=nullptr)
                q->next = p->next->next;
        }
        return ans;
    }
};