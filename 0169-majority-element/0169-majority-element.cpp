class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int element;
        int n = arr.size();
        int cnt = 0;
        for(int i = 0;i < n;i++){
              if (cnt == 0) {
                cnt++;
                element = arr[i];
              } else if (arr[i] == element)
                cnt++;
              else
                cnt--;

        }
        int cnt1 = 0;
        for(int i = 0;i < n;i++)
            if(arr[i]==element)
                cnt1++;

        return (cnt1 > n/2?element:-1);
    }
};