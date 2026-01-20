class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int prefix=0;
        int total=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];

        }
        for(int i=0;i<nums.size();i++){
            int suffix=total-prefix-nums[i];
            if(prefix==suffix){
                return i;
            }
            prefix +=nums[i];

        }
        return -1;
        
    }
};