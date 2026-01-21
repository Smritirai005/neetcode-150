class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& f : flights) adj[f[0]].push_back({f[1], f[2]});

        vector<int> minCost(n, INT_MAX);
        minCost[src] = 0;

        queue<pair<int, pair<int, int>>> q; // {stops, {node, cost}}
        q.push({0, {src, 0}});

        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            int stops = cur.first;
            int u = cur.second.first;
            int cost = cur.second.second;

            if (stops > k) continue;

            for (auto& edge : adj[u]) {
                int v = edge.first;
                int price = edge.second;
                if (cost + price < minCost[v]) {
                    minCost[v] = cost + price;
                    q.push({stops + 1, {v, minCost[v]}});
                }
            }
        }
        return minCost[dst] == INT_MAX ? -1 : minCost[dst];
    }
};
