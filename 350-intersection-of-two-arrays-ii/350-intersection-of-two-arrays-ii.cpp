class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        vector<int> a(nums1.size(),0);
        vector<int> b(nums2.size(),0);
        for(int i = 0;i<nums1.size();i++){
            for(int j = 0;j<nums2.size();j++){
                if(nums1[i]==nums2[j] && a[i] == 0 && b[j] == 0){
                    ans.push_back(nums1[i]);
                    a[i] = 1;
                    b[j] = 1;
                }
            }
        }
        return ans;
    }
};