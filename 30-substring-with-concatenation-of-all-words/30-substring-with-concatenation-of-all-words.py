class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        lenword = len(words[0])
        lenwords = len(words)
        winsize = lenword*lenwords
        res=[]
        l,r=0,winsize-1
        while(r<len(s)):
            i=l
            copy = words.copy()
            while(i<l+winsize):
                sub=s[i:i+lenword]
                if sub in copy:
                    copy.remove(sub)
                    i+=lenword
                    sub=""
                    continue
                else:
                    break
            if i==l+winsize:
                res.append(l)
            l+=1
            r+=1
        return res