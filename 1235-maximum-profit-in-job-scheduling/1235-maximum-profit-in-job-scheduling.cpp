class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        map<int,int> times;
        unordered_map<int,vector<pair<int,int>>> jobs;
        
        for(int i = 0;i < startTime.size();i++){
            jobs[startTime[i]].push_back({endTime[i],profit[i]});
            times[startTime[i]] = 0;
        }
        
        int maxProfit = 0;
        
        for(auto it = times.rbegin();it!=times.rend();it++){
            for(auto job: jobs[it->first]){
                auto itr = times.lower_bound(job.first);
                maxProfit = max(maxProfit,(itr==times.end()?0:itr->second)+job.second);
            }
            it->second = maxProfit;
        }
        
        return maxProfit;
    }
};