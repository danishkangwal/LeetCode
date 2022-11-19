class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []
        def helper(open,closed,n,curr):
            if(open==closed and open==n):
                ans.append(curr)
                return
            if(open<n):
                helper(open+1,closed,n,curr+"(")
            if(closed<open):
                helper(open,closed+1,n,curr+")")
        helper(0,0,n,"")
        return ans