class Cmp {
    public:
    bool operator ()(pair<string, int>& a, pair<string, int>& b) {
        if(a.second == b.second) return a.first < b.first;
        return a.second > b.second;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        Cmp cmp;
        unordered_map<string, int> mp;
        vector<pair<string, int>> vec;
        
        for(string i : words) mp[i]++;
        for(auto it : mp) vec.push_back(it);
        
        sort(vec.begin(), vec.end(), cmp);
        
        vector<string> res;
        
        for(auto it : vec) {
            if(k == 0) break;
            
            res.push_back(it.first);
            k--;
        }
        
        return res;
    }    
};