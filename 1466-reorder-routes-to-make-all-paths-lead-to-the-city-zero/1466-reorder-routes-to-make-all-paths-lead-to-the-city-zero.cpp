class Solution {
    int ans;
    void dfs(vector<vector<pair<int,int>>>& adj,int node,vector<bool>& vis){
        vis[node] = 1;
        for(auto&i :adj[node]){
            if(!vis[i.first]){
                if(i.second==1)
                    ans++;
                dfs(adj,i.first,vis);
            }
        }
        
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        
        vector<vector<pair<int,int>>> adj(n);
        for(auto&i : connections){
            adj[i[0]].push_back({i[1],1});
            adj[i[1]].push_back({i[0],0});
        }
        
        ans = 0;
        vector<bool> vis(n,0);
        dfs(adj,0,vis);
        
        return ans;
    }
};