class Solution {
    int cycleStart = -1;
    bool *vis,*cycle,found;
    void dfs(vector<int> adj[],int node,int parent){
        if(vis[node]){
            cycleStart = node;
            found = true;
           return;
        }
        vis[node] = 1;
        for(auto& u:adj[node]){
            if(u==parent)
                continue;
            if(!found)
                dfs(adj,u,node);
            if(cycleStart != -1)
                cycle[node] = 1;
            if(node == cycleStart){
                cycleStart = -1;
                return;
            }
        }
        
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        cycle = (bool*)calloc(n+1,sizeof(bool));
        vis = (bool*)calloc(n+1,sizeof(bool));
        vector<int> adj[n+1];
        for(auto& edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        dfs(adj,1,-1);
        for(int i = n-1;i>=0 ;i--){
            if(cycle[edges[i][0]] and cycle[edges[i][1]])
                return edges[i];
        }
        return {};
    }
};