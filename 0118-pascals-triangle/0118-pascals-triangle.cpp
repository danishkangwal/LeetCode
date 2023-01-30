class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int row = 1;row <= numRows;row++){
            vector<int> a;
            long long b = 1;
            for(int i = 0;i < row;i++){
                a.push_back(b);
                b *= (row-i-1);
                b /= (i+1);
            }
            ans.push_back(a);
        }
        return ans;
    }
};