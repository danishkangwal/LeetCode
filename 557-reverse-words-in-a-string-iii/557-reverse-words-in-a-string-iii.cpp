class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string tmp="";
        for(auto ch:s){
            if(ch==' '){
                v.push_back(tmp);
                tmp="";
            }else{
                tmp+=ch;
            }
        }
        v.push_back(tmp);
        for(auto &x:v){
            reverse(x.begin(),x.end());
        }
        s="";
        for(int i=0;i<v.size()-1;i++){
            s+=v[i];
            s+=" ";
        }
        s+=v.back();
        return s;
    }
};