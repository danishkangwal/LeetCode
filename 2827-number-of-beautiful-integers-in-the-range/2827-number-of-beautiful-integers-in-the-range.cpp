class Solution {
    int check(int low){
        int even=0,odd=0;
        
        while(low){
            if(low%2==0)
                even++;
            else
                odd++;
            low /= 10;
        }
        
        return even==odd;
    }
public:
    int numberOfBeautifulIntegers(int low, int high, int k) {
        low = ((low-1)/k + 1)*k;
        int count = 0;
        while(low<=high){
            count += check(low);
            low+=k;
            
            if(low>=100000000)
                return count;
        }
        return count;
    }
};