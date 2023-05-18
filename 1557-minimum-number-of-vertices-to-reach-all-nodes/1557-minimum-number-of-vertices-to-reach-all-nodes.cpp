class Solution {
    vector<vector<int>> adj;
    void dfs(int i,vector<int>& a,vector<bool>& vis){
        if(vis[i])
            return;
        vis[i] = 1;
        a.push_back(i);
        for(auto neigh:adj[i]){
            dfs(neigh,a,vis);
        }
    }
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
        }
        vector<int> nodes;
        
        
        vector<vector<int>> total;
        for(int i = 0;i < n;i++){
            vector<bool> vis(n,0);
            vector<int> a;
            for(auto neigh:adj[i])
                dfs(i,a,vis);
            total.push_back(a);
        }
        unordered_set<int> st;
        for(int i = 0;i < n;i++)
            st.insert(i);
        
        for(auto i:total){
            if(i.size()==0)
                continue;
            int j = 1;
            while(j<i.size()){
                st.erase(i[j]);
                j++;
            }
        }
        for(auto it:st){
            nodes.push_back(it);
        }
        
        return nodes;
    }
};