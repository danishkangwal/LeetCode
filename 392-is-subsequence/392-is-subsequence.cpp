class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i,j=0;
        for(i=0;i<t.size();i++)
        {
            if(t[i]==s[j])
                j=j+1;
            
        }
        return j==s.size();
    }
};