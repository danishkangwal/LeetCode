class Solution {
    void merge(vector<int>& nums,int left,int mid,int right){
        vector<int> t;
        int l = left,r = mid+1;
        while(l <= mid and r <= right){
            if(nums[l] < nums[r]){
                t.push_back(nums[l++]);
            }else{
                t.push_back(nums[r++]);
            }
        }
        while(l <= mid)
            t.push_back(nums[l++]);
        while(r <= right)
            t.push_back(nums[r++]);
        for(int i = left;i <= right;i++){
            nums[i] = t[i-left];
        }
    }
    int countPairs(vector<int>&nums,int left,int mid,int right){
        int r = mid+1, cnt = 0;
        for(int i = left;i <= mid;i++){
            while(r <= right and nums[i]>1LL*2*nums[r])
                r++;
            cnt += r-mid-1;
        }
        return cnt;
    }
    int solve(vector<int>& nums,int left,int right){
        int cnt = 0;
        if(left >= right)
            return cnt;
        int mid = left + (right-left)/2;
        cnt += solve(nums,left,mid);
        cnt += solve(nums,mid+1,right);
        cnt += countPairs(nums,left,mid,right);
        merge(nums,left,mid,right);
        return cnt;
    }
    
public:
    int reversePairs(vector<int>& nums) {
        
        return solve(nums,0,nums.size()-1);
    }
};