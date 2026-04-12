class Solution {
public: bool dfs(vector<vector<int>>&adj,int node, vector<int>&vis,vector<int>&currpth){
    vis[node]=1;
    currpth[node]=1;
    for(int i=0;i<adj[node].size();i++){
        int nbr=adj[node][i];
        if(!vis[nbr]){
            int res=dfs(adj,nbr,vis,currpth);
            if(res==false)return false;
        }
        else if(currpth[nbr]==1){
            return false;
        }
        
       

    }
    currpth[node]=0;
    return true;
}
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>>adj(n);
        vector<int>vis(n,0);
        vector<int>currpth(n,0);
        for(int i=0;i<prerequisites.size();i++){
            vector<int>edge=prerequisites[i];
            int src=edge[0];
            int des=edge[1];
            adj[des].push_back(src);

        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int ans=dfs(adj,i,vis,currpth);
                if(ans==false){
                    return false;
                }
            }
        }
        return true;


        
        
    }
};