class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<pair<int,int>> sortedSpells;
        int idx = 0;
        for(auto i:spells){
            sortedSpells.push_back({i,idx});
            idx++;
        }
        sort(sortedSpells.begin(),sortedSpells.end());
        sort(potions.begin(),potions.end());
        vector<int> res(spells.size());
        int m = potions.size();
        int potionIdx = m-1;
        for(const auto&[val,idx]:sortedSpells){
            while(potionIdx>=0 and 1LL*val*potions[potionIdx]>=success)
                potionIdx--;
            res[idx] = m-(potionIdx+1);
        }
        return res;
    }
};