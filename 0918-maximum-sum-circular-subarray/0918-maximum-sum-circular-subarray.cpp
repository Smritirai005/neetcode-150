class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int mxsum=nums[0];
        int minsum=nums[0];
        int bestmx=nums[0];
        int bestmin=nums[0];
        int total=nums[0];
        for(int i=1;i<nums.size();i++){
            total+=nums[i];
            int v1=bestmx;
            int v2=bestmin;
            bestmx=max(v1+nums[i],nums[i]);
            bestmin=min(v2+nums[i],nums[i]);
            mxsum=max(mxsum,bestmx);
            minsum=min(minsum,bestmin);
            
        }
        if (mxsum < 0) return mxsum;
        return max(mxsum,total-minsum);
        
        
    }
};