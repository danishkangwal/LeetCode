class Solution {
    int ans = -1;
    void dfs(vector<int>&edges,int node,vector<bool>&vis,unordered_map<int,int>&dist){
        vis[node] = 1;
        int u = edges[node];
        if(u!=-1){
            if(!vis[u]){
                dist[u] = dist[node]+1;
                dfs(edges,u,vis,dist);
            }
            else if(dist.count(u)){
                ans = max(ans,dist[node]-dist[u]+1);
            }
        }
        
    }
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> vis(n,0);
        for(int i = 0;i < n;i++){
            if(!vis[i]){
                unordered_map<int,int> dist;
                dist[i] = 1;
                dfs(edges,i,vis,dist);
            }
        }
        return ans;
    }
};