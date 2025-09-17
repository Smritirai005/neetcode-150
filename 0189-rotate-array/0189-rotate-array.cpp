class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //brute
        int n = nums.size();
        k = k % n; // in case k >= n

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[(i + k) % n] = nums[i];
        }

        nums = ans; // copy back to original
        //optimal
        // int n = nums.size();
        // k = k % n;

        // reverse(nums.begin(), nums.end());
        // reverse(nums.begin(), nums.begin() + k);
        // reverse(nums.begin() + k, nums.end());
    
    }
};