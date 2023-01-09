class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 1;
        for(int i = 0;i < nums.size();i++){
            if(nums[idx-1]!=nums[i]){
                nums[idx] = nums[i];
                idx++;
            }
        }
        return idx;
    }
};