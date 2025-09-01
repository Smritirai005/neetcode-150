class Solution {
public:
    int trap(vector<int>& height) {
        stack<int>st;
        int count=0;
        for(int i=0;i<height.size();i++){
            while(!st.empty() && height[i]>height[st.top()]){
                int h=st.top();
                st.pop();
                if(st.empty())break;
                int w=i-st.top()-1;
                int h2=min(height[i],height[st.top()])-height[h];

                count+=h2*w;




            }
            st.push(i);
        }
        return count;

        



        
        
        
        
    }
};


