class Solution {
public:
    int climbStairs(int n) {
        int prev = 1;
        int prev2 = 0;
        for(int i = 2 ; i <= n + 1 ; i++){
            int curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }
        return prev; 
    }
};