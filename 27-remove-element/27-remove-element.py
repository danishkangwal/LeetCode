class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        l,idx=len(nums),0
        while idx<l:
            if nums[idx]==val:
                nums[idx]=nums[l-1]
                l-=1
            else:
                idx+=1
        return l
                