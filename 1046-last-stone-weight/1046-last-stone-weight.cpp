class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        while(stones.size()>1){
            sort(stones.begin(),stones.end(),greater<int>());
            int t = stones[0]-stones[1];
            stones[0] = t;
            vector<int>::iterator it;
            it = stones.begin()+1;
            stones.erase(it);
        }
        return stones[0];
    }
};