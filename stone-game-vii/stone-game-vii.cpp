class Solution {
public:
    
    int dp[1005][10005][2];
    
    int prefix[1005];
    
    int rec(vector<int>& stones, int i, int j, int turn){
        
        if(i>=j)
            return 0;
        
        if(dp[i][j][turn]!=-1)
            return dp[i][j][turn];
        
        int s1=prefix[j+1]-prefix[i+1],s2=prefix[j]-prefix[i];
        
//         for(int k=i+1;k<=j;k++)
//             s1+=stones[k];
        
//         for(int k=i;k<j;k++)
//             s2+=stones[k];
        
        if(!turn)
            return dp[i][j][turn]=max({s1+rec(stones,i+1,j,1), s2+rec(stones,i,j-1,1)});
        else
            return dp[i][j][turn]=min({-s1+rec(stones,i+1,j,0), -s2+rec(stones,i,j-1,0)});
    }
    
    int stoneGameVII(vector<int>& stones) {
        
        memset(dp,-1,sizeof(dp));
        
        prefix[0]=0;
        
        for(int i=0;i<stones.size();i++)
            prefix[i+1]=prefix[i]+stones[i];
        
        return rec(stones,0,stones.size()-1,0);
    }
};