class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(begin(potions),end(potions));
        int m = potions.size();
        vector<int> res;
        for(auto& i:spells){
            long long minRequired = ceil((1.0*success)/i);
            if(minRequired > potions[m-1]){
                res.push_back(0);
            }else{
                int idx = lower_bound(potions.begin(),potions.end(),minRequired)-potions.begin();
                res.push_back(m-idx);
            }
        }
        return res;
    }
};