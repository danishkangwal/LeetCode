class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        unordered_map<int,bool> m;
        for (int i = 0; i < a.size(); ++i)
        {
            m[a[i]] = true;
        }
        
        int maxLength = 0;
        for (int i = 0; i < a.size(); ++i)
        {
            if(m[a[i]] == false)
                continue;
            int length = 0;
            int x = a[i];
            while(m[x]){
                length++;
                m[x] = false;
                x++;
            }
            x = a[i]-1;
            while(m[x]){
                length++;
                m[x] = false;
                x--;
            }

            if(length > maxLength){
                maxLength = length;
            }
        }
        return maxLength;
    }
};