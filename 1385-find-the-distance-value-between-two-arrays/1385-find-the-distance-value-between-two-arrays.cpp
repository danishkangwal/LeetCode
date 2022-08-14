class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(),arr2.end());
        int ans = 0;
        for(auto num:arr1){
            int left = 0,right = arr2.size()-1;
            bool found = false;
            while(left<=right){
                int mid = left + (right-left)/2;
                if(abs(num-arr2[mid])<=d){
                    found = true;
                    break;
                }
                else if(arr2[mid]<num)
                    left = mid+1;
                else
                    right = mid-1;
            }
            if(!found)ans++;
        }
        return ans;
    }
};