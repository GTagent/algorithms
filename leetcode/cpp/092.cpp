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
    ListNode* reverseBetween(ListNode* head, int l, int r) {
        ListNode* root = new ListNode();
        root->next = head;
        ListNode* p = root;
        ListNode *left, *right;
        for(int i = 0; i < r; ++i){
            if(i == l - 1){
                left = p;
            }
            p = p->next;
            if(i == r - 1){
                right = p;
            }
        }
        stack<ListNode*> st;
        p = left->next;
        while(p != right){
            st.push(p);
            p = p->next;
        }
        ListNode* rightNext = right->next;
        left->next = right;
        p = right;
        while(!st.empty()){
            ListNode* q = st.top();
            st.pop();
            p->next = q;
            p = p->next;
        }
        p->next = rightNext;
        return root->next;
    }
};