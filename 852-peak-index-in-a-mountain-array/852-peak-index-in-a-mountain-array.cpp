class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 1,h = arr.size()-2;
        while(l<=h){
            int m = l + (h-l)/2;
            if(arr[m]>arr[m-1]&&arr[m]>arr[m+1])
                return m;
            else if(arr[m]<arr[m+1])
                l = m+1;
            else
                h = m-1;
        }
        return -1;
    }
};