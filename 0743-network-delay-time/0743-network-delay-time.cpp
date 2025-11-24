class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // graph should be size n+1, not times.size()
        vector<vector<pair<int,int>>> graph(n+1);

        // build directed weighted graph
        for (auto &p : times) {
            graph[p[0]].push_back({p[1], p[2]});
        }

        // distance array
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;

        // min-heap {time, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();

            if (time > dist[node]) continue;

            for (auto &nbr : graph[node]) {
                int next = nbr.first;
                int w = nbr.second;

                if (dist[next] > time + w) {
                    dist[next] = time + w;
                    pq.push({dist[next], next});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};
