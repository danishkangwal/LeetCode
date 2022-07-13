class Solution {
public:
    bool isHappy(int n) {
        set<int> visited;
        while(visited.find(n)==visited.end()){
            visited.insert(n);
            n = sumOfSquares(n);
            
            if(n==1)
                return true;
        }
        return false;
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