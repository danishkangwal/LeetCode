class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        int n = str.size();
        if(n==0){
            return "";
        }
        
        string ans  = "";
        sort(begin(str), end(str));
        string a = str[0];
        string b = str[n-1];
        
        for(int i=0; i<a.size(); i++){
            if(a[i]!=b[i]){
                break;
            } 
            ans = ans + a[i];
        }
        
        return ans;
    }
};