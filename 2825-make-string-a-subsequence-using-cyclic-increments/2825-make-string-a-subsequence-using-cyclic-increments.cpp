class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        if(str1.size() < str2.size())
            return 0;
        
        int idx = 0;
        for(int i = 0;i < str1.size() && idx<str2.size();i++){
            if(str1[i]==str2[idx] or ((str1[i]-'a')+1)%26==str2[idx]-'a')
                idx++;
        }
        return idx==str2.size();
    }
};
