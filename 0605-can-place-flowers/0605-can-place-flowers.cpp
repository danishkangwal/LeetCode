class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        for(int i = 0; i < flowerbed.size(); i++){
            if(flowerbed[i] == 0){
                int prev = i - 1 >= 0 ? flowerbed[i - 1] : 0;
                int next = i + 1 < flowerbed.size() ? flowerbed[i + 1] : 0;
                
                if(prev == 0 && next == 0){
                    flowerbed[i] = 1;
                    count++;
                }
            }
        }
        
        return count >= n;
    }
};