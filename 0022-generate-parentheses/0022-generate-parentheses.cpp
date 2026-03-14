class Solution {
private:
    void fun(vector<string> &ans, int n, int open, int close, string curr) {
        
        if(open==n && close==n){
            ans.push_back(curr);
            return;
        }

        if(open < n){
            curr.push_back('(');
            fun(ans,n,open+1,close,curr);
            curr.pop_back();
        }

        if(close < open){
            curr.push_back(')');
            fun(ans,n,open,close+1,curr);
            curr.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        fun(ans, n, 0, 0, "");
        return ans;
    }
};