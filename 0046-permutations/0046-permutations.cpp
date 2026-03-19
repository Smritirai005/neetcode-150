class Solution {
private:
    void fun(vector<int>& nums, int n, int idx, vector<int>& diary, vector<vector<int>>& ans, vector<int>& used) {
        if (idx == n) {
            ans.push_back(diary);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (used[i]==1) continue;

            diary.push_back(nums[i]);   // fix: push nums[i], not idx
            used[i] = 1;

            fun(nums, n, idx + 1, diary, ans, used);

            diary.pop_back();
            used[i] = 0;
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> diary;              // fix: remove &
        vector<vector<int>> ans;
        vector<int> used(n, 0);         // fix: track used elements

        fun(nums, n, 0, diary, ans, used); // fix: start idx = 0

        return ans;
    }
};