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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head;
        ListNode* curr=head;
        ListNode* start=curr;
        int n=1;
        while(curr->next!=nullptr){
            n++;
            curr=curr->next;
        }
        k=k%n;
        if(k==0)return head;
        int count=1;
        ListNode* prevrev=nullptr;
        curr=head;
        while(curr!=nullptr ){
            if(count==n-k){
                prevrev=curr;
            }
            if(count==n-k+1){
                ListNode* newHead = curr;

                prevrev->next = nullptr;  
                ListNode* tail = curr;

                while (tail->next != nullptr) {
                    tail = tail->next;
                }

                tail->next = start;        
                return newHead;
            }
            count++;
            curr = curr->next;

        }
        return head;
        
    }
};