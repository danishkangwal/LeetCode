class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string res;
        
        for(int i = 0;i < path.size(); ++i)
        {
            if(path[i] == '/')    
                continue;
            
            string temp;
            while(i < path.size() && path[i] != '/')
            {
                temp += path[i];
                ++i;
            }
            if(temp == ".")
                continue;
            else if(temp == "..")
            {
                if(st.size())
                    st.pop();
            }
            else
                st.push(temp);
        }
        
        if(st.size() == 0)
            return "/";
        while(!st.empty())
        {
            res = "/" + st.top() + res;
            st.pop();
        }
        
        return res;
    }
};