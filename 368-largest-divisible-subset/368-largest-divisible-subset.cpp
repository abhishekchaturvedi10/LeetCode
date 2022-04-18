class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n=nums.size(), imax=0;
        
        sort(nums.begin(),nums.end());
        
        vector<int> dp(n,1), child(n,-1);
        
        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(nums[i]%nums[j]==0&&dp[j]+1>dp[i]) {
                    dp[i]=dp[j]+1;
                    child[i]=j;
                }
            }
            if(dp[imax]<dp[i]) {
                imax=i;
            }
        }
        
        vector<int> res;
        
        while(imax!=-1) {
            res.push_back(nums[imax]);
            imax=child[imax];
        }
        
        return res;
    }
};