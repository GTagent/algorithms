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
    ListNode* middleNode(ListNode* head) {
        ListNode *p = head;
        int cnt = 0;
        while(p){
            ++cnt;
            p = p->next;
        }
        // cout<<cnt<<endl;
        int i = 0;
        p = head;
        while(i < ((cnt >> 1))){
            ++i;
            // cout<<p->val<<endl;
            p = p->next;
        }
        return p;
    }
};