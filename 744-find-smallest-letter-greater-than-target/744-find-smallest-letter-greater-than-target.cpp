class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        vector<int> present(126,0);
        for(auto ch:letters){
            present[ch]=1;
        }
        int tmp = target+1;
        if(tmp==123)tmp=97;
        while(tmp<=122){
            if(present[tmp]==1){
                return tmp;
            }
            tmp++;
            if(tmp>122)tmp=97;
        }
        return 0;
    }
};