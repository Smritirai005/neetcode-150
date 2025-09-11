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
    ListNode* reverseKGroup(ListNode* head, int k) {
        stack<ListNode*>st;
        ListNode dummy(0);
        dummy.next=head;
        ListNode* curr=head;
        ListNode* prev=&dummy;
    
        int count=0;
        if(head==nullptr||head->next==nullptr||k==1)return head;
        while(curr!=nullptr){
            st.push(curr);
            count++;
            curr=curr->next;
                
            
            if(count==k){
                while(!st.empty()){
                    prev->next=st.top();
                    st.pop();
                    prev=prev->next;
                    
                }
                prev->next=curr;
                count=0;

            }
        }
        return dummy.next;
    }       
};