class Solution {
public:
    int minJumps(vector<int>& a) {
        int i,n=a.size();
        int dp[n],inq[n];
        
        unordered_map<int,vector<int>> mp;
        
        for(i=0;i<n;i++){
            dp[i]=INT_MAX;
            inq[i]=0;
            mp[a[i]].push_back(i);
        }
        
        dp[n-1]=0;
        queue<int> q;
        q.push(n-1);
        
        while(q.size()){
            int f=q.front();
            q.pop();
            inq[f]=0;
			
            for(auto v:mp[a[f]])
                if(dp[v]>dp[f]+1){
                    dp[v]=dp[f]+1;
                    if(!inq[v]){
                        inq[v]=1;
                        q.push(v);
                    }
                }
            
            mp.erase(a[f]);
			
            if(f+1<n && dp[f+1]>dp[f]+1){
                dp[f+1]=dp[f]+1;
                if(!inq[f+1]){
                    q.push(f+1);
                    inq[f+1]=1;
                }
            }
            
            if(f && dp[f-1]>dp[f]+1){
                dp[f-1]=dp[f]+1;
                if(!inq[f-1]){
                    q.push(f-1);
                    inq[f-1]=1;
                }
            }
        }
		
        return dp[0];
    }
};