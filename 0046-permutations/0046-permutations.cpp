class Solution {
    void helper(vector<int>& nums,vector<vector<int>>& ans,vector<int>& ds,int freq[]){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i = 0;i < nums.size();i++){
            if(!freq[i]){
                freq[i] = 1;
                ds.push_back(nums[i]);
                helper(nums,ans,ds,freq);
                ds.pop_back();
                freq[i] = 0;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int freq[nums.size()];
        for(int i = 0;i < nums.size();i++)freq[i] = 0;
        helper(nums,ans,ds,freq);
        return ans;
    }
};