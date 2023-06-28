class Solution {
public:
    string reverseWords(string str) {
        string s = "";
        string tmp = "";
        for(int i = 0;i < str.size();i++){
            if(str[i]==' '){
                if(tmp != ""){
                    if(s != "")
                        s = tmp + " " + s;
                    else
                        s = tmp;
                }
                tmp = "";
            }
            else
                tmp += str[i];
        }
        if(tmp != ""){
            if(s != "")
                s = tmp + " " +s;
            else
                s = tmp;
        }
        return s;
    }
};