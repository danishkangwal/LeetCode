class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        int dp[100001] = {};
        unordered_map<int,vector<pair<int,int>>> mp;
        for(auto offer:offers){
            mp[offer[1]].push_back({offer[0],offer[2]});
        }
        
        for (int k = 0; k < n; ++k) {
            dp[k + 1] = dp[k];
            if (mp.count(k))
                for (auto [start, gold] : mp[k])
                    dp[k + 1] = max(dp[k + 1], dp[start] + gold);
        }
        
        return dp[n];
    }
};