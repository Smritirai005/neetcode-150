class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);

        int mx = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            prefix[i] = gcd(nums[i], mx);
        }
        sort(prefix.begin(),prefix.end());
        long long ans=0;
        int i=0;
        int j=n-1;
        while(i<j){
            ans+=gcd(prefix[i], prefix[j]);
            i++;
            j--;
        }
        return ans;

        
    }
};