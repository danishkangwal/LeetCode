class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long ans = nums[0];
        long long total = nums[0];
        for(int i = 1; i < nums.size();i++){
            total += nums[i];
            ans = max(ans, 1LL * (total+i)/(i+1));
        }
        return ans;
    }
};