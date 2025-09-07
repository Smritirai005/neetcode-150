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
    bool hasCycle(ListNode *head) {
        ListNode* curr=head;
        ListNode* forward=head;

        while(forward && forward->next){
            curr=curr->next;
            forward=forward->next->next;
            if(curr==forward){
                return true;
            }
        }
        return false;
    }
};