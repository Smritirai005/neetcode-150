class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/")          {
                int n=st.top();st.pop();
                int m=st.top();st.pop();
                if(tokens[i]=="+")st.push(n+m);
                else if(tokens[i]=="-")st.push(m-n);
                else if(tokens[i]=="*")st.push(n*m);
                else if(tokens[i]=="/")st.push(m/n);
            
            }else{
                st.push(stoi(tokens[i]));
            }
            
            
        }
        return st.top();



        
    }
};