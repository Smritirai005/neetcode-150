class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp1;
        int i=0;
        int j=0;
        int start=0;
        int count=t.size();;
        int ans=INT_MAX; 
        for(i=0;i<t.length();i++){
            mp1[t[i]]++;
        }
        i=0;
        while(j<s.length()){
            
            if(mp1[s[j]]>0){
                count--;
            }
            mp1[s[j]]--;
            while(count==0){
                if(j-i+1<ans){
                    ans=j-i+1;
                    start=i;
                }
                mp1[s[i]]++;
                

                if(mp1[s[i]]>0){
                    count++;
                }
                i++;
            }
            j++;
               
                

                
            

        } 
        return (ans==INT_MAX)?"":s.substr(start,ans);
        
    }
};