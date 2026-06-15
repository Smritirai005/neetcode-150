class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<long long, long long> freq;

        long long prefixXor = 0;
        long long ans = 0;

        freq[0] = 1; // empty prefix

        for (int num : nums) {
            prefixXor ^= num;

            ans += freq[prefixXor];

            freq[prefixXor]++;
        }

        return ans;
    }
};