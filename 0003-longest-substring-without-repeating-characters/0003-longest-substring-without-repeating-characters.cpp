class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char,int>mp;
        int i=0;
        int j=0;
        int mx=0;
        while(j<s.length()){
            mp[s[j]]++;
            while(mp[s[j]]>1){
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;

            }
            mx=max(mx,j-i+1);
            j++;

        }
        return mx;
    }
};