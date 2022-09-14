class Solution {
public:
    bool isPalindrome(string s) {
        string a="";
        for(char &ch:s){
            if('A'<=ch&&ch<='Z'){
                a+=tolower(ch);
            }
            else if('a'<=ch && ch<='z'){
                a+=ch;
            }
            else if('0'<=ch && ch<='9'){
                a+=ch;
            }
        }cout<<a;
        s = a;
        reverse(a.begin(),a.end());
        return a==s;
    }
};