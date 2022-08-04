class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans;
        for(auto &i:nums)ans.push_back(i);
        for(auto &i:nums)ans.push_back(i);
        
        return ans;
    }
};