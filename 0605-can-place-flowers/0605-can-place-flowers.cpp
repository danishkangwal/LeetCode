class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        int count = 0;
        for(int i = 0; i < size; i++){
            
            int last = i - 1 >= 0 ? flowerbed[i - 1] : 0;
            int next = i + 1 < size ? flowerbed[i + 1] : 0;
            
            if (flowerbed[i] == 0 and last == 0 and next == 0) {
                count++;
                i++;
            }
            if (count >= n)
                return true;
            
        }
        return false;
    }
};