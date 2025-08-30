class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int ans=0;
        int res=0;
        for(int i=0;i<=heights.size();i++){
            int h = (i==heights.size() ? 0 : heights[i]);
            while(!st.empty() && h<heights[st.top()]){
                int first=st.top();
                st.pop();
                int w=st.empty()? i :i-st.top()-1;
                int res=heights[first]*w;
                ans=max(ans,res);


                
            }
            st.push(i);

            
        }
        return ans;
        
    }
};