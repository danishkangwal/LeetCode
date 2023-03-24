class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        
        vector<vector<pair<int,int>>> adj(n);
        for(auto&i : connections){
            adj[i[0]].push_back({i[1],1});
            adj[i[1]].push_back({i[0],0});
        }
        
        int ans = 0;
        vector<bool> vis(n,0);
        queue<int> q;
        q.push(0);
        while(q.size()){
            int curr = q.front();
            q.pop();
            cout << curr<<" ";
            vis[curr] = 1;
            for(auto&i: adj[curr]){
                if(!vis[i.first]){
                    vis[i.first] = 1;
                    if(i.second==1)
                        ans++;
                    q.push(i.first);
                }
            }
        }
        
        return ans;
    }
};