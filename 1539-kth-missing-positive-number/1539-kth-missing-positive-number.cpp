class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int x = 1,i=0;
        while(1){
            if(i<arr.size() && arr[i]==x){
                x++;
                i++;
            }else{
                k--;
                if(!k)
                    return x;
                x++;
            }
        }
        return -1;
    }
};