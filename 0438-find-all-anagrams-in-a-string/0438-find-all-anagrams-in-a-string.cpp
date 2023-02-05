class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size())
            return {};
        
        vector<int> sMap(26,0);
        vector<int> pMap(26,0);
        
        for(int i = 0;i < p.size();i++){
            sMap[s[i]-'a']++;
            pMap[p[i]-'a']++;
        }
        
        int count = 0;
        for(int i = 0;i < 26;i++){
            if(sMap[i]==pMap[i])
                count++;
        }
        
        vector<int> ans;
        for(int i = 0;i <= s.size()-p.size();i++){
            if(count == 26){
                ans.push_back(i);
            }
            if(i==s.size()-p.size())
                break;
            int l = s[i]-'a';
            int r = s[i+p.size()]-'a';
            
            sMap[r]++;
            if(sMap[r]==pMap[r])
                count++;
            else if(sMap[r] == pMap[r]+1)
                count--;
            
            sMap[l]--;
            if(sMap[l]==pMap[l])
                count++;
            else if(sMap[l]==pMap[l]-1)
                count--;
            
        }
        return ans;
    }
};