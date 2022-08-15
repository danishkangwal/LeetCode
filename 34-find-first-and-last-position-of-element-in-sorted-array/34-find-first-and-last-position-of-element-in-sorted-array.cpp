class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()<2){
            if(nums.size()&&nums[0]==target){
                return {0,0};
            }
            return {-1,-1};
        }
        int n = nums.size();
        int lvalue = search(nums,0,n-1,target,0);
        int rvalue = search(nums,0,n-1,target,1);
    
        return {lvalue,rvalue};
    }
    int search(vector<int> &nums,int low,int high,int target,int toggle){
        int ans = -1;
        while(low<=high){
            int mid = low + ((high-low)>>1);
            if(nums[mid]==target){
                ans = mid;
                low = toggle?mid+1:low;
                high = toggle?high:mid-1;
            }
            else if(nums[mid]>target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};