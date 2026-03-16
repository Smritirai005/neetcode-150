class Solution {
private:
    unordered_map<char,string>f;
    void fun(string& digits,int n, vector<string>&ans,string res,int idx){
        
        if(idx==n){
            ans.push_back(res);
            return;
        }
        string t=f[digits[idx]];
        for(int i=0;i<t.length();i++){
            res.push_back(t[i]);
            fun(digits,n,ans,res,idx+1);
            res.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.size()==0) return ans;
        f['2']="abc";
        f['3']="def";
        f['4']="ghi";
        f['5']="jkl";
        f['6']="mno";
        f['7']="pqrs";
        f['8']="tuv";
        f['9']="wxyz";
        string res="";
        fun(digits,digits.size(),ans,res,0);

        return ans;


        
        
    }
};