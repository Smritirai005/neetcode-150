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
    TreeNode* prev = nullptr;
    bool ans = true;

    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;

        isValidBST(root->left);

        if (prev != nullptr && root->val <= prev->val) {
            ans = false;
        }

        prev = root;

        isValidBST(root->right);

        return ans;
    }
};