class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i,int j){
        if(i<0||j<0||i>=grid.size() || j>=grid[0].size() || grid[i][j]=='0')
            return;
        
        // mark current cell as visited (sink the island)
        grid[i][j] ='0';
        
        // explore all 4 directions
        dfs(grid, i + 1, j); // down
        dfs(grid, i - 1, j); // up
        dfs(grid, i, j + 1); // right
        dfs(grid, i, j - 1); // left

    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())return 0;
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(grid,i,j);
                }
            }
        }
        return count;

        
        
        
    }
};