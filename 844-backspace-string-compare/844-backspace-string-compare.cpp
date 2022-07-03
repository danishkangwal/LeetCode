class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1="",t1="";
        for(int i = 0;i < s.size();i++){
            if(s[i]=='#'){
                (s1.size()<2)?s1="" : s1 = s1.substr(0,s1.size()-1);
                continue;
            }
            s1+=s[i];
        }
        for(int i = 0;i < t.size();i++){
            if(t[i]=='#'){
                (t1.size()<2)?t1="" : t1 = t1.substr(0,t1.size()-1);
                continue;
            }
            t1+=t[i];
        }
        return s1==t1;
    }
};