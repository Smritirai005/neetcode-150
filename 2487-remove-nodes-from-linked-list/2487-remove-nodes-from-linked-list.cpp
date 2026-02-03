class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        ListNode* curr = head;

        // Process nodes
        while (curr) {
            while (!st.empty() && st.top()->val < curr->val) {
                st.pop();   // smaller nodes get eliminated
            }
            st.push(curr);
            curr = curr->next;
        }

        // Rebuild linked list from stack
        ListNode* newHead = nullptr;
        while (!st.empty()) {
            st.top()->next = newHead;
            newHead = st.top();
            st.pop();
        }

        return newHead;
    }
};
