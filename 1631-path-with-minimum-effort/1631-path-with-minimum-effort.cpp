class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        priority_queue<
            pair<int,pair<int,int>>, 
            vector<pair<int,pair<int,int>>>, 
            greater<>
        > pq;

        vector<vector<int>> dis(m, vector<int>(n, INT_MAX));

        pq.push({0,{0,0}});
        dis[0][0] = 0;

        int x[4] = {-1,1,0,0};
        int y[4] = {0,0,-1,1};

        while(!pq.empty()){
            auto p = pq.top();   
            pq.pop();

            int d = p.first;
            int row = p.second.first;
            int col = p.second.second;

            for(int k=0;k<4;k++){
                int nr = row + x[k];
                int nc = col + y[k];

                if(nr>=0 && nc>=0 && nr<m && nc<n){
                    int ans = max(d, abs(heights[row][col] - heights[nr][nc]));

                    if(ans < dis[nr][nc]){
                        dis[nr][nc] = ans;
                        pq.push({ans,{nr,nc}});
                    }
                }
            }
        }

        return dis[m-1][n-1];
    }
};
