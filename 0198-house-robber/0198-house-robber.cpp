class Solution {
public:
    int n;
    int a[101];
    int dp[101];
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        n = nums.size();
        for(int i=0;i < n;i++)
            a[i] = nums[i];
        return rec(0);
    }
private:
    int rec(int level){
        if(level >= n)
            return 0;
        if(dp[level]!=-1){
            return dp[level];
        }
        int ans = 0;
        ans = a[level] + rec(level+2);
        if(level!=n-1){
            int tmp = a[level+1]+rec(level+3);
            if(tmp > ans)
                ans = tmp;
        }
        return dp[level] =  ans;
    }
};