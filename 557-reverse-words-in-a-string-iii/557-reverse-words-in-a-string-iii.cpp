class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        string tmp="";
        for(auto ch:s){
            if(ch==' '){
                reverse(tmp.begin(),tmp.end());
                ans+=tmp+' ';
                tmp="";
            }else{
                tmp+=ch;
            }
        }
        reverse(tmp.begin(),tmp.end());
        ans+=tmp;
        return ans;
    }
};