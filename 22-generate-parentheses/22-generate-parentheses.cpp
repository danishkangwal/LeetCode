class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        helper(0,0,n,"");
        return ans;
    }
    void helper(int open,int closed,int n,string curr){
        if(open==closed && open==n){
            ans.push_back(curr);
            return;
        }
        if(open<n)
            helper(open+1,closed,n,curr+"(");
        if(closed<open)
            helper(open,closed+1,n,curr+")");
    }
};