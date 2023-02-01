class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
        int n = a.size(),m = b.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1));

        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            for(int j = 1;j <= m;j++){
                if(a[n-i]==b[m-j]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};