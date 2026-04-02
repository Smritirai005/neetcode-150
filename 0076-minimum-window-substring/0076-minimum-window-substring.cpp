class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        
        for(char c : t) {
            mp[c]++;
        }

        int i = 0, j = 0;
        int count = t.size();
        int mn = INT_MAX, start = 0;

        while(j < s.size()) {
            if(mp[s[j]] > 0) count--;
            mp[s[j]]--;

            while(count == 0) {
                if(j - i + 1 < mn) {
                    mn = j - i + 1;
                    start = i;
                }

                mp[s[i]]++;
                if(mp[s[i]] > 0) count++;
                i++;
            }

            j++;
        }

        return mn == INT_MAX ? "" : s.substr(start, mn);
    }
};