class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int idx1 = 0,idx2 = 0;
        string ans = "";
        while(idx1 < word1.size() or idx2 < word2.size()){
            if(idx1 < word1.size())
                ans += word1[idx1++];
            if(idx2 < word2.size())
                ans += word2[idx2++];
        }
        
        return ans;
    }
};