class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& currpth, vector<int>& res) {
        vis[node] = 1;
        currpth[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, adj, vis, currpth, res)) return true;
            }
            else if (currpth[it]) {
                return true; // cycle
            }
        }

        currpth[node] = 0;
        res.push_back(node);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;

        vector<vector<int>> adj(n);   // 🔥 missing
        vector<int> vis(n, 0);
        vector<int> currpth(n, 0);   // 🔥 missing ;
        vector<int> res;             // 🔥 missing ;

        for (int i = 0; i < prerequisites.size(); i++) {
            vector<int> edge = prerequisites[i];
            int src = edge[0];
            int des = edge[1];
            adj[des].push_back(src);
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, currpth, res)) {
                    return {}; // cycle → no order
                }
            }
        }

        reverse(res.begin(), res.end()); // 🔥 important
        return res;
    }
};