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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp = new ListNode(0);   
        ListNode* head = temp;
        int p=0;
        while(l1!=nullptr||l2!=nullptr||p){
            int x=(l1 ? l1->val:0);
            int y=(l2 ? l2->val:0);
            int ans=x+y+p;
            p=ans/10;
            head->next=new ListNode(ans%10);
            head=head->next;

            
            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
            
        }
        return temp->next;
        
        
    }
};