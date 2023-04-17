class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = *max_element(candies.begin(),candies.end());
        vector<bool> res;
        for(auto&i :candies){
            if(i+extraCandies>=max)
                res.push_back(1);
            else
                res.push_back(0);
        }
        return res;
    }
};