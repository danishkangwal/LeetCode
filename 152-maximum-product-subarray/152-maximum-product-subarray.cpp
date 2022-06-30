class Solution {
public:
    int maxProduct(vector<int>& nums) {
                int maxcurrent = nums[0];
        int maxglobal = nums[0];
        int mincurrent = nums[0];
        int minglobal = nums[0];
        int maxcurrent_n;
        int mincurrent_n;
        for(int i=1; i<nums.size(); i++){
            maxcurrent_n = max(nums[i],max(maxcurrent*nums[i],mincurrent*nums[i]));
            mincurrent_n = min(nums[i], min(mincurrent*nums[i],maxcurrent*nums[i]));
            maxglobal = max(maxglobal,maxcurrent_n);
            maxcurrent = maxcurrent_n;
            mincurrent = mincurrent_n;
            
        }
        return maxglobal;
        
    }
};