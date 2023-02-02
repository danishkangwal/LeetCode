class Solution {
public:
    int minDistance(string a, string b) {
        int n = a.size(),m = b.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1));

        for (int i = 0; i < n+1; ++i){
            dp[i][0] = i;
        }
        for (int i = 0; i < m+1; ++i){
            dp[0][i] = i;
        }
        for (int i = 1; i < n+1; ++i)
        {
            for (int j = 1; j < m+1; ++j)
            {
                if(a[n-i]==b[m-j]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
                }
            }
        }
        return dp[n][m];
    }
};