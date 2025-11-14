class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites){
        int v = numCourses;
        vector<vector<int>> graph(v);
        for (auto &p : prerequisites) {
            graph[p[1]].push_back(p[0]);
        }
        vector<int>indegree(v);
        vector<int>ans;
        for(int i=0;i<v;i++){
            for(int &x:graph[i]){
                indegree[x]++;

            }
        }
        queue<int>q;
        for(int i=0;i<v;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int f=q.front();
            q.pop();
            ans.push_back(f);
            for(int &x:graph[f]){
                indegree[x]--;
                if(indegree[x]==0){
                    q.push(x);
                }
            }

        }
        if (ans.size() != v) return {};
        return ans;
        
    }
};