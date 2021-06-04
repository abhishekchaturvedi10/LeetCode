class Solution {
public:
    
    int dp[1005][1005];
    
    int rec(int n, int c, int req){
        
        if(n==req)
            return 0;
        
        if(n>req)
            return INT_MAX/2;
        
        if(dp[req-n][c]!=-1)
            return dp[req-n][c];
        
        return dp[req-n][c]=min(1+rec(n+c,c,req), 2+rec(n+n,n,req));
    }
    
    int minSteps(int n) {
        
        if(n==1)
            return 0;
       
        memset(dp,-1,sizeof(dp));
        
        return 1+rec(1,1,n);
    }
};