class Solution {
public:
    bool solve(TreeNode* root, int k, unordered_set<int>& st) {
        if (!root) return false;

        if (st.find(k - root->val)!=st.end()) return true;

        st.insert(root->val);

        return solve(root->left, k, st) || solve(root->right, k, st);
    }

    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> st;
        return solve(root, k, st);
    }
};