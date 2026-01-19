class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mp;
        int i=0;
        int j=0;
        int total=0;
        int ans=INT_MIN;
        while(j<fruits.size()){
            mp[fruits[j]]++;
            total++;
            if(mp.size()<=2){
                ans=max(ans,total);

            }
            else if(mp.size()>2){
                total--;
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0)mp.erase(fruits[i]);
                i++;
            }
            j++;
            
        }
        return ans;


        
    }
};