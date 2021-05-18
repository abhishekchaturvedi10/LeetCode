class Solution {
public:
    
    int dp[505];
    
    int helper(vector<int>& arr, int i, int kk){
        
        if(i>=arr.size())
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        
        int mx=INT_MIN;
        
        int mn=i+kk;
        
        if(mn>arr.size())
            mn=arr.size();
        
        for(int j=i;j<mn;j++){
            
            mx=max(mx,arr[j]);
            
            int val=0;
            
            for(int k=1;k<=j-i+1;k++){
                val+=mx;
            }
            
            dp[i]=max(dp[i],val+helper(arr,j+1,kk));
        }
        
        return dp[i];
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        memset(dp,-1,sizeof(dp));
        
        return helper(arr,0,k);
    }
};