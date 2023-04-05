class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        
        long long ans = 0, pref = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            pref += nums[i];
            ans = max(ans, (pref + i) / (i + 1));
        }
        
        return ans;
    }
};