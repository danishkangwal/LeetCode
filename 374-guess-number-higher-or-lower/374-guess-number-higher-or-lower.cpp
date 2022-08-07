/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        if(guess(n)==0)
            return n;
        int l = 1,h = n;
        while(l<=h){
            int mid = l + (h-l)/2;
            int tmp = guess(mid);
            if(tmp==0)
                return mid;
            else if(tmp==1)
                l = mid+1;
            else 
                h = mid - 1;
        }
        return n;
    }
};