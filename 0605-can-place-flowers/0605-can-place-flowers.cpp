class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        for(int i = 0;i < flowerbed.size();i++){
            if(flowerbed[i]==0){
                bool leftEmpty = (i==0)||(flowerbed[i-1]==0);
                bool rightEmpty = (i==flowerbed.size()-1)||(flowerbed[i+1]==0);
                
                if(leftEmpty and rightEmpty){
                    flowerbed[i] = 1;
                    count++;
                    if(count>=n){
                        return 1;
                    }
                    
                }
            }
            
        }
        
        return count>=n;
    }
};