class Solution {
    int rec(vector<int>&arr,int level,int mul,vector<vector<int>>& memo){
        if(level>=arr.size())
            return 0;
        if(memo[level][mul]!=-1)
            return memo[level][mul];
        int ans = 0;
        ans = arr[level]*mul + rec(arr,level+1,mul+1,memo);
        ans = max(ans, rec(arr,level+1,mul,memo));
        return memo[level][mul] = ans;
    }
public:
    int maxSatisfaction(vector<int>& arr) {
        vector<vector<int>> memo(arr.size(),vector<int>(510,-1));
        sort(begin(arr),end(arr));
        return rec(arr,0,1,memo);
    }
};