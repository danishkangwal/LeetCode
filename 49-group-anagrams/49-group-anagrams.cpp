class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> copy=strs;
        for(auto &i:copy){
            sort(i.begin(),i.end());
        }
        vector<vector<string>> ans;
        vector<bool> done(strs.size(),0);
        for(int i=0;i<strs.size();i++){
            vector<string> t;
            if(done[i]==0)
                t.push_back(strs[i]);
            for(int j=i+1;j<strs.size();j++){
                if(done[j]==0 && copy[i]==copy[j]){
                    t.push_back(strs[j]);
                    done[j]=1;
                }
            }
            if(t.size()){
                ans.push_back(t);
            }
        }
        return ans;
    }
};