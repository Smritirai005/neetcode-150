/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int fun(TreeNode* root, int digit){
        if(root == nullptr) return 0;

        digit = digit * 10 + root->val;

        // leaf node
        if(root->left == nullptr && root->right == nullptr){
            return digit;
        }

        int left = fun(root->left, digit);
        int right = fun(root->right, digit);

        return left + right;
    }

    int sumNumbers(TreeNode* root) {
        return fun(root, 0);
    }
};