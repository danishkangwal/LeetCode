class Solution {
public:
    int arrangeCoins(int n) {
        long i = 1,temp = 0;
        while(n>temp){
            temp+=i;
            i++;
        }
        return temp==n?i-1:i-2;
    }
};