class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        for(int i = 0;i < mat.size();i++){
            sum += mat[i][i];
            if(mat.size()%2==0 or i!= mat.size()/2)
                sum += mat[i][mat[0].size()-1-i];
        }
        return sum;
    }
};