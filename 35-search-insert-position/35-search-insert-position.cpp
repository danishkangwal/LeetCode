class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0) return 0;
        if(nums[nums.size()-1]<target)return nums.size();
		
		int l = 0, r = nums.size() - 1;
		while(l < r){
			int m = l + (r - l)/2;
			
			if(nums[m] == target) return m;
			else if(nums[m] > target) r = m;
			else l = m + 1;
		}
		
		return l;
    }
};