class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(int i=0;i<strs.size();i++){
            string k=strs[i];
            sort(k.begin(),k.end());

            mp[k].push_back(strs[i]);
        }
        vector<vector<string>> result;
        for (auto const& pair : mp) {
            result.push_back(pair.second);  
        }

        return result;


        
    }
}; 