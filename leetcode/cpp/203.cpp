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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *p = new ListNode();
        p->next = head;
        ListNode *q = p;
        while(q && q->next){
            if(q->next->val == val){
                q->next = q->next->next;
            }else
                q = q->next;
        }
        return p->next;
    }
};