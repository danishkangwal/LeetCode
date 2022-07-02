class Solution {
    const unsigned int mod = 1000000007;
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts)     {
            ios_base::sync_with_stdio(0);
            cin.tie(NULL);
        
            sort(horizontalCuts.begin(), horizontalCuts.end());
            sort(verticalCuts.begin(), verticalCuts.end());
            int prev = 0, mxm = 0;
            for (int cut : horizontalCuts) {
                mxm = max(mxm, cut-prev);
                prev = cut;
            }
            mxm = max(mxm, h-prev);
            int max_h = mxm;

            prev = 0, mxm = 0;
            for (int cut : verticalCuts) {
                mxm = max(mxm, cut-prev);
                prev = cut;
            }
            mxm = max(mxm, w-prev);
            long prod = (long)max_h * (long)mxm;
            return prod % mod;
     }
};