class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        vector<vector<string>> ans;
        for(auto i:strs){
            string tmp(i);
            sort(tmp.begin(),tmp.end());
            m[tmp].push_back(i);
        }
        for(auto it=m.begin();it!=m.end();it++){
            ans.push_back(it->second);
        }
        return ans;
    }
};