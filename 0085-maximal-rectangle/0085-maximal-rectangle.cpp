class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;

        int n = matrix.size(), m = matrix[0].size();
        vector<int> heights(m, 0);
        int maxArea = 0;

        for(int i = 0; i < n; i++) {
            // Build heights like histogram
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '1')
                    heights[j] += 1;
                else
                    heights[j] = 0;
            }

            // Calculate largest rectangle in histogram
            maxArea = max(maxArea, largestRectangle(heights));
        }

        return maxArea;
    }

    int largestRectangle(vector<int>& heights) {
        stack<int> st;
        heights.push_back(0); // sentinel
        int maxArea = 0;

        for(int i = 0; i < heights.size(); i++) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                int h = heights[st.top()];
                st.pop();
                int left = st.empty() ? -1 : st.top();
                int width = i - left - 1;
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }

        heights.pop_back();
        return maxArea;
    }
};
