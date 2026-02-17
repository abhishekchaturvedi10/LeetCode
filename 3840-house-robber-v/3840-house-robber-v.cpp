class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        
        vector<vector<long long>> dp(nums.size()+1,vector<long long>(2LL,0));
        int n=nums.size();

        dp[0][1]=nums[0];

        for(int i=1;i<n;i++) {
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
            dp[i][1] = nums[i] + dp[i-1][0];
            if(colors[i-1]!=colors[i]) {
                dp[i][1] = max(dp[i][1], nums[i]+dp[i-1][1]);
            }
        }

        return max(dp[n-1][0], dp[n-1][1]);
    }
};