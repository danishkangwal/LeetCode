class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        vector<pair<int,int>> v;
        for(int i = 0;i < score.size();i++){
            v.push_back({score[i][k],i});
        }
        sort(v.begin(),v.end(),[](pair<int,int> a,pair<int,int> b){
            return a.first>b.first;
        });
        vector<vector<int>> ans;
        for(auto& i:v){
            ans.push_back(score[i.second]);
        }
        return ans;
    }
};