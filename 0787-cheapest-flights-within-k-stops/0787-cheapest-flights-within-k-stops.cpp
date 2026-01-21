class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        vector<int> minCost(n, INT_MAX);
        minCost[src] = 0;

        queue<pair<int,int>> q; // {node, cost}
        q.push({src, 0});

        int stops = 0;

        while (!q.empty() && stops <= k) {
            int sz = q.size();
            while (sz--) {
                auto [u, cost] = q.front();
                q.pop();

                for (auto &[v, price] : adj[u]) {
                    if (cost + price < minCost[v]) {
                        minCost[v] = cost + price;
                        q.push({v, minCost[v]});
                    }
                }
            }
            stops++;
        }

        return minCost[dst] == INT_MAX ? -1 : minCost[dst];
    }
};

