class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        vector<vector<int>> vis(n, vector<int>(n, 0));

        pq.push({grid[0][0], 0, 0});

        int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int time = curr[0];
            int x = curr[1];
            int y = curr[2];

            if (vis[x][y]) continue;
            vis[x][y] = 1;

            if (x == n - 1 && y == n - 1)
                return time;

            for (auto &d : dirs) {
                int nx = x + d[0];
                int ny = y + d[1];

                if (nx >= 0 && ny >= 0 && nx < n && ny < n && !vis[nx][ny]) {
                    pq.push({
                        max(time, grid[nx][ny]),
                        nx,
                        ny
                    });
                }
            }
        }

        return -1;
    }
};