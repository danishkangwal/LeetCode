class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int length=nums.size(),idx=0;
        while(idx<length){
            if(nums[idx]==val){
                nums[idx]=nums[length-1];
                length--;
            }
            else{
                idx++;
            }
        }
        return length;
    }
};