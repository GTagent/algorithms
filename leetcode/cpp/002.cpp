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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL || l2==NULL){
            return (l1==NULL) ? l2:l1;
        }
        ListNode* l3=new ListNode(0);
        ListNode* ans=l3;
        int v1=0;
        int v2=0;
        while(l1!=NULL && l2!=NULL){
            v1=l1->val+l2->val+v2;
            v2=v1/10;
            v1=v1%10;
            
            l3->next=new ListNode(v1);
            
            l1=l1->next;
            l2=l2->next;
            l3=l3->next;
            // l1 , l2 may have different number of digits
            if(l1==NULL && l2==NULL)
                break;
            if(l1==NULL)
                l1=new ListNode(0);
            if(l2==NULL)
                l2=new ListNode(0);
        }
        if (v2 != 0){
            l3->next=new ListNode(v2);
        }
        return ans->next;
    }
};