class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> memo(nums.size(),-1);
        return helper(nums,0,memo);
    }
private:
    bool helper(vector<int>& a,int level,vector<int>& memo){
        int n = a.size();
        if(level == n-1){
            return true;
        }
        if(level >= n){
            return false;
        }
        if(memo[level]!=-1)
            return memo[level];

        bool ans = false;
        for(int i = 1;i <= a[level];i++){
            if(helper(a,level+i,memo)){
                ans = true;
                break;
            }
        }
        return memo[level]=ans;
    }
};