class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int i=n-1;
        digits[i]++;
        while(i>=0){
            if(digits[i]!=10)
                return digits;
            digits[i]=0;
            if(i>0)
                digits[i-1]++;
            else
                digits.insert(digits.begin(),1);
            i--;
        }
        return digits;
    }
};