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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* curr=head;

        while(curr && curr->next){
            slow=slow->next;
            curr=curr->next->next;
            if(slow==curr){
                slow=head;
                while(slow!=curr){
                    slow=slow->next;
                    curr=curr->next;
                }
                return slow;
                
            }
        }
        return NULL;
        
        
    }
};