class Solution {
public:
    int compress(vector<char>& chars) {
        
        if(chars.size()==1)
            return 1;
        int res = 0;
        int i = 0;
        while(i < chars.size()){
            int cnt = 1;
            
            while(i+cnt < chars.size() and chars[i+cnt]==chars[i]){
                cnt++;
            }
            chars[res++] = chars[i];
            
            if(cnt>1){
                for(auto c : to_string(cnt)){
                    chars[res++] = c;
                }
                
            }
            i += cnt;
        }
        return res;
    }
};