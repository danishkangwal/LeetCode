class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
       unordered_map<int, int> hash_map;
        for(int i=0; i<nums.size(); i++){
            hash_map[nums[i]]++;
            if(hash_map[nums[i]]>1){
                return true;
            }
        }
        return false;
    }
};