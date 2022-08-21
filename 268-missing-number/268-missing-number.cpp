class Solution {
public:
    int missingNumber(vector<int>& nums) {
        bitset<10000> s;
        for(auto &i:nums){
            s.set(i);
        }
        for(int i = 0;i<=nums.size();i++){
            if(s.test(i)==0)
                return i;
        }
        return 0;
    }
};