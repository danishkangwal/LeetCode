class Solution {
public:
    int partitionString(string s) {
        int ans = 0;
        unordered_map<int,bool> mp;
        int i = 0;
        while(i < s.size()){
            if(mp[s[i]-'a']){
                ans++;
                mp.clear();
            }
            mp[s[i]-'a']=1;
            i++;
        }
        ans += mp.size()>0;
        return ans;
    }
};