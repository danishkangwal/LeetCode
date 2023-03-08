class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long low = 1;
        long high = *max_element(piles.begin(),piles.end());
        while(low<high){
            long mid = low + (high-low)/2;
            long time = 0;
            for(auto i :piles){
                time += i/mid;
                if(i%mid!=0)
                    time++;
                if(time>h)
                    break;
            }
            if(time <= h){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
                    
        return high;
    }
};