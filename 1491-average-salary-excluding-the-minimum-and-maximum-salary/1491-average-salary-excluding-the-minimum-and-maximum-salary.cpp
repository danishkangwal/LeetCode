class Solution {
public:
    double average(vector<int>& salary) {
        int mini = INT_MAX,maxi = INT_MIN;
        for(auto&i : salary){
            mini = min(mini,i);
            maxi = max(maxi,i);
        }
        double sum = 0;
        for(auto&i : salary){
            if(i!=mini and i!=maxi)
                sum += i;
        }
        return sum/(salary.size()-2);
    }
};