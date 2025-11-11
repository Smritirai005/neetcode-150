class Solution {
public:
    bool dfs(int node,vector<vector<int>>& graph,vector<int>& visited,vector<int>& currpth){
        visited[node]=1;
        currpth[node]=1;
        for(int nbr:graph[node]){
            if(!visited[nbr]){
                bool res=dfs(nbr,graph,visited,currpth);
                if(res==true)return true;
            }
            else{
                if(currpth[nbr]==1){
                    return true;
                }
            }
        }
        currpth[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int>visited(v),currpth(v),ans;
        for(int i=0;i<v;i++){
            if(!visited[i]){
                dfs(i,graph,visited,currpth);
                
            }
            
        }
        for(int i=0;i<v;i++){
            if(currpth[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
        
        
        
    }
};