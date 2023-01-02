class Solution {
public:
    bool detectCapitalUse(string word) {
        bool allCap = true,allSmall = true,allSmall1 = true;
        for(int i = 0;i < word.size();i++){
            if(!isupper(word[i])){
                allCap = false;
            }else{
                if(i > 0){
                    allSmall1 = false;
                }
                allSmall = false;
            }
        }
        if(allCap || allSmall){
            return true;
        }
        if(isupper(word[0]) && allSmall1)
            return true;
        else
            return false;
    }
};