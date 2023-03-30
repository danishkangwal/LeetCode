class Solution {
    unordered_map<string,unordered_map<string,int>> mp;
    //use 1 for true and -1 for false
    bool solve(string s1,string s2){
        if(s1==s2)
            return 1;
        if(s1.size()<=1)
            return 0;
        if(mp[s1][s2]!=0)
            return mp[s1][s2]==1;
        bool check = 0;
        for(int i = 1;i < s1.size();i++){
            //swap
            if(isScramble(s1.substr(0,i), s2.substr(s2.size()-i))
              and isScramble(s1.substr(i),s2.substr(0,s2.size()-i))){
                check = 1;
                break;
            }

            //no swap
            if(isScramble(s1.substr(0,i),s2.substr(0,i)) and
              isScramble(s1.substr(i),s2.substr(i))){
                check = 1;
                break;
            }
        }
        mp[s1][s2] = (check?1:-1);
        return check;
    }
public:
    bool isScramble(string s1, string s2) {
        return solve(s1,s2);
    }
};