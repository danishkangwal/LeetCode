class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> mp;
        queue<char> q;
        for(auto i:s){
            mp[i]++;
            q.push(i);
        }
        int idx = 0;
        while(q.size()){
            auto ch = q.front();
            q.pop();
            if(mp[ch]==1)
                return idx;
            idx++;
        }
        return -1;
    }
};