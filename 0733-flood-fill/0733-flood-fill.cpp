class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        queue<pair<int,int>> q;
        int oldColor = image[sr][sc];
        if(oldColor == color) return image;

        q.push({sr,sc});
        image[sr][sc] = color;
        int x[4]={-1,1,0,0};
        int y[4]={0,0,-1,1};

        while(!q.empty()){
            pair<int,int>p=q.front();
            q.pop();
            int r=p.first;
            int c=p.second;
            for(int i=0;i<4;i++){
                int row=r+x[i];
                int col=c+y[i];
                if(row>=0 && col>=0 && row<m &&col<n && image[row][col]==oldColor){
                    image[row][col]=color;
                    q.push({row,col});
                }
            }

        }
        return image;
        
    }
};