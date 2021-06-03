class Solution {
public:
    
    long long dp[4][4][5005];
        
    long long rec(int x, int y, int k){
        
        if((x==3&&y==0)||(x==3&&y==2)||x<0||y<0||x>3||y>2)
            return 0;
        
        if(k==1)
            return 1;
        
        if(dp[x][y][k]!=-1)
            return dp[x][y][k];
                
            dp[x][y][k]=(rec(x-2,y-1,k-1)+rec(x+2,y-1,k-1)+rec(x-2,y+1,k-1)+rec(x+2,y+1,k-1)+rec(x-1,y-2,k-1)+rec(x-1,y+2,k-1)+rec(x+1,y-2,k-1)+rec(x+1,y+2,k-1))%1000000007;
        
        return dp[x][y][k];
    }
    
    int knightDialer(int n) {
        
        memset(dp,-1,sizeof(dp));
                
        long long res=0;
        
        for(int i=0;i<=3;i++)
            for(int j=0;j<3;j++)
                if(!((i==3&&j==0)||(i==3&&j==2)))
                    res+=(rec(i,j,n))%1000000007;
        
        return res%1000000007;
    }
};