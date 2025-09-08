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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0;
        if(head==nullptr) return head;
        ListNode* curr=head;
        while(curr!=nullptr){
            count++;
            curr=curr->next;
        }
        int total=count;
        if(n == total) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        count=0;
        curr=head;
        while(curr!=nullptr){
            count++;
            if(count==total-n){
                ListNode* temp=curr->next;
                    curr->next=curr->next->next;
                    delete temp;
                    break;

            }
            curr=curr->next;
            
        }
        return head;

    }
};