class Solution {
public:
    int result;
    
    int DFS(unordered_map<int, vector<int>> &adj, int curr, int parent, string& s) {
        
        int longest = 0;
        int second_longest = 0;
        
        for(int &child : adj[curr]) {
            if(child == parent)
                continue;
            
            int child_longest_length = DFS(adj, child, curr, s);
            
            if(s[child] == s[curr])
                continue;
            
            if(child_longest_length > second_longest)
                second_longest = child_longest_length;
            
            if(second_longest > longest)
                swap(longest, second_longest);
        }
        
        int case1 = longest + second_longest + 1;
        int case2     = max(longest, second_longest) + 1;
        int case3 = 1; 
        
        
        result = max({result, case1, case2, case3});
        
        return max(case2, case3);
        
    }
    
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        result = 0;
        unordered_map<int, vector<int>> adj;
        
        for(int i = 1; i<n; i++) {
            int u = i;
            int v = parent[i];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        DFS(adj, 0, -1, s);
        
        return result;
    }
};