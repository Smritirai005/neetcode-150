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
// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         vector<int> freq(26, 0);
        
//         int i = 0, maxFreq = 0, maxLen = 0;
        
//         for (int j = 0; j < s.size(); j++) {
//             freq[s[j] - 'A']++;
            
//             // update max frequency
//             maxFreq = max(maxFreq, freq[s[right] - 'A']);
            
//             // if window is invalid
//             while ((j - i + 1) - maxFreq > k) {
//                 freq[s[i] - 'A']--;
//                 i++;
//             }
            
//             maxLen = max(maxLen, j - i + 1);
//         }
        
//         return maxLen;
//     }
// };