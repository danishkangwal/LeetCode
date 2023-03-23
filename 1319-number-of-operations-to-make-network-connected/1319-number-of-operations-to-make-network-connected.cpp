class Solution {
    void dfs(vector<vector<int>>&adj,int node,vector<bool>&visited){
        visited[node] = 1;
        for(auto& i:adj[node]){
            if(!visited[i]){
                dfs(adj,i,visited);
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n-1>connections.size()) 
            return -1;
        vector<vector<int>> adj(n);
        for(auto &i:connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<bool> visited(n,0);
        int connected = 0;
        for(int i = 0;i<n;i++){
            if(!visited[i]){
                connected++;
                dfs(adj,i,visited);
            }
        }
        return connected-1;
    }
};