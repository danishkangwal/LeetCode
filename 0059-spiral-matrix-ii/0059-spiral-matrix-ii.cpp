class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n,vector<int>(n,0));
        int num = 0;
        int left = 0,right = n-1;
        int up = 0,down = n-1;
        while(up<=down and left<=right){
            for(int i = left;i <= right && left<=right;i++){
                mat[up][i] = ++num;
            }
            up++;
            for(int i = up;i <= down && up<=down;i++){
                mat[i][right] = ++num;
            }
            right--;
            for(int i = right;i >= left && left<=right;--i){
                mat[down][i] = ++num;
            }
            down--;
            for(int i = down;i >= up && up <=down;i--){
                mat[i][left] = ++num;
            }
            left++;
            
        }
        return mat;
    }
};