class Solution {
    void bfs(vector<vector<int>>&adj,int node,vector<bool>&visited){
        visited[node] = 1;
        queue<int> q;
        q.push(node);
        while(q.size()){
            int curr = q.front();
            q.pop();
            for(int& i:adj[curr]){
                if(!visited[i]){
                    visited[i] = 1;
                    q.push(i);
                }
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
                bfs(adj,i,visited);
            }
        }
        return connected-1;
    }
};