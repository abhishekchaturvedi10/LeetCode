class Solution {
public:

    int wiggleMaxLength(vector<int>& nums) {
        
        vector<vector<int>> dp(nums.size(), vector<int>(2));
        
        int res=0;
        
        for(int i=1;i<nums.size();i++){
            
            for(int j=0;j<i;j++){
                
                if(nums[i]-nums[j]>0){
                    dp[i][1]=max(dp[i][1], dp[j][0]+1);
                }
                
                if(nums[i]-nums[j]<0){
                    dp[i][0]=max(dp[i][0], dp[j][1]+1);
                }
            }
            
            res=max({res, dp[i][0], dp[i][1]});
        }
        
        return res+1;
    }
};