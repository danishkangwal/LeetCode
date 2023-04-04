class Solution {
public:
    int partitionString(string s) {
        int ans = 0;
        unordered_set<char> st;
        int i = 0;
        while(i < s.size()){
            if(st.count(s[i])){
                ans++;
                st.clear();
            }
            st.insert(s[i]);
            i++;
        }
        ans += st.size()>0;
        return ans;
    }
};