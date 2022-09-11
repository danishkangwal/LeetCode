class Solution:
    def myPow(self, x: float, n: int) -> float:
        if(n<0):
            return self.myPow(1/x,-n)
        res=1
        while(n):
            if n%2 != 0:
                if n>0:
                    res = res*x
                else:
                    res = res/x
            x = x*x
            n = n//2
        return res