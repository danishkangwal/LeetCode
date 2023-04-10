class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(auto& c:s){
            if(c=='(' or c=='{' or c=='['){
                st.push(c);
            }
            else if(c==')'){
                if(st.size() and st.top()=='('){
                    st.pop();
                }
                else
                    return 0;
            }
            else if(c=='}'){
                if(st.size() and st.top()=='{'){
                    st.pop();
                }
                else
                    return 0;
            }
            else if(c==']'){
                if(st.size() and st.top()=='['){
                    st.pop();
                }
                else
                    return 0;
            }
            
        }
        return st.size()==0;
    }
};