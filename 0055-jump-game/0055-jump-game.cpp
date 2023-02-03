class Solution {
public:
    bool canJump(vector<int>& a) {
        int i=0,maxDistance = 0;

        while(i <= maxDistance){
            maxDistance = max(maxDistance,i+a[i]);
            if(maxDistance >= a.size()-1){
                return true;
            }
            i++;
        }
        return false;
    }
};