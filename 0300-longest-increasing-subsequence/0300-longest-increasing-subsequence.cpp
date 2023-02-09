class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        int ans = 1;
        vector<int> dp(n,1);

        for (int i = 0; i < n; ++i)
        {
            for(int prev = i-1; prev >= 0;prev--){
                if(a[prev]<a[i]){
                    dp[i] = max(dp[i],1+dp[prev]);
                    ans = max(ans,dp[i]);
                }
            }
        }

        return ans;
    }
};