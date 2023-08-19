class Solution {
    int lengthOfLIS(vector<int>& nums) {
        vector<int> t;
        for(auto i:nums){
            if(t.empty() or t.back() < i){
                t.push_back(i);
            }else{
                auto it = lower_bound(t.begin(),t.end(),i);
                *it = i;
            }
        }
        return t.size();
    }
public:
    int minimumOperations(vector<int>& nums) {
        vector<vector<int>> v(4);
        for(int i = 0;i < nums.size();i++)
            v[nums[i]].push_back(i);
        
        sort(v[1].begin(),v[1].end());
        sort(v[2].begin(),v[2].end());
        sort(v[3].begin(),v[3].end());
        
        v[1].insert(v[1].end(),v[2].begin(),v[2].end());
        v[1].insert(v[1].end(),v[3].begin(),v[3].end());
        return nums.size()-lengthOfLIS(v[1]);
    }
};