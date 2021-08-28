/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *q=new ListNode();
        q->next = head;
        ListNode *p = q;
        while(p->next && p->next->next){
            ListNode *t1 = p->next;
            ListNode *t2 = t1->next;
            // cout<<p->val<<" "<<t1->val<<" "<<t2->val<<endl;
            t1->next = t2->next;
            t2->next = t1;
            p->next = t2;
            p = t1;
            // cout<<p->val<<endl;
        }
        return q->next;
    }
};