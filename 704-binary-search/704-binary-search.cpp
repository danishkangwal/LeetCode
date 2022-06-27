class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums,0,nums.size()-1,target);
    }
    int binarySearch(vector<int> &nums,int begin,int end,int target){
        while(begin<=end){
            int mid = begin + (end - begin)/2;
            if(nums[mid]==target) return mid;
            else if(target < nums[mid]) end = mid-1;
            else begin = mid+1;
            
        }
        return -1;
    }
};