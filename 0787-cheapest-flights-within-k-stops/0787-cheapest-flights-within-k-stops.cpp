class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto&i : flights) {
            adj[i[0]].push_back({i[1], i[2]});
        }
        vector<int> dist(n,INT_MAX);
        queue<pair<int,int>> q;
        q.push({src, 0});

        int stops = 0;
        while (stops <= k && !q.empty()) {
            int size = q.size();
            while (size--) {
                auto [node, distance] = q.front();
                q.pop();
                
                for (auto& [neighbour, price] : adj[node]) {
                    if (price + distance >= dist[neighbour]) continue;
                    dist[neighbour] = price + distance;
                    q.push({neighbour, dist[neighbour]});
                }
            }
            stops++;
        }
        return (dist[dst] == INT_MAX) ? -1 : dist[dst];
    }
};