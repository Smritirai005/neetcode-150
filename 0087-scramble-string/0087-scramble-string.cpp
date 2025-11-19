class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        memo.clear();
        return dfs(s1, s2);
    }
private:
    unordered_map<string, bool> memo;
    bool dfs(const string& a, const string& b) {
        string key = a + "#" + b;
        if (memo.count(key)) return memo[key];
        if (a == b) return memo[key] = true;
        int n = a.size();
        // fast char-frequency prune
        int cnt[26] = {0};
        for (int i = 0; i < n; ++i) {
            cnt[a[i]-'a']++;
            cnt[b[i]-'a']--;
        }
        for (int i = 0; i < 26; ++i) if (cnt[i]) return memo[key] = false;

        // try every split
        for (int len = 1; len < n; ++len) {
            // no swap
            if (dfs(a.substr(0, len), b.substr(0, len)) &&
                dfs(a.substr(len), b.substr(len)))
                return memo[key] = true;

            // swap
            if (dfs(a.substr(0, len), b.substr(n - len)) &&
                dfs(a.substr(len), b.substr(0, n - len)))
                return memo[key] = true;
        }
        return memo[key] = false;
    }
};
