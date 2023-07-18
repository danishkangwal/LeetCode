class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> mp;
        for(auto i:nums)
            mp[i]++;
        
        vector<pair<int,int>> v;
        for(auto it:mp){
            v.push_back({it.second,it.first});
        }
        
        sort(v.begin(),v.end(),[](pair<int,int>&a,pair<int,int>&b){
            if(a.first==b.first)
                return a.second > b.second;
            return a.first < b.first;
        });
        
        vector<int> res;
        for(auto& i:v){
            while(i.first){
                res.push_back(i.second);
                i.first--;
            }
        }
        
        return res;
    }
};