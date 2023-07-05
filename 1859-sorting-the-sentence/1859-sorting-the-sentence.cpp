class Solution {
public:
    string sortSentence(string s) {
        vector<string> vs(900);
        
        string tmp = "";
        for(auto i:s){
            if(i==' '){
                vs[tmp.back()-'0'] = tmp.substr(0,tmp.size()-1);
                tmp = "";
            }
            else{
                tmp += i;
            }
        }
        vs[tmp.back()-'0'] = tmp.substr(0,tmp.size()-1);
        string res = "";
        for(int i = 1;i <= 9;i++){
            if(vs[i]=="")
                break;
            res += vs[i]+" ";
        }
        res = res.substr(0,res.size()-1);
        return res;
    }
};