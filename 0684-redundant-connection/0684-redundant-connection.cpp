class Solution {
public:
    bool dfs(int node,vector<vector<int>>& graph,vector<int>& visited,int parent){
        visited[node]=1;
        for(int nbr:graph[node]){
            if(!visited[nbr]){
                bool res=dfs(nbr,graph,visited,node);
                if(res==true)return true;
            }
            else if(nbr!=parent){
                return true;
                
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int v=edges.size();
        vector<vector<int>>graph(v+1);
        for(auto &p : edges){
            graph[p[0]].push_back(p[1]);
            graph[p[1]].push_back(p[0]);

            vector<int>visited(v+1,0);
            int parent;
            if (dfs(p[0], graph, visited, -1)) {
                return p;
            }
        }
        
        return {};
        
        
    }
};