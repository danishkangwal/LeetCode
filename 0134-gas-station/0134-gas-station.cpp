class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), start = 0;
        int gasTotal = 0,costTotal = 0;
        int currGas = 0;
        for(int i = 0;i < n;i++){
            gasTotal += gas[i];
            costTotal += cost[i];
            
            currGas += gas[i]-cost[i];
            
            if(currGas < 0){
                start = i+1;
                currGas = 0;
            }
        }
        return (gasTotal < costTotal ? -1: start);
    }
};