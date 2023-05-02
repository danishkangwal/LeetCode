class Solution {
public:
    int arraySign(vector<int>& nums) {
        int cnt = 0;
        bool zeroPresent = 0;
        for(auto&i:nums){
            if(i==0){
                zeroPresent = 1;
                break;
            }
            if(i < 0)
                cnt++;
        }
        if(zeroPresent)
            return 0;
        return cnt%2==0?1:-1;
    }
};