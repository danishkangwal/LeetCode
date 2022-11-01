class Solution:
    def frequencySort(self, s: str) -> str:
        l = list(s)
        d = {}
        ans = []
        for item in l:
            if item in d:
                d[item] += 1
            else:
                d[item] = 1
        d = sorted(d.items(), key = lambda kv:(kv[1], kv[0]))
        for i in range (len(d)):
            ans += [d[i][0]]*d[i][1]
        ans.reverse()
        return ans