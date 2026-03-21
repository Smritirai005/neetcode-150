class Solution {
private:
    bool isPal(string &s, int l, int r){
        while(l < r){
            if(s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }

    void fun(string s,int n,int idx,
             vector<string>& diary,
             vector<vector<string>>& ans){

        if(idx==n){
            ans.push_back(diary);
            return;
        }

        string temp = "";
        for(int i = idx; i < n; i++){
            temp += s[i];   // build substring (your diary idea)

            if(isPal(s, idx, i)){
                diary.push_back(temp);
                fun(s, n, i+1, diary, ans);
                diary.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<string>> ans;
        vector<string> diary;

        fun(s, n, 0, diary, ans);
        return ans;
    }
};