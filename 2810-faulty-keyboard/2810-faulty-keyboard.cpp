class Solution {
public:
    string finalString(string s) {
        string res = "";
        for(auto i:s){
            if(i!='i')
                res += i;
            else
                reverse(res.begin(),res.end());
        }
        return res;
    }
};