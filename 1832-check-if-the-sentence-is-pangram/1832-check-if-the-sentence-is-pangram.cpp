class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> freq(26,0);
        for(auto &ch:sentence){
            freq[ch-'a'] = 1;
        }
        for(auto &i:freq)
            if(i!=1)
                return false;
        return true;
    }
};