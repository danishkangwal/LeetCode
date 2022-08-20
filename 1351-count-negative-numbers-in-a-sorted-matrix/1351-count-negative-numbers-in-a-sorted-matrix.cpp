class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        for(auto &i:grid){
            int tmp = binarySearch(i);
            if(tmp!=-1)
                ans += (i.size() - tmp);
        }
        return ans;
    }
    int binarySearch(vector<int> &arr){
        int start = 0,end = arr.size()-1;
        int res = -1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(arr[mid]<0){
                res = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return res;
    }
};