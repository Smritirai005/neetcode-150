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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        if(head==nullptr || head->next==nullptr)return head;
        ListNode* curr=head;
        ListNode* before=nullptr;
        int group=1;

        while(curr!=nullptr){
            int count=0;
            ListNode* start=curr;
            while(start!=nullptr && count<group){
                start=start->next;
                count++;
            }
            if(count%2==0){
                ListNode* temp=curr;
                ListNode* prev=nullptr;
                int k=count;
                while(k--){
                    ListNode* nextNode=temp->next;
                    temp->next=prev;
                    prev=temp;
                    temp=nextNode;
                }
                if(before!=nullptr){
                    before->next=prev;
                }
                else{
                    head=prev;

                }
                curr->next=temp;
                before=curr;
                curr=temp;

                

            }
            else{
                int k=count;
                while(k--){
                    before=curr;
                    curr=curr->next;
                }

            }
            group++;
        }
        return head;

        
    }
};