class Solution {
public:
    string convert(string s, int numRows) {
        
        vector<vector<char>> v(numRows,vector<char>(s.size(),'-'));
        int col = 0;
        while(s.size()>0){
            for(int i = 0;i < numRows;i++){
                if(s.size()==0)
                    break;
                v[i][col] = s[0];
                s = s.substr(1);
            }
            col++;
            for(int i = numRows-2;i >= 1;i--){
                if(s.size()==0)
                    break;
                v[i][col++] = s[0];
                s = s.substr(1);
            }
        }
        
        string ans = "";
        for(auto& row:v){
            for(auto& i:row)
                if(i != '-')
                    ans += i;
        }
        return ans;
    }
};