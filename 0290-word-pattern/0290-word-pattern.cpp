class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string,char> m;
        int idx = 0;
        for(int i = 0;i < s.size();i++){
            string tmp = "";
            while(s[i]!=' ' && i<s.size()){
                tmp += s[i];
                i++;
            }
            if(m.count(tmp)>0){
                if(m[tmp] != pattern[idx]){
                    return false;
                }else{
                    idx++;
                    continue;
                }
            }
            for(auto it=m.begin();it != m.end();it++){
                if(it->second == pattern[idx]){
                    return false;
                }
            }
            m[tmp] = pattern[idx++];
        }
        if(idx != pattern.size())
            return false;
        return true;
    }
};