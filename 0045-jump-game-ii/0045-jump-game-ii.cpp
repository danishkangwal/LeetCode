class Solution {
public:
    int jump(vector<int>& a) {
        int jumps = 0,n=a.size();
        int end=0,far=0;
        
        for(int i = 0;i < n-1;i++){
            far = max(far,i+a[i]);
            
            if(i==end){
                jumps++;
                end = far;
            }
        }
        
        return jumps;
    }
};