class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<string,bool> mp;
        for(auto& word:words){
            for(auto&ch : word){
                ch = 'a' + order.find(ch);
            }
            mp[word] = 1;
        }
        int idx = 0;
        for(auto it = mp.begin();it != mp.end();it++){
            if(it->first != words[idx++])
                return 0;
        }
        return 1;
    }
};