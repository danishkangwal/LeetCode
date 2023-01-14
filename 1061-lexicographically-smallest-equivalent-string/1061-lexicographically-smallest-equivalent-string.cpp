class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        char ch[26];
        for (int i=0; i < 26; i++)
            ch[i] = 'a' + i;

        for (int i = 0;i < s1.size();i++) {
            char toReplace = max(ch[s1[i]-'a'], ch[s2[i]-'a']);
            char replaceWith = min(ch[s1[i]-'a'], ch[s2[i]-'a']);
            for (int i=0; i<26; i++)
                if (ch[i] == toReplace)
                    ch[i] = replaceWith;
        }
        
        string ans = baseStr;
        for (int i = 0; i < ans.size(); i++)
            ans[i] = ch[ans[i]-'a'];

        return ans;
    }
};