class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0)
            return {-1,-1};
        if(nums.size()==1){
            if(nums[0]==target)
                return {0,0};
            else
                return {-1,-1};
        }
        int n = nums.size();
        int lvalue = search(nums,target,0,n-1,0);
        int rvalue = search(nums,target,0,n-1,1);
        
        return {lvalue,rvalue};
    }
    int search(vector<int> &nums,int target,int low,int high,int toggle){
        int res = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target){
                res = mid;
                low = (toggle?mid+1:low);
                high = (toggle?high:mid-1);
            }
            else if(nums[mid]>target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return res;
    }
};