class Solution {
public:
    int compress(vector<char>& chars) {
        
        if(chars.size()==1)
            return 1;
        string s = "";
        for(auto&ch:chars)
            s += ch;
        
        string res = "";
        int i = 0,j = 0;
        while(j < s.size()){
            int cnt = 1;j++;
            while(j < s.size() and s[j]==s[i]){
                cnt++;
                j++;
            }
            if(cnt == 1){
                res += s[i];
            }
            else{
                res += s[i];
                res += to_string(cnt);
            }
            i = j;
        }
        for(int i = 0;i < res.size();i++){
            chars[i] = res[i];
        }
        return res.size();
    }
};