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
    ListNode* reverse(ListNode* p){
        if(!p || !p->next)
            return p;
        ListNode* q = p->next;
        ListNode* head = reverse(q);
        q->next = p;
        return head;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* rhead = reverse(head);
        if(head)
            head->next = NULL;
        return rhead;
    }
};