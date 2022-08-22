class Solution {
public:
    bool isPowerOfFour(int n) {
        long long x = 1;
        while(x<=n){
            if(x==n)
                return true;
            x*=4;
        }
        return false;
    }
};