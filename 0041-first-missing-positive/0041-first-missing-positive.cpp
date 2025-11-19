class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Step 1: clean the array
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = n + 1;
            }
        }

        // Step 2: mark present numbers
        for (int i = 0; i < n; i++) {
            int x = abs(nums[i]);
            if (x >= 1 && x <= n) {
                if (nums[x - 1] > 0) {
                    nums[x - 1] = -nums[x - 1];
                }
            }
        }

        // Step 3: find first positive
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) return i + 1;
        }

        return n + 1;
    }
};
