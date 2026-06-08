class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0];
        int minending=nums[0];
        int maxending=nums[0];
        for(int i=1;i<nums.size();i++){
            int v1=nums[i];
            int v2=minending*nums[i];
            int v3=maxending*nums[i];

            minending=min(v1,min(v2,v3));
            maxending=max(v1,max(v2,v3));
            ans=max(ans,max(minending,maxending));




            
        }
        return ans;
        
        
    }
};