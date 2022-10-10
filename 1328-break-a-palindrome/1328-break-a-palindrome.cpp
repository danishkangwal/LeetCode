class Solution {
public:
    string breakPalindrome(string s) {
        if(s.size()==1)
            return "";
        int i=0;
        while(i < s.size()/2){
            if(s[i]!='a'){
                s[i] = 'a';
                return s;
            }
            i++;
        }
        s[s.size()-1] = 'b';
        return s;
    }
};