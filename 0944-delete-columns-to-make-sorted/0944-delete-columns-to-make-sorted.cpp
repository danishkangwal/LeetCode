class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        if(n == 1)
            return 0;
        int count = 0;
        for(int x = 0;x < strs[0].size();x++){
            char prev = ',';
            for(int i = 0;i < n;i++){
                if(prev == ','){
                    prev = strs[i][x];
                }
                else{
                    int tmp = strs[i][x] - prev;
                    if(tmp < 0){
                        count++;
                        break;
                    }
                    prev = strs[i][x];
                }
            }
        }
        return count;
    }
};