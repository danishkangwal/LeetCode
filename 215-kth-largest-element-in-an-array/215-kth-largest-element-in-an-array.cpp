class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        return quickSelect(nums,0,nums.size()-1,k);
    }
    int quickSelect(vector<int> &nums,int l,int r,int k){
        int pivot = nums[r];
        int p = l;
        for(int i = l;i < r;i++){
            if(nums[i]<= pivot){
                int t = nums[p];
                nums[p] = nums[i];
                nums[i] = t;
                p++;
            }
        }
        int t = nums[p];
        nums[p] = nums[r];
        nums[r] = t;
        if(p > k) return quickSelect(nums,l,p-1,k);
        if(p < k) return quickSelect(nums,p+1,r,k);
        return nums[p];
    }
};