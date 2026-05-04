class Solution {
public:
    int solve(int i, int sum, vector<int>& nums, int target){
        // base case
        if(i == nums.size()){
            return (sum == target) ? 1 : 0;
        }

        // choose +
        int plus = solve(i + 1, sum + nums[i], nums, target);

        // choose -
        int minus = solve(i + 1, sum - nums[i], nums, target);

        return plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0, 0, nums, target);
    }
};