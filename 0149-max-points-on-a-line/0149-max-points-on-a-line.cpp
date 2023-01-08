class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n==1)
            return 1;
        int ans = 0;
        for(int i = 0;i < n;i++){
            unordered_map<double,int> mp;
            for(int j = i+1;j < n;j++){
                double slope = helper(points[i],points[j]);
                mp[slope]++;
                ans = max(ans,mp[slope]);
            }
        }
        return ans+1;
    }
private:
    double helper(vector<int>& p1, vector<int>& p2){
        int x1 = p1[0],y1 = p1[1]; 
        int x2 = p2[0],y2 = p2[1];
        if(x1 == x2)
            return INT_MAX;
        if(y1 == y2)
            return 0;
        return (double)(y2-y1)/(double)(x2-x1);
    }
};