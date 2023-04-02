class Solution {
    const int mod = 1e9+7;
public:
    int ways(vector<string>& pizza, int k) {
        int m = pizza.size(),n = pizza[0].size();
        vector dp(k,vector(m,vector<int>(n,0)));
        vector apples(m+1,vector<int>(n+1));
        for(int i = m-1;i>=0;i--){
            for(int j = n-1;j>=0;j--){
                apples[i][j] = (pizza[i][j]=='A')+apples[i+1][j]+apples[i][j+1] - apples[i+1][j+1];
                dp[0][i][j] = apples[i][j]>0;
            }
        }
        for(int _k = 1;_k<k;_k++){
            for(int i = 0;i < m;i++){
                for(int j = 0;j < n;j++){
                    for(int row=i+1;row<m;row++){
                        if(apples[i][j]-apples[row][j]>0)
                            (dp[_k][i][j] += dp[_k-1][row][j])%=mod;
                    }
                    for(int col = j+1;col<n;col++){
                        if(apples[i][j]-apples[i][col]>0)
                            (dp[_k][i][j] += dp[_k-1][i][col])%=mod;
                    }
                }
            }
        }
        
        return dp[k-1][0][0];
    }
};