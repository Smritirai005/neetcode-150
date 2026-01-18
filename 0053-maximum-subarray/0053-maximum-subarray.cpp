class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int bestending=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            bestending=max(nums[i],bestending+nums[i]);
            ans=max(ans,bestending);

        }
        return ans;
    }
};