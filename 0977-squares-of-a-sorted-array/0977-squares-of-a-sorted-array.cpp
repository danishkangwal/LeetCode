class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0,j = nums.size()-1,n = nums.size();
        vector<int> squares(n);
        int idx = n-1;
        while(i<=j){
            int left = nums[i]*nums[i];
            int right = nums[j]*nums[j];
            if(left > right){
                squares[idx--] = left;
                i++;
            }else{
                squares[idx--] = right;
                j--;
            }
        }
        return squares;
    }
};