class Solution {
public:
    int trap(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int la=0;
        int ra=0;
        int ans=0;
        while(left<right){
            la=max(height[left],la);
            ra=max(height[right],ra);

            if(la<ra){
                ans+=la-height[left];
                left++;
            }
            else{
                ans+=ra-height[right];
                right--;
            }
            
            



            

        }
        return ans;



        
        
        
        
    }
};