class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fact(n+1,1);
        for (int i=1;i<=n;i++) fact[i] = fact[i-1]*i;
        vector<int> nums;
        for (int i=1;i<=n;i++) nums.push_back(i);
        k--; // convert to 0-based
        string ans;
        for (int i = n; i >= 1; --i) {
            int idx = k / fact[i-1];
            k %= fact[i-1];
            ans.push_back('0' + nums[idx]);
            nums.erase(nums.begin() + idx);
        }
        return ans;
    }
};
