class Solution {
public:
    string removeDuplicates(string s) {
        
        int n=s.length();
        stack<char>st;
        string res="";
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(s[i]);
                continue;
            }
            else if(st.top()==s[i]){
                st.pop();
                continue;
            }
            st.push((s[i]));
        }
        while(!st.empty()){
            char tp=st.top();
            st.pop();
            res.push_back(tp);
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};