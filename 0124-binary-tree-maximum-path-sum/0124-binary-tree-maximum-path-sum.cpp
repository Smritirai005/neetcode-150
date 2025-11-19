class Solution {
public:
    int maxSum = INT_MIN;

    int dfs(TreeNode* node) {
        if (!node) return 0;

        int left = max(0, dfs(node->left));
        int right = max(0, dfs(node->right));

        // Max path THROUGH this node
        maxSum = max(maxSum, left + right + node->val);

        // Max path GOING DOWN (only pick one side)
        return node->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};
