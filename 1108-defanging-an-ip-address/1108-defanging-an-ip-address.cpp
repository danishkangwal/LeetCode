class Solution {
    static regex r;
public:
    static string defangIPaddr(const string& address)
    {
        return regex_replace(address, r, "[.]");
    }
};
regex Solution::r = regex("[.]");