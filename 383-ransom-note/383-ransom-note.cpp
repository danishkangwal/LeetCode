class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size()>magazine.size())
            return false;
        int freq[26];
        memset(freq,0,sizeof(freq));
        for(auto &ch:magazine){
            freq[ch-'a']++;   
        }
        for(auto &ch:ransomNote){
            if(freq[ch-'a']==0)
                return false;
            freq[ch-'a']--;
        }
        return true;
    }
};