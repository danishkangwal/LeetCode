class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int temp = 0;
        while(temp < nums.size()&&nums[temp]<0)
            temp++;
        if(temp == 0){
            vector<int> squares(nums.size());
            for(int i = 0;i < nums.size();i++){
                squares[i] = nums[i]*nums[i];
            }
            return squares;
        }
        if(temp == nums.size()){
            vector<int> squares(nums.size());
            for(int i = nums.size()-1;i>=0;i--){
                squares[nums.size()-1-i] = nums[i]*nums[i];
            }
            return squares;
        }
        vector<int> squares(nums.size());
        int left = temp - 1,idx=0;
        while(left>=0 && temp<nums.size()){
            int leftSq = nums[left]*nums[left];
            int rightSq = nums[temp]*nums[temp];
            if(leftSq > rightSq){
                squares[idx++] = rightSq;
                temp++;
            }else{
                squares[idx++] = leftSq;
                left--;
                }
        }
        while(left >= 0){
            squares[idx++] = nums[left]*nums[left];
            left--;
        }
        while(temp <= nums.size()-1){
            squares[idx++] = nums[temp]*nums[temp];
            temp++;
        }
        return squares;
    }
};