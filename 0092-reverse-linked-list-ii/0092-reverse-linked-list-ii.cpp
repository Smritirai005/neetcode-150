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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==nullptr)return nullptr;
        if(left==right)return head;
        
        ListNode* before=nullptr;
        ListNode* t=head;
        int pos=1;
        while(t!=nullptr){
            if(pos<left){
                before=t;
                t=t->next;
                pos++;
            }
            else if(pos==left){
                ListNode* curr=t;
                ListNode* prev=nullptr;
                int times=right-left+1;
                while(times--){
                    ListNode* nextNode=curr->next;
                    curr->next=prev;
                    prev=curr;
                    curr=nextNode;
                }
                t->next=curr;
                if(before){
                    before->next=prev;
                    return head;
                }
                return prev;
            }
        }
        return head;
    }
};