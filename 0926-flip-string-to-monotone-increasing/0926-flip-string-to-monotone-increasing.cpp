class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int m = 0;
        for(auto ch:s){
            if(ch == '0'){
                ++m;
            }
        }
        int ans = m;
        for(auto ch:s){
            if(ch == '0')
                ans = min(ans,--m);
            else
                m++;
        }
        return ans;
    }
};