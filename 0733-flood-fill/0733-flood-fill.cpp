class Solution {
public:
    void dfs(vector<vector<int>>& image,int i,int j,int m,int n,int old,int color){
        if(i < 0 || j < 0 || i >= m || j >= n || image[i][j] != old) return;

        image[i][j] = color;

        dfs(image, i+1, j, m, n, old, color);
        dfs(image, i-1, j, m, n, old, color);
        dfs(image, i, j+1, m, n, old, color);
        dfs(image, i, j-1, m, n, old, color);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        int old = image[sr][sc];
        if(old == color) return image;

        dfs(image, sr, sc, m, n, old, color); 

        return image;
    }
};