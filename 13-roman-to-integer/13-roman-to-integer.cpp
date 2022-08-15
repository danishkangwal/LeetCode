class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        map<char,int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        for(int i = 0;i < s.size();i++){
            string tmp = "";
            tmp+=s[i];
            tmp+=s[i+1];
            if(tmp=="IV"){
                ans+=4;i++;
            }
            else if(tmp=="IX"){
                ans+=9;i++;
            }
            else if(tmp=="XL"){
                ans+=40;i++;
            }
            else if(tmp=="XC"){
                ans+=90;i++;
            }
            else if(tmp=="CD"){
                ans+=400;i++;
            }
            else if(tmp=="CM"){
                ans+=900;i++;
            }
            else{
                ans+=m[s[i]];
            }
        }
        
        return ans;
    }
};