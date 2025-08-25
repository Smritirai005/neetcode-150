class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        int count=1;
        int mn=1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]-nums[i]==1){
                count++;
            }
            else if(nums[i+1]==nums[i]){
                continue;
            }
            else{
                
                count=1;

            }
            mn=max(mn,count);
        }
        return mn;
        
        


        
    }
};