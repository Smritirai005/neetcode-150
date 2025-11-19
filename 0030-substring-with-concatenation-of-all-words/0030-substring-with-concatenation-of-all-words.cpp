class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.empty()) return res;

        int n = s.size();
        int wordLen = words[0].size();
        int wordCount = words.size();
        int windowLen = wordLen * wordCount;

        if (n < windowLen) return res;

        unordered_map<string, int> freq;
        for (auto &w : words) freq[w]++;

        // try each offset: 0, 1, 2... wordLen-1
        for (int offset = 0; offset < wordLen; offset++) {
            int left = offset;
            int count = 0;
            unordered_map<string, int> seen;

            for (int right = offset; right + wordLen <= n; right += wordLen) {
                string word = s.substr(right, wordLen);

                if (freq.count(word)) {
                    seen[word]++;
                    count++;

                    // fix overflow of a word
                    while (seen[word] > freq[word]) {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    // perfect window
                    if (count == wordCount) {
                        res.push_back(left);
                        // slide window by removing leftmost word
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        left += wordLen;
                        count--;
                    }
                } else {
                    // word not in list → reset window
                    seen.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }
        return res;
    }
};
