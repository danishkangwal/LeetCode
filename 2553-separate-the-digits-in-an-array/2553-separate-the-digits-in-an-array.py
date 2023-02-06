class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        ans = []
        for x in nums:
            ans.extend(map(int,str(x)))
        return ans