class Solution {
public:
    
    int dp[25][25];
    
    int total;
    
    int rec(vector<int>& nums, int s, int e){
        
        if(s==e)
            return nums[s];
        
        if(dp[s][e]!=-1)
            return dp[s][e];
                
        return dp[s][e]=max({nums[s]-rec(nums,s+1,e), nums[e]-rec(nums,s,e-1)});
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        
        memset(dp,-1,sizeof(dp));
        
        return rec(nums,0,nums.size()-1)>=0;
    }
};