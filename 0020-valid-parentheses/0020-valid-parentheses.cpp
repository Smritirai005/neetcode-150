class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char ch:s){
            if(ch=='('|| ch=='{'|| ch=='['){
                st.push(ch);
            }
            else{
                if(st.empty()) return false;

                char first=st.top();
                st.pop();
                
                if((ch==')'&& first !='(') ||
                    (ch=='}'&& first != '{') ||
                    (ch==']'&& first != '[')){
                    return false;
                }
            }
        }
        return st.empty();
    }
};