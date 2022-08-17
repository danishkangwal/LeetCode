class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> codes = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> found;
        for(auto word:words){
            string cur = "";
            for(auto ch:word){
                cur += codes[ch-'a'];
            }
            found.insert(cur);
        }
        
        return found.size();
    }
};