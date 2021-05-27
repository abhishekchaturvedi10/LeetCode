class Solution {
public:
    
    int dp[205][205];
    
    int rec(vector<vector<int>>& arr, int i, int j){
        
        if(i==arr.size())
            return 0;
                
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        dp[i][j]=INT_MAX;
                
        for(int k=0;k<arr[0].size();k++)
            if(k!=j)
                dp[i][j]=min(dp[i][j], arr[i][j]+rec(arr,i+1,k));
                
        return dp[i][j];
    }
    
    int minFallingPathSum(vector<vector<int>>& arr) {
        
        memset(dp,-1,sizeof(dp));
        
        int res=INT_MAX;
        
        for(int i=0;i<arr[0].size();i++)
            res=min(res, rec(arr,0,i));
        
        return res;
    }
};