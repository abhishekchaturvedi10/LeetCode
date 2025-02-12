class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n=nums.size(), res=-1;
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++) {
            int x=nums[i], sum=0;
            while(x>0) {
                sum+=x%10;
                x/=10;
            }
            if(mpp.find(sum)==mpp.end()) {
                mpp[sum]={nums[i]};
            } else {
                res=max(res,nums[i]+mpp[sum]);
                mpp[sum]=max(mpp[sum],nums[i]);
            }
        }
        return res;
    }
};