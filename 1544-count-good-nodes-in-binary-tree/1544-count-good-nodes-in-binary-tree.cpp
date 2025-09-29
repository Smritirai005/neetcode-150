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
    int goodNodes(TreeNode* root) {
        if (!root) return 0;

        int count = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});

        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                auto [node, mx] = q.front();
                q.pop();

                if (node->val >= mx){
                    mx=node->val;
                    count++;
                }

                if (node->left) 
                    q.push({node->left,mx});
                if (node->right) 
                    q.push({node->right,mx});
            }
        }
        return count;
        
    }
};