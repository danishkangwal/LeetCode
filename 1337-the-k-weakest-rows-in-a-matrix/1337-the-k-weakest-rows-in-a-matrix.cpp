class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> ans;
        vector<pair<int, int>> vect;
        
        int m = mat.size(), n = mat[0].size();
        for(int i=0; i<m; i++)
        {
            int j=0, cntSol = 0;
            while(j<n && mat[i][j++] == 1)
                cntSol++;
            
            vect.push_back({cntSol, i});
        }
        
        sort(vect.begin(), vect.end());
        
        for(int i=0; i<k; i++)
        {
            int ele = vect[i].second;
            ans.push_back(ele);
        }
        return ans;
        
        
    }
};