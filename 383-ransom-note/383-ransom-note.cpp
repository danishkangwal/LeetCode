class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> m;
        for(auto ch:magazine){
            m[ch]++;
        }
        for(auto ch:ransomNote){
            if(m[ch])
                m[ch]--;
            else
                return false;
        }
        return true;
    }
};