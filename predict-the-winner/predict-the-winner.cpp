class Solution {
public:
    
    int dp[25][25];
    
    int rec(vector<int>& nums, int s, int e){
        
        if(s>e)
            return 0;
        
        if(dp[s][e]!=-1)
            return dp[s][e];
                
        return dp[s][e]=max(nums[s]+min(rec(nums,s+2,e), rec(nums,s+1,e-1)), nums[e]+min(rec(nums,s,e-2),rec(nums,s+1,e-1)));
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        
        memset(dp,-1,sizeof(dp));
        
        int P1=rec(nums,0,nums.size()-1);
                        
        int tot=0;
        
        for(int i:nums)
            tot+=i;
        
        return tot-P1<=P1;
    }
};