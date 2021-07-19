class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        
        sort(clips.begin(), clips.end());
        
        vector<int> dp(101, 101);
        
        dp[0]=0;
        
        int n=clips.size();
        
        for(int i=0;i<n;i++){
            if(clips[i][1]==0)
                continue;
            for(int j=min(time, max(1,clips[i][0]));j<=min({time, 100, clips[i][1]});j++)
                dp[j]=min(dp[j], dp[clips[i][0]]+1);
        }
        
        return dp[time]==101?-1:dp[time];
    }
};