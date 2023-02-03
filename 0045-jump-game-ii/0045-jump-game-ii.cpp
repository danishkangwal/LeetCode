class Solution {
public:
    int jump(vector<int>& a) {
        int n = a.size();
        vector<int> dp(n,a.size());

        dp[n-1] = 0;
        for(int i = n-2;i>=0;i--){
            for(int j = 1;j <= a[i] && (i+j) < n;j++){
                dp[i] = min(dp[i],1+dp[i+j]);
            }
        }
        return dp[0];
    }
};