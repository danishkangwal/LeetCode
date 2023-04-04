class Solution {
public:
    int partitionString(string s) {
        int map = 0;
        int count = 1;
        for(char ch : s){
            int c = ch-'a';
            if((map & (1<<c)) > 0) {
                count++;
                map = 0;
            }
            map |= (1<<c);
        }
        return count;
    }
};