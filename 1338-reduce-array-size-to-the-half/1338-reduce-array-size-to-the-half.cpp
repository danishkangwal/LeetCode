class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> m;
        multiset<int,greater<int>> s;
        for(auto &i:arr)
            m[i]++;
        for(auto &i:m)
            s.insert(i.second);
        int ans = 0,count = 0;
        for(auto it = s.begin();count<arr.size()/2;it++){
            ans++;
            count += *it;
        }
        return ans;
    }
};