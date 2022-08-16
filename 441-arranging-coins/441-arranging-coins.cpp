class Solution {
public:
    int arrangeCoins(int n) {
        int low = 1,high = n;
        int res = 1;
        while(low<=high){
            long long mid = low+(high-low)/2;
            if((mid+1)*mid/2<=n){
                res = mid;
                low = mid+1;
            }
            else if((mid+1)*mid/2>n){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return res;
    }
};