class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long ans = 0;
        sort(time.begin(),time.end());
        unsigned long long low = 1,high = 1LL * totalTrips*time[0];
        while(low<high){
            long mid = (low+high)>>1;
            long total = 0;
            for(auto i:time){
                total += mid/i;
                if(total>=totalTrips)
                    break;
            }
            if(total < totalTrips)
                low = mid+1;
            else
                high = mid;
        }
        
        return high;
    }
};