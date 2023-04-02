class Solution {
    vector<vector<int>> table;
    vector<vector<vector<int>>> memo;
    const int md = 1e9+7;
    int solve(int i,int j,int k,int m,int n){
        if(table[i][j]<k)
            return 0;
        if(k==1){
            return ((table[i][j]>=1)?1:0);
        }
        if(memo[i][j][k]!=-1)
            return memo[i][j][k];

        memo[i][j][k] = 0;
        for(int h = i+1;h < m;h++){
            if(table[i][j]-table[h][j]>0 and table[h][j]>=k-1){
                memo[i][j][k] = (memo[i][j][k] + solve(h,j,k-1,m,n))%md; 

            }
        }
        for(int v = j+1;v<n;v++){
            if(table[i][j]-table[i][v]>0 and table[i][v]>=k-1){
                memo[i][j][k] = (memo[i][j][k] + solve(i,v,k-1,m,n))%md;
            }
        }

        return memo[i][j][k];
    }
public:
    int ways(vector<string>& pizza,int k){
        int m = pizza.size(),n = pizza[0].size();
        table.resize(m,vector<int>(n,0));
        table[m-1][n-1] = (pizza[m-1][n-1]=='A'?1:0);
        for(int i = m-2;i>=0;i--){
            table[i][n-1] = table[i+1][n-1] + ((pizza[i][n-1]=='A')?1:0);
        }
        for(int i = n-2;i>=0;i--){
            table[m-1][i] = table[m-1][i+1] + ((pizza[m-1][i]=='A')?1:0);
        }
        for(int i = m-2;i>=0;i--){
            for(int j = n-2;j>=0;j--){
                table[i][j] = table[i+1][j]+table[i][j+1]-table[i+1][j+1];
                if(pizza[i][j]=='A')
                    table[i][j]++;
            }
        }
        memo.resize(m,vector<vector<int>>(n,vector<int>(k+1,-1)));

        return solve(0,0,k,m,n);
    }
};