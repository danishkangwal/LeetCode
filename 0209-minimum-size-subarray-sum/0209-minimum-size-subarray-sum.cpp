class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int res = INT_MAX;
        int i = 0,j = 0,sum = 0;
        for(j = 0;j < n;j++){
            sum += nums[j];
            while(sum >= target){
                res = min(res,j-i+1);
                sum -= nums[i++];
            }
        }
        
        return res==INT_MAX?0:res;
    }
};