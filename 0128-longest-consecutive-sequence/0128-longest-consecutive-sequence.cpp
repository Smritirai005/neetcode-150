class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;

        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;

        for(int num : s) {   // iterate set instead of nums
            if(!s.count(num - 1)) {  // start of sequence
                int current = num;
                int streak = 1;

                while(s.count(current + 1)) {
                    current++;
                    streak++;
                }
                longest = max(longest, streak);
            }
        }
        return longest;
    }
};

