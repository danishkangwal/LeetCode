class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = INT_MIN;
        int i = 0;
        for(auto j:gain){
            ans = max(ans,i);
            i += j;
        }
        return max(ans,i);
    }
};