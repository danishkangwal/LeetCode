class Solution {
public:
    map<string,map<int,int>> board;
    int N;

    bool canplace(int i,int j){
        return (board["row"][i]==0 and board["col"][j]==0 and board["nwtose"][j-i]==0 and board["swtone"][j+i]==0);
    }

    void addqueen(int i,int j){
        board["queen"][i] = j;
        board["row"][i] = 1;
        board["col"][j] = 1;
        board["nwtose"][j-i] = 1;
        board["swtone"][j+i] = 1;
    }    

    void undoqueen(int i,int j){        
        board["queen"][i] = -1;
        board["row"][i] = 0;
        board["col"][j] = 0;
        board["nwtose"][j-i] = 0;
        board["swtone"][j+i] = 0;
    }

    void placequeen(int i,int& res){
        int n = N;
        for(int j = 0;j < n;j++){
            if(canplace(i,j)){
                addqueen(i,j);
                if (i==n-1){
                    res++;
                }
                else{
                    placequeen(i+1,res);
                }
                undoqueen(i,j);
            }
        }
    }
    
    int totalNQueens(int n) {
        int res = 0;
        N = n;
        for (int i = 0; i < n; ++i)
        {
            board["queen"][i] = -1;
            board["row"][i] = 0;
            board["col"][i] = 0;
        }
        for(int i = -(n-1);i < n;i++)
            board["nwtose"][i] = 0;
        for(int i = 0;i < 2*n-1;i++)
            board["swtone"][i] = 0;

        placequeen(0,res);
        return res;
    }
};