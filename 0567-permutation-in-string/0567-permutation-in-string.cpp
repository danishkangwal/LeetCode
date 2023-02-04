class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size())
            return false;
        vector<int> freq(26,0);
        for(int i = 0;i < s1.size();i++){
            freq[s1[i]-'a']++;
        }
        
        vector<int> curr(26,0);
        for(int i = 0;i < s1.size();i++){
            curr[s2[i]-'a']++;
        }
    
        int right = s1.size();
        for(int i = 1;right < s2.size();i++){
            bool tmp = true;
            for(int i = 0;i < 26;i++){
                if(freq[i]!=curr[i]){
                    tmp = false;
                    break;
                }
            }
            if(tmp==true)
                return true;
            curr[s2[i-1]-'a']--;
            curr[s2[right]-'a']++;
            right++;
        }
        for(int i = 0;i < 26;i++){
            if(freq[i]!=curr[i])
                return false;
        }
        return true;
    }
};