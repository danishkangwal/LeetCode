class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        bool flag = false;
        for(int i = 0 ; i < str.size() ; i++){
            if(str[i] == '{' || str[i] == '(' || str[i] == '[')
                s.push(str[i]);
            else{
                if(s.empty())
                    return false;
                char prev = s.top();
                s.pop();
                if((str[i] == ')' && prev == '(') || (str[i] == ']' && prev == '[') || (str[i] == '}' && prev == '{')){
                    flag = true;
                }
                else
                    return false;
            }
        }
        if(!s.empty()){
            return false;
        }
        return flag;
    }
};