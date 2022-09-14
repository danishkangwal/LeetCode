class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> a = digits;
        int n=a.size();
        if(a[n-1]!=9){
            a[n-1]++;
            return a;
        }
        a[n-1]=0;
        int carry = 1;
        for(int i=n-2;i>=0;i--){
            if(a[i]+carry>9){
                a[i]+=carry-10;
            }else{
                a[i]+=carry;
                carry = 0;
                break;
            }
        }
        if(carry)
            a.insert(a.begin(),carry);
        return a;
    }
};