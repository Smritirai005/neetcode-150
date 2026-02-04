class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mp1, mp2;
        string s = "balloon";

        for (int i = 0; i < text.size(); i++) {
            mp1[text[i]]++;
        }

        for (int i = 0; i < s.size(); i++) {
            mp2[s[i]]++;
        }

        int ans = INT_MAX;
        for (auto it : mp2) {
            ans = min(ans, mp1[it.first] / it.second);
        }

        return ans;
    }
};
