class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        
        vector<int> mn(n);
        
        mn[0]=nums[0];
        
        for(int i=1;i<n;i++){
            
            mn[i]=min(nums[i],mn[i-1]);
        }
        
        set<int> s;
        
        s.insert(nums[n-1]);
        for(int i=n-2;i>=1;i--){
            
            s.insert(nums[i]);
            
            auto it=s.lower_bound(nums[i]);
            
            if(it!=s.begin()){
                it--;
                
                int mid=*it;
                
                if(mid>mn[i-1]&&mid<nums[i])
                    return true;
            }

        }
   
        
        return false;
    }
};