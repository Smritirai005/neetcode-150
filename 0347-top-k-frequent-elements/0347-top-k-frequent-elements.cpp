class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;

        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

        for(auto const& [nums,freq]: mp){
            minHeap.push({freq,nums});
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }
        while(!minHeap.empty()){
            ans.push_back(minHeap.top().second);
            minHeap.pop();

        }
        return ans;
        
    
        
        
        

    }
};