class Solution {
public:
    int countKDifference(vector<int>& a, int k) {
        int freq[101] = {},n = a.size();
        for(auto i:a){
            freq[i]++;
        }
        int count = 0;
        for(int i = k+1;i < 101;i++){
            count += freq[i]*freq[i-k];
        }
        return count;
    }
};