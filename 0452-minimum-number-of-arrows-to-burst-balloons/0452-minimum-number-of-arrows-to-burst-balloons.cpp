class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) {
            return 0;
        }
        sort(points.begin(),points.end(),[](const vector<int> &a, const vector<int> &b){
            return a[1] < b[1];
        });
        int pos = points[0][1];
        int count = 1;
        for (int i = 1; i < points.size(); i++) {
            if (pos >= points[i][0]) {
                continue;
            }
            count++;
            pos = points[i][1];
        }
        return count;
    }
};