class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int max = *max_element(costs.begin(),costs.end());
        vector<int> countMap(max+1);
        for(auto& i:costs)
            countMap[i]++;
        int count = 0;
        for(int cost = 1;cost <= max; cost++){
            if(countMap[cost] == 0)
                continue;
            if(cost > coins)
                break;
            int no = min(countMap[cost],coins/cost);
            coins -= no*cost;
            count += no;
        }
        return count;
    }
};