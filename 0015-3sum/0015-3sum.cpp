class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.empty())
            return ans;
        sort(nums.begin(),nums.end());
        if(nums[0]>0)
            return ans;
        for(int i = 0;i < nums.size();i++){
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int j = i+1,k = nums.size()-1;
            while(j < k){
                if(i!=j && j!=k && i!=k){
                    int sum = nums[i]+nums[j]+nums[k];
                    if(sum == 0){
                        ans.push_back({nums[i],nums[j],nums[k]});
                        j++;
                        k--;
                        while(j < k && nums[j]==nums[j-1])
                            j++;
                        while(j < k && nums[k]==nums[k+1])
                            k--;
                    }
                    else if(sum > 0)
                        k--;
                    else
                        j++;
                }
            }
        }
        return ans;
    }
};