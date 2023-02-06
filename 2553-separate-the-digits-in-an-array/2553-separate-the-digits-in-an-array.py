class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        return [int(c) for a in nums for c in str(a)]