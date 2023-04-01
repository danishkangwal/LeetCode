class Solution {
public:
    int search(vector<int>& nums, int target) {
        int idx = -1;
        int left = 0,right = nums.size()-1;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(nums[mid]==target){
                idx = mid;
                break;
            }else if(nums[mid]>target){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return idx;
    }
};