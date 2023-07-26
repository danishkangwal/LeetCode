class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        if(nums.size()==2)
            return max(nums[0],nums[1]);
        
        auto _rob = [&](int l,int r){
            int dp=0,dp1=0,dp2=0;
            for(int i = l;i < r;i++){
                dp = max(dp2+nums[i],dp1);
                dp2 = dp1;
                dp1 = dp;
            }
            return dp;
        };
        
        return max(_rob(0,nums.size()-1),_rob(1,nums.size()));
    }
};