class Solution {
public:
    long long ans = 0;
    long long dfs(vector<vector<int>>& edges,int node,vector<bool>& vis,int seats){
        vis[node] = true;
        
        long long cnt = 1;
        for(int i = 0;i < edges[node].size();i++){
            if(!vis[edges[node][i]]){
                cnt += dfs(edges,edges[node][i],vis,seats);
            }
        }
        long long x = cnt/seats;
        if(cnt%seats)x++;
        
        if(node != 0)
            ans += x;
        
        return cnt;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        if(roads.size()==0)
            return 0;
        
        int n = roads.size();
        vector<vector<int>> edges(n+1);
        for(auto& i:roads){
            edges[i[0]].push_back(i[1]);
            edges[i[1]].push_back(i[0]);
        }
        vector<bool> vis(n+1,0);
        dfs(edges,0,vis,seats);
        return ans;
    }
};