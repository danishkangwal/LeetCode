def initialize(board,n):
    for key in ["queen","row","col","nwtose","swtone"]:
        board[key] = {}
    for i in range(n):
        board['queen'][i] = -1
        board['row'][i] = 0
        board['col'][i] = 0
    for i in range(-(n-1),n):
        board['nwtose'][i] = 0
    for i in range(2*n-1):
        board['swtone'][i] = 0
    
    
def canplace(i,j,board):
    return (board['row'][i]==0 and board['col'][j]==0 and board['nwtose'][j-i]==0 and board['swtone'][j+i]==0)

def addqueen(i,j,board):
    board['queen'][i] = j
    board['row'][i] = 1
    board['col'][j] = 1
    board['nwtose'][j-i] = 1
    board['swtone'][j+i] = 1

def undoqueen(i,j,board):        
    board['queen'][i] = -1
    board['row'][i] = 0
    board['col'][j] = 0
    board['nwtose'][j-i] = 0
    board['swtone'][j+i] = 0
    
    

        
class Solution:
    def totalNQueens(self, n: int) -> int:
        def placequeen(i,board):
            n = len(board['queen'].keys())
            for j in range(n):
                if canplace(i,j,board):
                    addqueen(i,j,board)
                    if i==n-1:
                        nonlocal res 
                        res += 1
                    else:
                        extendsol = placequeen(i+1,board)
                    undoqueen(i,j,board)
        
        board = {}
        initialize(board,n)
        res = 0
        placequeen(0,board)
        return res
        
        
        