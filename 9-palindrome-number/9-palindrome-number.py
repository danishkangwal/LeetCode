class Solution:
    def isPalindrome(self, x: int) -> bool:
        s = str(x)
        def reverse(s: str) -> str:
            if len(s)==0:
                return ""
            return reverse(s[1:]) + s[0]
            
        s2 = reverse(s)
        if s==s2:
            return True
        return False