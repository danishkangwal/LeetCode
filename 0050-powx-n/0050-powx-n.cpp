class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long long N = n;
        if(N < 0)
            N = -1*N;
        while(N){
            if(N%2){
                ans = ans*x;
                N--;
            }
            else{
                x *= x;
                N /= 2;
            }
        }
        if(n < 0)
            return 1.0 / ans;
        return ans;
    }
};