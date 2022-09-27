class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> a(m+n);
        int idx1=0,idx2=0,idx=0;
        while(idx1<m&&idx2<n){
            if(nums1[idx1]<nums2[idx2]){
                a[idx++]=nums1[idx1++];
            }else{
                a[idx++]=nums2[idx2++];
            }
        }
        while(idx1<m)
            a[idx++]=nums1[idx1++];
        while(idx2<n)
            a[idx++]=nums2[idx2++];
        nums1=a;
    }
};