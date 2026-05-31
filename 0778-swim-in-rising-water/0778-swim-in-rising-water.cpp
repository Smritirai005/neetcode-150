class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({grid[0][0],0,0});
        dist[0][0]=grid[0][0];
        int row[4]={-1,1,0,0};
        int col[4]={0,0,-1,1};
        while(!pq.empty()){
            vector<int> p = pq.top();
            pq.pop();
            int time = p[0];
            int rw = p[1];
            int cl = p[2];
            if(rw==n-1 && cl==n-1){
                return time;
            }
            for(int i=0;i<4;i++){
                int nr=rw+row[i];
                int nc=cl+col[i];
                if(nr>=0&&nr<n && nc >= 0 && nc < n){
                    int newt=max(time,grid[nr][nc]);

                    if(newt<dist[nr][nc]){
                        dist[nr][nc]=newt;
                        pq.push({newt,nr,nc});
                    }
                }
            }
           
        }
        return -1;



        
        
    }
};