class Solution:
    def longestCommonSubsequence(self, a: str, b: str) -> int:
        n = len(a)
        m = len(b)
        
        dp = [[0]*(m+1) for i in range(n+1)]
        
        print(dp)
        for i in range(1,n+1):
            for j in range(1,m+1):
                if(a[n-i]==b[m-j]):
                    dp[i][j] = 1 + dp[i-1][j-1]
                else:
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1])
        return dp[n][m]