class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string> count[26];
        for (auto& i : ideas)
            count[i[0] - 'a'].insert(i.substr(1));
        long long ans = 0;
        for (int i = 0; i < 26; ++i)
            for (int j = i + 1; j < 26; ++j) {
                long long ch1 = 0L, ch2 = 0L;
                for (auto& c : count[i])
                    if (!count[j].count(c)) ch1++;
                for (auto& c : count[j])
                    if (!count[i].count(c)) ch2++;
                ans += ch1 * ch2;
            }
        return ans * 2;
    }
};