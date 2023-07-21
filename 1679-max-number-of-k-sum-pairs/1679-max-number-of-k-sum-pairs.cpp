class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto i:nums)
            mp[i]++;
        
        int res = 0;
        for(auto i:nums){
            if(mp[i]==0)
                continue;
            if(k-i==i){
                if(mp[i]>1){
                    mp[i]-=2;
                    res++;
                }
            }
            else{
                if(mp[k-i]>0){
                    mp[i]--;
                    mp[k-i]--;
                    res++;
                }
            }
        }
        return res;
    }
};