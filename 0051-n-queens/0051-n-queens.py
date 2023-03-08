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
        
def printboard(board):
    n = len(board['row'].keys())
    ans = []
    for i in range(n):
        str = ""
        for j in range(n):
            if board['queen'][i]==j:
                str += 'Q'
            else:
                str += '.'
        ans.append(str)
    return ans
    
    
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
    
    
def placequeen(i,board,res):
    n = len(board['queen'].keys())
    for j in range(n):
        if canplace(i,j,board):
            addqueen(i,j,board)
            if i==n-1:
                res.append(printboard(board))
            else:
                extendsol = placequeen(i+1,board,res)
            undoqueen(i,j,board)
        
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        board = {}
        initialize(board,n)
        res = []
        placequeen(0,board,res)
        return res
        
        
        