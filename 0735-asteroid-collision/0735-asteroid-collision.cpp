class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        stack<int>st;
        vector<int>res;
        for(int i=0;i<n;i++){
            while(!st.empty()&& st.top()>0 && asteroids[i]<0){
                int tp=st.top();
                st.pop();
                if(abs(tp)>abs(asteroids[i])){
                    st.push(tp);
                    asteroids[i] = 0;
                    break;
                }
                else if(abs(tp)==abs(asteroids[i])){
                    asteroids[i] = 0;
                    break;
                }
    
            }
            if (asteroids[i] != 0) {
                st.push(asteroids[i]);
            }
        }
        while(!st.empty()){
            int tp=st.top();
            st.pop();
            res.push_back(tp);
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};