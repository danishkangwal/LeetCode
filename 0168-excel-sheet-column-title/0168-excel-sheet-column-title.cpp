class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        char c = 'A';
        while(n){
            n--;
            res += (c+(n%26));
            n /= 26;
        }
        
        reverse(res.begin(),res.end());
        
        return res;
    }
};