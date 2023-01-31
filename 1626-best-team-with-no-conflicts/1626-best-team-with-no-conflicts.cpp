class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> players;
        for(int i = 0;i < scores.size();i++){
            players.push_back({ages[i],scores[i]});
        }
        sort(players.begin(),players.end(),greater<>());
        
        vector<int> dp(scores.size());
        int ans = 0;
        for(int i = 0;i < players.size();i++){
            int score = players[i].second;
            dp[i] = score;
            for(int j = 0;j < i;j++){
                if(players[j].second>=score){
                    dp[i] = max(dp[i],dp[j]+score);
                }
            }
            ans = max(dp[i],ans);
        }
        return ans;
    }
};