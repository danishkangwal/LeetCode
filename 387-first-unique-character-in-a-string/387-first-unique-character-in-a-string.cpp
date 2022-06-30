class Solution {
public:
    int firstUniqChar(string s) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);
        int arr[26] = {0};
        for (auto &ch : s) {
            arr[ch-'a']++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (arr[s[i]-'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};