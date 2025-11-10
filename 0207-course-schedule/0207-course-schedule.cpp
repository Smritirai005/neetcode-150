class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& visited, vector<int>& currpth) {
        visited[node] = 1;
        currpth[node] = 1;

        for (int nbr : graph[node]) {
            if (!visited[nbr]) {
                int res = dfs(nbr, graph, visited, currpth);
                if (res == false) return false;
            } 
            else {
                if (currpth[nbr] == 1) {
                    return false;
                }
            }
        }

        currpth[node] = 0;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int v = numCourses;
        vector<vector<int>> graph(v);
        for (auto &p : prerequisites) {
            graph[p[1]].push_back(p[0]);
        }
        vector<int> visited(v), currpth(v);

        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                int ans = dfs(i, graph, visited, currpth);
                if (ans == false) {
                    return false;
                }
            }
        }

        return true;
    }
};
