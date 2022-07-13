class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = sumOfSquares(n);
        
        while(fast!=1 && slow != fast){
            slow = sumOfSquares(slow);
            fast = sumOfSquares(sumOfSquares(fast));
        }
        return fast==1;
    }
    int sumOfSquares(int n){
        int ans = 0;
        while(n){
            int digit = n%10;
            digit *= digit;
            ans += digit;
            n /= 10;
        }
        return ans;
    }
};