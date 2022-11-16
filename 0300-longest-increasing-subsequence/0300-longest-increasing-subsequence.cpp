class Solution {
public:
    int dp[2501][2501];
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return helper(0,-1,nums);
    }
private:
    int helper(int level,int last,vector<int>& nums){
        if(level==nums.size())
            return 0;
        if(dp[level][last+1] != -1)
            return dp[level][last+1];
        int ans = helper(level+1,last,nums);
        if(last==-1 || nums[level]>nums[last]){
            ans = max(ans,1+helper(level+1,level,nums));
        }
        return dp[level][last+1] = ans;
    }
};