class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(),m = board[0].size();
	
        vector<vector<bool>> visited(n,vector<bool>(m,0));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if(board[i][j]!=word[0])
                    continue;
                visited[i][j] = 1;
                if(wordSearch(board,word.substr(1),visited,i,j))
                    return 1;
                visited.clear();
                visited.resize(n,vector<bool>(m,0));
            }
        }
        return 0;
    }
private:
    bool wordSearch(vector<vector<char>>& board,string word,vector<vector<bool>>& visited,int r,int c){
        if(word.size()==0)
            return 1;
        int n = board.size(),m = board[0].size();
        if(r<0 || r>n || c<0 || c>m)
            return word.size()==0;

        if(r>0 and board[r-1][c]==word[0] and visited[r-1][c]==0){
            visited[r-1][c] = 1;
            if(wordSearch(board,word.substr(1),visited,r-1,c))
                return 1;
            visited[r-1][c] = 0;
        }
        if(c>0 and board[r][c-1]==word[0] and visited[r][c-1]==0){
            visited[r][c-1] = 1;
            if(wordSearch(board,word.substr(1),visited,r,c-1))
                return 1;
            visited[r][c-1] = 0;
        }
        if(r<n-1 and board[r+1][c]==word[0] and visited[r+1][c]==0){
            visited[r+1][c] = 1;
            if(wordSearch(board,word.substr(1),visited,r+1,c))
                return 1;
            visited[r+1][c] = 0;
        }
        if(c<m-1 and board[r][c+1]==word[0] and visited[r][c+1]==0){
            visited[r][c+1] = 1;
            if(wordSearch(board,word.substr(1),visited,r,c+1))
                return 1;
            visited[r][c+1] = 0;
        }



        return 0;
    }
};