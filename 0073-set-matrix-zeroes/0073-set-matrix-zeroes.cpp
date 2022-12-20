class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> a;
        a = matrix;
        for(int r = 0;r < n;r++){
            for(int c = 0;c < m;c++){
                if(matrix[r][c] == 0){
                    helper(a,r,c);
                }
            }
        }
        matrix = a;
    }
private:
    void helper(vector<vector<int>>& matrix,int r, int c){
        for(int i = 0;i < matrix[0].size();i++)
            matrix[r][i] = 0;
        for(int i = 0;i < matrix.size();i++)
            matrix[i][c] = 0;
        
    }
};