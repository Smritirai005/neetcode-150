class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-2;
        int res=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]<nums[mid+1]){
                low=mid+1;
            }
            else{
                res=mid;
                high=mid-1;
                
            }
        }
        return res;

    }
};