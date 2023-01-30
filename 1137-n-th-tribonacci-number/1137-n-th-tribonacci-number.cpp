class Solution {
public:
    int tribonacci(int n) {
        if(n==0)
            return 0;
        int n0 = 0;
        int n1 = 1;
        int n2 = 1;
        for(int i = 0;i < n-2;i++){
            int sum = n0+n1+n2;
            n0 = n1;
            n1 = n2;
            n2 = sum;
        }
        return n2;
    }
};