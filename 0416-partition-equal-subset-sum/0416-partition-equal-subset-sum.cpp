class Solution {
public:
    int rec(vector<int>& nums, int i, int reqSum, vector<vector<int>>& dp) {
        if(reqSum==0) {
            return true;
        }
        if(i==nums.size()||reqSum<0) {
            return false;
        }
        if(dp[i][reqSum]!=-1) {
            return dp[i][reqSum];
        }
        return dp[i][reqSum]=rec(nums,i+1,reqSum,dp)|rec(nums,i+1,reqSum-nums[i],dp);
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int& i:nums) {
            sum+=i;
        }
        if(sum&1) {
            return false;
        }
        vector<vector<int>> dp(nums.size(),vector<int>(sum+1,-1));
        return rec(nums,0,sum/2,dp);
    }
};