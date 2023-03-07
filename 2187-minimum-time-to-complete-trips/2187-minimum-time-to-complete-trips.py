class Solution:
    def minimumTime(self, time: List[int], totalTrips: int) -> int:
        ans = 0;
        time.sort()
        low ,high = 1,totalTrips*time[0];
        while(low<high):
            mid = low + (high-low)//2;
            total = 0
            for i in time:
                total += mid//i
            if total < totalTrips:
                low = mid+1
            else:
                high = mid
        return high;