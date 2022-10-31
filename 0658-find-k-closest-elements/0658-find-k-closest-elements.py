class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        min_heap = []
        ans = []
        for i in range(len(arr)):
            heappush(min_heap,(abs(arr[i]-x),arr[i]))
        while k > 0:
            ans.append(heappop(min_heap)[1])
            k-=1
        ans.sort()
        return ans