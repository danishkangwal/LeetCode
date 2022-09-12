class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size(),k=0;
        for(int i=0;i<n-k;i++){
            if(nums[i]==val){
                nums.erase(nums.begin()+i);
                k++;
                i--;
            }
            
        }
        return n-k;
    }
};