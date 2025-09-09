class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto const& pair:mp){
            if(pair.second>1){
                return pair.first;
            }
        }
        return -1;
        
    }
};