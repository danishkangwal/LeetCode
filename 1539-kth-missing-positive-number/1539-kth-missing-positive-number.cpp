class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int left = 0,right = n-1;
        while(left<=right){
            int mid = left +(right-left)/2;
            int missing = arr[mid]-(mid+1);
            if(missing>=k)
                right = mid-1;
            else
                left = mid+1;
        }
        
        if(right==-1)
            return k;
        return arr[right] + k - (arr[right]-(right+1));
    }
};