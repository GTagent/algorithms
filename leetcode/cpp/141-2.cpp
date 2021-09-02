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
    bool hasCycle(ListNode *head) {
        ListNode *p = head, *pre = head;
        while(p && p->next){
            if(p->next == head) return true;
            p = p->next;
            pre->next = head;
            pre = p;
        }
        return false;
    }
};