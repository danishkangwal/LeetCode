class Solution {
public:
    int maxProfit(vector<int>& prices) {
        ios_base::sync_with_stdio(0);cin.tie(0);
        if(prices.size()<=1) return 0;
        int minVal = prices[0];
        int maxProfit = 0;
        for(int i = 1;i < prices.size();++i){
            if(prices[i]<minVal){
                minVal = prices[i];
                continue;
            }
            maxProfit = max(maxProfit, prices[i] - minVal);
        }
        return maxProfit;        
    }
};