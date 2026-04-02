class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()) return false;

        unordered_map<char,int>mp1;
        for(int i=0;i<s1.length();i++){
            mp1[s1[i]]++;
        }
        int i=0;
        int j=0;
        while(j<s2.length()){
            mp1[s2[j]]--;
            while(mp1[s2[j]]<0){
                mp1[s2[i]]++;
                i++;

            }
            if(j-i+1==s1.length()) return true;
            j++;


            
                
            
        }
        return false;
    }
};
    // class Solution {
    // public:
    //     bool checkInclusion(string s1, string s2) {
    //         if(s1.length() > s2.length()) return false;

    //         vector<int> cnt(26, 0);

    //         // count s1
    //         for(char c : s1) cnt[c - 'a']++;

    //         int i = 0;

    //         for(int j = 0; j < s2.length(); j++) {
    //             cnt[s2[j] - 'a']--;   // include char in window

    //             // if negative → extra char, shrink window
    //             while(cnt[s2[j] - 'a'] < 0) {
    //                 cnt[s2[i] - 'a']++;
    //                 i++;
    //             }

    //             // valid window size
    //             if(j - i + 1 == s1.length()) return true;
    //         }

    //         return false;
    //     }
    // };
    
