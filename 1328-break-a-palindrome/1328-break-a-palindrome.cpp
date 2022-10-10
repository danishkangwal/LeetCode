class Solution {
public:
    string breakPalindrome(string s) {
        if(s.size()==1)
            return "";
        int i=0;
        while(i<s.size() && s[i]=='a'){
            i++;
        }
        if(i==s.size()){
            s[s.size()-1]='b';
            return s;
        }
        else if(i==s.size()/2){
            s[s.size()-1]='b';
            return s;
        }
        s[i] = 'a';
        return s;
    }
};