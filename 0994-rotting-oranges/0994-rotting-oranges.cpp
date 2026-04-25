class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        int fresh=0;
        int time=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        int x[4]={-1,1,0,0};
        int y[4]={0,0,-1,1};
        while(!q.empty()&& fresh>0){
            int s=q.size();
            while(s--){
                pair<int,int>p=q.front();
                q.pop();
                int r=p.first;
                int c=p.second;
                for(int i=0;i<4;i++){
                    int row=r+x[i];
                    int col=c+y[i];
                    if(row>=0&&col>=0 && row<m && col<n &&grid[row][col]==1){
                        grid[row][col]=2;
                        fresh--;
                        q.push({row,col});

                    }
                }
            }
            time++;

        }
        return fresh == 0 ? time : -1;

        
    }
};