class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> m;
        for(auto i:tasks){
            m[i]++;
        }
        int rounds = 0;
        for(auto it=m.begin();it != m.end();it++){
            int value = it->second;
            if(value == 1)
                return -1;
            if(value%3 == 0){
                rounds += value/3;
            }
            else if(value%3 == 1){
                rounds += (value-2)/3;
                rounds += 2;
            }
            else{
                rounds += value/3;
                rounds += 1;
            }
        }
        return rounds;
    }
};