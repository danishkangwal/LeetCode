class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> memo(nums.size(),-1);
        return jumpGameTwo(nums,memo,0);
    }
private:
    int jumpGameTwo(vector<int>& a,vector<int>& memo,int level){
        if(level>=a.size()-1)
            return 0;
        if(memo[level]!=-1)
            return memo[level];
        int ans = a.size()-1;
        for(int i = 1;i <= a[level];i++){
            ans = min(ans,1+jumpGameTwo(a,memo,level+i));
        }
        return memo[level]=ans;
    }
};