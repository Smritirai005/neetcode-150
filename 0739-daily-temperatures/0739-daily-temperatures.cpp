class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>ans(n,0);
        stack<int>st;
        for(int i=0;i<temperatures.size();i++){
           
            while(!st.empty() && temperatures[i]>temperatures[st.top()]){
                int top=st.top();
                st.pop();
                int res=i-top;
                ans[top]=res;
                    
            }
            st.push(i);
        }
        
        return ans;
    }
};