class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        map<string,int> mp;
        for(int i = 0;i <str1.size();i++){
            string prefix = str1.substr(0,str1.size()-i);
            mp[prefix] = 1;
        }
        string ans = "";
        for(int i = 0;i <str2.size();i++){
            string prefix = str2.substr(0,str2.size()-i);
            if(mp[prefix]&&prefix.size()>ans.size()){
                if(helper(str1,prefix) and helper(str2,prefix))
                    ans = prefix;
            }
        }
        return ans;
    }
private:
    bool helper(string s,string gcd){
        if(s.size()==0)
            return 1;
        string temp = s.substr(0,gcd.size());
        if(temp!=gcd)
            return 0;
        return helper(s.substr(gcd.size()),gcd);
    }
};