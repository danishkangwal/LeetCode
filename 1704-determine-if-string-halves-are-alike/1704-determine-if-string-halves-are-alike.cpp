class Solution {
public:
    bool halvesAreAlike(string s) {
        string left = s.substr(0,s.size()/2);
        string right = s.substr(s.size()/2,s.size());
        int vowels = 0;
        unordered_set<char> st = {'a','e','i','o','u','A','E','I','O','U'};
        for(int i=0;i<left.size();i++){
            if(st.find(left[i])!=st.end())
                vowels++;
        }
        for(int i=0;i<right.size();i++){
            if(st.find(right[i])!=st.end())
                vowels--;
        }
        if(vowels!=0)
            return false;
        return true;
    }
};