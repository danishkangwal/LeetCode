class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        for(int i = 1;i <= s.size()/2;i++){
            string t = s.substr(0,i);
            int times = s.size()/t.size();
            string st = "";
            while(times--)
                st += t;
            if(st == s)
                return 1;
        }
        
        return 0;
    }
};