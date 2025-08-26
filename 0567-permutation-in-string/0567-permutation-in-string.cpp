class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()) return false;

        unordered_map<char,int>mp1,mp2;
        for(int i=0;i<s1.length();i++){
            mp1[s1[i]]++;
        }
        int i=0;
        int j=0;
        while(j<s2.length()){
            mp2[s2[j]]++;
            if(j-i+1<s1.length()){
                j++;
            }
            else if(j-i+1==s1.length()){
                if(mp1==mp2){
                    return true;
                }
        
                mp2[s2[i]]--;
                if(mp2[s2[i]]==0){
                    mp2.erase(s2[i]);
                }
                i++;
                j++;
                
            }
        }
        return false;
    }
};

 
