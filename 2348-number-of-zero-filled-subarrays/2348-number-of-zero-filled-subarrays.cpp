class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0,count=0;
        int idx = 0;
        
        while(idx < nums.size()){
            if(nums[idx]==0){
                count++;
                long long temp = 1;
                idx++;
                while(idx < nums.size() and nums[idx]==0){
                    count++;
                    temp++;
                    idx++;
                }
                if(temp>1)
                    ans += 1LL*temp*(temp-1)/2;
                idx--;
            }
            idx++;
        }
        ans += count;
        return ans;
    }
};