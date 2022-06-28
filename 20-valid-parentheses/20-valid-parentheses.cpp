class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        if(str.size()==1) return false;
        for(auto i:str){
            if(s.empty()){
                s.push(i);
                continue;
            } 
            char prev = s.top();
            if(prev == '(' && i == ')')
                s.pop();
            else if(prev == '[' && i == ']')
                s.pop();
            else if(prev == '{' && i == '}')
                s.pop();
            else 
                s.push(i);
        }
        if(s.empty()) 
            return true;
        else 
            return false;
    }
};