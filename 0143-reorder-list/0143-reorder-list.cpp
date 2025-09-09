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
    void reorderList(ListNode* head) {
        if(!head||!head->next)return;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast !=nullptr && fast->next !=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* mid=slow;
        ListNode* temp=mid;
        ListNode* prev=nullptr;

        while(temp!=nullptr){
            ListNode* nextNode=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nextNode;

        }
        ListNode* curr=head;
        temp=prev;
        while(temp->next!=nullptr){
            ListNode* per=curr->next;
            ListNode* temprev=temp->next;
            curr->next=temp;
            temp->next=per;
            curr=per;
            temp=temprev;

        }
      
         
        
    }
};