class Solution {
public:
    
    int dp[505][505];
    
    int rec(int i, int j, string &a, string &b){
        
        if(i==a.size())
            return b.size()-j;
        
        if(j==b.size())
            return a.size()-i;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(a[i]==b[j])
            return dp[i][j]=rec(i+1, j+1, a, b);
        else
            return dp[i][j]=1+min(rec(i+1,j,a,b), rec(i,j+1,a,b));
    }
    
    int minDistance(string a, string b) {
        memset(dp,-1,sizeof(dp));
        return rec(0,0,a,b);
    }
};