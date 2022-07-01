class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();

        vector<int> char_count(26,0);
        int start = 0, ans = 0,max_rep_count = 0;
        
        for(int end = 0; end < n ; end++){
            char_count[s[end] - 'A']++;
            max_rep_count = max(max_rep_count,char_count[s[end]-'A']);
            while( end - start + 1 - max_rep_count > k){
                char_count[s[start]-'A']--;
                start++;
            }
            ans = max(ans , end - start + 1);
        }
        return ans;
    }
};