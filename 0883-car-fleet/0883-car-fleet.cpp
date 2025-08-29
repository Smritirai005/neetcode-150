class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double>st;
        vector<pair<int,int>>ans;
        int fleet=0;
        for(int i=0;i<position.size();i++){
            ans.push_back({position[i],speed[i]});

        }
        sort(ans.rbegin(),ans.rend());
        for(int i=0;i<ans.size();i++){
            double res=(double)(target-ans[i].first)/ans[i].second;
            if(!st.empty() && res<=st.top()){
                continue;
            }
            else{
                fleet++;
                st.push(res);
            }


            

        }
        return fleet;
        

        
    }
};