class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        if(nums.size()==2)
            return max(nums[0],nums[1]);
        
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(2,0));
        
        dp[n-1][1] = 0;
        dp[n-1][0] = nums[n-1];
        dp[n-2][1] = nums[n-2];
        dp[n-2][0] = max(nums[n-2],nums[n-1]);
        
        for(int i = n-3;i>0;i--){
            dp[i][1] = max(nums[i]+dp[i+2][1],dp[i+1][1]);
            dp[i][0] = max(nums[i]+dp[i+2][0],dp[i+1][0]);
        }
        dp[0][1] = max(dp[1][1],nums[0]+dp[2][1]);
        dp[0][0] = max(dp[1][0],dp[2][0]);
        
        return max(dp[0][1],dp[0][0]);
    }
};