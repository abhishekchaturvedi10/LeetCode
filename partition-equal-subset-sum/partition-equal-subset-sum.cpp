class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i:nums)
            sum+=i;
        if(sum%2)
            return false;
        sum/=2;
        vector<int> dp(sum+1);
        dp[0]=1;
        for(int i:nums)
            for(int j=sum;j>=i;j--)
                dp[j]=dp[j]|dp[j-i];
        return dp[sum];
    }
};