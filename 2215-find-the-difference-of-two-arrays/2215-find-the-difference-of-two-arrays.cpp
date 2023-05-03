class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1,s2;
        for(auto&i:nums1){
            s1.insert(i);
        }
        for(auto&i:nums2){
            s1.erase(i);
        }
        for(auto&i:nums2){
            s2.insert(i);
        }
        for(auto&i:nums1){
            s2.erase(i);
        }
        vector<int> v1(s1.begin(),s1.end());
        vector<int> v2(s2.begin(),s2.end());
        return {v1,v2};
        
    }
};