class Solution {
    bool isVowel(char i){
        return i=='A' or i=='E' or i=='I' or i=='O' or i=='U' or i=='a' or i=='e' or i=='i' or i=='o' or i=='u';
    }
public:
    string sortVowels(string s) {
        string v = "";
        copy_if(s.begin(),s.end(),back_inserter(v),[&](char ch){
            return isVowel(ch);
        });
        sort(v.begin(),v.end());
        int idx=0;
        for(auto &i:s){
            if(isVowel(i))
                i=v[idx++];
        }
        return s;
    }
};