class Solution {
private:
    void fun(vector<int>& candidates,int n,int idx,vector<int>&diary,int target, vector<vector<int>>&ans,int sum){

        if(sum==target){
            ans.push_back(diary);
            return;
        }
        if (idx == n || sum > target) return;
        diary.push_back(candidates[idx]);
        fun(candidates,n,idx,diary,target,ans,sum+candidates[idx]);
        diary.pop_back();
        fun(candidates,n,idx+1,diary,target,ans,sum);




    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<int>diary;
        vector<vector<int>>ans;
        fun(candidates,n,0,diary,target,ans,0);
        return ans;


        
    }
};