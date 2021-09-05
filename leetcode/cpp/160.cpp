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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Assume headA has length n and intersect at ith node
        // head B has length m and intersect at jth node
        // apparently n-i = m-j
        // transform, n + j = m + i
        ListNode *i =headA, *j = headB;
        while(i != j){
            i = i? i->next:headB;
            j = j? j->next:headA;
        }
        return i;
    }
};