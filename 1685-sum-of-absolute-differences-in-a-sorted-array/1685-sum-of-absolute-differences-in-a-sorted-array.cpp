class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {

        int n = nums.size();
        vector<int> preSum(n), res(n);
        preSum[0]=nums[0];

        for(int i=1;i<n;i++) {
            preSum[i] = preSum[i-1]+nums[i];
        }

        for(int i=0;i<n;i++) {
            int prevSum = i>0?((nums[i]*i)-preSum[i-1]):0;
            int nextSum = i<n-1?((preSum[n-1]-preSum[i])-(nums[i]*(n-i-1))):0;
            res[i]=prevSum+nextSum;
        }

        return res;
    }
};