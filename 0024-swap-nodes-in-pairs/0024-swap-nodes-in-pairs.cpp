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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* curr = head;
        ListNode* before = nullptr;
        head = head->next;   // new head after first swap

        while(curr != nullptr && curr->next != nullptr){
            ListNode* start = curr;   // MUST reset
            ListNode* prev = nullptr; // MUST reset
            int times = 2;

            // reverse 2 nodes (your logic)
            while(times--){
                ListNode* nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }

            // reconnect
            start->next = curr;
            if(before != nullptr){
                before->next = prev;
            }

            before = start;
        }
        return head;
    }
};
