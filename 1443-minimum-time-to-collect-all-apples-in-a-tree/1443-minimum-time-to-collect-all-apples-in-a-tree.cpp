class Solution {
public:
    unordered_map<int, vector<int>> adj;
    unordered_map<int, bool> visited;

    int dfs(int node, int cost, vector<bool>& hasApple) {

        if (visited[node]) {
            return 0;
        }
        visited[node] = true;

        int childrenCost = 0;
        for (auto x : adj[node]) {
            childrenCost += dfs(x, 2, hasApple);
        }

        if (childrenCost == 0 && hasApple[node] == false) {
            return 0;
        }

        return (childrenCost + cost);
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return dfs(0, 0, hasApple);
    }
};