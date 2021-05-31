class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        
        int n=ages.size();
        
        vector<vector<int>> players(n);
        
        for(int i=0;i<n;i++)
            players[i]={ages[i], scores[i]};
        
        sort(players.begin(), players.end());
        
        vector<int> dp(n);
        
        dp[0]=players[0][1];
        
        int res=dp[0];
        
        for(int i=1;i<n;i++){
            
            dp[i]=players[i][1];
            
            for(int j=0;j<i;j++){
                
                if(players[i][1]>=players[j][1]){
                    dp[i]=max(dp[j]+players[i][1], dp[i]);
                }
            }
            
            res=max(res,dp[i]);
        }
        
        return res;
    }
};