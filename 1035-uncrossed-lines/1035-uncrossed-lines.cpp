class Solution {
    int solve(vector<int>&num1,vector<int>&num2,int i,int j,vector<vector<int>>& memo){
        if(i <= 0 or j<=0){
            return 0;
        }
        if(memo[i][j]!=-1)
            return memo[i][j];
        if(num1[i-1]==num2[j-1])
            memo[i][j] = 1 + solve(num1,num2,i-1,j-1,memo);
        else
            memo[i][j] = max(solve(num1,num2,i,j-1,memo) , 
                            solve(num1,num2,i-1,j,memo));
        return memo[i][j];
    }
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int i = nums1.size();
        int j = nums2.size();
        
        vector<vector<int>> memo(i+1,vector<int>(j+1,-1));
        return solve(nums1,nums2,i,j,memo);
    }
};