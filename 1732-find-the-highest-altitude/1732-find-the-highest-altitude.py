class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        ans = float("-inf")
        i = 0
        for j in range(len(gain)):
            ans = max(ans,i)
            i += gain[j]
        
        return max(ans,i)
        