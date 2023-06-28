class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        vector<int> res;
        unordered_map<int,int> mp;
        for(auto i:arr)
            mp[i]++;

        for(auto it:mp){
            if(it.second > arr.size()/3)
                res.push_back(it.first);
        }
        return res;
    }
};