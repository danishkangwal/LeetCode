class Solution {
public:
    bool canJump(vector<int>& a) {
        int n = a.size();
        vector<int> dp(n);
        dp[n-1]=1;

        for(int i = n-2;i>=0;i--){
            for(int j = 1;j <= a[i];j++){
                if(dp[i+j]){
                    dp[i] = 1;
                    break;
                }
            }

        }
        return dp[0];
    }
};