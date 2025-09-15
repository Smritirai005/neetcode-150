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
    static bool compare(ListNode* x,ListNode* b){
         return x->val>b->val;
        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(0);
        ListNode* prev=&dummy;
        priority_queue<ListNode*, vector<ListNode*>, decltype(&compare)> pq(compare);

        for (auto list : lists) {
            if (list) pq.push(list);
        }

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            prev->next = node;
            prev = prev->next;

            if (node->next) pq.push(node->next);
        }

        return dummy.next;


    }
};