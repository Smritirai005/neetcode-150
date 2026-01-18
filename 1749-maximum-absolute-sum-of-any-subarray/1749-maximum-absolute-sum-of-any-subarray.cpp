class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int bestmx=nums[0];
        int bestmin=nums[0];
        int mxsum=nums[0];
        int minsum=nums[0];
        for(int i=1;i<nums.size();i++){
            bestmx=max(bestmx+nums[i],nums[i]);
            bestmin=min(bestmin+nums[i],nums[i]);
            mxsum=max(mxsum,bestmx);
            minsum=min(minsum,bestmin);
        }
        return max(abs(mxsum), abs(minsum));
        
        
    }
};