class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()>haystack.size())
            return -1;
        if(needle==haystack)
            return 0;
        int winSize = needle.size();
        int start = 0;
        for(;start<=haystack.size()-winSize;start++){
            if(haystack.substr(start,winSize)==needle){
                return start;
            }
        }
        return -1;
    }
};