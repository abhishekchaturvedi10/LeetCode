class Solution {
public:
    
    int dp[505][505];
    
    int pre[505];
    
    int rec(vector<int>& s, int i, int j){
        
        // cout<<"i "<<i<<" j "<<j<<endl;
        
        if(j-i<1)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int res=INT_MIN;
        
        for(int k=i+1;k<=j;k++){
            
            int s1=pre[k]-pre[i], s2=pre[j+1]-pre[k];
            
            // cout<<s1<<" "<<s2<<" "<<k<<endl;
            
            if(s1>s2){
                res=max(res, s2+rec(s,k,j));
            }
            else if(s2>s1){
                res=max(res, s1+rec(s,i,k-1));
            }
            else{
                res=max({res, s2+rec(s,k,j), s1+rec(s,i,k-1)});
            }
        }
        
        return dp[i][j]=res;
    }
    
    int stoneGameV(vector<int>& stoneValue) {
        
        
        pre[0]=0;
        
        for(int i=0;i<stoneValue.size();i++)
            pre[i+1]=pre[i]+stoneValue[i];
        
        memset(dp,-1,sizeof(dp));
        
        return rec(stoneValue, 0, stoneValue.size()-1);
    }
};