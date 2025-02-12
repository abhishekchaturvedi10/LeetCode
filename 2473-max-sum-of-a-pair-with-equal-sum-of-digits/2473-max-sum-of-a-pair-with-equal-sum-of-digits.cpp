class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n=nums.size(), res=-1;
        vector<int> mpp(82,-1);
        for(int i=0;i<n;i++) {
            int x=nums[i], sum=0;
            while(x) {
                sum+=x%10;
                x/=10;
            }
            if(mpp[sum]==-1) {
                mpp[sum]=nums[i];
            } else {
                res=max(res,nums[i]+mpp[sum]);
                mpp[sum]=max(mpp[sum],nums[i]);
            }
        }
        return res;
    }
};