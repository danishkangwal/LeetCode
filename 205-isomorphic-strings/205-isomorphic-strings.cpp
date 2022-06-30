class Solution {
public:
    bool isIsomorphic(string s, string t) {
    char mapStoT[128] = {0};
    char mapTtoS[128] = {0};
    for (int i = 0; i < s.size(); ++i)
    {
        if(mapStoT[s[i]]!=mapTtoS[t[i]])return false;
        mapStoT[s[i]]=i+1;
        mapTtoS[t[i]]=i+1;
    }
    return true;
    }
};