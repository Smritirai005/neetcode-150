class Solution {
public:
    int characterReplacement(string s, int k) {
        
        unordered_map<char,int> mp;
        int i = 0;
        int j = 0;
        int mx = 0;
        int maxFreq = 0;

        while(j < s.length()) {
            mp[s[j]]++;

            // track most frequent character in window
            maxFreq = max(maxFreq, mp[s[j]]);

            // if invalid window → shrink
            while((j - i + 1) - maxFreq > k) {
                mp[s[i]]--;
                i++;
            }

            mx = max(mx, j - i + 1);
            j++;
        }

        return mx;
    }
};