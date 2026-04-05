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
    void fun(TreeNode* root,int targetSum,int sum,vector<int>&path,vector<vector<int>> &res){
        if(root==nullptr)return ;
        sum+=root->val;
        path.push_back(root->val);
        if(root->left==nullptr && root->right==nullptr){
            if(sum==targetSum){
                res.push_back(path);

            }
        }
        fun(root->left,targetSum,sum,path,res);
        fun(root->right,targetSum,sum,path,res);
        path.pop_back();


}
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> path;

        fun(root, targetSum, 0, path, res); 

        return res;
        
    }
};