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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        return merge(lists, 0, lists.size()-1);
    }
private:
    ListNode*  merge(vector<ListNode*>& lists, int start, int end) {
        if(end==start) return lists[start];
        int mid = (start+end)/2;
        ListNode* l1 = merge(lists, start, mid);
        ListNode* l2 = merge(lists, mid+1, end);
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        return mergeTwo(l1, l2);
    }
    ListNode* mergeTwo(ListNode* l1, ListNode* l2){
        ListNode dummy(-1);
        ListNode* pa=&dummy;
        while(l1!=NULL && l2!=NULL){
            if(l1->val < l2->val){
                pa->next = l1;
                l1 = l1->next;
                pa = pa->next;
            }
            else{
                pa->next = l2;
                l2 = l2->next;
                pa = pa->next;
            }
        }
        pa->next = l1!=NULL ? l1: l2;
        return dummy.next;
    }
};