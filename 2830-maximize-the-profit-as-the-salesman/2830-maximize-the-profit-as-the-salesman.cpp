class Solution {
    int helper(vector<vector<int>>& offers,vector<int>& dp,int i){
        if(i>=offers.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        vector<int> tmp;
        tmp.push_back(offers[i][1]);
        tmp.push_back(INT_MAX);
        tmp.push_back(INT_MAX);
        
        int idx = lower_bound(offers.begin()+1,offers.end(),tmp)-offers.begin();
        int take = helper(offers,dp,idx)+offers[i][2];
        int nottake = helper(offers,dp,i+1); 
        return dp[i] = max(take,nottake);
    }
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        vector<int> dp(offers.size(),-1);
        sort(offers.begin(),offers.end());
        return helper(offers,dp,0);
    }
};

