class Solution {
public: 
    bool res=true;
    void dfs(int node,vector<vector<int>>&adj, vector<int>&color,int c){
        color[node]=c;
        for(int i=0;i<adj[node].size();i++){
            int nbr=adj[node][i];
            if(color[nbr]!=-1 && color[nbr]==c){
                res=false;
                return;

            }
            if(color[nbr]==-1){
                dfs(nbr,adj,color,1-c);
            }
        }
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>adj=graph;
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                dfs(i,adj,color,0);
            }
        }
        return res;
        
        
    }
};