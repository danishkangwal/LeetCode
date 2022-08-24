class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<1)
            return false;
        int x = log10(n)/log10(3);
        if(n== pow(3,x))
            return true;
        return false;
    }
};