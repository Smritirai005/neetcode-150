class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        
        queue<pair<int,int>> pq;
        pq.push({0,0});
        
        // mark visited by changing grid itself
        grid[0][0] = 1;
        
        int x[8] = {-1,-1,-1,0,0,1,1,1};
        int y[8] = {-1,0,1,-1,1,-1,0,1};
        
        int dist = 1;
        
        while(!pq.empty()){
            int size = pq.size();
            
            while(size--){
                auto p = pq.front();
                pq.pop();
                
                int row = p.first;
                int col = p.second;
                
                if(row == n-1 && col == n-1) return dist;
                
                for(int k=0;k<8;k++){
                    int nr = row + x[k];
                    int nc = col + y[k];
                    
                    if(nr>=0 && nc>=0 && nr<n && nc<n && grid[nr][nc]==0){
                        pq.push({nr,nc});
                        grid[nr][nc] = 1; // mark visited
                    }
                }
            }
            dist++;
        }
        
        return -1;
    }
};