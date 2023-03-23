class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& arr, int target) {
        int ans = 0;
        
        double product = 1;
        int left = 0;
        for (int right = 0; right < arr.size(); right++) {
          product *= arr[right];
          while (product >= target && left < arr.size()) {
            product /= arr[left++];
          }
            
          for (int i = right; i >= left; i--) {
              ans++;
          }
        }
        
        return ans;
    }
};