class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l = 0
        r = len(nums)-1
        
        while (l <= r):
            mid = (l+r) // 2;
            if (target == nums[mid]):
                return mid
            
            if (nums[mid] > nums[r]) :
                if (target < nums[mid] and target >= nums[l]):
                    r = mid - 1
                else:
                    l = mid + 1
            elif (nums[mid] < nums[l]):
                if (target > nums[mid] and target <= nums[r]):
                    l = mid + 1
                else:
                    r = mid - 1
            else:
                if (target < nums[mid]):
                    r = mid - 1
                else:
                    l = mid + 1
        return -1