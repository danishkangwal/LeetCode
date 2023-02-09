class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> subArray;
        for(const auto& num : nums){
            if(subArray.size()==0 || subArray[subArray.size()-1]<num)
                subArray.push_back(num);
            else{
                auto it = lower_bound(subArray.begin(),subArray.end(),num);
                *it = num;
            }
        }
        return subArray.size();
    }
};