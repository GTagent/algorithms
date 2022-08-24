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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* root = new ListNode();
        ListNode* p = root;
        bool null = false;
        while(!null){
            int q = -1;
            for(int i = 0; i < lists.size(); ++i){
                if(lists[i] != NULL){
                    if(q == -1 || lists[i]->val < lists[q]->val){
                        q = i;
                    }
                }
            }
            if(q == -1)
                break;
            p->next = lists[q];
            p = p->next;
            lists[q] = lists[q]->next;
        }
        return root->next;
    }
};