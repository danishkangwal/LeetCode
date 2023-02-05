class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size())
            return false;
        int s1Map[26] = {0};
        int s2Map[26] = {0};
        
        for(int i = 0;i < s1.size();i++){
            s1Map[s1[i]-'a']++;
            s2Map[s2[i]-'a']++;
        }
        
        int count = 0;
        for(int i = 0;i < 26;i++){
            if(s1Map[i]==s2Map[i])
                count++;
        }
        
        for(int i = 0;i < s2.size()-s1.size();i++){
            if(count == 26)
                return true;
            int l = s2[i]-'a';
            int r = s2[i+s1.size()]-'a';
            
            s2Map[r]++;
            if(s2Map[r]==s1Map[r])
                count++;
            else if(s2Map[r] == s1Map[r]+1)
                count--;
            
            s2Map[l]--;
            if(s2Map[l]==s1Map[l])
                count++;
            else if(s2Map[l]==s1Map[l]-1)
                count--;
            
        }
        return count==26;
    }
};