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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int, int> h;
        ListNode* p = head;
        while(p){
            int num = p->val;
            if(h.find(num) == h.end()){
                h[num] = 1;
            }else{
                ++h[num];
            }
            p = p->next;
        }
        ListNode* root = new ListNode();
        root->next =  head;
        p = root;
        while(p && p->next){
            ListNode* q = p->next;
            if(q){
                int num = q->val;
                // cout<<num<<" "<<h[num]<<endl;
                if(h[num] > 1){
                    while(q && (q->val == num)) 
                        q = q->next;
                    p->next = q;
                }else
                    p = p->next;
            }
        }
        return root->next;
    }
};